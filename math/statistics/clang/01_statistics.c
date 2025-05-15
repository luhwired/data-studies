#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float media(float dados[], int tamanho){
    float soma = 0.0;
    for (int i = 0; i < tamanho; i++){
	soma += dados[i];
    }
    return soma / tamanho;
}

int comparar_floats(const void *a, const void *b){
    float fa = *(const float*)a;
    float fb = *(const float*)b;

    return (fa > fb) - (fa < fb);
}

float mediana(float dados[], int tamanho){
    float copia[tamanho];

    for (int i=0; i < tamanho; i++){
	copia[i] = dados[i];
    }
    qsort(copia, tamanho, sizeof(float), comparar_floats);

    if (tamanho % 2 ==1){
	return copia[tamanho / 2];
    } else {
	int meio = tamanho / 2;
	return(copia[meio - 1] + copia[meio]) / 2.0;
    }
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
    qsort(valores, n, sizeof(float), comparar_floats);
    for (int i = 0; i < n; i++){
	printf("%f, ", valores[i]);
    }
    printf("\nMédia: %f\n", media(valores, n));
    printf("Mediana: %f\n", mediana(valores, n));
    printf("Desvio Padrão: %f\n", desvio_padrao(valores, n));
    
    return EXIT_SUCCESS;
}
