// 1087 - Queen

#include <stdio.h>

int main() {
    int x1,y1,x2,y2,verdade = 1;
    
    while(verdade == 1){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        
        if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0){
            break;
        } 
                   
        if(x1 == x2 && y1 == y2){
            printf("0\n");
        }else if((x2-x1) == -(y2-y1) || -(x2-x1) == -(y2-y1) || -(x2-x1) == (y2-y1) || (x2-x1) == (y2-y1)){
            printf("1\n");
        } else if(x1 == x2 || y1 == y2){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }

    return 0;
}