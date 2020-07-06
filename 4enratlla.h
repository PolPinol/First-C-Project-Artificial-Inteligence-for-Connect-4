#define N 8
#define PF 6

int taulerPle(int tauler[N][N]);
int comprovarTirada(int tauler[N][N],int p);
void CopiaTauler(int desti[N][N], int origen[N][N]);
int determinaFills(int tauler[N][N]);
int comprovar(int taulell[N][N],int jugador);
int tiradaReal(int tauler[N][N], int tiradaFalsa);
void imprimir(int tauler[N][N]);
void aplicarTirada(int tauler[N][N],int p, int jugador);
int taulerguanyat(int tauler[N][N]);
int taulerperdut(int tauler[N][N]);
int mirarVertical3(int tauler[N][N],int i, int j,int jugador);
int mirarHoritzontal3(int tauler[N][N],int i, int j,int jugador);
int mirarDiagonals3(int tauler[N][N],int i, int j,int jugador);
int mirarVertical2(int tauler[N][N],int i, int j,int jugador);
int mirarHoritzontal2(int tauler[N][N],int i, int j,int jugador);
int mirarDiagonals2(int tauler[N][N],int i, int j,int jugador);
int comptar2(int tauler[N][N],int jugador);
int comptar3(int tauler[N][N],int jugador);
double funcioHeuristica(int tauler[N][N]);
