import javax.lang.model.util.ElementScanner14;

public class LeapYear{
    public static void main(String[] args){

        int year= 2024;

        if(year % 4 == 0)
        {
            if(year % 100 == 0)
            {
                if(year % 400 == 0)
                {
                    System.out.println("Leap Year");
                }
                else
                {
                    System.out.println("Not a Leap Year!");
                }
            }
            else
            {
                System.out.println("Leap Year!");
            }
        }
        else
        {
            System.out.println("Not a Leap Year!");
        }
    }
}
