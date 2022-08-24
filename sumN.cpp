#include <iostream>

using namespace std;
 int n;
void nhap(){
	cout << "Nhap n: ";
	cin >> n;
}
int sum1ToN(int n){
		if(n==1)
		return 1;
		else return (n+ sum1ToN(n-1));
	}
void ketQua(){
	cout << "Ket qua: " << sum1ToN(n);
}
	
main(){
	nhap();
	ketQua();
} 


	
