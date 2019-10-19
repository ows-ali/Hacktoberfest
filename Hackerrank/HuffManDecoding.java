import java.util.*;
 
abstract class Node implements Comparable<Node> {
    
  	public  int frequency; // the frequency of this tree
    public  char data;
    public  Node left, right; 
    public Node(int freq) { 
    	frequency = freq;
   	}
 
    // compares on the frequency
    public int compareTo(Node tree) {
        return frequency - tree.frequency;
    }
  
}
 
class HuffmanLeaf extends Node {
    
    public HuffmanLeaf(int freq, char val) {
        super(freq);
        data = val;
    }
  
}
 
class HuffmanNode extends Node {
    
    public HuffmanNode(Node l, Node r) {
        super(l.frequency + r.frequency);
        left = l;
        right = r;
    }

}


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

 
public class Solution {
    
  	// input is an array of frequencies, indexed by character code
    
  	public static Node buildTree(int[] charFreqs) {
      
        PriorityQueue<Node> trees = new PriorityQueue<Node>();
        // initially, we have a forest of leaves
        // one for each non-empty character
        for (int i = 0; i < charFreqs.length; i++)
            if (charFreqs[i] > 0)
                trees.offer(new HuffmanLeaf(charFreqs[i], (char)i));
 
        assert trees.size() > 0;
        // loop until there is only one tree left
        while (trees.size() > 1) {
            // two trees with least frequency
            Node a = trees.poll();
            Node b = trees.poll();
 
            // put into new node and re-insert into queue
            trees.offer(new HuffmanNode(a, b));
        }
        return trees.poll();
    }
  
    public static Map<Character,String> mapA=new HashMap<Character ,String>();
  
    public static void printCodes(Node tree, StringBuffer prefix) {
        assert tree != null;
      
        if (tree instanceof HuffmanLeaf) {
            HuffmanLeaf leaf = (HuffmanLeaf)tree;
 
            // print out character, frequency, and code for this leaf (which is just the prefix)
            //System.out.println(leaf.data + "\t" + leaf.frequency + "\t" + prefix);
            mapA.put(leaf.data,prefix.toString());

        } else if (tree instanceof HuffmanNode) {
            HuffmanNode node = (HuffmanNode)tree;
 
            // traverse left
            prefix.append('0');
            printCodes(node.left, prefix);
            prefix.deleteCharAt(prefix.length()-1);
 
            // traverse right
            prefix.append('1');
            printCodes(node.right, prefix);
            prefix.deleteCharAt(prefix.length()-1);
        }
    }
 
    public static void main(String[] args) {
      
        Scanner input = new Scanner(System.in);
    
        String test= input.next();
 
        // we will assume that all our characters will have
        // code less than 256, for simplicity
        int[] charFreqs = new int[256];
      
        // read each character and record the frequencies
        for (char c : test.toCharArray())
            charFreqs[c]++;
 
        // build tree
        Node tree = buildTree(charFreqs);
 
        // print out results
        printCodes(tree, new StringBuffer());
        StringBuffer s = new StringBuffer();
       
        for(int i = 0; i < test.length(); i++) {
          
          char c = test.charAt(i);
          s.append(mapA.get(c));
          
        }
      
        //System.out.println(s);
        Decoding d = new Decoding();
        d.decode(s.toString(),tree);

    }
}
