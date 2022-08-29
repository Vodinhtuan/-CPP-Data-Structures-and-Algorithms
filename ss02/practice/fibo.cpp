#include <iostream>
using namespace std;
int fibonaci(int n){
	if(n<=1)
	return 1;
	else
	return (fibonaci(n-1) + fibonaci(n-2));
}
main(){
	cout << fibonaci(10);
		}
