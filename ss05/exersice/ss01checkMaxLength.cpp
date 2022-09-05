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
void findMaxLength(int arr[], int n)
{
    int Length = 1;
    int max = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            Length++; 						
            if (Length > max){					
                max = Length;
            }

        }else{
            Length = 1; 
		}						
    }
   	cout << "So phan tu cua doan tang dai nhat là: " << max << endl;
}
main(){
	int arr[30], n;
	inputArr(arr,n);
	findMaxLength(arr,n);
	
}
