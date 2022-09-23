#include <iostream>
using namespace std;
int len(char A[]){
	int i = 0;
	while(1){
		if(A[i] == '\0'){
			return i;
		}
		i++;
	}
}

void xuatChuoi(char A[]){
	for(int i=0; i<len(A); i++){
		cout << A[i];
	}
	cout <<endl;
}

void maHoa(char A[], int k){
	for(int i = 0; i<len(A); i++){
		if(A[i] >= 65 && A[i]<= 90){
			int x = int(A[i]) + k % 26;
			if(x>90){
				x = x - 26;
			}
			A[i] = (char) x;
		}
		if(A[i] >= 97 && A[i] <= 122){
			int x = int(A[i]) + k % 26;
			if(x>122){
				x = x - 26;
			}
			A[i] = (char) x;
		}
	}
}

void giaiMa(char A[], int k){
	for(int i = 0; i < len(A); i++){
		if(A[i] >= 65 && A[i] <= 90){
			int x = int(A[i]) - k % 26;
			if(x < 65){
				x = x + 26;
			}
			A[i] = (char) x;
		}
		if(A[i] >= 97 && A[i] <= 122){
			int x = int(A[i]) - k % 26;
			if(x < 97){
				x = x + 26;
			}
			A[i] = (char) x;
		}
	}
}

main(){
	char A[50], s; int k;
	while(1){
		cout << "---------- CHUONG TRINH XXX ---------- \n";
		cout << "1. Ma hoa\n";
		cout << "2. Giai ma\n";
		cout << "3. Nen Chuoi\n";
		cout << "4. Thoat\n";
		cout << "--- Nhap vao phim chuc nang: "; cin >> s;
		system("cls"); // xoa cac du lieu cu tren man hinh;
		if(s == '1'){
			cout << "Nhap Chuoi: "; 
			fflush(stdin);
			cin.getline(A, 50);
			cout << "Nhap K: "; cin >> k;
			maHoa(A, k);
			xuatChuoi(A);
		}else if( s == '2'){
			cout << "Nhap Chuoi: ";
			fflush(stdin);
			cin.getline(A, 50);
			cout << "Nhap K: "; cin >> k;
			giaiMa(A, k);
			xuatChuoi(A);
		}else if( s == '3'){
			cout << " ";
		}else if( s == '4'){
			break;
		}else{
			cout << "Nhap sai phim chuc nang!!!\n";
			cout << "Moi ban nhap lai!!!";
		}
	}
}

