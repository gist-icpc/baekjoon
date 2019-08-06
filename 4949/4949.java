import java.util.Stack;
import java.util.Scanner;
import java.util.ArrayList;

public class peacefulWorld {
    public static void main(String[] args) {
        Stack<Character> stack = new Stack<>();
        ArrayList<String> ans = new ArrayList<>();
        Scanner scan = new Scanner(System.in);
        String checker;
        int i;
        while(true) {
            checker = scan.nextLine();
            stack.clear();

            if(checker.equals("."))
                break;

            try {
                for (i = 0; i < checker.length(); i++) {
                    if (checker.charAt(i) == '(' || checker.charAt(i) == '[') {
                        stack.push(checker.charAt(i));
                    } else if (checker.charAt(i) == ')') {
                        if (stack.pop() != '(') {
                            throw new Exception();
                        }
                    } else if (checker.charAt(i) == ']') {
                        if (stack.pop() != '[') {
                            throw new Exception();
                        }
                    }
                }

                if(stack.isEmpty())
                    ans.add("yes");
                else
                    ans.add("no");
            } catch (Exception e) {
                ans.add("no");
            }
        }

        for(i = 0; i < ans.size(); i++) {
            System.out.println(ans.get(i));
        }
    }
}
