import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

    static int[] stairs;
    static int[] Answer;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("input"));
        int N = sc.nextInt();

        stairs = new int[N+1];
        Answer = new int[N+1];

        for (int i=1; i<=N; i++) {
            stairs[i] = sc.nextInt();
        }

        if (N == 1) {
            System.out.println(stairs[1]);
        } else if (N == 2) {
            System.out.println(stairs[1] + stairs[2]);
        } else if (N ==3) {
            System.out.println(Answer[3] = Math.max(stairs[1] + stairs[3], stairs[2] + stairs[3]));
        } else {

            // For first step
            Answer[1] = stairs[1];
            Answer[2] = stairs[1] + stairs[2];
            Answer[3] = Math.max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

            for (int i = 4; i <= N; i++) {
                Answer[i] = Math.max(Answer[i - 3] + stairs[i - 1] + stairs[i], Answer[i - 2] + stairs[i]);
            }

            System.out.println(Answer[N]);
        }

    }
}

