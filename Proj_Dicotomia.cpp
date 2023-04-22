#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float CalculaValorK(float a, float b, float erro);
float funcaoX(float ponto);
void ImprimirCabecalhoTabela();
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB,float fM, char fAfM, char fMfB);
int grau;
float multi[7], erro;
float calculadicotomia(float a, float b, float m, float erro, float k, float fA, float fB,float fM, char fAfM, char fMfB);
void aloca(float *ptr, int tam);

main(){
	int i;
	float a, b, c, erro, ponto, k, m,fValorK,f_a,f_b,f_m,fAfM,fBfM;
	float *ptr=NULL;
	
	printf("Dicotomia\n\n");
	printf("Informe o grau da funcao (2 a 6): ");
	scanf("%i", &grau);
	ptr= multi;

	for(i=grau; i>=0; i--){
		printf("Informe o fator multiplicador de x^%i: ", i);
		scanf("%f", &ptr[i]);
	}
 	
	printf("\nQual o valor do erro: ");
	scanf("%f", &erro);
	printf("A funcao recebida foi: ");
	
	for(i=grau; i>=1; i--){	
		if(i!=0)
 			printf("%.2fx^%i + ", multi[i], i);
		 else
        	printf("%.2f = 0", multi[i]);
	}

	if(i==0){
		printf("%.2f = 0", multi[i], i);
	}
	else{
		printf("%.2fx^%i + ", multi[i], i);
	}

	printf("\nDigite os Intervalos:");
	scanf("%f %f", &a, &b);

	f_a = funcaoX(a);
	f_b = funcaoX(b);
	f_m = funcaoX(m);

	if ((f_a * f_b) > 0) {
        printf("Nao existe zero da funcao no intervalo [A, B].\n");
        return 0;
    }
	else{
		k=CalculaValorK( a, b, erro);
		printf("k = %f, arredondamos para %.0f", k,ceil(CalculaValorK( a, b, erro)));
		printf("\n\n");
		system("pause");
	
		ImprimirCabecalhoTabela();
	
		
	    calculadicotomia(a, b,  m, erro, k, f_a, f_b, f_m, 0, 0); 
	}	

	printf("\n\n");
	system("pause");
	free(ptr);	

}


void aloca(float *ptr, int tam){
	if((ptr = (float *)malloc(tam * sizeof(float)))==NULL);
    	exit(1);
}

float CalculaValorK(float a, float b, float erro){
	float fValorK;
	fValorK = (log(b-a) - log(erro)/ log(2));

	ceil(fValorK);
	return fValorK;
}

float funcaoX(float ponto){
	int i;
	float resultado;
	resultado = 0;

	for(i=0; i<=grau; i++){
		resultado = resultado + multi[i]*pow(ponto, i);
	}
	
	return resultado;
}

float calculadicotomia(float a, float b, float m, float erro, float k, float fA, float fB,float fM, char fAfM, char fBfM){
    float f_a, f_b, f_m;
    int i;

	for(i=0;i<=k;i++){
		float m;
        m = (a + b) / 2;
        f_m = funcaoX(m);
        f_a = funcaoX(a);
        f_b = funcaoX(b);
        
    
		
    if(f_a*f_m<0){
    	fAfM= '-';
    	fBfM= '+';
	}
	else{
		fAfM= '+';
    	fBfM= '-';
	}
	
    ImprimirTabela(i+1,a, b, m, f_a,f_b,f_m , fAfM, fBfM);
    
        if (f_m * f_a < 0){
            b = m;
            f_b = f_m;
            a = a;
            fAfM = '-';
            fBfM = '+';
        } 
		else {
            a = m;
            f_a = f_m;
            b = b;
            fAfM = '+';
            fBfM = '-';
        }		
        
        
    
	}
	printf("Raiz aproximada: %f\n", (a+b)/2);  	
	
}

void ImprimirCabecalhoTabela(){
	printf("I | a\t| b\t| m\t| f(a)\t| f(b)\t| f(m)\t| fa*fm\t| fm*fb\t|\n");
	printf("--+-------+---------+---------+---------+---------+---------+---------+---------+\n");
}

void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB,float fM, char fAfM, char fMfB){
	printf("%i |%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%c\t|%c\t|\n", iteracao,a, b, m, fA, fB, fM, fAfM, fMfB);
}
