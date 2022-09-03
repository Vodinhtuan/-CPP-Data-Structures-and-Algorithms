#include <iostream>
using namespace std;
void nhapMang(int A[], int &n){
	cout << "Moi ban nhap so phan tu: "; cin >> n;
	for(int i = 0; i<n; i++){
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> A[i];
	}
}

int timViTriChen(int A[], int &n, int k){
	for(int i = 0; i < n; i++){
		if(A[i] > k){
			return i;
		}
	}
	return n;
}
void chenMang(int A[], int n, int k){
	int viTri = timViTriChen(A, n, k); 
	for(int i = n; i> viTri; i--){
		A[i] = A[i-1];
	}
	A[viTri] = k;
	n++;
}
void xuatMang(int A[], int n){
	for(int i = 0; i<n; i++){
		cout << "\n\t- Phan tu: " << i + 1<< ": " << A[i];
	} 
}
main(){
	int A[2000], n, k;
	nhapMang(A, n);
	cout << "Nhap vao so K: "; cin >> k;
	chenMang(A, n, k);
	xuatMang(A, n);
	
}
