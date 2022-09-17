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

int sumString(char A[]) {
	int sum = 0;
	for(int i = 0; i < length(A); i++){
		sum += int(A[i]);
	}
	return sum;
}

int compare(char A[], char B[]) {
	int result = 0;
	if(sumString(A) > sumString(B)){
		result = 1;
	}else if (sumString(A) < sumString(B)) {
		result = -1;
	}else{
		result = 0;
	}
	return result;
}

main(){
	char A[200], B[200];
	cin.getline(A,200);
	cin.getline(B,200);
	cout << compare(A,B);
}
