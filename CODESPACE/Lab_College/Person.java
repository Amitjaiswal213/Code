import java.util.Scanner;

class Person {
    public String name;
    public int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    void display() {
        System.out.println("Name:" + name);
        System.out.println("age:" + age);
    }
}

class Student extends Person {
    int roll_no;
    String branch;

    Student(int roll_no, String branch, int age, String name) {
        super(name, age);
        this.roll_no = roll_no;
        this.branch = branch;

    }
    void display() {
        System.out.println("Name:" + name);
        System.out.println("Age:" + age);
        System.out.println("Roll:" + roll_no);
        System.out.println("Branch:" + branch);

    }
}

class Employee extends Person {
    int ecNo;
    String doj;

    Employee(int ecNo, String doj, String name, int age) {
        super(name, age);
        this.ecNo = ecNo;
        this.doj = doj;
    }
    void display() {
        System.out.println("Name:" + name);
        System.out.println("Age:" + age);
        System.out.println("EcNo:" + ecNo);
        System.out.println("DoJ:" + doj);
    }
}

class Staff extends Employee {
    String des_data;
    Staff(String des_data, int ecNo, String doj, String name, int age) {
        super(ecNo, doj, name, age);
        this.des_data = des_data;

    }
    void display() {
        System.out.println("Name:" + name);
        System.out.println("Age:" + age);
        System.out.println("EcNo:" + ecNo);
        System.out.println("DoJ:" + doj);
        System.out.println("Des Data:" + des_data);
    }
}

class Faculty extends Employee {
    String des_data;

    Faculty(String des_data, int ecNo, String doj, String name, int age) {
        super(ecNo, doj, name, age);
        this.des_data = des_data;
    }
    void display() {
        System.out.println("Name:" + name);
        System.out.println("Age:" + age);
        System.out.println("EcNo:" + ecNo);
        System.out.println("DoJ:" + doj);
        System.out.println("Des Data:" + des_data);
    }
}

class MainDemoClass {
    public static void main(String a[]) {
        Scanner sc = new Scanner(System.in);
        String name, branch, doj, des_data1, des_data2;
        int age, roll_no, ecNo, ch;
        System.out.println("Enter the name of person:");
        name = sc.next();
        System.out.println("Enter the age of person:");
        age = sc.nextInt();
        Person p1 = new Person(name, age);
        p1.display();

        System.out.println("Press 1 if person is student and 2 if person is employee:");
        ch = sc.nextInt();
        if (ch == 1) {
            System.out.println("Enter the details of Student:");
            System.out.println("Enter the roll no:");
            roll_no = sc.nextInt();
            System.out.println("Enter the branch:");
            branch = sc.next();
            Student s1 = new Student(roll_no, branch, age, name);
            s1.display();
        }
        else {
            System.out.println("Enter the details of Employee:");
            System.out.println("Enter the ec Number:");
            ecNo = sc.nextInt();
            System.out.println("Enter the date of joining:");
            doj = sc.next();
            Employee e1 = new Employee(ecNo, doj, name, age);
            e1.display();

            System.out.println("Press 1 if employee is Staff and 2 if employee is Faculty:");
            ch = sc.nextInt();
            if (ch == 1) {
                System.out.println("Enter the details of Staff:");
                System.out.println("Enter the designation data:");
                des_data1 = sc.next();
                Staff s2 = new Staff(des_data1, ecNo, doj, name, age);
                s2.display();
            } else {
                System.out.println("Enter the details of Faculty:");
                System.out.println("Enter the designation data:");
                des_data2 = sc.next();
                Faculty f1 = new Faculty(des_data2, ecNo, doj, name, age);
                f1.display();
            }
        }
    }
}