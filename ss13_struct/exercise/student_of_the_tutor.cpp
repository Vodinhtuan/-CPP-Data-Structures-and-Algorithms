#include <iostream>
using namespace std;
struct sinhVien{
	int msv;
	char hoTen[50], xepLoai;
	float cc, gk, ck, tk;
};

float tongKet (float a, float b, float c){
	return a * 0.1 + b * 0.3 + c * 0.6;
}

char xepLoai(float x){
	if(x >= 8.5){
		return 'A';
	}
	if(x >= 7){
		return 'B';
	}
	if(x >= 5.5){
		return 'C';
	}
	if(x >= 4){
		return 'D';
	}
	return 'F';
}

void nhapSinhVien(sinhVien A[], int &n){
	cout << "Nhap vao so luong sinh vien: "; cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Nhap vao ma sinh vien " << i + 1 << ": ";
		cin >> A[i].msv;
		cout << "Nhap vao ho & ten sinh vien " << i + 1 << ": ";
		fflush(stdin); cin.getline(A[i].hoTen,50);
		cout << "Nhap vao diem chuyen can sinh vien " << i + 1 << ": ";
		cin >> A[i].cc;
		cout << "Nhap vao diem giua ky sinh vien " << i + 1 << ": ";
		cin >> A[i].gk;
		cout << "Nhap vao diem cuoi ky sinh vien " << i + 1 << ": ";
		cin >> A[i].ck;
		A[i].tk = tongKet(A[i].cc, A[i].gk, A[i].ck);
		A[i].xepLoai = xepLoai(A[i].tk);
	}	
}

void xuatSinhVien(sinhVien A[], int n){
	for(int i = 0; i < n; i++){
		cout << "\nThong tin sinh vien thu " << i + 1 << ": ";
		cout << "\n\tMa sinh vien: " << A[i].msv;
		cout << "\n\tHo va ten: " << A[i].hoTen;
		cout << "\n\tTong ket: " << A[i].tk;
		cout << "\n\tXep loai: " << A[i].xepLoai;
	}
}

void sapXep(sinhVien A[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i + 1; j<n; j++){
			if(A[i].tk > A[j].tk){
				sinhVien tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}
main(){
	sinhVien A[100]; int n;
	nhapSinhVien(A, n);
	sapXep(A, n);
	xuatSinhVien(A, n);
}
