#include<iostream>
using namespace std;

void particao_ED(int IniSeg, int FimSeg) {
	int IniSeg1, FimSeg1,
	Ch,
	Ender;
	bool Esq;
	IniSeg1 = IniSeg;
	FimSeg1 = FimSeg;
	
	Ch = Vet_Ch[IniSeg];
	
	Ender = Vet_End[IniSeg];
	Esq = true;
	
	while(IniSeg1 < FimSeg1) {
		if(Esq) {
			if(Ch > Vet_Ch[FimSeg1]) {
				Vet_Ch[IniSeg1] = Vet_Ch[FimSeg1];
				Vet_End[IniSeg1] = Vet_End[FimSeg1];
				IniSeg1 = IniSeg1 + 1;
				Esq = false;
			} else {
				FimSeg1 = FimSeg1 - 1;
			}
		} else {
			if(Ch < Vet_Ch[IniSeg1]) {
				Vet_Ch[FimSeg1] = Vet_Ch[IniSeg1];
				Vet_End[FimSeg1] = Vet_End[IniSeg1];
				FimSeg1 = FimSeg1 - 1;
				Esq = true;
			} else {
				IniSeg1 = IniSeg1 + 1;
			}	
		}
	}
	
	Vet_Ch[IniSeg1] = Ch;
	Vet_End[IniSeg1] = Ender;
	ElemPart = IniSeg1;
}
