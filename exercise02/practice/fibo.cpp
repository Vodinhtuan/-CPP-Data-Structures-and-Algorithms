#include <iostream>
using namespace std;
int fibonaci(int n){
	if(n==0)
	return n;
	else
	return (fibonaci(n-1) + fibonaci(n-2));
}
main(){
	fibonaci(5);
	}
