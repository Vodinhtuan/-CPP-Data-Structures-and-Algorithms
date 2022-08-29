#include<iostream>
using namespace std;
int n;
void inPut(){
	cout << "Enter the number: ";
	cin >> n;
}
int sumEven(int n){
	if(n==1)
	return 1;
	else if (n%2==0)
	return (n + (sumEven(n-1)));
}
void outPut(){
	cout << "Result: ";
	sumEven()
}

