import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Tree {
        static ArrayList<Integer> []edge = new  ArrayList[702] ;
        static Scanner cin = new Scanner(System.in);
        static int n;
        static BigInteger [][]dp = new BigInteger[702][702];
        static int []sz = new int[702];
        static void dfs(int f, int u){
//              System.out.println(f +" "+u);
                sz[u] = 1;
                for(int i = 0; i <= n; ++i){
                        dp[u][i] = BigInteger.valueOf(1);
                }
                for(int i = 0; i < edge[u].size(); ++i){
                        if(edge[u].get(i) == f)continue;
                        dfs(u, edge[u].get(i));
                        for(int j = sz[u]; j >= 1; --j){
                                for(int k = sz[edge[u].get(i)]; k >= 0; --k){
                                        if(dp[u][j + k].compareTo(dp[u][j].multiply(dp[edge[u].get(i)][k])) < 0){
                                                dp[u][j + k] = dp[u][j].multiply(dp[edge[u].get(i)][k]);
                                        }
                                }
                        }
                        sz[u] += sz[edge[u].get(i)];
                }
                for(int i = 1; i <= sz[u]; ++i){
                        if(dp[u][0].compareTo(dp[u][i].multiply(BigInteger.valueOf(i))) < 0){
                                dp[u][0] = dp[u][i].multiply(BigInteger.valueOf(i));
                        }
                }
        }
        public static void main(String[] args) {
            // TODO Auto-generated method stub
				int a, b;
                n = cin.nextInt();
                for(int i = 1; i <= n; ++i)
                        edge[i] = new ArrayList<Integer>();
                
                for(int i = 0; i < n - 1; ++i){
                        a = cin.nextInt();
                        b = cin.nextInt();
                        edge[a].add(b);
                        edge[b].add(a);
                }
//              System.out.println("hello");
                dfs(1, 1);
                System.out.println(dp[1][0]);
        }

}