//demo tham tri và tham chieu
#include <iostream>
using namespace std;
voi ez(int a, int &b){
	a= a+5;
	b = b+10;
	cout << a;
	cout<< b;
}
main(){
	int a,b; cin>> a>> b;
	ez(a,b)
	cout << "a in main: "<<a;
	cout<< "b in main: "<<b;
}
