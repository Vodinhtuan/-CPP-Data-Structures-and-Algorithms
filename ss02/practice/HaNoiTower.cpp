// Ha Noi tower
#include <iostream>
void haNoi(int n, char a, char b, char c){
	if(int==1){
		cout<<"\n Chuyen dia tu "<<a<<" qua "<< c;
	}
	else {
		haNoi(n-1, a, c, b);
		haNoi(1, a, b, c);
		haNoi(n-1, b, a, c);
	}
}
main(){
	int n; cin>>n;
	haNoi(n, "A", "B", "C");
}
