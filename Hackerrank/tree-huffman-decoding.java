/*  
   class Node
      public  int frequency; // the frequency of this tree
       public  char data;
       public  Node left, right;
    
*/ 
static Node move(Node root,char value){
    if(value == '1')
        return root.right;
    return root.left;
}

void decode(String S ,Node root)
    {
        
        char Str[] = new char[100];
        int j = 0,i=0;
        Node CN = root;
        while(j<S.length())
        {
            //Node CN = root;
            CN = move(CN,S.charAt(j));
            j++;
            if (CN.data != '\0'){
                Str[i++] = CN.data;
                CN = root;
            }
            //System.out.println(i + " " + j);
            
                
         }    
         for(int k=0;k<i;k++)
             System.out.print(Str[k]);
       
    }
