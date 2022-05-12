#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alberoBinario.h"
#include "lista.h"

//FUNZIONI DI ESERCITAZIONE

TipoInfoAlbero trova_massimo(TipoAlbero a);
TipoInfoAlbero somma_foglie(TipoAlbero a);
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);
int conta_dispari(TipoAlbero a);
int somma_singoli(TipoAlbero a);
TipoLista albero_lista(TipoAlbero a);
TipoLista percorso_lungo(TipoAlbero a);
TipoAlbero somma_sottoalbero(TipoAlbero a);
TipoAlbero scambia_foglie(TipoAlbero a);

//FUNZIONI UTENTE
bool estFogliaAlbero(TipoAlbero a){
  return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

int main(){

}

TipoInfoAlbero max(int a, int b){
  if (a>=b) return a;
  else return b;
}

TipoInfoAlbero trova_massimo(TipoAlbero a){
  if (estVuoto(a)) return -1;
  else if (estFogliaAlbero(a)) return radice(a);
  else{
    TipoInfoAlbero info = radice(a);
    int m1 = max(trova_massimo(destro(a)), trova_massimo(sinistro(a)));
    return max(info, m1);
  }
}

TipoInfoAlbero somma_foglie(TipoAlbero a){
  if (estVuoto(a)) return 0;
  if (estFogliaAlbero(a)) return radice(a);
  else{
    return somma_foglie(destro(a)) + somma_foglie(sinistro(a));
  }
}

// int cerca_livello(TipoAlbero a, TipoInfoAlbero v){
//   if (estVuoto(a)) return -1;
//   else if (radice(a) == v) return 0;
//   else{
//     //IMPLEMENTARE (SERVE FORSE FUNZIONE AUSILIARIA)
//   }
// }

int somma_singoli(TipoAlbero a){
  if (estVuoto(a)) return 0;
  else if (estFogliaAlbero(sinistro(a))&&estFogliaAlbero(destro(a))) return 1;
  else return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

// TipoLista albero_lista(TipoAlbero a){  //IMPLEMENTARE (SERVE FORSE FUNZIONE AUSILIARIA)
//   if (estVuoto(a)) return listaVuota();
//   else if (estFogliaAlbero(a)){
//     if ()
//   }
// }
