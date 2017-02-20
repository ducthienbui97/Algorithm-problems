import java.io.*;
import java.util.*;

public class swallow {
  public final int MAX_SIZE = 500;


  public static String fold(String s) {
    if (s.length() == 1)
      return s;

    String ans = s;
    for (int i = 1; i < s.length(); ++i) {
      final String p1 = s.substring(0, i);
      final String p2 = s.substring(i);
      final String p1a = fold(p1);
      final String p2a = fold(p2);

      String t = p1a + p2a;
      if (t.length() < ans.length())
        ans = t;

      if (p2.length() % p1.length() == 0) {
        int idx = 0;
        boolean is_repeated = true;

        while (idx != p2.length()) {
          if (!p2.substring(idx, idx+p1.length()).equals(p1)) {
            is_repeated = false;
            break;
          }
          idx += p1.length();
        }

        if (is_repeated) {
          t = (p2.length()/p1.length()+1) + "(" + p1a + ")";
          if (t.length() < ans.length()) {
            ans = t;
          }
        }
      }
    }

    return ans;
  }

  public static void main(String args[]) throws Exception {
    BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(fin.readLine());
    String s = fin.readLine().trim();
    System.out.println(fold(s));
  }
}
