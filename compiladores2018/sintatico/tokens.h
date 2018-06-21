

#include <stdarg.h>
#include <stdbool.h>
typedef enum { Tok, Ast } tipoNodoE;


typedef struct {
    int val;                      
} nodoIdentificador;

typedef struct {
	int tokenOpr;
	int n_filhos;                                      
    struct astnode **filhos;	
} nodoAst;

typedef struct astnode {
    union {
        nodoIdentificador token;       
        nodoAst astn;        
    };
    tipoNodoE tipoNodo;
    
} noAst;
