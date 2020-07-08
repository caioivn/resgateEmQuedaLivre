#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

class grafo{
public:
    int x, y, pai;
    
    grafo(){
        x = 0;
        y = 0;
        pai = -1;
    }
    
};


/*
 *Algoritmo de Prim
 */
void prim(grafo vertices[], double **adjacencia, int n){
    int primeiro, pai = 0, filho;
    double menorPeso = 999999;
    vertices[0].pai = 0;
    while(true){
        primeiro = 1;
        for(int i = 0; i < n; i++){
            if(vertices[i].pai != -1){
                for(int j = 0; j < 5; j++){
                    if((i != j) && vertices[j].pai == -1){
                        if(primeiro){
                            menorPeso = adjacencia[i][j];
                            pai = i;
                            filho = j;
                            primeiro = 0;
                        }else{
                            if(menorPeso > adjacencia[i][j]){
                                menorPeso = adjacencia[i][j];
                                pai = i;
                                filho = j;
                            }
                        }
                    }
                }
            }
                
        }
        if(primeiro == 1){
            break;
        }
        vertices[filho].pai = pai;
    }
}

int main() {
    int c, n;
    cin >> c;
    while(c > 0){
        cin >> n;
        grafo vertices[n];
        double **adjacencia, peso = 0;
        /*
         *Alocação da matriz de adjacencia
         */
        adjacencia = (double **) malloc(n * sizeof(double *));
        for(int i = 0; i < n; i++){
            adjacencia[i] = (double *)malloc(n * sizeof(double));
            for(int j = 0; j < n; j++){
                adjacencia[i][j] = 0;
            }
        }
        //Lê as coordenadas de cada pessoa
        for(int i = 0; i < n; i++){
            cin >> vertices[i].x;
            cin >> vertices[i].y;
        }
        //Determina a distância entre cada pessoa
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjacencia[i][j] = sqrt(pow((vertices[i].x-vertices[j].x),2)+pow((vertices[i].y-vertices[j].y),2));
            }
        }
        prim(vertices,adjacencia, n);
        //Acumula o peso total das arestas
        for(int i = 0; i < n; i++){
            peso += adjacencia[i][vertices[i].pai];
        }
        cout << fixed << setprecision(2);
        cout << peso/100 << endl;
        cout << endl;
        c--;
    }    
    return 0;
}