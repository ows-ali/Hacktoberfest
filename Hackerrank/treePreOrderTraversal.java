public static void preOrder(Node root) {
        if(root==null){
            return; 
        }
        System.out.print(root.data + " "); 
        if(root.left!=null || root.right!= null ){
            preOrder(root.left); 
            preOrder(root.right); 
        }
    }
