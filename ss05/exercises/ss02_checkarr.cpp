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
void findMaxLenght(int arr[], int n){
    int Length = 1;
    int max = 1;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n ; i++){
        if (arr[i] < arr[i + 1]){
            Length++; 							
            if (Length > max){					
                max = Length;
                start = i + 2 - Length; 		//0
                end = i + 2;					//0
            }

        }else{
            Length = 1; 
		}						
    } 								
   	cout << "So phan tu cua doan tang dai nhat là: " << max << endl;
    for (int i = start; i < end; i++)
        cout << arr[i] << " ";
}
main(){
	int arr[50], n;
	inputArr(arr,n);
	findMaxLenght(arr,n);
	
}
