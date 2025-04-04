import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] digits = new int[20];
        int ind = 0;
        while (true) {
            if (n<2){
                digits[ind++] = n;
                break;
            }
            digits[ind++] = n%2;
            n/=2;
        }
        for (int i=ind-1;i>=0;i--){
            System.out.print(digits[i]);
        }
    }
}