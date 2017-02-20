import java.io.*;
import java.util.*;

public class swallow {
  public static final int MAX_SIZE = 1000;

  public static String folded[][] = new String[MAX_SIZE+1][MAX_SIZE+1];

  public static void fold(String s, int i, int j) {
    if (folded[i][j] != null)
      return;

    folded[i][j] = s.substring(i, j);
    if (j-i == 1) {
      return;
    }

    for (int k = i+1; k < j; ++k) {
      fold(s, i, k);
      fold(s, k, j);

      String p1a = folded[i][k];
      String p2a = folded[k][j];

      if (p1a.length() + p2a.length() < folded[i][j].length())
        folded[i][j] = p1a + p2a;

      if ((j-k) % (k-i) == 0) {
        final String p1 = s.substring(i, k);
        int idx = k;
        boolean is_repeated = true;

        while (idx != j) {
          if (!s.substring(idx, idx+p1.length()).equals(p1)) {
            is_repeated = false;
            break;
          }
          idx += p1.length();
        }

        if (is_repeated) {
          String t = "" + ((j-k)/p1.length()+1);
          if (t.length() + p1a.length() + 2 < folded[i][j].length()) {
            folded[i][j] = t + "(" + p1a + ")";
          }
        }
      }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(fin.readLine());
    String s = fin.readLine().trim();

    fold(s, 0, s.length());
    
    System.out.println(folded[0][s.length()]);
  }
}
