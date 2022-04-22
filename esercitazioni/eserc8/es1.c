#include "insf_scl.h"
#include <stdio.h>
#include <stdlib.h>

Insieme init(int *arr, int n);
void print(Insieme s);
Insieme copy(Insieme s);
int size(Insieme s);
bool subset(Insieme a, Insieme b);
bool equal(Insieme a, Insieme b);
Insieme intersection(Insieme a, Insieme b);
Insieme unione(Insieme a, Insieme b);

int main(){
  T arr1[5] = {1, 2, 3, 3, 5};
  T arr2[4] = {3, 3, 1, 7};
  Insieme ins1 = init(arr1, 5); printf("INSIEME1 = ");print(ins1);
  Insieme ins2 = copy(ins1); printf("INSIEME2 = "); print(ins2);
  Insieme ins3 = init(arr2, 4); printf("INSIEME3 = "); print(ins3);
  printf("SIZE2 = %d\n", size(ins2));
  printf("SIZE3 = %d\n", size(ins2));
  printf("SUBSET = %d\n", subset(ins3, ins1));
  printf("EQUAL = %d\n", equal(ins3, ins1));
  Insieme inters = intersection(ins1, ins3);printf("INTERSECT = "); print(inters);
  return 0;
}

Insieme init(T *arr, int n){
  Insieme ins = insiemeVuoto();
  for (int i = 0; i < n; i++){
      ins = inserisci(ins, arr[i]);
    }
  return ins;
}

void print_aux(IteratoreInsieme it){
  if (!hasNext(it)) printf("\n");
  else{
    T value = next(it);
    printf("%d ",value);
    print_aux(it);
  }
}

void print(Insieme s){
  IteratoreInsieme it = creaIteratoreInsieme(s);
  print_aux(it);
}

Insieme copy(Insieme s){
  Insieme copy = insiemeVuoto();
  IteratoreInsieme it = creaIteratoreInsieme(s);
  while(hasNext(it)){
    T info = next(it);
    copy = inserisci(copy, info);
  }
  return copy;
}

int size(Insieme s){
  int num = 0;
  IteratoreInsieme it = creaIteratoreInsieme(s);
  while(hasNext(it)){
    num++;
    next(it);
  }
  return num * sizeof(int);
}

bool subset(Insieme a, Insieme b){
  IteratoreInsieme it = creaIteratoreInsieme(a);
  while(hasNext(it)){
    if(!membro(b, next(it))) return 0;
  }
  return 1;
}

bool equal_aux(IteratoreInsieme it1,IteratoreInsieme it2){
  if (!hasNext(it1) && !hasNext(it2)) return 1;
  else if ((!hasNext(it1) && hasNext(it2)) || (hasNext(it1) && !hasNext(it2))) return 0;
  else{
    return (next(it1) == next(it2)) && equal_aux(it1, it2);
  }
}

bool equal(Insieme a, Insieme b){
  IteratoreInsieme it1 = creaIteratoreInsieme(a);
  IteratoreInsieme it2 = creaIteratoreInsieme(b);
  bool same = equal_aux(it1, it2);
  return same;
}

Insieme intersection_aux(IteratoreInsieme it_a, Insieme b){
  if (!hasNext(it_a)) return NULL;
  else{
    Insieme inters = insiemeVuoto();
    T val = next(it_a);
    if(membro(b, val)) inters = inserisci(intersection_aux(it_a, b), val);
    //inters = intersection_aux(it_a, b);
    return inters;
  }
}

Insieme intersection(Insieme a, Insieme b){
  Insieme inters = intersection_aux(creaIteratoreInsieme(a), b);
  return inters;
}

Insieme unione(Insieme a, Insieme b){
  Insieme un = copy(insieme b);

}
