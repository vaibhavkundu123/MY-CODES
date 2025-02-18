class Stack<T> {
    T[] stack;
    int top;
    int capacity;

    Stack(int capacity) {
        this.capacity = capacity;
        stack = (T[]) new Object[capacity];
        top = -1;
    }

    void push(T element) {
        if (isFull()) {
            throw new RuntimeException("Stack is full");
        }
        stack[++top] = element;
    }

    T pop() {
        if (top == -1) {
            throw new RuntimeException("Stack is empty");
        }
        return stack[top--];
    }

    T peek() {
        if (top == -1) {
            throw new RuntimeException("Stack is empty");
        }
        return stack[top];
    }

    boolean isEmpty() {
        return top == -1;
    }

    boolean isFull() {
        return top == capacity - 1;
    }
}

class Test {
    public static void main(String[] args) {
        Stack<Integer> intStack = new Stack<>(3);
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        System.out.println("Is stack Full (Integer)? " + intStack.isFull());
        System.out.println("Top element (Integer): " + intStack.peek());
        System.out.println("Popped element (Integer): " + intStack.pop());
        System.out.println("Popped element (Integer): " + intStack.pop());
        System.out.println("Is stack empty (Integer)? " + intStack.isEmpty());
        System.out.println("Popped element (Integer): " + intStack.pop());
        System.out.println("Is stack empty (Integer)? " + intStack.isEmpty());
        System.out.println("Is stack Full (Integer)? " + intStack.isFull());

        Stack<String> stringStack = new Stack<>(3);
        stringStack.push("Hello");
        stringStack.push("World");
        stringStack.push("!");

        System.out.println();
        System.out.println("Is stack Full (String)? " + stringStack.isFull());
        System.out.println("Top element (String): " + stringStack.peek());
        System.out.println("Popped element (String): " + stringStack.pop());
        System.out.println("Popped element (String): " + stringStack.pop());
        System.out.println("Is stack empty (String)? " + stringStack.isEmpty());
        System.out.println("Popped element (String): " + stringStack.pop());
        System.out.println("Is stack empty (String)? " + stringStack.isEmpty());
        System.out.println("Is stack Full (String)? " + stringStack.isFull());
    }
}