#include <iostream>
using namespace std;
void input(int A[], int &n) {
	cout << "Enter the array length: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
}
void arrC(int A[], int n, int B[], int m, int C[], int &c){
	c = n + m;
	int iA = 0;
	int iB = 0;
		for ( int iC = 0; iC < c; iC++){ 
			if(iA >= n){ 				// Neu phan tu cua mang A[iA] het thi lay het phan tu con lai cua mang B[iB]
				C[iC] = B[iB];
				iB++;
			}else if(iB >= m){			// Neu phan tu cua  mang B[iB] het thi lay het phan tu con lai cua mang A[iA]
				C[iC] = A[iA];
				iA++;
			}else if(A[iA] > B[iB]){ 	// neu A[iA] ma lon hon B[iB] thi C[iC] luc nay bang B[iA] va iB++ de so sanh tiep voi A[iA]
				C[iC] = B[iB];
				iB ++;
			}else{  	 				// neu B[iB] ma lon hon A[iA] thi C[iC] luc nay bang A[iA] va iA++ de so sanh tiep voi B[iB]
				C[iC] = A[iA];			
				iA++;
			}
		}
}
void output(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}
int main() {
	int A[200], n, B[200], m, C[400], c;
	input(A, n);
	input(B,m);
	arrC(A,n,B,m,C,c);
	output(C,c); 
}

