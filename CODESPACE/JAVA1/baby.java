// Define a class Baby with the following attributes.
// a) Name
// b) Date of Birth
// c) Date on which Polio drops to be given(45 days from date of birth)
// Write a constructor to construct the baby object. The constructor must find out polio drops date from date of birth. In the main
// program define a baby and display its result.

import java.util.*;

class Baby {
    String name;
    Calendar dob;
    Calendar polio;

    Baby(String name, Calendar dob) {
        this.name = name;
        this.dob = dob;
        polio = (Calendar) dob.clone();
        polio.add(Calendar.DATE, 45);

    }

    public String toString() {
        return "Name: " + name + "\nDate of Birth: " + dob.getTime() + "\nPolio drops: " + polio.getTime();
    }
}

class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name: ");
        String name = sc.nextLine();
        System.out.println("Enter the year of birth: ");
        int year = sc.nextInt();
        System.out.println("Enter the month of birth: ");
        int month = sc.nextInt();
        System.out.println("Enter the day of birth: ");
        int day = sc.nextInt();
        Calendar dob = new GregorianCalendar(year, month - 1, day);

        Baby baby = new Baby(name, dob);
        System.out.println(baby);

    }
}