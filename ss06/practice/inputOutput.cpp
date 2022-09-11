#include <iostream>
using namespace std;
void inputArr(int arr[50][50], int &row, int &column){
	cout << "Enter the array row: " ; 
	cin >> row;
	cout << "Enter the array column: " ; 
	cin >> column;
	for(int i = 0;i<row;i++){
		for(int j = 0; j<column;i++){
			cin>>arr[i][j];
		}
		cout<<endl;
	}
	
}
void outPut(int arr[50][50], int row, int column){
	for(int i = 0;i<row;i++){
		for(int j = 0; j<column;i++){
			cout << arr[i][j] <<" ";
		}
		cout<<endl;
	}
}
main(){
	int a[50][50], row, column;
	inputArr(a, row, column);
	outPut(a, row, column);
}
