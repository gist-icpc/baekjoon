import java.io.FileInputStream;
import java.util.Scanner;



public class Main {
    private static int[] Answer = new int[3];   // Answer[0]은 -1, Answer[1]은 1, Answer[2]는 2로만 이루어진 행렬 수
    private static int[][] matrix;



    public static void main(String args[]) throws Exception	{

       Scanner sc = new Scanner(System.in);
        // Scanner sc = new Scanner(new FileInputStream("input.txt"));

        int N = sc.nextInt();
        matrix = new int[N][N];

        // Initialize matrix
        for (int row=0; row<N; row++){
            for (int col=0; col<N; col++){
                matrix[row][col] = sc.nextInt();
            }
        }


        divide(0,0,N);
        // Print the answer to standard output(screen).

        for (int i=0; i<3; i++) {
            System.out.println(Answer[i]);
        }
        sc.close();
    }

    /*
    확인하고자 하는 행렬 왼쪽 위 시작 위치와 크기를 받는다.
    시작 행렬은 divide(0,0,N)
    Base case는 행렬이 모두 같은 수로 이루어져 있을 경우
     */
    private static void divide(int startRow, int startCol, int size) {
        // 모두 같은 수일 경우 종료
        if (check(startRow, startCol, size))
            return;

        // 아닐 경우 9등분 하여 다시 함수 실행

        size = size/3;

        // 이부분에서 실수 엄청했음...
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                divide(startRow+i*size, startCol+j*size, size);
            }
        }

    }

    /*
    확인하고자 하는 행렬 왼쪽 위 시작 위치와 크기를 받는다.
    이후 행렬이 모두 같은 값일 경우 answer의 값을 증가시킨다.
     */
    private static boolean check(int startRow, int startCol, int size){
        int temp = matrix[startRow][startCol];
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (temp != matrix[startRow+i][startCol+j]) {
                    return false;
                }
            }
        }

        switch (temp) {
            case -1:
                Answer[0]++;
                break;
            case 0:
                Answer[1]++;
                break;
            case 1:
                Answer[2]++;
                break;
        }

        return true;
    }


}