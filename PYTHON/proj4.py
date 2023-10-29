class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.head = None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def pop(self):
        if self.head is None:
            return None
        data = self.head.data
        self.head = self.head.next
        return data

    def is_empty(self):
        return self.head is None

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("NULL")

    def is_full(self):
        return False


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, data):
        new_node = Node(data)
        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def dequeue(self):
        if self.head is None:
            return None
        data = self.head.data
        self.head = self.head.next
        if self.head is None:
            self.tail = None
        return data

    def is_empty(self):
        return self.head is None

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("NULL")

    def is_full(self):
        return False


def main():
    stack = Stack()
    queue = Queue()

    while True:
        print("Menu:")
        print("1. Push element onto stack")
        print("2. Pop element from stack")
        print("3. Enqueue element onto queue")
        print("4. Dequeue element from queue")
        print("5. Display stack")
        print("6. Display queue")
        print("7. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            data = int(input("Enter the element to push: "))
            stack.push(data)
        elif choice == 2:
            data = stack.pop()
            if data is None:
                print("Stack is empty.")
            else:
                print("Popped element:", data)
        elif choice == 3:
            data = int(input("Enter the element to enqueue: "))
            queue.enqueue(data)
        elif choice == 4:
            data = queue.dequeue()
            if data is None:
                print("Queue is empty.")
            else:
                print("Dequeued element:", data)
        elif choice == 5:
            stack.display()
        elif choice == 6:
            queue.display()
        elif choice == 7:
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
