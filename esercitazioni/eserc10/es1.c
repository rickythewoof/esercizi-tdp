#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "scl.h"
#include "coda.h"
#include "pila.h"

void stampa_sequenza_inversa(void);
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n);
bool check_palindrome(const char* s);
bool check_palindrome_r(const char* s);
int* rimuoviMinori(int* arr, int len);
void stampa_sequenza(void);
int elemento_iesimo(Coda *c, int pos);
void avoid_stampa(Coda *c, int elem);
Coda * coda_circolare(Coda *c, int n);
Coda * elementi_pari(Coda *c);

int main(){
  stampa_sequenza_inversa();
  return 0;
}

void stampa_sequenza_inversa(void){
  Pila ris = pilaVuota();
  int a; scanf("%d",&a);
  while (a>=0){
    ris = inPila(&ris, a);
    scanf("%d",&a);
  }
  while (!estPilaVuota(&ris)){
    printf("%d ", outPila(&ris));
  }
  printf("\n");
}
