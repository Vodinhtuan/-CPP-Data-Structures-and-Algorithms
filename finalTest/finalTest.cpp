#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct SinhVien {
	int msv;
	char hoten[50], xeploai;
	float th, lt, tb;
};

struct Node {
	SinhVien Data;
	Node *Next;
};
typedef Node* List;

void insert_last(SinhVien x, List &SV) {
	List p = new(Node);
	p -> Data = x;
	p -> Next = NULL;
	if(SV == NULL) {
		SV = p;
	}else {
		List q = SV;
		while(q -> Next) {
			q = q -> Next;
		}
		q -> Next = p;
	}
}

void input_SV (SinhVien &x, List SV) {
	List p = SV;
	cout << "Ma sinh vien: "; cin >> x.msv;
	while(p) {
		if(x.msv == p -> Data.msv) {
			cout << "MSV da ton tai!" << "\n";
			cout << "Ma sinh vien: "; cin >> x.msv;
			p = SV;
		}else
			p = p -> Next;
	}
	cout << "Ho ten sinh vien: "; fflush(stdin) ; cin.getline(x.hoten,50);
	while(true) {
		cout << "Nhap diem ly thuyet: "; cin >> x.lt;
		if(x.lt >= 0 && x.lt <= 10) 
			break;
		else 
			cout << "Vui long nhap lai!" << "\n";
	}
	while(true) {
		cout << "Nhap diem thuc hanh: "; cin >> x.th;
		if(x.th >= 0 && x.th <= 10) 
			break;
		else 
			cout << "Vui long nhap lai!" << "\n";
	}
	x.tb = (x.lt + (x.th * 2))/ 3;
}

char xepLoai(float x) {
	if(x >= 8.0)
		return 'G';
	else if(x >= 7.0)
		return 'K';
	else if(x >= 5.0)
		return 'T';
	else if(x < 5) 
		return 'Y';
}

void xuatSinhVien(List SV) {
	ofstream output("danhsach.dat");
	cout << "\nThong tin sinh vien: ";
	List p = SV;
	while(p) {
		output << "\n";
		output << "Ma sinh vien: " << p -> Data.msv;
		output << "\nHo ten sinh vien: " << p -> Data.hoten;
		output << "\nDiem ly thuyet: " << p -> Data.lt;
		output << "\nDiem thuc hanh: " << p -> Data.th;
		output << "\nDiem trung binh: " << p -> Data.tb;
		output << "\nXep loai: " << xepLoai(p -> Data.tb);
		output << "\n";
		p = p -> Next;
	}
}

void delete_last(List &SV) {
	List x = SV, y;
	while(x -> Next){
		y = x;
		x = x -> Next;
	}
	y -> Next =  NULL;
	delete x;
}

void delete_first(List &SV) {
	List p = SV;
	SV = SV -> Next;
	delete p;
}

void delete_x(List &SV) {		// xoa theo ten 
	List p = SV;
	char x[50];
	while(p -> Next) {
		p = p -> Next;
	}
	cout << "Nhap ho ten SV can xoa: "; fflush(stdin); cin.getline(x,50);
	int check = 0;
	List c = SV;
	while(c) {
		if(strcmp(c -> Data.hoten,x) == 0) {
			check++;
			cout << "Ma sinh vien: " << c -> Data.msv;
			cout << "\nHo ten sinh vien: " << c -> Data.hoten;
			cout << "\n";
		}
		c = c -> Next;
	}
	
	if(check == 1) {
		if(strcmp(SV -> Data.hoten,x) == 0)
			delete_first(SV);
		else if(strcmp(p -> Data.hoten,x) == 0)
			delete_last(SV);
		else{
			List p = SV;
			List q = new(Node);
			while(p) {
				if(strcmp(p -> Data.hoten,x) == 0) {
					q -> Next = p -> Next;
					delete p;
				}
				q = p;
				p = p -> Next;
			}
		}
		cout << "Da xoa thanh cong!";
	}else if (check > 1){
		int k;
		cout << "\nTen SV trung nhau!!!";
		cout << "\nNhap ma sinh vien can xoa: "; cin >> k;
		if(SV -> Data.msv == k)
			delete_first(SV);
		else if(p -> Data.msv == k)
			delete_last(SV);
		else{
			List p = SV;
			List q = new(Node);
			while(p) {
				if(p -> Data.msv == k) {
					q -> Next = p -> Next;
					delete p;
				}
				q = p;
				p = p -> Next;
			}
		}
		cout << "Da xoa thanh cong!";
	}else 
		cout << "Khong tim thay";
}

int spaceLast(char x[]) {
	for(int i = strlen(x) - 1; i > 0 ; i--) {
		if(x[i] == ' ')
			return i;
	}
}

void sapXep(List SV) { 		// sap xep theo ten 
	List p = SV;
	for(List i = p; i != NULL; i = i -> Next) {
		for(List j = i -> Next ; j != NULL; j = j -> Next) {
			char ten1[50],ten2[50];
			int a = 0, b = 0;
			for(int q = spaceLast(i -> Data.hoten) + 1, k = spaceLast(j -> Data.hoten) + 1; q < strlen(i -> Data.hoten), k < strlen(j -> Data.hoten); q++, k++) {
				ten1[a] = i -> Data.hoten[q];
				ten2[b] = j -> Data.hoten[k];
				a++;
				b++;
			}
			if(strcmp(ten1,ten2) == 1) {
				swap(i -> Data.hoten ,j -> Data.hoten);
				swap(i -> Data.msv ,j -> Data.msv);
				swap(i -> Data.lt ,j -> Data.lt);
				swap(i -> Data.th ,j -> Data.th);
				swap(i -> Data.tb ,j -> Data.tb);
			}
		}
	}
}

main() {
	List SV = NULL;
	SinhVien x;
	char select;
	while(true) {
		cout <<"\n-----------CHUONG TRINH QUAN LY SINH VIEN-----------";
		cout <<"\n 1.Nhap sinh vien";
		cout <<"\n 2.Xoa 1 sinh vien";
		cout <<"\n 3.Sap xep thong tin sinh vien theo ten va xuat file";
		cout <<"\n 0.Thoat";
		cout <<"\n Nhap lua chon: ";
		cin >> select;
		system("cls");
		if(select == '1') {
			input_SV(x,SV);
			insert_last(x,SV);
		} 
		if(select == '2') {
			delete_x(SV);
		}
		if(select == '3') {
			sapXep(SV);
			xuatSinhVien(SV);
		}
		if(select == '0')
			break;
	}
}
