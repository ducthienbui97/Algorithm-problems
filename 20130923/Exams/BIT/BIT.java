/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author KhuongND
 */
public class BIT {

    private boolean debug = false;
    char matrix[][];
    int M, N;
    private Scanner reader;
    private PrintStream writer;
    private int counter = 0;
    private BigInteger result;

    public BIT(Scanner reader, PrintStream writer) {
        this.reader = reader;
        this.writer = writer;
    }

    public BIT(BIT bit) {
        M = bit.M;
        N = bit.N;
        matrix = new char[M][N];
        for (int i = 0; i < matrix.length; i++) {
            char[] cs = bit.matrix[i];
            System.arraycopy(cs, 0, matrix[i], 0, cs.length);
        }
    }

    void read() {
        M = reader.nextInt();
        N = reader.nextInt();
        matrix = new char[M][N];
        for (int i = 0; i < M; i++) {
            String s = reader.next();
            if (debug) {
                System.out.println("s == " + s);
            }
            BigInteger number = new BigInteger(s);
            String big = number.toString(2);
            while (big.length() < N) {
                big = "0" + big;
            }
            if (debug) {
                System.out.println("big == " + big);
            }
            for (int j = 0; j < N; j++) {
                matrix[i][j] = (char) (big.charAt(j) - '0');
            }
        }
    }
    private int cols[], rows[];

    void counting() {
        rows = new int[M];
        cols = new int[N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                rows[i] += matrix[i][j];
                cols[j] += matrix[i][j];
            }
        }
    }

    void solve(boolean first) {
        if (debug) {
            print();
        }
        counter = 0;
        if (first) {
            counter++;
            for (int i = 0; i < M; i++) {
                matrix[i][0] = (char) (1 - matrix[i][0]);
            }
        }
        if (debug) {
            System.out.println("solve");
        }
        if (debug) {
            print();
        }
        for (int i = 0; i < M; i++) {
            if (matrix[i][0] == 0) {
                counter++;
                for (int j = 0; j < N; j++) {
                    matrix[i][j] = (char) (1 - matrix[i][j]);
                }
            }
        }
        if (debug) {
            print();
        }
        counting();
        BigInteger pow2 = new BigInteger("1");
        result = new BigInteger("0");
        for (int j = N - 1; j >= 0; j--) {
            if (cols[j] < M - cols[j]) {
                counter++;
                cols[j] = M - cols[j];
                if (debug) {
                    System.out.println("col = " + j + " " + counter);
                }
            }
            BigInteger a = new BigInteger("" + cols[j]);
            if (debug) {
                System.out.println(j + " " + a + " " + pow2 + " " + pow2.multiply(a));
            }
            BigInteger plus = pow2.multiply(a);
            result = result.add(plus);
            pow2 = pow2.multiply(new BigInteger("2"));
        }
        if (debug) {
            System.out.println(counter + " " + result);
        }
    }

    int getNumber() {
        return counter;
    }

    BigInteger getValue() {
        return result;
    }

    boolean isBetter(BIT bit) {
        return (result.compareTo(bit.result) > 0) || (result.compareTo(bit.result) == 0 && counter < bit.counter);
    }

    void print() {
        if (debug) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(((int) matrix[i][j]) + " ");
                }
                System.out.println();
            }
        }
        if (debug) {
            System.out.println("-----End-----");
        }
    }

    public static void main(String args[]) {
        try {
            Scanner reader = new Scanner(System.in);
            PrintStream writer = System.out;
            BIT bit = new BIT(reader, writer);
            bit.read();
            BIT b2 = new BIT(bit);

            bit.solve(true);
            b2.solve(false);

            if (b2.isBetter(bit)) {
                bit = b2;
            }
            System.out.println(bit.getNumber());
            System.out.println(bit.getValue());
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
