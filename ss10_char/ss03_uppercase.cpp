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
void xuLy(char A[], char B[]) {
	int n = length(A) + length(B);
	int iB = 0;
	for(int i = 0;  i < length(A); i++) {
		if(A[i] >= 'a' && A[i] <= 'z')
			A[i] = int(A[i]) - 32;
	}
	
	for(int i = 0; i < length(B); i++) {
		if(B[i] >= 'A' && B[i] <= 'Z')
			B[i] = int(B[i]) + 32;	
	}

	for(int i = length(A); i < n; i++){
		A[i] = B[iB];
		iB++;
	}
	A[n] = '\0';
}

void outputString(char A[]) {
	int n = length(A);
	for(int i = 0 ; i < n; i++) {
		cout << A[i];
	}
}
main(){
	char A[200], B[200];
	cin.getline(A,200);
	cin.getline(B,200);
	xuLy(A,B);
	outputString(A);
}
