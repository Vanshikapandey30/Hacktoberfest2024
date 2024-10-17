abstract class Vehicle {
    abstract void start();
    
    public void stop() {
        System.out.println("Vehicle stopped");
    }
}

class Car extends Vehicle {
    @Override
    void start() {
        System.out.println("Car started");
    }
}

class Bike extends Vehicle {
    @Override
    void start() {
        System.out.println("Bike started");
    }
}

public class Abstraction {
    public static void main(String[] args) {
        Vehicle car = new Car();
        car.start();
        car.stop();
        
        Vehicle bike = new Bike();
        bike.start();
        bike.stop();
    }
}