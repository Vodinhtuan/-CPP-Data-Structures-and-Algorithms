#include <iostream>
using namespace std;
/* Cho mot mang a gom n phan tu da duoc sap xep tang dan. Saud nhap vao 1 so nguyen 'k' hay chen 'k' vao mang sau cho 
   mang A van duoc sap xep tang dan? 
   arr[] = {1, 3, 7, 9, 10};
   int k = 2;
   ==> arr[] = {1, 2, 3, 7, 9, 10};
*/

void inputArr(int arr[], int &n){
	cout << "Enter the array length: " ;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cout << "array[" << i<< "]= ";
		cin >> arr[i];
	} 
}
int findLocation(int arr[], int n, int k){
	if(k < arr[0]){
		return 0;
	}else if(k > arr[n-1]){
		return n;
	}
	for(int i = 0; i < n; i++){
		if(arr[i] >= k){
			cout << "Location at: " << i << endl;
			return i;
		}
	}
}                      // x == position 
void insert(int arr[], int n, int x, int k){
	for(int i = n-1; i > x; i--){
		arr[i] = arr[i - 1];
	}
	arr[x] = k;
}
void bubbleSort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j>i; j--){
			if(arr[j] < arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
void output(int arr[], int n){
	cout << "Your array is: " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << "\t";
	} 
}
main(){
	int arr[30], n;
	inputArr(arr, n);
	bubbleSort(arr, n-1);
	int k;
	cout << "Enter k: "; 
	cin >> k;
	int p = findLocation(arr,n-1, k);
	insert(arr, n, p, k);
	output(arr,n);
	return 0;
}
