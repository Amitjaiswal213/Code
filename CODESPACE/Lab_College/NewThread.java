import java.util.*;
public class NewThread extends Thread {
    NewThread(String s){
        super(s);
    }
    public void run(){
        for(int i=0; i<10; i++){
            System.out.println(getName());
            try{
                Thread.sleep(1000);
            }
            
            catch (Exception e){
                System.out.println(e);
            }
        }
    }
}

class Multidriver{
    public static void main(String[] args){
        NewThread t1=new NewThread("Ping");
        NewThread t2=new NewThread("Pong");
          t1.start();
          t2.start();
        System.out.println("End from"+Thread.currentThread());
    }
}