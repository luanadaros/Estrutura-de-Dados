#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "vector.h"

double get_timestamp()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return now.tv_sec + (((double)now.tv_nsec) / 1e9);
}

int main (){
    int n;
    int m;
    //int valor;
    double inicio, fim, duracao;
    double maior = -1000000, menor = 1000000, medio = 0;

    srand(time(NULL));

    printf("N menor maior medio\n");

    for(n = 200; n < 20001; n += 2000){
        Vector * v = vector_construct(n);

        //preenche vetor com n valores aleatorios
        for(int i = 0; i < n; i++) {
            vector_push_back(v, rand() % n); 
        }


        for(m = 0; m < 5000; m++){

            //busca valor aleatorio no vetor
            //valor = vector_get(v, rand() % n);

            //mede tempo para encontrar o valor
            inicio = get_timestamp();
            vector_sort(v);
            fim = get_timestamp();
            duracao = fim - inicio; 

            //compara tempos
            if(duracao > maior){
                maior = duracao;
            }
            if(duracao < menor){
                menor = duracao;
            }

            medio += duracao;
    }   

    medio = medio/5000;

    printf("%d %.7lf %.7lf %.7lf\n", n, menor, maior, medio);

    //volta pros valores iniciais
    maior = -1000000;
    menor = 1000000;
    medio = 0;

    vector_destroy(v);
    }
}
