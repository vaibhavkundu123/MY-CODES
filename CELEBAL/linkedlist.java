// class Node {
//     int data;
//     Node next;

//     public Node(int data) {
//         this.data = data;
//         this.next = null;
//     }
// }

// class LinkedList {
//     private Node head;

//     public LinkedList() {
//         head = null;
//     }

//     // Append a new node at the end
//     public void append(int data) {
//         Node newNode = new Node(data);

//         if (head == null) {
//             head = newNode;
//             return;
//         }

//         Node current = head;
//         while (current.next != null) {
//             current = current.next;
//         }

//         current.next = newNode;
//     }

//     // Print the entire list
//     public void printList() {
//         if (head == null) {
//             System.out.println("LinkedList is empty.");
//             return;
//         }

//         Node current = head;
//         while (current != null) {
//             System.out.print(current.data);
//             if (current.next != null)
//                 System.out.print(" → ");
//             current = current.next;
//         }
//         System.out.println();
//     }

//     // Delete the nth node (1-based index)
//     public void deleteNthNode(int n) throws Exception {
//         if (head == null) {
//             throw new Exception("Cannot delete from an empty list.");
//         }

//         if (n <= 0) {
//             throw new Exception("Invalid index " + n + ". Index must be >= 1.");
//         }

//         if (n == 1) {
//             head = head.next;
//             return;
//         }

//         Node prev = head;
//         int count = 1;

//         while (prev != null && count < n - 1) {
//             prev = prev.next;
//             count++;
//         }

//         if (prev == null || prev.next == null) {
//             throw new Exception("Index " + n + " is out of range.");
//         }

//         prev.next = prev.next.next;
//     }
// }

// public class LinkedListDemo {
//     public static void main(String[] args) {
//         LinkedList list = new LinkedList();

//         // Add nodes
//         list.append(10);
//         list.append(20);
//         list.append(30);
//         list.append(40);
//         list.append(50);

//         System.out.println("Initial list:");
//         list.printList(); // 10 → 20 → 30 → 40 → 50

//         // Delete 1st node
//         try {
//             list.deleteNthNode(1);
//             System.out.println("\nAfter deleting 1st node:");
//             list.printList(); // 20 → 30 → 40 → 50
//         } catch (Exception e) {
//             System.out.println("Error: " + e.getMessage());
//         }

//         // Delete 3rd node
//         try {
//             list.deleteNthNode(3);
//             System.out.println("\nAfter deleting 3rd node:");
//             list.printList(); // 20 → 30 → 50
//         } catch (Exception e) {
//             System.out.println("Error: " + e.getMessage());
//         }

//         // Delete last node
//         try {
//             list.deleteNthNode(3);
//             System.out.println("\nAfter deleting last node:");
//             list.printList(); // 20 → 30
//         } catch (Exception e) {
//             System.out.println("Error: " + e.getMessage());
//         }

//         // Out-of-range deletion
//         try {
//             list.deleteNthNode(5);
//         } catch (Exception e) {
//             System.out.println("\nError on deleteNthNode(5): " + e.getMessage());
//         }

//         // Delete remaining nodes
//         try {
//             list.deleteNthNode(1); // delete 20
//             list.deleteNthNode(1); // delete 30
//             System.out.println("\nAfter deleting all nodes:");
//             list.printList(); // LinkedList is empty
//         } catch (Exception e) {
//             System.out.println("Error: " + e.getMessage());
//         }

//         // Try deleting from empty list
//         try {
//             list.deleteNthNode(1);
//         } catch (Exception e) {
//             System.out.println("\nError on deleteNthNode(1) when empty: " + e.getMessage());
//         }
//     }
// }








class Node <T> {
	private T data;
	private Node <T> next;
	private Node <T> head = null; 
	Node(){}
	Node(T n){
		data=n;
		next=null;
	}
	void create (T n){    
	    Node <T> newNode = new Node<T>(n);     //Create a new node     
	    if(head == null) {    		           //Checks if the list is empty    
	        head = newNode;      
	    }    
	    else{    
	        System.out.println("List already created !!! ");
	    }    
	}
	void insert_end(T n) {
		
		Node<T> p;
		p=head;
		if(p==null)
	        System.out.println("List is Empty !!! ");
		if(p!=null)
		{
			Node <T> newNode = new Node<T> (n);    //Create a new node
			while(p.next!=null)
	            p=p.next;
			p.next=newNode;
		}
	}
	void insert_beg(T n) {
		Node <T> p;
		p=head;
		if(p==null)
			 System.out.println("List is Empty !!! ");
		
	    if(p!=null)
		{
	    	Node <T> newNode = new Node<T> (n); 
	    	newNode.next=p;
			head=newNode;
		}
	}
	void insert_any_pos(T n,int pos) {
		if(pos==1) {
			this.insert_beg(n);
			return;
		}
		else if(pos==this.count()+1) {
			this.insert_end(n);
			return;
		}
		else {
			Node <T> p;
			int x=1,f=0;
			p=head;
			Node <T> newNode = new Node<T> (n);
			if(p!=null){
				while(p.next!=null){	
					if(x==pos-1){
						f=1;
						break;
					}
					p=p.next;
					x++;
				}
				if(f==1){
					newNode.next=p.next;
					p.next=newNode;
				}
				else
					System.out.println("The position is not found ");
			}
			else
				System.out.println("List is Empty !!! ");
		}
	}
	
	void del_list()
	{
		head = null;
	}
	void del_end(){
		Node<T>  p;
		Node<T>  t;
		t=null;
		p=head;
	    if(p==null)
	    	System.out.println("\n List is Empty !!! ");
		
		if(p!=null)
		{
			while(p.next!=null)
			{
				t=p;
				p=p.next;
			}
			t.next=null;
		}
	}	
	void del_beg() {
		Node<T> p;
		p=head;	
	    if(p==null)
	    	System.out.print("\n List is Empty !!! ");
		if(p!=null)	
			head=p.next;
	}
	void del_any_pos(int pos) {
		if(pos==1) {
			this.del_beg();
			return;
		}
		else if(pos==this.count()) {
			this.del_end();
			return;
		}
		else {
			Node<T>  p,t;
			int f=0,x=1;
			p=head;
			if(p==null)
				System.out.print("\n List is Empty !!! ");
			if(p!=null)
			{
				while(p.next!=null){
					if(x==pos-1){
						f=1;
						break;
					}
					p=p.next;
					x++;
				}
				if(f==1){
					t=p;
					p=p.next;
					t.next=p.next;
				}
			}
		}
	}
	void display(){
		Node<T>  p;
		p=head;
		if(p==null)
			System.out.println("List is Empty !!! ");
		while(p!=null){
			System.out.print(p.data + "--");
			p=p.next;
		}
		System.out.println();
	}
	int count()
	{
		int c=0;
		Node<T>  p;
		p=head;
		while(p!=null){
			c++;
			p=p.next;
		}
		return c;
	}
}
	
public class Single_LinkedList {	
	public static void main(String[] args) {
		Node<Integer> x=new Node<Integer>();
		x.create(1);
		x.insert_end(2);
		x.insert_end(3);
		x.insert_end(4);
		x.insert_beg(0);
		x.insert_any_pos(5, 3);
		x.display();
		x.insert_any_pos(9, 6);
		x.display();
		
		x.del_end();
		x.del_end();
		x.del_beg();
		x.display();
		
		x.del_any_pos(2);
		x.display();
		
		x.del_list();
		x.display();
		
	}

}
