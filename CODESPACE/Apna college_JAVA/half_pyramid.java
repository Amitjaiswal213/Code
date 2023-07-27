public class half_pyramid {
    public static void main(String[] args){

        int m=4;
        
        //for outer loop
        for(int i=1; i<=m; i++){
            //for inner loop
            for(int j=1; j<=i; j++){
                System.out.print("*");
            }
            System.out.println();

        }
    }
}
