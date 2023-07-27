import java.util.*;
public class ifelse_switch{
    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);

        System.out.print("Enter button: ");
        int button= sc.nextInt();
       

        /*if(button==1)
        {
            System.out.println("Hello");
        }
        else if(button==2)
        {
            System.out.println("Namaste");
        }
        else if(button==3)
        {
            System.out.println("Banjour");
        }
        else
        {
            System.out.println("Invalid Button!");
        }           
    } 
} */

switch(button){
            case 1 : System.out.println("Namaste!");
             break;
            case 2 : System.out.println("Hello!");
            break;
            case 3 : System.out.println("Banjaur!");
             break;
            default: System.out.println("Invalid Button!");
        }
    }
}

