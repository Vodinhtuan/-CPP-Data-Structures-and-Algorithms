#include <iostream>
using namespace std;
int length(char A[100]){
	int i = 0;
	int count = 0;	
	while (1){
		if(A[i] != '\0'){
			count ++;
		}else{
			return count;
		}
	}
}
void left(char A[100],int &c, int &d){
	cout<<"Left:"<<endl;
	cout<<"Nhap phan tu bat dau lay: "; 
	cin >> c;
	cout<<"Nhap so phan tu can lay: "; 
	cin >> d;
	int n = length(A);
	for(int i =0; i<n; i++){
		if(i>=c && i<=d){
			cout<<A[i];
		}
	}
}
void right(char A[100],int &c, int &d){
	cout<<"Right: "<<endl;
	cout<<"Nhap phan tu bat dau lay: "; 
	cin >> c;
	cout<<"Nhap so phan tu can lay: "; 
	cin >> d;
	int n = length(A);
	for(int i = n-1; i<d; i--){
		
	}
}
void mid(char A[100],int &c, int &d){
	cout<<"Mid: "<<endl;
	cout<<"Nhap phan tu bat dau lay: "; 
	cin >> c;
	cout<<"Nhap so phan tu can lay: "; 
	cin >> d;
	int n = length(A);
	for(int i = c; i<=d; i++){
		
	}
}
main(){
	char A[100];
	cin.get(A,100);
	int c,d;
	cout<<"Length: "<< length(A) << "\n";
	left(A,c,d);
	right(A,c,d);
	mid(A,c,d);
}
