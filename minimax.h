
typedef struct node {
    struct node **fills;
    int n_fills;
    int tauler[N][N];
    double valor;
    int profunditat;
}Node;

void inicialitza(Node *arrel);
void canviar1per2(Node *arrel);
Node *creaNode(Node *pare, int numFill, int prof);
void crea1Nivell(Node *pare,int prof);
void crearArbre(Node *arrel, int prof);
void MiniMax(Node *pare);
double ferMiniMax(Node *pare);
void esborraArbre(Node *arrel);

