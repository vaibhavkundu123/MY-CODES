class Node:
    """
    A Node in a singly linked list.
    Holds 'data' and a reference to the 'next' node.
    """
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    """
    A singly linked list implementation.
    Supports:
      - append(data): add a new node with 'data' at the end
      - print_list(): print all node values in sequence
      - delete_nth_node(n): delete the node at 1-based index n
    """
    def __init__(self):
        self.head = None

    def append(self, data):
        """
        Append a new node with the given data to the end of the list.
        """
        new_node = Node(data)
        if not self.head:
            # Empty list → new_node becomes head
            self.head = new_node
            return

        # Traverse to the end
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def print_list(self):
        """
        Traverse the list and print each node's data.
        """
        if not self.head:
            print("LinkedList is empty.")
            return

        current = self.head
        nodes = []
        while current:
            nodes.append(str(current.data))
            current = current.next
        print(" → ".join(nodes))

    def delete_nth_node(self, n):
        """
        Delete the node at 1-based index n.
        Raises:
          - IndexError if the list is empty or n is out of valid range.
        """
        # Edge case: deleting from an empty list
        if not self.head:
            raise IndexError("Cannot delete from an empty list.")

        # Edge case: non‐positive index
        if n <= 0:
            raise IndexError(f"Invalid index {n}. Index must be >= 1.")

        # If deleting the head (n == 1)
        if n == 1:
            to_delete = self.head
            self.head = self.head.next
            to_delete.next = None  # Help the garbage collector
            return

        # Traverse to the (n-1)-th node, so we can skip its 'next'
        prev = self.head
        current_index = 1
        while prev and current_index < n - 1:
            prev = prev.next
            current_index += 1

        # If prev is None or prev.next is None, n is out of range
        if prev is None or prev.next is None:
            raise IndexError(f"Index {n} is out of range.")

        # Delete the n-th node
        to_delete = prev.next
        prev.next = to_delete.next
        to_delete.next = None  # Help the garbage collector


if __name__ == "__main__":
    # ----------------------------
    # Example usage / Test cases
    # ----------------------------

    ll = LinkedList()

    # 1) Append some items
    for value in [10, 20, 30, 40, 50]:
        ll.append(value)

    print("Initial list:")
    ll.print_list()          # Expected: 10 → 20 → 30 → 40 → 50

    # 2) Delete the 1st node (head)
    try:
        ll.delete_nth_node(1)
        print("\nAfter deleting 1st node:")
        ll.print_list()      # Expected: 20 → 30 → 40 → 50
    except IndexError as e:
        print(f"Error: {e}")

    # 3) Delete the 3rd node (which is currently '40')
    try:
        ll.delete_nth_node(3)
        print("\nAfter deleting 3rd node:")
        ll.print_list()      # Expected: 20 → 30 → 50
    except IndexError as e:
        print(f"Error: {e}")

    # 4) Delete the last node (now index = length = 3)
    try:
        ll.delete_nth_node(3)
        print("\nAfter deleting last node:")
        ll.print_list()      # Expected: 20 → 30
    except IndexError as e:
        print(f"Error: {e}")

    # 5) Attempt to delete with an out-of-range index (e.g., 5)
    try:
        ll.delete_nth_node(5)
    except IndexError as e:
        print(f"\nError on delete_nth_node(5): {e}")

    # 6) Delete remaining nodes one by one
    try:
        ll.delete_nth_node(1)   # deletes 20
        ll.delete_nth_node(1)   # deletes 30, now list is empty
        print("\nAfter deleting all nodes:")
        ll.print_list()         # Expected: "LinkedList is empty."
    except IndexError as e:
        print(f"Error: {e}")

    # 7) Attempt to delete from an empty list
    try:
        ll.delete_nth_node(1)
    except IndexError as e:
        print(f"\nError on delete_nth_node(1) when empty: {e}")
