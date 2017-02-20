/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.math.BigInteger;
import java.util.Random;

/**
 *
 * @author KhuongND
 */
public class GenTest {

    static boolean  debug;

    public static void main(String args[]) {
        int M, N;
        if (args.length > 0) {
            M = Integer.parseInt(args[0]);
            N = Integer.parseInt(args[1]);
            debug = false;
        } else {
            M = 3;
            N = 16;
            debug = true;
        }
        System.out.println(M + " " + N);
        Random rand = new Random();
        for (int i = 0; i < M; i++) {
            String s = "";
            for (int j = 0; j < N; j++) {
                int bit = Math.abs(rand.nextInt()) % 2;
                s = s + bit;
            }
            if (debug) {
                System.out.println(s);
            }
            BigInteger big = new BigInteger(s, 2);
            System.out.print(big + " ");
            if (debug) {
                System.out.println(big.toString(2));
            }
        }
        System.out.println();
    }
}
