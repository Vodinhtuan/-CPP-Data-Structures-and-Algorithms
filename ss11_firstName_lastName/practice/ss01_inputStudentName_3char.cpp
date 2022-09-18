#include <iostream>
using namespace std;
int length(char A[]){
	int i = 0;
	while(true){
		if(A[i]=='\0'){
			return i;
		}
		i++;
	}
}
void lastName(char A[]){
	int tempL = 0;
	for(int i=0; i<length(A); i++){
		if(A[i]==' '){
			A[i]='\0';
		}
		tempL = i;
		cout<<A[i];
	}
}
int firstSpace(char A[]){
	int fS = 0;
	for(int i=0; i<length(A); i++){
		if(A[i]==' '){
			return i;
		}
	}
}
int lastSpace(char A[]){
	for(int i = length(A)-1; i>=0; i--){
		if(A[i] == ' '){
			return i;
		}
	}
}
void firstName(char A[]){
	
}
//void mid(char A[]){
//	for(int i=0; i<le)
//}

main(){
	char A[200];
	cin.getline(A,200);
	cout << length(A)<<endl;
	cout << lastSpace<< endl;
	
//	cout << "Lastname is: " ;
//	lastName(A);
//	cout << endl;
//	cout << lastSpace(A);
	//cout << "Firstname is: ";
	//firstName(A);
	return 0;
}
