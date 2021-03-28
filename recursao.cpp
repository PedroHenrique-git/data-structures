#include<iostream>
#include<stdlib.h>
using namespace std;
char *a, *b;

int funcaoX() {
	int localA, localB;
}

int pot2(int base, int expoente) {
	int s = 1;
	for(int i=0;i<expoente;i++) {
		s *= base;	
	}
	return s;
}

int pot(int n) {
	if(n == 0) return 1;
	else return 2 * pot(n-1);
}

int fibonacci(int n) {
	int ant = 0;
	int prox = 1;
	if(n == 0) {
		return 0;
	} else if(n == 1) {
		return 1;
	} else {
		for(int i =0; i < n; i++) {
			cout<<prox<<endl;
			prox = ant + prox;
			ant = prox - ant;
		}
	}
}

int fibonnacciRecursiva(int n) {
	if(n == 0 || n == 1) {
		return n;
	} else {
		return fibonnacciRecursiva(n - 1) + fibonnacciRecursiva(n - 2);  
	}
	
}

int fatorial(int n) {
	int resultado = 1;
	for(int i =1; i <= n; i++) {
		resultado *= i;
		//cout<<i<<endl;	
	}
	return resultado;
}

int fatorialRecursiva(int n) {
	if(n == 0) {
		return 1;
	} else {
		return n * fatorialRecursiva(n - 1);
	}
}

bool isPrimo(int n) {
	int div = 0; 
	for(int  i = 1; i <= n; i++) {
		if(n % i ==0) div++;
	}
	
	if(div == 2) return true;
	return false;
}

int mmc(int a, int b) {
	int resto1 = 0;
	int resto2 = 0;
	int divisores = 2;
	do {
		
		if(isPrimo(divisores)) {
			
			resto1 = a % divisores;
			resto2 = b % divisores;
			
			if(resto1 == 0 && resto2 == 0) {
				a /= divisores;
				b /= divisores;	
			} else if(resto1 == 0) {
				a /= divisores;	
			} else {
				b /= divisores;	
			}
		}
		divisores++;
			
	}while(a != 0 && b != 0);
	/*
	while(resto1 != 0 && resto2 != 0) {
		
		if(isPrimo(divisores)) {
			
			resto1 = a % divisores;
			resto2 = b % divisores;
			
			if(resto1 == 0 && resto2 == 0) {
				a /= divisores;
				b /= divisores;	
			} else if(resto1 == 0) {
				a /= divisores;	
			} else {
				b /= divisores;	
			}
			
			if(resto)
		}
	}
	*/
}

main() {
 //a = "Global A";
 //b = "Global B";
 //int *r = (int *) malloc(2000);
 //int *n = (int *) calloc(40,sizeof(int));
 // r = (int *) realloc(3000);
 //cout<<r<<endl;
 //cout<<n<<endl;
 //free(r);
 //free(n);
 //funcaoX();
 //cout<<pot2(2,5)<<endl;
 //cout<<pot(5)<<endl;
 //cout<<fatorial(5)<<endl;
 //cout<<fatorialRecursiva(5)<<endl;
 //fibonacci(24);
 //cout<<fibonnacciRecursiva(50);
 mmc(44,16);
}
