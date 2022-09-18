#include <iostream>
using namespace std;
void handle(int A[50][50], int d, int c){
	for(int i = 0; i<n; i++){
		A[i][0]=1;
	}
	for(int i = 1; i<n; i++){
		for(int j = 1; j<n; j++){
			A[i][j] = A[i-1][j-1] + A[i-1][j]
		}
	}
}
void outPut(int A[50][50], int n){
	cout << "\n Result: " << endl;
	for(int i = 0; i<n; i++){
		cout << A[n-1][i] << " ";
	}
}
