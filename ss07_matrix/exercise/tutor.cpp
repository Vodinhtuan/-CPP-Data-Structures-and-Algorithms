#include <iostream>
using namespace std;
void handle(int A[50][50], int n){
	int d = n/2, c = n/2 +1;
	for(int i = 1; i<n*n; i++){
		if((i-1)% n ==0 && i> i){
			d++; c++;
		}
		if(c>=n){
			c=c-n;
		}
		if(d<0){
			d = d+n;
		}
		A[d][c] = i;
		d--; c++;
	}
}
main{
}
