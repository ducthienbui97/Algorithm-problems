import java.io.*;
import java.util.*;

public class subway {
  public static class graph {
    public int size;
    public Vector<Vector<Integer> > al;
    public graph() {
      al = new Vector<Vector<Integer>>();
    }
  }

  public static graph build_graph(String s) {
    graph result = new graph();
    result.size = s.length()/2 + 1;
    for(int i = 0; i < result.size; i++) result.al.add(new Vector<Integer>());

    Vector<Integer> cur_node = new Vector<Integer>();
    cur_node.add(0);
    int last_used = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (s.charAt(i) == '0') {
        cur_node.add(++last_used);
      } else {
        int parent = cur_node.get(cur_node.size() - 2);
        int cur = cur_node.get(cur_node.size() - 1);
        cur_node.remove(cur_node.size()-1);

        result.al.get(parent).add(cur);
        result.al.get(cur).add(parent);
      }
    }

    return result;
  }

  public static String repr(int node, graph g, int parent) {
    Vector<String> temp = new Vector<String>();

    for (int i = 0; i < g.al.get(node).size(); ++i) {
      if (g.al.get(node).get(i) == parent) continue;

      temp.add(repr(g.al.get(node).get(i), g, node));
    }

    String ans = "";
    Collections.sort(temp);

    for (int i = 0; i < temp.size(); ++i) {
      ans += "0";
      ans += temp.get(i);
      ans += "1";
    }

    return ans;
  }

  public static String canonical(graph g) {
    Vector<Integer> height = new Vector<Integer>(g.size);
    for(int i = 0; i < g.size; i++) height.add(-1);
    Queue<Integer> q = new LinkedList<Integer>();

    for (int i = 0; i < g.al.size(); ++i) {
      if (g.al.get(i).size() == 1) {
        q.offer(i);
        height.set(i, 0);
      }
    }

    while (!q.isEmpty()) {
      int x = q.poll();

      for (int j = 0; j < g.al.get(x).size(); ++j) {
        int y = g.al.get(x).get(j);
        if (height.get(y) < 0) {
          height.set(y, height.get(x) + 1);
          q.offer(y);
        }
      }
    }

    int max_height = -1;
    for(int x : height) max_height = Math.max(max_height, x);
    Vector<String> ans = new Vector<String>();

    for (int i = 0; i < g.size; ++i) {
      if (height.get(i) != max_height) continue;

      ans.add(repr(i, g, -1));
    }

    String ret = ans.get(0);
    for(String s : ans) ret = ret.compareTo(s) < 0 ? ret : s;
    return ret;
  }

  public static String canonical(String s) {
    Vector<Vector<String> > stack = new Vector<Vector<String>>();

    for (int i = 0; i < s.length(); ++i) {
      if (s.charAt(i) == '0') {
        stack.add(new Vector<String>());
      } else {
        Vector<String> children = stack.get(stack.size()-1);
        String sortedChildren = "";
        Collections.sort(children);
        for (int j = 0; j < stack.get(0).size(); ++j) {
          sortedChildren += "0";
          sortedChildren += children.get(i);
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

      unique.add(canonical(build_graph(s)));
    }

    System.out.println(unique.size());
  }
}
