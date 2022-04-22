#include "insf_scl.h"
#include <stdio.h>

Insieme init(int *arr, int n);
void print(Insieme s);
Insieme copy(Insieme s);
int size(Insieme s);
bool subset(Insieme a, Insieme b);
bool equal(Insieme a, Insieme b);
Insieme intersection(Insieme a, Insieme b);
Insieme unione(Insieme a, Insieme b);

int main(){
  int arr[5] = {1, 2, 3, 3, 5};
  int n = 5;
  Insieme ins = init(arr, n);
  print(ins);
  return 0;
}

Insieme init(int *arr, int n){
  Insieme ins = NULL;
  for (int i = 0; i < n; i++){
      inserisci(ins, arr[i]);
    }
  return ins;
}

void print_aux(IteratoreInsieme it){
  while(hasNext){
    printf("%d ",next(it));
  }
  printf("\n");
}

void print(Insieme s){
  IteratoreInsieme it = creaIteratoreInsieme(s);
  print_aux(it);
}
