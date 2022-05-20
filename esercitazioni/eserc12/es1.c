#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alberoBinario.h"
#include "lista.h"



int singleChildSum(TipoAlbero a);
int livelli_completi(TipoAlbero a);
TipoLista listaNodiFoglia(TipoAlbero a);
TipoAlbero taglia_livello(TipoAlbero a, int livello);

bool estFoglia(TipoAlbero a){
  return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

TipoLista inFondo(TipoLista l);
TipoLista invertiInParte(TipoLista l, int inizio);

int main(){
  TipoAlbero alb = creaAlbBin(1, creaAlbBin(2, creaAlbBin(4,NULL,NULL), creaAlbBin(5, NULL, NULL)),
                  creaAlbBin(3, creaAlbBin(6,NULL,NULL),
                  creaAlbBin(7, NULL, creaAlbBin(8, NULL, NULL))));
  printf("TEST ALBERI\n\n");
  printf("SINGLE_CHILD_SUM\t%d\n", singleChildSum(alb));
  return 0;
}

int singleChildSum(TipoAlbero a){
  if (estVuoto(a) || estFoglia(a)) return 0;
  else{
    if(!estVuoto(sinistro(a))){
      if(estVuoto(destro(a)))
        return radice(a) + singleChildSum(sinistro(a));
      else
        return singleChildSum(sinistro(a)) + singleChildSum(destro(a));
    }
    else{
      if(estVuoto(sinistro(a)))
        return radice(a) + singleChildSum(destro(a));
      else
        return singleChildSum(sinistro(a)) + singleChildSum(destro(a));
    }
  }
}

int livelli_completi(TipoAlbero a){
  return 0;
}

TipoLista listaNodiFoglia(TipoAlbero a){
  if(estVuoto(a)) return listaVuota();
  else if (estFoglia(a)) return cons(radice(a), listaNodiFoglia(sinistro(a)));
  else{
    listaNodiFoglia(sinistro(a));
    return listaNodiFoglia(destro(a));
  }
}
