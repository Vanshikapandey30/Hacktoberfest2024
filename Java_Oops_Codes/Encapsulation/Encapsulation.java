class Employee {
    private String name;
    private int age;
    
    // Constructor
    public Employee(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    // Getter for name
    public String getName() {
        return name;
    }
    
    // Setter for name
    public void setName(String name) {
        this.name = name;
    }
    
    // Getter for age
    public int getAge() {
        return age;
    }
    
    // Setter for age
    public void setAge(int age) {
        if(age > 0) {
            this.age = age;
        }
    }
    
    public void display() {
        System.out.println("Employee Name: " + name + ", Age: " + age);
    }
}

public class Encapsulation {
    public static void main(String[] args) {
        Employee emp = new Employee("Alice", 30);
        emp.display();
        emp.setAge(32);
        emp.display();
    }
}