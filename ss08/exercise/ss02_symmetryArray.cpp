#include <iostream>
using namespace std;
int inputArr(int arr[],int &n)
{
	cout<<"Enter the array length: ";
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"arr["<<i<<"]= ";
		cin>>arr[i];
	}
}
bool checkSymmetryArr(int n, int A[]){
    for(int i = 0;i < n/2;i++){
        if(A[i] != A[n-i-1]) {
        	return false;
		} 
    }
    return true; 
}
int output(int arr[],int n){
	cout << "Your array is: "<< endl; 
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}
main(){
    int Arr[30], n;
    inputArr(Arr,n);
    output(Arr,n);
    if(checkSymmetryArr(n, Arr)){
    	cout<<"\n\n =>Your array is symmetry";
	}else {
		cout<<"\n\n =>Your array not symmetry";
	}
}
