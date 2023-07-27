// Write a program which will print whether the elements of a given array are Prime or not.

import java.util.Scanner;

class Prime {
    int n;
    int[] arr;

    Prime(int n) {
        this.n = n;
        arr = new int[n];
    }

    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    void checkPrime() {
        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = 2; j <= Math.sqrt(arr[i]); j++) {
                if (arr[i] % j == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                System.out.println(arr[i] + " is a prime number");
            } else {
                System.out.println(arr[i] + " is not a prime number");
            }
        }
    }
}

class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements: ");
        int n = sc.nextInt();
        Prime p = new Prime(n);
        p.input();
        p.checkPrime();
    }
}
