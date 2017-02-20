/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Random;

/**
 *
 * @author KhuongND
 */
public class Gen {
    public static void main(String args[]){
        int N = Integer.parseInt(args[0]);
        int D = Integer.parseInt(args[1]);
        System.out.println(N);
        Random rand = new Random();
        for (int i=0; i<N; i++)
            System.out.print(rand.nextInt(D) + " ");
        System.out.println();
    }
}
