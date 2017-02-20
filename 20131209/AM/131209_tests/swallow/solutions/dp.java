import java.io.*;
import java.util.*;

public class swallow {
  public static int MAX_SIZE = 1000;

  public static String folded[][] = new String[MAX_SIZE+1][MAX_SIZE+1];

  public static void fold(String s) {
    for (int w = 1; w <= s.length(); ++w) {
      for (int i = 0; i < s.length()-w+1; ++i) {
        folded[i][i+w] = s.substring(i, i+w);
        for (int j = 1; j < w; ++j) {
          String t = folded[i][i+j] + folded[i+j][i+w];
          if (t.length() < folded[i][i+w].length()) {
            folded[i][i+w] = t;
          }

          if (w % j == 0) {
            int d = j;
            boolean is_repeated = true;

            while (d != w) {
              if (!s.substring(i+d, i+d+j).equals(s.substring(i, i+j))) {
                is_repeated = false;
                break;
              }
              d += j;
            }

            if (is_repeated) {
              t = (w/j) + "(" + folded[i][i+j] + ")";
              if (t.length() < folded[i][i+w].length()) {
                folded[i][i+w] = t;
              }
            }
          }
        }
      }
    }
  }

  public static void main(String args[]) throws Exception {
    BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(fin.readLine());
    String s = fin.readLine().trim();

    fold(s);
    
    System.out.println(folded[0][s.length()]);
  }
}
