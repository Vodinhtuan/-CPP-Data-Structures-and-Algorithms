//cau 2 : 
#include <iostream>
using namespace std;

void  aVg(int a[], int n){
	int avg = 0;
	
	for(int i=0; i< n; i++){
		if(a[i]%2!=0){
		avg+=a[i];
		}
	}
	cout << avg/n;
}
main(){
	
	int a[5] = {1, 7, 2, 3, 5};
	int n = 5;
	aVg(a,n);
}
