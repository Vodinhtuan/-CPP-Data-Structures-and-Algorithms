#include <iostream>
using namespace std;

// k = 4 ; Ki?m tra k có trong m?ng hay không?

int inputArr(int a[],int &n)
{
	cout<<"Enter the array length: ";
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}

void check(int arr[], int k){
	for(int i=0; i< n; i++){
		if(arr[i]==k){
			cout<<"Yes!";
			break;
		}else{
			cout<<"No!";
			break;
		}
	}
}
int output(int arr[],int n){
	cout << "Your array is: "<<endl; 
	for(int i=0;i<n;i++){
		cout << arr[i] << endl;
	}
}
main()
{
	int arr[10], n, k=4;
	inputArr(arr,n);
	output(arr,n);
	check(arr,k);
}

