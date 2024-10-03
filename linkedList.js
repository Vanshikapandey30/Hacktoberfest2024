class Node {
    constructor(name, id, rollno, batch) {
        this.stu_name = name;
        this.stu_id = id;
        this.stu_rollno = rollno;
        this.stu_batch = batch;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    create(n) {
        if (n < 1) {
            console.log("No students to create.");
            return;
        }

        let name = prompt(`Enter the name of student 1:`);
        let id = parseInt(prompt(`Enter id of student 1:`));
        let rollno = parseInt(prompt(`Enter roll no of student 1:`));
        let batch = parseInt(prompt(`Enter batch of student 1:`));

        this.head = new Node(name, id, rollno, batch);
        let temp = this.head;

        for (let i = 2; i <= n; i++) {
            name = prompt(`Enter the name of student ${i}:`);
            id = parseInt(prompt(`Enter id of student ${i}:`));
            rollno = parseInt(prompt(`Enter roll no of student ${i}:`));
            batch = parseInt(prompt(`Enter batch of student ${i}:`));

            const newNode = new Node(name, id, rollno, batch);
            temp.next = newNode;
            temp = temp.next;
        }
    }

    deleteRecord(id) {
        if (!this.head) {
            console.log("List is empty.");
            return;
        }

        // If head needs to be deleted
        if (this.head.stu_id === id) {
            this.head = this.head.next;
            return;
        }

        let current = this.head;
        let previous = null;

        while (current && current.stu_id !== id) {
            previous = current;
            current = current.next;
        }

        if (current) {
            previous.next = current.next;
        } else {
            console.log("Student with ID not found.");
        }
    }

    printList() {
        let temp = this.head;
        if (!temp) {
            console.log("No records to display.");
            return;
        }

        while (temp) {
            console.log(`Name: ${temp.stu_name}, ID: ${temp.stu_id}, Roll No: ${temp.stu_rollno}, Batch: ${temp.stu_batch}`);
            temp = temp.next;
        }
    }
}

// Example usage
const studentList = new LinkedList();
const numStudents = parseInt(prompt("Enter the number of students:"));
studentList.create(numStudents);
studentList.printList();

const deleteId = parseInt(prompt("Enter student ID to delete:"));
studentList.deleteRecord(deleteId);
console.log("Updated List:");
studentList.printList();
