#include<iostream>

using namespace std;

int ucln(int a, int b){
    if (a == 0 || b==0) 
	return a>b?a,b;
	
    if (a % b == 0) 
	return b;
	else
    return ucln(b, a%b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << ucln(a, b);
}
