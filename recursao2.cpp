#include<iostream>
using namespace std;

int pot(int base, int expoente) {
	int result = 0;
	if(expoente == 0) {
		return 1;
	} else {
		result = base * pot(base, expoente - 1);
		return result;
	}
}

void binarioToDecimal(int n) {
	if(n /2 != 0) {
		binarioToDecimal(n / 2);	
	}
	cout<<n%2<<endl;
}

main() {
	int vet [5] = {1,2,3,4,5};
	//cout<<pot(2,5)<<endl;
	//binarioToDecimal(45);
	varreArray(vet, 5);
}
