import java.util.*;
 
class Decoding {

/*  
	class Node
		public  int frequency; // the frequency of this tree
    	public  char data;
    	public  Node left, right;
    
*/ 

    void decode(String s, Node root) {
        Stack<Node> st = new Stack<>();
        st.add(root);

        String ans = "";

        int i = 0;
        while (i < s.length()) {
            while (i < s.length()) {
                Node top = st.peek();
                if (s.charAt(i) == '0' && top.left != null) {
                    st.add(top.left);
                } else if (s.charAt(i) == '1' && top.right != null) {
                    st.add(top.right);
                } else {
                    break;
                }
                i++;
            }
            ans += st.peek().data;
            while (!st.isEmpty() && st.peek() != root) {
                st.pop();
            }
        }

        System.out.print(ans);
    }

}
