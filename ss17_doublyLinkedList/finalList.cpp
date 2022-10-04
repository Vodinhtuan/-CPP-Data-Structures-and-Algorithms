#include <iostream>
using namespace std;
struct SinhVien {
	int msv;
	char hoten[50];
	float cc, gk, ck, tk;
};

struct Node {
	SinhVien Data;
	Node *Next, *Prev;
};
typedef Node* List;

void insert_first(SinhVien x, List &F, List &L) {
	List p = new(Node);
	p -> Next = p -> Prev = NULL;
	p -> Data = x;
	if(F == NULL) {
		F = L = p;
	}else {
		p -> Next = F;
		F -> Prev = p;
		F = p;
	}
}

void insert_last(SinhVien x, List &F, List &L) {
	List p = new(Node);
	p -> Next = p -> Prev = NULL;
	p -> Data = x;
	if(F == NULL) {
		F = L = p;
	}else {
		L -> Next = p;
		p -> Prev = L;
		L = p;
	}
}

void delete_last(List &F, List &L) {
	List p = L;
	if(F == L) {
		F = L = NULL;
	}else{
		L = L -> Prev;
		L -> Next = NULL;
	}
	delete(p);
}

void delete_first(List &F, List &L) {
	List p = F;
	F = F -> Next;
	F -> Prev = NULL;
	delete p;
}

void input_SV (SinhVien &x) {
	cout << "Ma sinh vien: "; cin >> x.msv;
	cout << "Ho ten sinh vien: "; fflush(stdin) ; cin.getline(x.hoten,50);
	cout << "Nhap diem chuyen can: "; cin >> x.cc;
	cout << "Nhap diem giua ky: "; cin >> x.gk;
	cout << "Nhap diem cuoi ky: "; cin >> x.ck;
	x.tk = (0.1 * x.cc) + (0.3 * x.gk) + (0.6 * x.ck);
}

char xepLoai(float x) {
	if(x >= 8.5)
		return 'A';
	if(x >= 7.0)
		return 'B';
	if(x >= 5.5)
		return 'C';
	if(x >= 4.0)
		return 'D';
	return 'F';
}

int check(List F, List L) {
	List p = F;
	int count = 0;
	while(p) {
		count ++;
		p = p -> Next;
	}
	return count;
}

void search (List F, List L) {
	int x;
	cout << "Nhap msv can tim: "; cin >> x;
	List p = F;
	while(p) {
		if(p -> Data.msv == x) {
			cout << "\nMa sinh vien: " << p -> Data.msv;
			cout << "\nHo ten sinh vien: " << p -> Data.hoten;
			cout << "\nTong ket: " << p -> Data.tk;
			cout << "\nXep Loai: " << xepLoai(p -> Data.tk);
			cout << "\n";
			break;
		}
		p = p -> Next;
	}
}

void print_F(List F, List L) {
	cout << "\nDanh sach sinh vien: ";
	List p = F;
	while(p) {
		cout << "\nMa sinh vien: " << p -> Data.msv;
		cout << "\nHo ten sinh vien: " << p -> Data.hoten;
		cout << "\nTong ket: " << p -> Data.tk;
		cout << "\nXep Loai: " << xepLoai(p -> Data.tk);
		cout << "\n";
		p = p -> Next;
	}
}

void print_L(List F, List L) {
	cout << "\nDanh sach sinh vien: ";
	List p = L;
	while(p) {
		cout << "\nMa sinh vien: " << p -> Data.msv;
		cout << "\nHo ten sinh vien: " << p -> Data.hoten;
		cout << "\nTong ket: " << p -> Data.tk;
		cout << "\nXep Loai: " << xepLoai(p -> Data.tk);
		cout << "\n";
		p = p -> Prev;
	}
}

main() {
	List F,L;
	SinhVien x;
	char select;
	F = L = NULL;
	while(1) {
		cout << "\n-------------------MENU-------------------" << "\n";
		cout << " 1.Them mot sinh vien vao dau danh sach" << "\n";
		cout << " 2.Them mot sinh vien vao cuoi danh sach" << "\n";
		cout << " 3.Xoa mot sinh vien o dau danh sach" << "\n";
		cout << " 4.Xoa mot sinh vien o cuoi danh sach" << "\n";
		cout << " 5.Kiem tra danh sach co bao nhieu sinh vien" << "\n";
		cout << " 6.Tim kiem sinh vien" << "\n";
		cout << " 7.In ra danh sach sinh vien tu dau den cuoi" << "\n";
		cout << " 8.In ra danh sach sinh vien tu cuoi ve dau" << "\n";
		cout << " 9.Thoat" << "\n";
		cout << "Nhap lua chon: "; cin >> select;
		system("cls");
		if(select == '1') {
			input_SV(x);
			insert_first(x,F,L);
		}
		if(select == '2') {
			input_SV(x);
			insert_last(x,F,L);
		}
		if(select == '3') {
			delete_first(F,L);
		}
		if(select == '4') {
			delete_last(F,L);	
		}
		if(select == '5') {
			cout << "Trong danh sach co: " << check(F,L) << " sinh vien\n";
		}
		if(select == '6') {
			search(F,L);
		}
		if(select == '7') {
			print_F(F,L);
		}
		if(select == '8') {
			print_L(F,L);
		}
		if(select == '9') {
			break;
		}
	}
}
