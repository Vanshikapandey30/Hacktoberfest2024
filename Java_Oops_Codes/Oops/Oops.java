// Abstract class representing a Product (Abstraction)
abstract class Product {
    private String name;
    private double price;

    // Constructor with encapsulation
    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    // Getter and Setter for name (Encapsulation)
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    // Getter and Setter for price (Encapsulation)
    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        if (price >= 0) {
            this.price = price;
        }
    }

    // Abstract method to calculate discount (Abstraction)
    public abstract double calculateDiscount();

    // Concrete method to display product details
    public void displayInfo() {
        System.out.println("Product: " + name + ", Price: $" + price);
    }
}

// Electronics class inheriting from Product (Inheritance)
class Electronics extends Product {
    private int warranty; // warranty in months

    // Constructor using super for inheritance
    public Electronics(String name, double price, int warranty) {
        super(name, price);
        this.warranty = warranty;
    }

    // Overriding the abstract method (Polymorphism)
    @Override
    public double calculateDiscount() {
        // 10% discount for electronics
        return getPrice() * 0.10;
    }

    public void displayWarranty() {
        System.out.println("Warranty: " + warranty + " months");
    }
}

// Clothing class inheriting from Product (Inheritance)
class Clothing extends Product {
    private String size;

    // Constructor using super for inheritance
    public Clothing(String name, double price, String size) {
        super(name, price);
        this.size = size;
    }

    // Overriding the abstract method (Polymorphism)
    @Override
    public double calculateDiscount() {
        // 15% discount for clothing
        return getPrice() * 0.15;
    }

    public void displaySize() {
        System.out.println("Size: " + size);
    }
}

// Main class to demonstrate OOP concepts
public class Oops {
    public static void main(String[] args) {
        // Creating an array of Product
        Product[] products = new Product[2];
        
        // Adding Electronics product
        products[0] = new Electronics("Laptop", 1000.00, 24);
        
        // Adding Clothing product
        products[1] = new Clothing("T-Shirt", 30.00, "M");
        
        // Displaying product info and calculating discounts
        for (Product product : products) {
            product.displayInfo();  // Display product info
            System.out.println("Discount: $" + product.calculateDiscount()); // Calculate and display discount
            
            // Call specific methods based on product type
            if (product instanceof Electronics) {
                ((Electronics) product).displayWarranty();
            } else if (product instanceof Clothing) {
                ((Clothing) product).displaySize();
            }
            
            System.out.println(); // Just for better readability in output
        }
    }
}