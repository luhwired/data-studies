#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float media(float dados[], int tamanho){
    float soma = 0.0;
    for (int i=0; i < tamanho; i++){
	soma += dados[i];
    }
    return soma / tamanho;
}

float desvio_padrao(float dados[], int tamanho){
    float m = media(dados,tamanho);
    float diferencas_quadradas = 0.0;
    for (int i=0; i < tamanho; i++){
	diferencas_quadradas += pow(dados[i] - m, 2);
    }
    return sqrt(diferencas_quadradas / tamanho);
}
int main(){
    float valores[] = {10.0, 12.5, 9.5, 14.0, 11.0};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("Média: %f\n", media(valores, n));
    printf("Desvio Padrão: %f\n", desvio_padrao(valores, n));
    
    return EXIT_SUCCESS;
}
