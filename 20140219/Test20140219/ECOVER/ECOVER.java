import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ECOVER {

    private int N;
    private int M;
    private List<Point> points;
    private List<Integer> edges[];
    private int result;
    private int F[][];
    private int visited[];
    private int going[];
    private int trace[];
    private boolean DEBUG = false;

    public static void main(String args[]) {
        try {
            ECOVER ecover = new ECOVER();
            ecover.read();
            ecover.process();
            ecover.print();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void print() throws FileNotFoundException {
        PrintStream writer = new PrintStream(new File("ECOVER.OUT"));
        result = 0;
        for (int x = 0; x < N; x++)
            for (int i = 0; i < edges[x].size(); i++)
                result = Math.max(result, F[x][i]);
        writer.println(result);
        writer.flush();
        writer.close();
    }

    private void process() {
        F = new int[N][];
        visited = new int[N];
        going = new int[N];
        trace = new int[N];
        for (int i = 0; i < N; i++) {
            trace[i] = -1;
            visited[i] = -1;
        }
        force(0);
    }

    private void force(int x) {
        if (DEBUG)
            System.out.println("visit: " + x);
        F[x] = new int[edges[x].size()];
        for (int i = visited[x] + 1; i < edges[x].size(); i++) {
            F[x][i] = 1;
            int y = edges[x].get(i);
            visited[x] = i;
            going[x] = y;
            if (trace[y] != -1) {
                Pair pair = backEdges(y);
                forwardEdges(pair.first, y, pair.second);
            }
            trace[y] = x;
            if (visited[y] == -1)
                force(y);
        }
    }

    private void forwardEdges(int x, int t, int maxf) {
        while (x != t) {
            int y = going[x];
            if (DEBUG) System.out.println(x + " => " + y + " " + (maxf + 1));
            trace[y] = x;
            F[x][visited[x]] = maxf + 1;
            x = y;
        }
        if (DEBUG) System.out.println();
    }

    private Pair backEdges(int y) {
        int x, s, max = Integer.MIN_VALUE;
        while (true) {
            x = trace[y];
            if (going[x] != y) {
                s = x;
                max = Math.max(max, F[x][visited[x] - 1]);
                break;
            } else {
                max = Math.max(max, F[x][visited[x]]);
            }
            y = x;
        }
        return new Pair(s, max);
    }

    private void read() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("ECOVER.INP"));
        String tokens[] = reader.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        points = new ArrayList<Point>(10);
        edges = new List[N];
        int x, y;
        for (int i = 0; i < N; i++) {
            edges[i] = new ArrayList<Integer>();
            tokens = reader.readLine().split(" ");
            x = Integer.parseInt(tokens[0]);
            y = Integer.parseInt(tokens[1]);
            points.add(new Point(x, y));
        }
        for (int i = 0; i < M; i++) {
            tokens = reader.readLine().split(" ");
            x = Integer.parseInt(tokens[0]) - 1;
            y = Integer.parseInt(tokens[1]) - 1;
            edges[x].add(y);
        }
        if (DEBUG) for (int i = 0; i < N; i++) {
            System.out.print((i + 1) + " => ");
            for (int j = 0; j < edges[i].size(); j++)
                System.out.print(" " + (edges[i].get(j) + 1));
            System.out.println();
        }
        for (int i = 0; i < N; i++)
            Collections.sort(edges[i], new Comp(points.get(i).x, points.get(i).y, points));
        reader.close();
    }

    private static class Comp implements Comparator<Integer> {

        int x, y;
        List<Point> points;

        public Comp(int x, int y, List<Point> points) {
            this.x = x;
            this.y = y;
            this.points = points;
        }

        private int comp(Point p1, Point p2) {
            return Double.compare((p1.y - y) * (0.0 + p2.x - x), (p2.y - y) * (0.0 + p1.x - x));
            //return p1.y - p2.y;
        }

        @Override
        public int compare(Integer x, Integer y) {
            return comp(points.get(x), points.get(y));
        }
    }

    private static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    protected static class Point {

        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }
}
