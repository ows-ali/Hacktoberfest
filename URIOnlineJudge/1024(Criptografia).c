#include <stdio.h>
#include <string.h>

void invert(char a[]){
  int i , t = strlen(a);
  char tmp;
  for(i = 0; i < t/2; i++){
     tmp= a[i];
     a[i] = a[t-i-1];
     a[t-i-1] = tmp;
  }
}

void criptografar(char *a, char *b){
  int j, i, t = strlen(a), metade = t/2, aux = strlen(a);
  char saux[t];
  for(i = 0; i < 3; i++){
    if(i+1 == 1){
      for(j = 0; j < t; j++){
        if(a[j] > 64 && a[j] < 91){
          a[j] += 3;
        }
        if(a[j] > 96 && a[j] < 123){
          a[j] += 3;
        }
      }
    }
    else if(i+1 == 2){
      invert(a);
    }
    else if(i+1 == 3){
      for(j = metade; j < t; j++){
        a[j] -= 1;
      }
    }
  }
}

int main(void) {
  int t, i;
  char senha[1002];
  char aux[1002];
  scanf("%d", &t);
  for(i = 0; i < t; i++){
    scanf(" %[^\n]s", senha);
    criptografar(senha, aux);
    printf("%s\n", senha);
  }
  return 0;
}
