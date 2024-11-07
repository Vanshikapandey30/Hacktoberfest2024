package school.management.system;

import java.util.ArrayList;
import java.util.List;


public class Main {
    public static void main(String[] args) {
        Teacher Sam = new Teacher(1,"Sam",500);
        Teacher Pam = new Teacher(2,"Pam",700);
        Teacher Harry = new Teacher(3,"Harry",600);

        List<Teacher> teacherList = new ArrayList<>();
        teacherList.add(Sam);
        teacherList.add(Pam);
        teacherList.add(Harry);


        Student tamasha = new Student(1,"Tamasha",4);
        Student rakshith = new Student(2,"Rakshith Vasudev",12);
        Student rabbi = new Student(3,"Rabbi",5);
        List<Student> studentList = new ArrayList<>();

        studentList.add(tamasha);
        studentList.add(rabbi);
        studentList.add(rakshith);




        School ghs = new School(teacherList,studentList);

        Teacher megan = new Teacher(6,"Megan", 900);

        ghs.addTeacher(megan);


        tamasha.payFees(5000);
        rakshith.payFees(6000);
        System.out.println("GHS has earned $"+ ghs.getTotalMoneyEarned());

        System.out.println("------Making SCHOOL PAY SALARY----");
        Sam.receiveSalary(Sam.getSalary());
        System.out.println("GHS has spent for salary to " + Sam.getName()
        +" and now has $" + ghs.getTotalMoneyEarned());

        Harry.receiveSalary(Harry.getSalary());
        System.out.println("GHS has spent for salary to " + Harry.getName()
                +" and now has $" + ghs.getTotalMoneyEarned());


        System.out.println(rakshith);

        Pam.receiveSalary(Pam.getSalary());

        System.out.println(Pam);


    }
}
