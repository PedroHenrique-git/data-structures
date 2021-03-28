#include <iostream>
#include <stdlib.h>
using namespace std;

main() {
	int *p;
	char *s;
	
	p = (int *) malloc(sizeof(int));
	
	*p = 7;
	
	s = (char *) malloc(20*sizeof(char));
	
	cout<<"Digite um caracter: ";
	cin>>s;
	
	cout<<endl<<"Conteudo de p: "<<*p<<endl<<"Conteudo de s: "<<s;
}
