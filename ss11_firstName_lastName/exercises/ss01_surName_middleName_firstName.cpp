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

int firstSpace (char A[]) {
	for(int i = 0; i < length(A); i++) {
		if(A[i] == ' ')
			return i;
	}
}

int lastSpace(char A[]) {
	for(int i = length(A) - 1; i > firstSpace(A); i--) {
		if(A[i] == ' ')
			return i;
	}
}

void surName(char A[]) {
	int x = firstSpace(A);
	for(int i = 0; i <= x; i++) {
		cout << A[i];
	}
}

void firstName(char A[]) {
	int x = lastSpace(A);
	for(int i = x + 1; i < length(A); i++) {
		cout << A[i];
	}
}

void middleName(char A[]) {
	int x = firstSpace(A);
	int y = lastSpace(A);
	for(int i = x + 1; i <= y; i++) {
		cout << A[i];
	}
}

main(){
	char A[200];
	cin.getline(A,200);
	cout << "Surname: ";
	surName(A);
	cout << "\nMiddle name: ";
	middleName(A);
	cout << "\nFirst name: ";
	firstName(A);
}
