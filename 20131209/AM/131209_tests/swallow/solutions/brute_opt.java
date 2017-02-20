import java.io.*;
import java.util.*;

public class swallow {
  public final int MAX_SIZE = 500;

  public static String fold(String s) {
    if (s.length() == 1)
      return s;

    String ans = s;
    for (int i = 1; i < s.length(); ++i) {
      String p1 = s.substring(0, i);
      String p2 = s.substring(i);
      String p1a = fold(p1);
      String p2a = fold(p2);

      if (p1a.length() + p2a.length() < ans.length())
        ans = p1a + p2a;

      if (p2.length() % p1.length() == 0) {
        int idx = 0;
        boolean is_repeated = true;

        while (is_repeated && idx != p2.length()) {
          for (int j = 0; j < p1.length(); ++j) {
            if (p2.charAt(idx+j) != p1.charAt(j)) {
              is_repeated = false;
              break;
            }
          }
          idx += p1.length();
        }

        if (is_repeated) {
          String t = "" + (p2.length()/p1.length()+1);
          if (t.length() + p1a.length() + 2 < ans.length()) {
            ans = t + "(" + p1a + ")";
          }
        }
      }
    }

    return ans;
  }

  public static void main(String[] args) throws Exception {
    BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(fin.readLine());
    String s = fin.readLine().trim();
    System.out.println(fold(s));
  }
}
