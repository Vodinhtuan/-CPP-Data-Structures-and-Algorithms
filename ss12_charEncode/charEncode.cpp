#include <iostream>
using namespace std;
int length(char A[]){
	int i = 0;
	while(true){
		if(A[i]=='\0'){
			return i;
		}
		i++;
	}
}

void maHoaChuoi(char A[200], int k) {
	cout << "Nhap vao chuoi can ma hoa: ";
	fflush(stdin);
	cin.getline(A,200);
	cout << "Nhap K: ";
	cin >> k;
	for (int i = 0; i < length(A); i++) {
		if(A[i] != ' ') {
			if(A[i] == 'Z' || A[i] == 'z')
				A[i] = int(A[i]) - 25;
			else
				A[i] = int(A[i]) + k;
		}
	}
}

void giaiMaChuoi(char A[200], int k) {
	cout << "Nhap vao chuoi can giai ma: ";
	fflush(stdin);
	cin.getline(A,200);
	cout << "Nhap K: ";
	cin >> k;
	for (int i = 0; i < length(A); i++) {
		if(A[i] != ' ') {
			if(A[i] == 'A' || A[i] == 'a')
				A[i] = int(A[i]) + 25;
			else
				A[i] = int(A[i]) - k;
		}
	}
}

void nenChuoi(char A[]) {
	cout << "Nhap vao chuoi can nen: ";
	fflush(stdin);
	cin.getline(A,200);
	int dem = 0;
	for (int i = 0; i < length(A); i++) {
		for(int j = i ; j < length(A) ; j++) {
			if(A[i] == A[j]) {
				dem ++;
			}else {
				i = j - 1;
				break;
			}
		}	
		cout << dem << A[i];
		dem = 0;
	}
}

void outPutString(char A[]){
	int n = length(A);
	for(int i = 0; i < n; i++){
		cout << A[i];
	}
	cout << endl;
}
main(){
	int select,k;	
	char A[200];
	do{
		cout << "\nCHUONG TRINH GIAI MA VA MA HOA" << endl;
		cout << "1. Ma Hoa Chuoi" << endl;
		cout << "2. Giai Ma Chuoi" << endl;
		cout << "3. Nen Chuoi" << endl;
		cout << "4. Thoat" << endl;
		cout << "Your selection: ";
		cin >> select;
		switch (select) {
			case 1: {
				maHoaChuoi(A,k);
				outPutString(A);
				break;
			}
			case 2: {
				giaiMaChuoi(A,k);
				outPutString(A);
				break;
			}
			case 3: {
				nenChuoi(A);
				break;
			}
		}
	}while(select != 4);
}
