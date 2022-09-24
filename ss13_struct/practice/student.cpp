#include <iostream>
using namespace std;
struct sinhVien{
	int msv;
	char hoTen[50];
	float CC, GK, CK;
};
void nhapSV(sinhVien A[100], int &n){
	cout << "Nhap vao so luong sinh vien: "; cin >> n;
	for(int i = 0; i<n; i++){
		cout << "Nhap ma sinh vien thu " << i+1 << ": ";
		fflush(stdin); cin>>(A[i].msv);
		cout << "Nhap ho ten sinh vien: ";
		fflush(stdin); cin.getline(A[i].hoTen,50);
		cout<< "Nhap vao diem chuyen can: ";
		cin >> A[i].CC;
		cout << "Nhap vao diem giua ky: ";
		cin >> A[i].GK;
		cout << "Nhap vao diem cuoi ky: ";
		cin >> A[i].CK;
	}
}
void xuatThongTin(sinhVien A[100], int n){
	float tongKet ;
	char xepLoai;
	cout << "Danh sach nay co: " << n << " sinh vien!\n";
	for(int i = 0; i<n; i++){
		cout << "Ma sinh vien thu " << i+1 << ": ";
		cout<<(A[i].msv)  << endl;
		cout << "Ho ten sinh vien: ";
		cout<< (A[i].hoTen) << endl;
		cout<< "Diem chuyen can: ";
		cout <<  A[i].CC << endl;
		cout << "Diem giua ky: ";
		cout <<  A[i].GK << endl;
		cout << "Diem cuoi ky: ";
		cout <<  A[i].CK << endl;
		cout << "Diem tong ket: ";
		tongKet = (((A[i].CC)+10)/100) + (((A[i].GK)+30)/100) + (((A[i].CK)+60)/100) ;
		cout << tongKet;
		cout << "Xep loai: ";
		if
	}
}
float diemTongKet(sinhVien A[100], int n){
	for(int i = 0; i<n; i++)
	return (((A[i].CC)+10)/100) + (((A[i].GK)+30)/100) + (((A[i].CK)+60)/100);
}
char xepLoai(sinhVien A[100], int n){
	if(diemTongKet)
}
main(){
	sinhVien A[100];
	int n;
	nhapSV(A, n);
	xuatThongTin(A, n);
}
// Not the tutor's
