#define TAM 10

typedef int elem;
typedef struct fila fila_t;

fila_t *create();
int isEmpty(fila_t *f);
int isFull(fila_t *f);
int insert(fila_t *f, elem x);
int removeElem(fila_t *f, elem *x);
void destroy(fila_t *f);
