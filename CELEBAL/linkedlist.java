class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    private Node head;

    public LinkedList() {
        head = null;
    }

    // Append a new node at the end
    public void append(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }

        current.next = newNode;
    }

    // Print the entire list
    public void printList() {
        if (head == null) {
            System.out.println("LinkedList is empty.");
            return;
        }

        Node current = head;
        while (current != null) {
            System.out.print(current.data);
            if (current.next != null)
                System.out.print(" → ");
            current = current.next;
        }
        System.out.println();
    }

    // Delete the nth node (1-based index)
    public void deleteNthNode(int n) throws Exception {
        if (head == null) {
            throw new Exception("Cannot delete from an empty list.");
        }

        if (n <= 0) {
            throw new Exception("Invalid index " + n + ". Index must be >= 1.");
        }

        if (n == 1) {
            head = head.next;
            return;
        }

        Node prev = head;
        int count = 1;

        while (prev != null && count < n - 1) {
            prev = prev.next;
            count++;
        }

        if (prev == null || prev.next == null) {
            throw new Exception("Index " + n + " is out of range.");
        }

        prev.next = prev.next.next;
    }
}

public class LinkedListDemo {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Add nodes
        list.append(10);
        list.append(20);
        list.append(30);
        list.append(40);
        list.append(50);

        System.out.println("Initial list:");
        list.printList(); // 10 → 20 → 30 → 40 → 50

        // Delete 1st node
        try {
            list.deleteNthNode(1);
            System.out.println("\nAfter deleting 1st node:");
            list.printList(); // 20 → 30 → 40 → 50
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Delete 3rd node
        try {
            list.deleteNthNode(3);
            System.out.println("\nAfter deleting 3rd node:");
            list.printList(); // 20 → 30 → 50
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Delete last node
        try {
            list.deleteNthNode(3);
            System.out.println("\nAfter deleting last node:");
            list.printList(); // 20 → 30
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Out-of-range deletion
        try {
            list.deleteNthNode(5);
        } catch (Exception e) {
            System.out.println("\nError on deleteNthNode(5): " + e.getMessage());
        }

        // Delete remaining nodes
        try {
            list.deleteNthNode(1); // delete 20
            list.deleteNthNode(1); // delete 30
            System.out.println("\nAfter deleting all nodes:");
            list.printList(); // LinkedList is empty
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Try deleting from empty list
        try {
            list.deleteNthNode(1);
        } catch (Exception e) {
            System.out.println("\nError on deleteNthNode(1) when empty: " + e.getMessage());
        }
    }
}
