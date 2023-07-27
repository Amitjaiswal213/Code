public class Dog {
    String breed;
    String color;
    int age;

    public Dog(String dogBreed, String dogColor, int dogAge){
      System.out.println("Constructor invoked!");
        breed = dogBreed;
        color = dogColor;
        age = dogAge;
        
    }

    public static void main(String[] args){
        System.out.println("Main Method Started..");
      Dog g1 = new Dog("pet", "Red", 6);
      Dog g2 = new Dog("Wild", "Black", 8);

      boolean older = g1.age > g2.age;
      int  totalAge = g1.age + g2.age;

       
      System.out.println("Two Dog Created: a " + g1.breed  + " and a " + g2.breed+"."); 
      System.out.println("The statement that fido is an older dog is: " + older);
      System.out.println("The total age of the dogs is: " + totalAge);
      System.out.println("Main method finished!");
    }
}