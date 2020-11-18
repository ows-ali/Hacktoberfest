#include<stdio.h>
#include<stdlib.h>

bool cmp_arr(int a1[], int a2[]){
  for(int i=0; a1[i]!=NULL && a2[i]!=NULL; i++){
    if(a1[i] != a2[i]) return false;
  }
  return true;
}
