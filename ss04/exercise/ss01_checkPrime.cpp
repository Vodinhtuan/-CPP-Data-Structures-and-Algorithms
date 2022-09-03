#include <iostream>
using namespace std;
void inputArr(int arr[], int &n){
	cout << "Enter the array length: " ;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cout << "array[" << i<< "]= ";
		cin >> arr[i];
	} 
}
int checkPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {  
			return false;
		}
	}
	return true;
}
void output(int arr[], int n){
	cout << "Prime numbers in the array: " << endl;
	for(int i = 0; i < n; i++){
		if (checkPrime(arr[i])) {
			cout << arr[i] << " ";
		}
	} 
}
main(){
	int arr[100], n;
	inputArr(arr,n);
	output(arr,n);
}
