#include <iostream>
using namespace std;	
void inputA(int A[], int &n){
	do{
	cout<<"Enter the array length A: ";
	cin >> n;
	}while(n<=0);	
	for(int i = 0; i<n; i++){
		cin >> A[i];
	}
}
void inputB(int B[], int &m,int n){
	do{
	cout<<"Enter the array length B: ";
	cin >> m;
	}while(m<=0 || m>=n);
	for(int i = 0; i<m; i++){
		cin >> B[i];
	}
}

bool isSubArray(int A[], int B[], int n, int m){
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;
            if (j == m)
                return true;
        }
        else {
            i = i - j + 1; 		// i++
            j = 0;				// start
        }
    }
    return false;
}

main(){
	int A[200],B[200] ,n ,m;
	inputA(A,n);
	inputB(B,m,n);
	if (isSubArray(A, B, n, m))
        cout << "YES\n";
    else
        cout << "NO\n";
 
    return 0;
}
