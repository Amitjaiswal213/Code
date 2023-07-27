public class inv_half_pyramid {
    public static void main(String[] args){

        int n=4;
        
        //for outer loop
        for(int i=n; i>=1; i--){
            //for inner loop
            for(int j=1; j<=i; j++){
                System.out.print("*");
            }
            System.out.println();

        }
    }
}

