class Solution {
    public int romanToInt(String s) {
        int sum=0,z=0;
        String ch[] = s.split("");
        for(int i=0;i<ch.length;i++){
            sum = sum + z;
            if(ch[i] == 'I'){
                z = 1;
            }
            else if(ch[i] == 'V'){
                z=5;
            }
            else if(ch[i] == 'X'){
                z=10;
            }
            else if(ch[i] == 'L'){
                z=50;
            }
            else if(ch[i] == 'C'){
                z=100;
            }
            else if(ch[i] == 'D'){
                z=500;
            }
            else {
                z=1000;
            }
        }
        return sum;
    }
}
