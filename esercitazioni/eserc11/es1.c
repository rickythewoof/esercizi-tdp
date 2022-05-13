#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alberoBinario.h"
#include "lista.h"

//FUNZIONI DI ESERCITAZION

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
bool estFoglia(TipoAlbero a){
  return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

TipoInfoAlbero max(int a, int b){
  if (a>=b) return a;
  else return b;
}

int main(){
  TipoAlbero alb = creaAlbBin(1, creaAlbBin(2, creaAlbBin(4,NULL,NULL), NULL),
                  creaAlbBin(3, creaAlbBin(5,NULL,NULL),
                  creaAlbBin(6, NULL, creaAlbBin(7, NULL, NULL))));
  printf("ALBERO=\t"), stampaParentetica(alb); printf("\n");
  printf("MAX=\t\t%d\n", trova_massimo(alb));
  printf("SOMMA_FOGLIE=\t%d\n", somma_foglie(alb));
  printf("CERCA_LIVELLO=\t%d\n", cerca_livello(alb, 4));
  printf("CONTA_DISPARI=\t%d\n", conta_dispari(alb));
  printf("SOMMA_SINGOLI\t%d\n", somma_singoli(alb));
}

TipoInfoAlbero trova_massimo(TipoAlbero a){
  if (estVuoto(a)) return -1;
  else if (estFoglia(a)) return radice(a);
  else{
    int m1 = max(trova_massimo(destro(a)), trova_massimo(sinistro(a)));
    TipoInfoAlbero info = radice(a);
    return max(info, m1);
  }
}

TipoInfoAlbero somma_foglie(TipoAlbero a){
  if (estVuoto(a)) return 0;
  if (estFoglia(a)) return radice(a);
  else{
    return somma_foglie(destro(a)) + somma_foglie(sinistro(a));
  }
}

int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int liv){
  if (estVuoto(a)) return -1;
  else if (radice(a) == v) return liv;
  else{
    if (!estVuoto(sinistro(a)))
      return cerca_livello_aux(sinistro(a), v, liv+1);
    else if (!estVuoto(destro(a)))
      return cerca_livello_aux(destro(a), v, liv+1);
  }
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v){
  return cerca_livello_aux(a, v, 0);
}

int conta_dispari(TipoAlbero a){
  if (estVuoto(a)) return 0;
  else{
    int sum = radice(a);
    if (!estVuoto(sinistro(a)))
      sum += radice(sinistro(a));
    if (!estVuoto(destro(a)))
      sum += radice(destro(a));
    if(sum % 2 != 0)
      return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    else
      return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
  }
}

int somma_singoli(TipoAlbero a){
  if (estVuoto(a)) return 0;
  else if (estFoglia(a)) return 0;
  else if ((estVuoto(sinistro(a))&&!estVuoto(destro(a)))
            || (estVuoto(destro(a))&&!estVuoto(sinistro(a))))
      return 1;
  else return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

// TipoLista albero_lista(TipoAlbero a){  //IMPLEMENTARE (SERVE FORSE FUNZIONE AUSILIARIA)
//   if (estVuoto(a)) return listaVuota();
//   else if (estFoglia(a)){
//     if ()
//   }
// }
