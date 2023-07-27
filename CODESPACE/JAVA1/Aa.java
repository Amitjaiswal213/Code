
//package JAVA;

class Aa {
     int a=10;
     static int b= 8;

     public static void main(String[] args){
        int c=1;
        Aa obj1 = new Aa();

        //System.out.println(a);                //error    static int a=10;
        System.out.println(b);
        System.out.println(obj1.a);
        System.out.println(c);
     }
    
}

