import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;
import java.util.Queue;


public class G {

    public static class Code implements Comparable<Code> {

        private List<Integer> code;

        public Code() {
            code = new ArrayList<Integer>();
        }

        public void add(int x) {
            code.add(x);
        }

        public void add(Code other) {
            for (int x : other.code)
                add(x);
        }

        public int size() {
            return code.size();
        }

        @Override
        public int compareTo(Code other) {
            if (this.size() != other.size())
                return this.size() - other.size();
            for (int i = 0; i < size(); i++)
                if (code.get(i) != other.code.get(i))
                    return code.get(i) - other.code.get(i);
            return 0;
        }

        @Override
        public int hashCode() {
            int hash = 0;
            for (int i = 0; i < size(); i++)
                hash = hash * 31 + code.get(i);
            return hash;
        }

        public void print(PrintStream writer) {
            for (int x : code)
                writer.print(x + " ");
            writer.println();
        }
    }

    public static class Tree {

        private int N;
        private List<Integer> edges[];

        public Tree(int N) {
            this.N = N;
            this.edges = new List[N + 1];
            for (int i = 1; i <= N; i++)
                edges[i] = new ArrayList<Integer>();
        }

        public void add(int x, int y) {
            edges[x].add(y);
            edges[y].add(x);
        }

        private int trace[];

        private int spread(int x) {
            trace = new int[N + 1];
            Queue<Integer> queue = new LinkedList<Integer>();
            int last = x;
            trace[last] = last;
            queue.add(x);
            while (!queue.isEmpty()) {
                last = queue.remove();
                for (int y : edges[last])
                    if (trace[y] == 0) {
                        trace[y] = last;
                        queue.add(y);
                    }
            }
            return last;
        }

        private Code enCode(int x) {
            int degree = 0;
            List<Code> codes = new ArrayList<Code>();
            for (int y : edges[x])
                if (trace[y] == 0) {
                    trace[y] = x;
                    degree++;
                    codes.add(enCode(y));
                }
            Code code = new Code();
            code.add(degree);
            Collections.sort(codes);
            for (Code sub : codes)
                code.add(sub);
            return code;
        }

        private Code getCode(int x) {
            trace = new int[N + 1];
            trace[x] = x;
            return enCode(x);
        }

        public Code getCode() {
            int last = spread(1);
            last = spread(last);
            List<Integer> path = new ArrayList<Integer>();
            do {
                path.add(last);
                last = trace[last];
            } while (last != trace[last]);
            path.add(last);
            if (path.size() % 2 == 1) {
                return getCode(path.get(path.size() / 2));
            } else {
                Code x = getCode(path.get(path.size() / 2));
                Code y = getCode(path.get(path.size() / 2 - 1));
                if (x.compareTo(y) < 0)
                    return x;
                else
                    return y;
            }
        }

        public void read(Scanner reader) {
            for (int n = 1; n < N; n++) {
                int a = reader.nextInt();
                int b = reader.nextInt();
                add(a, b);
            }
        }
    }

    public static void main(String args[]) {
        try {
            System.out.println(System.currentTimeMillis());
            Scanner reader = new Scanner(new File("G.inp"));
            PrintStream writer = new PrintStream(new FileOutputStream("G.ans"));
            int T = reader.nextInt();
            for (int t = 0; t < T; t++) {
                Map<Integer, Set<Code>> map = new HashMap<Integer, Set<Code>>();
                int K = reader.nextInt();
                for (int k = 0; k < K; k++) {
                    Tree tree = new Tree(reader.nextInt());
                    tree.read(reader);
                    Code code = tree.getCode();
                    //code.write(System.out);
                    int hash = code.hashCode();
                    if (map.get(hash) == null)
                        map.put(hash, new TreeSet<Code>());
                    map.get(hash).add(code);
                }
                int result = 0;
                for (Set<Code> set : map.values())
                    result += set.size();
                writer.println(result);
            }
            reader.close();
            writer.flush();
            writer.close();
            System.out.println(System.currentTimeMillis());
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
