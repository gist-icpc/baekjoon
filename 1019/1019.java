import java.io.FileInputStream;
import java.util.Scanner;

class Main {

    private static int N;
    private static int[] Answer = new int[10];
    private static int digit=1;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("input.txt"));
        N = sc.nextInt();
        sc.close();

        int start = 1;
        int end = N;

        while(start <= end) {
            // 시작 값 끝자리 0으로 만들기
            while (start % 10 != 0 && start <= end) {
                countNum(start);
                start++;
            }

            if (start > end)
                break; // 계산 종료


            // 마지막 값 끝자리를 9로 만들기
            while (end % 10 != 9 && start <= end) {
                countNum(end);
                end--;
            }

            start /= 10;  // 10 -> 1
            end /= 10;  // 29 -> 2

            for(int i=0 ; i<10 ; i++)
                Answer[i] += (end-start+1) * digit;  // 일의 자리에 0~9가 총 2번씩 등장

            digit *= 10;  // 자리수 계산


        }

        StringBuilder builder = new StringBuilder();
        for(int i=0 ; i<10 ; i++)
            builder.append(Answer[i] + " ");

        System.out.println(builder.toString());

    }

    /*
    N에 있는 숫자들을 셉니다.
     */
    private static void countNum(int N) {
        while(N > 0){
            Answer[N%10] += digit;
            N /= 10;
        }
    }
}
