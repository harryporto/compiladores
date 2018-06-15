#include <stdarg.h>
#include <stdbool.h>

typedef enum {TokenChar, Ramo}tipoNodoE;
typedef struct {char str_tokken[20];}noIdentificador;
typedef struct {int tokenop;int qt_filho;struct noode **percorre;} nodoAst;
typedef struct noode {union {noIdentificador folha;nodoAst no;};tipoNodoE tipoNodo;} no_ast;
struct Node{char str[20];struct Node *prox;};
typedef struct Node node;
