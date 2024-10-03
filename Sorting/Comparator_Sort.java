// Problem Statement:
// You are given a list of Person objects. Each Person object contains two attributes:

// name: A string representing the name of the person.
// age: An integer representing the person's age.
// Your task is to sort the list of people in ascending order based on their age. If two people have the same age, they should retain their relative order in the input (i.e., the sort should be stable).
//
// Input:
// A list of Person objects, where each object contains:
// A String representing the person's name.
// An int representing the person's age.
//
// Output:
// A list of Person objects sorted by age in ascending order.
//
// Constraints:
// The number of people in the list will not exceed 10^4
// Each person’s age is a positive integer between 0 and 150.
//
// Function Signature:
// You need to implement the sorting logic in the main method. There is no function signature provided as this is part of the main program.

import java.util.*;

class Person {

    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return name + " (" + age + ")";
    }
}

public class Main {

    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 30));
        people.add(new Person("Bob", 25));
        people.add(new Person("Charlie", 35));

        // Sort by age
        Collections.sort(
            people,
            new Comparator<Person>() {
                public int compare(Person p1, Person p2) {
                    return Integer.compare(p1.age, p2.age);
                }
            }
        );

        System.out.println(people); // Output: [Bob (25), Alice (30), Charlie (35)]
    }
}
