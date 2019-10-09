//You can visit the hackerrank site by typing the URL below
// https://www.hackerrank.com/challenges/java-stack/problem
import java.util.*;

class JAVA_STACK{
    static class stack  
    { 
        int top=-1; 
        char items[]=new char[100]; 

        //push element in stack
        void push(char x)  
        { 
            if(top==99)  
            { 
                System.out.println("Stack full"); 
            }  
            else 
            { 
                items[++top]=x; 
            } 
        }

        //pop element from stack
        char pop()  
        {
            if(top==-1)  
            { 
                System.out.println("Underflow error"); 
                return '\0'; 
            }
            else 
            { 
                char element=items[top]; 
                top--; 
                return element; 
            }
        }

        //check is stack is empty or not
        boolean isEmpty()  
        { 
            if(top==-1){
                return true;
            }
            else
                return false;
        } 
    }

    //Match if a closing bracket occurs in the string
    public static boolean isMatch(char ch1, char ch2){
        if(ch1=='(' && ch2==')')
            return true;
        if(ch1=='{' && ch2=='}')
            return true;
        if(ch1=='[' && ch2==']')
            return true;
        else
            return false;
    }

    //function to check if parenthesis is balanced or not
    public static boolean checkparen(String str){
        int n=str.length();
        stack s=new stack();
        for(int i=0;i<n;i++){
            char c=str.charAt(i);
            //check if character at ith position is opening bracket or closing one.
            //if opening one push to stack
            if(c=='(' || c=='{' || c=='['){
                s.push(c);
            }

            //if closing one
            else if(c==')' || c=='}' || c==']'){
                //to check if we are getting an closed bracket on first position
                if(s.isEmpty()){
                    return false;
                }
                //otherwise check pairs
                if(!isMatch((char)s.pop(), c)){
                    return false;
                }
            }
        }

        //if not getting any string
        if(s.isEmpty()){
            return true;
        }
        else
            return false;
    }
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        while (sc.hasNext()) {
            String str=sc.next();
            boolean res=checkparen(str);
            if(res){
                System.out.println("true");
            }
            else{
                System.out.println("false");
            }
        }
    }
}


