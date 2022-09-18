#include <iostream>
using namespace std;
int length(char A[]){
	int i = 0;
	while(true){
		if(A[i]=='\0')
			return i;
		i++;
	}
}
void connect(char A[], char B[], char C[]) {
	int n = length(A) + length(B) + length(C);
	int j = 0;
	for(int i = length(A); i < length(A) + length(B); i++) {
		A[i] = B[j];
		j++;
	}
	int k = 0;
	for(int i = n - length(C); i <= n; i++) {
		A[i] = C[k];
		k++;
	}
}
void outPut(char A[]){
	int n = length(A);
	for(int i = 0; i < n; i++){
		cout << A[i];
	}
	cout << " ";
}
main(){
	char surname[200], firstName[200], middleName[200];
	cout << "Enter surname: ";
	cin.getline(surname,200);
	cout << "Enter firstName: ";
	cin.getline(firstName,200);
	cout << "Enter middle name: ";
	cin.getline(middleName,200);
	connect(surname,middleName,firstName);
	cout << "Full name: ";
	outPut(surname);
}
