/**********************************************************
 	Following is the Binary Tree Node class.

 	class BinaryTreeNode<T> {
 	    T data;
 	    BinaryTreeNode<T> left;
 	    BinaryTreeNode<T> right;

 	    public BinaryTreeNode(T data) {
 		this.data = data;
 	    }
 	}
 	
 ***********************************************************/

 public class Solution {
     public static BinaryTreeNode<Integer> lcaOfThreeNodes(BinaryTreeNode<Integer> root, 
                                                           int node1, int node2, int node3) {
         int n = lca(root, node1, node2).data;
         return lca(root, n, node3);
     }

     private static BinaryTreeNode<Integer> lca(BinaryTreeNode<Integer> root, int node1, int node2) {
         if (root == null) {
             return null;
         }

         if (root.data == node1 || root.data == node2) {
             return root;
         }

         BinaryTreeNode<Integer> left = lca(root.left, node1, node2);
         BinaryTreeNode<Integer> right = lca(root.right, node1, node2);

         if (left != null && right != null) {
             return root;
         }
         return left != null ? left : right;
     }
 }
