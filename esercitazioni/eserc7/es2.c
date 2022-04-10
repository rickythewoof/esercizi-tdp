#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char TipoInfoSCL;

struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void sclstring_print(TipoSCL s);
TipoSCL sclstring_create(const char *s);
TipoSCL sclstring_create(const char *s, TipoSCL* scl);
bool sclstring_equals(TipoSCL scl, const char *s);
void sclstring_remove(TipoSCL *scl_p, char val);

int main(){
    char* string = "Ciao!";
    TipoSCL scl = sclstring_create(string);
    return 0;
}


void sclstring_print(TipoSCL s);{
    if (scl == NULL) printf("\n");
    else{
        printf("%c", scl->info);
        sclstring_print(scl->next);
    }
}

TipoSCL sclstring_create(const char* s){

    TipoSCL sclstring_create(s, &scl);
    return scl;
}

TipoSCL sclstring_create(const char *s, *scl){

}

bool sclstring_equals(TipoSCL scl, const char *s){
    if (scl == NULL && s = '\0') return true;
    else if (scl->info != s) return false;
    else return true & sclstring_equals(scl->next, s+1);
}