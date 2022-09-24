#include <iostream>
#include <cstring>
using namespace std;
struct sinhVien{
	int msv;
	char hoten[50], xeploai;
	float cc, gk, ck, tk;
};
void nhapSinhVien(sinhVien A[], int &n) {
	cout << "Nhap bao nhieu sinh vien: ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "\nSinh vien thu " << i + 1 << " :" << endl;
		cout << " Nhap ma sinh vien: ";
		cin >> A[i].msv;
		cout << " Nhap ho va ten sinh vien: ";
		fflush(stdin); cin.getline(A[i].hoten,50);
		cout << " Nhap diem chuyen can: ";
		cin >> A[i].cc;
		cout << " Nhap diem giua ki: ";
		cin >> A[i].gk;
		cout << " Nhap diem cuoi ki: ";
		cin >> A[i].ck;
	}
	cout << endl;
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

void xuatSinhVien(sinhVien A[], int n) {
//	if(n==0){
//		cout << "Chua nhap thong tin sinh vien!!!";
//		cout << "Vui long nhap thong tin sinh vien truoc khi in!!!";
//		nhapSinhVien(A,n);
//	}
	cout << "\nThong tin sinh vien: " << endl;
	for(int i = 0; i < n; i++) {
		A[i].tk = (0.1 * A[i].cc) + (0.3 * A[i].gk) + (0.6 * A[i].ck);
		A[i].xeploai = xepLoai(A[i].tk);
		cout << " \nSinh vien thu " << i + 1 << " :" << endl;
		cout << " Ma sinh vien: " << A[i].msv <<endl;
		cout << " Ho va ten sinh vien: " << A[i].hoten << endl;
		cout << " Diem tong ket: " << A[i].tk << endl;
		cout << " Xep loai: " << A[i].xeploai << endl;
	}
}

void themSV(sinhVien A[], int &n) {
	cout << " Nhap ma sinh vien: ";
	cin >> A[n].msv;
	cout << " Nhap ho va ten sinh vien: ";
	fflush(stdin); cin.getline(A[n].hoten,50);
	cout << " Nhap diem chuyen can: ";
	cin >> A[n].cc;
	cout << " Nhap diem giua ki: ";
	cin >> A[n].gk;
	cout << " Nhap diem cuoi ki: ";
	cin >> A[n].ck;
	n++;
}

int viTriXoa(sinhVien A[], int n, int x) {
	for(int i = 0; i < n; i ++) {
		if(x == A[i].msv) 
			return i;
	}
}

void xoaSV(sinhVien A[], int &n, int x) {
	cout << "Nhap vao MSV can xoa: ";
	cin >> x;
	int vitri = viTriXoa(A,n,x);
	for(int i = vitri; i < n; i++) {
		A[i] = A[i+1];
	}
	n--;
	cout << "Da xoa thanh cong" << endl;
}

void reset(sinhVien A[], int &n) {
	n = 0;
	system("cls");
	cout << "Reset thanh cong" << endl;
}

int spaceLast(char A[]) {
	for(int i = strlen(A) - 1; i > 0; i--) {
		if(A[i] == ' ')
			return i;
	}
}
int compare(char A[], char B[]) {
	int spacelastA = spaceLast(A);
	int spacelastB = spaceLast(B);
	int lA = strlen(A);
	int lB = strlen(B);
	
	while(spacelastA < lA && spacelastB < lB) {
		if(A[spacelastA] < B[spacelastB]) {
			return -1;
		}else if(A[spacelastA] > B[spacelastB]) {
			return 1;
		}
		spacelastA++;
		spacelastB++;
	}
	if(lA == lB)
		return 0;
	else if (lA > lB)
		return 1;
	else
		return -1;
}

void sapXep(sinhVien A[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(compare(A[i].hoten,A[j].hoten) == 1) {
				sinhVien temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

main() {
	sinhVien A[200];
	int n,x;
	char select;
	while(true) {
		cout <<"-----------CHUONG TRINH QUAN LY SINH VIEN-----------" << endl;
		cout <<" 1.Nhap vao n sinh vien" << endl;
		cout <<" 2.Xuat ra danh sach n sinh vien" << endl;
		cout <<" 3.Sap xep thong tin sinh vien theo ten" << endl;
		cout <<" 4.Reset du lieu" << endl;
		cout <<" 5.Them 1 sinh vien vao cuoi danh sach" << endl;
		cout <<" 6.Xoa 1 sinh vien" << endl;
		cout <<" 7.Thoat" << endl;
		cout <<" Nhap lua chon: ";
		cin >> select;
		system("cls");
		if(select == '1') 
			nhapSinhVien(A,n);
		if(select == '2')
			if(n=0){
			cout << "Chua nhap thong tin sinh vien!!!";
			cout << "Vui long nhap thong tin sinh vien truoc khi in!!!";
			nhapSinhVien(A,n);
			}else
			xuatSinhVien(A,n);
		if(select == '3')
			sapXep(A,n);
			xuatSinhVien(A,n);
		if(select == '4')
			reset(A,n);
		if(select == '5')
			themSV(A,n);
		if(select == '6')
			xoaSV(A,n,x);
		if(select == '7')
			break;
	}
}
