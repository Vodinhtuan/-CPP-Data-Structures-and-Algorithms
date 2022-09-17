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
int xuLy(char A[], char B[]) {
	int iA = 0;
	int iB = 0;
	int dem = 0;
	while(iA < length(A) && iB < length(B)){
		if(A[iA] == B[iB]) {
			iA++;
			iB++;
			if(iB == length(B)){
				dem++;
				iB = 0;
				iA = iA - 1;
			}	
		}else if (A[iA] != B[iB] && A[iA] != B[iB - 1]){
			iB = 0;
			iA++;
		}else {
			iB = 0;
			iA;
		}
	}
	return dem;
}

main(){
	char A[200], B[200];
	cin.getline(A,200);
	cin.getline(B,200);
	cout << xuLy(A,B);
}
