// 1028 - Collectable Cards

#include <stdio.h>

int mdc(int a, int b) {
    int dnd, dvs, mod, res, stop = 0;

    if(a > b) {
        dnd = a;
        dvs = b;        
    } else {
        dnd = b;
        dvs = a;
    }
    
    while (stop == 0){
        mod = dnd%dvs;

        if(mod != 0){
            dnd = dvs;
            dvs = mod; 
        }else{
            stop = 1;
        }
    }

    return dvs;
}

int main() {
    int n, f1, f2;
    scanf("%d", &n);

    int i;
    for(i = 0; i < n; i++) {
        scanf("%d %d", &f1, &f2);
        printf("%d\n", mdc(f1, f2));
    }

    return 0;
}
