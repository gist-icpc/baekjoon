import java.util.Scanner;

public class Main {
    private static long[] numOfZeros;
    private static long[] numOfOnes;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // Initialize array
        numOfOnes = new long[N+1];
        numOfZeros = new long[N+1];

        // First step
        numOfZeros[1] = 0;
        numOfOnes[1] = 1;

        for (int i=2; i<=N; i++) {
            numOfZeros[i] = numOfZeros[i-1] + numOfOnes[i-1];
            numOfOnes[i] = numOfZeros[i-1];
        }

        System.out.println(numOfOnes[N] + numOfZeros[N]);
    }
}
