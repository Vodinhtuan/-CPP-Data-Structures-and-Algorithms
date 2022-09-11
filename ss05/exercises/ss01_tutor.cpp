#include <iostream>
using namespace std;
void inputArr(int arr[], int &n){
	cout << "Enter the array length: " ;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "array[" << i<< "]= ";
		cin >> arr[i];
	} 
}
int dayTangDanToiDa(int A[], int n){
	int ht = 1, smax = 1;
	for(int i = 1; i<n; i++){
		if(A[i] > A[i - 1]){
			ht++; smax = max(ht, smax);
		}else{
			ht = 1;
		}
	}
	return smax;
}
main(){
	int A[100], n;
	inputArr(A, n);
	cout << dayTangDanToiDa(A,n);
}
