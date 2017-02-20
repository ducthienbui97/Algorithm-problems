import java.util.*;
import java.io.*;

public class subway {
  public static Vector<String> parts(String s) {
    Vector<String> ans = new Vector<String>();
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
        ans.add(s.substring(current_start, i));
        current_start = i + 2;
      }
    }

    return ans;
  }

  public static boolean compare(String x, String y) {
    Vector<String> a = parts(x);
    Vector<String> b = parts(y);

    if(a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); ++i) {
      boolean foundMatch = false;
      for (int j = 0; j < b.size(); ++j) {
        if (compare(a.get(i), b.get(j))) {
          b.remove(j);
          foundMatch = true;
          break;
        }
      }
      if (!foundMatch)
        return false;
    }

    return true;
  }

  public static void main(String[] args) throws IOException {
    Scanner fin = new Scanner(System.in);
    int n = fin.nextInt();

    Vector<String> unique = new Vector<String>();

    for (int i = 0; i < n; ++i) {
      String s = fin.next();

      boolean foundMatch = false;
      for (int j = 0; j < unique.size(); ++j) {
        if (compare(s, unique.get(j))) {
          foundMatch = true;
          break;
        }
      }

      if (!foundMatch) {
        unique.add(s);
      }
    }

    System.out.println(unique.size());
  }
}
