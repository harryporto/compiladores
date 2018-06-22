

#include <stdarg.h>
#include <stdbool.h>
typedef enum { Tok,Ident, Ast } tipoNodoE;


typedef struct {
    int val;                      
} nodoIdentificador;

typedef struct {
    char val[30];                      
} nodaConstante;

typedef struct {
	int tokenOpr;
	int n_filhos;                                      
    struct astnode **filhos;	
} nodoAst;

typedef struct astnode {
    union {
        nodoIdentificador token;
	nodaConstante    constant;    
        nodoAst astn;        
    };
    tipoNodoE tipoNodo;
    
} noAst;
