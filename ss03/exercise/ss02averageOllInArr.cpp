#include <iostream>
using namespace std;

// Average of odd numbers in array

int inputArr(int arr[],int &n)
{
	cout<<"Enter the array length: ";
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"arr["<<i<<"]= ";
		cin>>arr[i];
	}
}

void average(int arr[],int n){
	int avg = 0;
	for(int i=0; i< n; i++){
		if( arr[i]%2 != 0){
		avg+= arr[i];
		}
	}
	cout << "Average of odd numbers in array: " << avg/n;
}

int output(int arr[],int n){
	cout << "Your array is: "<< endl; 
	for(int i=0; i<n; i++){
		cout << arr[i] << endl;
	}
}
main()
{
	int arr[10], n;
	inputArr(arr, n);
	output(arr,n);
	average(arr,n);
}
