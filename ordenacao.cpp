#include<iostream>
using namespace std;

int buscaBin(int v[], int n, int k) {
	int inicio = 0;
	int fim = n - 1;
	int centro;
	while(inicio <= fim) {
		centro= inicio + (fim - inicio) / 2;
		
		if(k == v[centro]) return centro;
		else if (k > v[centro])
				inicio = centro + 1;
			else
				fim = centro - 1;
	}
	return - 1;
}

main() {
	int vet[10] = {4,78,12,34,65,21,34,77,98,11};
	int aux = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = i + 1; j < 10; j++) {
			if(vet[i] > vet[j]) {
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
		cout<<vet[i]<<" ";	
	}
	cout<<endl<<buscaBin(vet, 10, 34);
	/*
	int vet[10] = {4,78,12,34,65,21,34,77,98,11};
	int n = 0;
	bool presente;
	cout<<"Digite o numero que deseja buscar: ";
	cin>>n;
 	
	for(int i = 0; i < 10; i++) {
		if(vet[i] == n) {
			presente = true;
			break;
		} else {
			presente = false;
		}		
	}
	
	if(presente == 1) {
		cout<<"Numero esta no array";
	} else {
		cout<<"Este numero nao esta no array";
	}
	*/
}
