package randomThings;

public class BINARY_TREE {

	Node root;
	BINARY_TREE left;
	BINARY_TREE right;
	
	public BINARY_TREE() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		BINARY_TREE b1 = new BINARY_TREE ();
		b1.insert(15);
		b1.insert(5);
		b1.insert(7);
		b1.insert(8);
		b1.insert(12);
		b1.insert(4);
		b1.insert(3);
		b1.insert(6);
		b1.insert(21);
		b1.insert(13);
		b1.insert(17);
		
		b1.trace();
		
	}
	
	public void insert (int number) {
		if (root == null) {
		// 	this.root = new Node(number);
			root = new Node(number);
			this.left = new BINARY_TREE();
			this.right = new BINARY_TREE();
		} else {
			if (number < root.getValue()) {
				left.insert(number);
			} else {
				right.insert(number);
			}
		}
	}
	
	public void trace () {
		if (right.root != null) {
			right.trace();
		}
		if (root != null) {
			System.out.print(root.getValue() + ", ");
		}
		if (left.root != null) {
			left.trace();
		}
	}

}
