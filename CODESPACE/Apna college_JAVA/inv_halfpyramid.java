//package Apna college_JAVA;

public class inv_halfpyramid {
    public static void main(String[] args){ 
        int n=4;
 
        // for outer loop
        for(int i=1; i<=n; i++){

            // for inner loop
            for(int j=1; j<=n-i; j++){
                System.out.print(" ");
            } 
            for(int j=1; j<=i; j++){  
            System.out.print("*");
            }
            System.out.println();
        }
    }
}
