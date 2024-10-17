class Animal {
    public void sound() {
        System.out.println("This animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    public void sound() {
        System.out.println("The dog barks");
    }
}

public class Inheritance {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.sound();  // Calls the sound method from Dog class
    }
}