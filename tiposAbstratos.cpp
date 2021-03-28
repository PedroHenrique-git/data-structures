#include <iostream>
using namespace std;

struct Fracao {
	float numerador;
	float denominador;
};

struct Complexos {
	float x;
	float yi;
};

struct Matriz {
	int m[2][2];
};

int sumMat(int matC[][], int linhas, int colunas) {
	int sum = 0;
	int matC[linhas][colunas]; 
	
	for(int i = 0; i < linhas; i++) {
		for(int j =0; j < colunas; j++) {
			matC[linhas][colunas] = 0;
		}
	}
	
	for(int i = 0; i < linhas; i++) {
		for(int j =0; j < colunas; j++) {
			sum += matC[linhas][colunas];
		}
	}
	
	return sum;
}

main() {
	int linhas, colunas, elemento;
	cout<<"Digite as linhas da matriz: ";
	cin>>linhas;
	cout<<"Digite as colunas da matriz: ";
	cin>>colunas;
	int matA[linhas][colunas];
	
	
	for(int i = 0; i < linhas; i++) {
		for(int j = 0; j < colunas; j++) {
			cout<<"Digite o elemento ["<<i<<","<<j<<"] da matriz: ";
			cin>>elemento;
			matA[linhas][colunas] = elemento;	
		}
	}
	
	cout<<"Soma: "<<sumMat(linhas,colunas);
}
