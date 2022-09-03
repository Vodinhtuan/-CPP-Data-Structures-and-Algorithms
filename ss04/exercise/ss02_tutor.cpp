#include <iostream>
using namespace std;
void nhapMang(int A[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
}
void arrC(int A[], int nA, int B[], int nB, int C[], int &nC){
	nC = nA + nB;
	int iA = 0;
	int iB = 0;
		for ( int iC = 0; iC < nC; iC++){ 
			if(A[iA] < B[iB] || iB>=nB){ 	
				C[iC] = A[iA];
				iA ++;
			}
			else{  	                //if(A[iA] > B[iB] || iA==nA)			
				C[iC] = B[iB];			
				iB++;
			}
		}
}
void xuatMang(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}
int main() {
	int A[200], n, B[200], m, C[400], c;
	nhapMang(A, n);
	nhapMang(B,m);
	arrC(A,n,B,m,C,c);
	xuatMang(C,c); 
}
