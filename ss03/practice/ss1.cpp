//cau 1 : 
#include <iostream>
using namespace std;

void (int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
int  check(int a[], int n){
	for(int i=0; i< n; i++){
		if(a[i]==n){
			return 1;
		}else{
			return 0;
		}
	}
}
main(){
	int a[5] = {1, 7, 2, 3, 5};
	int k = 4;
	cout<<check(a,k);
}
