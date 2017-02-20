import java.io.*;
import java.util.*;

public class subway {
  public static String canonical(String s) {
    Vector<Vector<String>> stack = new Vector<Vector<String>>();
    stack.add(new Vector<String>());

    for (int i = 0; i < s.length(); ++i) {
      if (s.charAt(i) == '0') {
        stack.add(new Vector<String>());
      } else {
        Vector<String> children = stack.get(stack.size()-1);
        String sortedChildren = "";
        Collections.sort(children);
        for (int j = 0; j < children.size(); ++j) {
          sortedChildren += "0";
          sortedChildren += children.get(j);
          sortedChildren += "1";
        }

        stack.remove(stack.size()-1);
        stack.get(stack.size()-1).add(sortedChildren);
      }
    }

    String ans = "";
    Collections.sort(stack.get(0));

    for (int i = 0; i < stack.get(0).size(); ++i) {
      ans += "0";
      ans += stack.get(0).get(i);
      ans += "1";
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
