#include <iostream>
using namespace std;
void input(int A[][200], int n){
	for(int i = 0; i <= n ; i++){
		A[i][0] = 1;
		A[i][i] = 1;
		for(int j = 0; j <= i; j++){
			if(A[i][j] != 1){
				A[i][j] = A[i-1][j] + A[i-1][j-1];
			}
		}
	}
}
void binomischeFormeln(int A[][200],int n){
	for(int i = n ; i <= n; i++){
		for(int j = 0; j <= i; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
main () {
	int A[200][200], n;
	cin >> n;
	input(A,n);
	binomischeFormeln(A,n);
}
