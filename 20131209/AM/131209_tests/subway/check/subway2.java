import java.util.*;
import java.io.*;

public class subway {
  public static String canonical(String s) {
    Vector<String> parts = new Vector<String>();
    int zeros = 0;
    int ones = 0;
    int current_start = 1;

    for (int i = 0; i < s.length(); ++i) {
      if (s.charAt(i) == '0') {
        zeros += 1;
      } else {
        ones += 1;
      }

      if (zeros == ones) {
        parts.add("0" + canonical(s.substring(current_start, i)) + "1");
        current_start = i + 2;
      }
    }

    String ans = "";
    Collections.sort(parts);

    for (int i = 0; i < parts.size(); ++i) {
      ans += parts.get(i);
    }

    return ans;
  }

  public static void main(String[] args) {
    Scanner fin = new Scanner(System.in);
    int n = fin.nextInt();

    Set<String> unique = new TreeSet<String>();

    for (int i = 0; i < n; ++i) {
      String s = fin.next();

      unique.add(canonical(s));
    }

    System.out.println(unique.size());
  }
}
