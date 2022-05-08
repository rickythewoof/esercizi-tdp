#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "scl.h"
#include "coda.h"
#include "pila.h"

void print_pila(Pila* p);                    //stampa la pila
void stampa_sequenza_inversa(Pila* ris);    //ora ho una pila utilizzabile
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n);
bool check_palindrome(const char* s);
bool check_palindrome_r(const char* s);
int* rimuoviMinori(int* arr, int len);
void stampa_sequenza(Coda* c);
int elemento_iesimo(Coda *c, int pos);
void avoid_stampa(Coda *c, int elem);
Coda * coda_circolare(Coda *c, int n);
Coda * elementi_pari(Coda *c);

int main(){
  //ESERCIZI SU PILE
  // Pila *p = pilaVuota();
  // stampa_sequenza_inversa(p);
  // int rimuovere[] = {1, 2, 3};
  // rimuovi_alcuni(p, rimuovere, 3);
  // print_pila(p);
  // printf("PALINDROME:\t%d\n",check_palindrome("abba"));
  // printf("PALINDROME_R:\t%d\n",check_palindrome_r("abba"));
  //ESERCIZI SU CODE
  Coda *c = codaVuota();
  stampa_sequenza(c);
  return 0;
}

//PILE
void print_pila(Pila* p){
  Pila* p2 = pilaVuota();
  while(!estPilaVuota(p)){
    printf("%d ",primoPila(p));
    inPila(p2, outPila(p));
  }
  printf("\n");
  while(!estPilaVuota(p2)){
    inPila(p, outPila(p2));
  }
}

void stampa_sequenza_inversa(Pila* ris){
  int a; scanf("%d",&a);
  while (a>=0){
    inPila(ris, a);
    scanf("%d",&a);
  }
  print_pila(ris);
  printf("\n");
}

void rimuovi_alcuni(Pila *p, const int *rimuovere, int n){
  Pila* ris = pilaVuota();
  while(!estPilaVuota(p)){
    T value = outPila(p);
    bool to_add = true;
    for (int i = 0; i < n; i++){
      if (value == rimuovere[i]) to_add = false;
    }
    if (to_add) inPila(ris, value);
  }
  while(!estPilaVuota(ris)){
    inPila(p, outPila(ris));
  }
}

bool check_palindrome(const char* s){
  if (strlen(s) % 2 != 0) return false;
  else{
    Pila* p = pilaVuota();
    for (int i = 0; i < strlen(s); i++){
      inPila(p, (int) s[i]);
    }
    print_pila(p);
    while (!estPilaVuota(p)){
      if (outPila(p) != (int) s[0])
        return false;
      else s = s + 1;
    }
    return true;
  }
}

bool check_palindrome_r(const char* s){
  printf("%s\n", s);
  if (strlen(s) == 0)
    return true;
  else if (strlen(s) % 2 != 0)
    return false;
  else{
    return (s[0] == s[strlen(s)-1]) && check_palindrome_r(s+1);
  }
}

int* rimuoviMinori(int* arr, int len){
  int* res;
  for (int i = 0; i < len; i++){

  }
  return res;
}

//CODE

void print_coda(Coda* c){
  Coda* ris = codaVuota();
  while(!estCodaVuota(c)){
    printf("%d ",primoCoda(c));
    inCoda(ris, outCoda(c));
  }
  printf("\n");
  while(!estCodaVuota(ris)){
    inCoda(c, outCoda(ris));
  }
}

void stampa_sequenza(Coda* c){
  int num; scanf("%d", &num);
  while (num >= 0){
    inCoda(c, num);
    scanf("%d", &num);
  }
  print_coda(c);
}
