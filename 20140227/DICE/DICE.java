import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

public class DICE {

    protected List<Status> allStatuses = new ArrayList<Status>();
    private Map<Integer, Integer> status2Turings = new HashMap<Integer, Integer>();
    private List<Dice> goes[][][][] = new List[3][3][3][5];
    private int cost[];
    private Dice dices[][][];
    private int result = 0;

    public DICE() {
    }

    public static void main(String args[]) {
        try {
            //long begin = System.currentTimeMillis();
            DICE DICE = new DICE();
            DICE.init();
            DICE.read();
            DICE.prepare();
            DICE.process();
            DICE.print();
            //System.out.println("time = " + (System.currentTimeMillis() - begin));
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    protected void prepare() {
        goes = new List[3][3][3][5];
        for (int i = 0; i < 27; i++) {
            Map<Dice, Integer> dice2cost = new HashMap<Dice, Integer>();
            int x = i / 9;
            int y = (i % 9) / 3;
            int z = (i % 9) % 3;
            for (int k = 0; k < allStatuses.size(); k++) {
                Dice dice = dices[x][y][z].goWith(allStatuses.get(k));
                dice2cost.put(dice, dice2cost.containsKey(dice) ?
                        Math.min(dice2cost.get(dice), cost[k]) : cost[k]);
            }
            for (int k = 0; k < 5; k++)
                goes[x][y][z][k] = new ArrayList<Dice>();
            for (Map.Entry<Dice, Integer> entry : dice2cost.entrySet()) {
                goes[x][y][z][entry.getValue()].add(entry.getKey());
                //System.out.println(first + " " + second + " " + z + " " + entry.getKey() + " " + entry.getValue());
            }
        }
    }

    protected void read() throws FileNotFoundException {
        //Scanner reader = new Scanner(new FileReader("DICE.INP"));
        Scanner reader = new Scanner(System.in);
        dices = new Dice[3][3][3];
        for (int i = 0; i < 27; i++) {
            String tokens[] = reader.nextLine().split(" ");
            int a[] = new int[tokens.length];
            for (int k = 0; k < a.length; k++)
                a[k] = Integer.parseInt(tokens[k]) - 1;
            dices[i / 9][(i % 9) / 3][(i % 9) % 3] = new Dice(a);
        }
        reader.close();
    }

    protected void print() throws FileNotFoundException {
        //PrintStream writer = new PrintStream(new File("DICE.OUT"));
        PrintStream writer = System.out;
        writer.println((result == Integer.MAX_VALUE ? -1 : result));
        writer.flush();
    }

    protected void process() {
        int F[][] = new int[4][1000000];
        Set<Integer> upFaces = null;
        for (int layer = 1; layer < 4; layer++) {
            upFaces = compute(layer, F[layer - 1], F[layer], dices[layer - 1], upFaces);
        }
        result = Integer.MAX_VALUE;
        for (Integer x : upFaces)
            result = Math.min(result, F[3][x]);
    }

    protected Set<Integer> compute(int layer, int[] f0, int[] f1, Dice[][] dice, Set<Integer> bottomFaces) {
        Set<Integer> upFaces = new HashSet<Integer>();
        Dice[][] tmpDices = new Dice[3][3];
        force(layer, 0, f0, f1, dice, tmpDices, bottomFaces, upFaces, 0);
        return upFaces;
    }

    protected void force(int layer, int k, int[] f0, int[] f1,
                         Dice[][] dice, Dice[][] tmpDices,
                         Set<Integer> bottomFaces, Set<Integer> upFaces, int current) {
        if (k == 9) {
            int b = 0;
            int f = 0;
            for (int x = 0; x < 3; x++)
                for (int y = 0; y < 3; y++) {
                    b = b * 3 + tmpDices[x][y].faces[1];
                    f = f * 3 + tmpDices[x][y].faces[0];
                }
            if (bottomFaces == null || bottomFaces.contains(b)) {
                if (current + f0[b] < f1[f] || !upFaces.contains(f)) {
                    f1[f] = current + f0[b];
                    upFaces.add(f);
                }
            }
            return;
        }
        int x = k / 3;
        int y = k % 3;
        for (int l = 0; l < 4; l++)
            for (int i = 0; i < goes[layer - 1][x][y][l].size(); i++) {
                tmpDices[x][y] = goes[layer - 1][x][y][l].get(i);
                if (x > 0 && tmpDices[x][y].faces[4] != tmpDices[x - 1][y].faces[5])
                    continue;
                if (y > 0 && tmpDices[x][y].faces[3] != tmpDices[x][y - 1].faces[2])
                    continue;
                force(layer, k + 1, f0, f1, dice, tmpDices, bottomFaces, upFaces, current + l);
            }
    }

    protected void init() {
        Queue<Status> queue = new LinkedList<Status>();
        Status start = new Status(new int[]{0, 1, 2, 3, 4, 5});
        status2Turings.put(start.hashCode(), 0);
        queue.add(start);
        allStatuses = new ArrayList<Status>();
        allStatuses.add(start);
        cost = new int[24];
        cost[0] = 0;
        while (!queue.isEmpty()) {
            start = queue.remove();
            List<Status> goes = start.goStatuses();
            for (Status go : goes)
                if (status2Turings.get(go.hashCode()) == null) {
                    status2Turings.put(go.hashCode(), 1);
                    queue.add(go);
                    allStatuses.add(go);
                    cost[allStatuses.size() - 1] = status2Turings.get(go.hashCode());
                }
        }
        /*for (int i = 0; i < allStatuses.size(); i++) {
            System.out.println(allStatuses.get(i).toString() + " " + cost[i]);
        }/**/
    }

    public static class Status {

        private static int rotate[][] = new int[][]{
                {4, 5, 2, 3, 1, 0}, {5, 4, 2, 3, 0, 1},
                {2, 3, 1, 0, 4, 5}, {3, 2, 0, 1, 4, 5}};
        public int faces[];

        public Status(int a[]) {
            faces = a;
        }

        @Override
        public int hashCode() {
            int code = 0;
            for (int i = 0; i < 6; i++)
                code = code * 6 + faces[i];
            return code;
        }

        @Override
        public boolean equals(Object obj) {
            if (!(obj instanceof Status)) return false;
            Status s = (Status) obj;
            for (int i = 0; i < 6; i++)
                if (faces[i] != s.faces[i])
                    return false;
            return true;
        }

        public List<Status> goStatuses() {
            List<Status> statuses = new ArrayList<Status>();
            for (int i = 0; i < rotate.length; i++) {
                int a[] = new int[6];
                for (int j = 0; j < 6; j++)
                    a[j] = faces[rotate[i][j]];
                statuses.add(new Status(a));
            }
            return statuses;
        }

        @Override
        public String toString() {
            StringBuffer result = new StringBuffer();
            for (int i = 0; i < faces.length; i++)
                if (result.length() == 0)
                    result.append(faces[i]);
                else
                    result.append(" " + faces[i]);
            return result.toString();
        }

        public void goByTurings(Dice dice, Status status) {
            for (int i = 0; i < 6; i++)
                faces[i] = dice.faces[status.faces[i]];
        }
    }

    public static class Dice extends Status {

        public Dice(int[] a) {
            super(a);
        }

        @Override
        public int hashCode() {
            int code = 0;
            for (int i = 0; i < 6; i++)
                code = code * 3 + faces[i];
            return code;
        }

        public Dice goWith(Status status) {
            Dice next = new Dice(new int[6]);
            next.goByTurings(this, status);
            return next;
        }
    }
}
