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
    char* string = "Ciaona!";
    TipoSCL scl = sclstring_create(string);
    sclstring_print(scl);
    printf("EQUAL = %d\n", sclstring_equals(scl, string));
    sclstring_remove(&scl, 'a'); sclstring_print(scl);
    return 0;
}

void sclstring_print(TipoSCL scl){
    if (scl == NULL);
    else if((scl->next) == NULL) printf("%c\n", scl->info);
    else{
        printf("%c->", scl->info);
        sclstring_print(scl->next);
    }
}

void scl_make (TipoSCL* scl, const char* s){
    if (s[0] == '\0') *scl = NULL;
    else {
        *scl = (TipoNodoSCL*)malloc(sizeof(TipoNodoSCL));
        (*scl)->info = s[0];
        (*scl)->next == NULL;
        scl_make(&((*scl)->next), s+1);
    }
}

TipoSCL sclstring_create(const char* s){
    TipoSCL scl;
    scl_make(&scl, s);
    return scl;
}

bool sclstring_equals(TipoSCL scl, const char *s){
    if (scl == NULL && s[0] == '\0') return true;
    else if (scl->info != s[0]) return false;
    else return true & sclstring_equals(scl->next, s+1);
}

void sclstring_remove(TipoSCL *scl_p, char val){
    if (*scl_p == NULL);
    else if (((*scl_p)->next)->info == val){
        TipoSCL to_del = ((*scl_p)->next);
        TipoSCL next_ptr = ((*scl_p)->next)->next;
        (*scl_p)->next = next_ptr;
        free(to_del);
    }
    else sclstring_remove(&((*scl_p)->next), val);
}