#include <iostream>
using namespace std;
struct Node {
	int Data;
	Node *Next;
};
typedef Node* List;

void firstIsert(int x, List &F) {
	List p = new(Node);
	p->Data = x;
	p->Next = F;
	F = p;
}
void lastInsert(int x, List &F) {
	List p = new(Node);
	p->Data = x;
	p->Next = NULL;
	if(F == NULL) {
		F = p;
	} else {
		List q = F;
		while(q->Next) {
			q = q->Next;
		}
		q->Next = p;
	}
}
void centerInsert(int x, List &F) {
	List p = new(Node);
	if(F == NULL) {
		F = p;
	}else {
		p->Data = x;
		p->Next = ;
	}
}

void print(List F) {
	cout << "\nDanh Sach: ";
	List p = F;
	while(p) {
		cout << p->Data << " ";
		p = p->Next;
	}
	cout << endl;
}
void input(List &F) {
	F = NULL;
	int x;
	while(1) {
		cout << "Nhap vao gia tri: "; cin >> x;
		if(x == 0) { 
			break;
		} else if(x < 50){
			insert_first(x, F);
		} else if(x > 100){
			insert_last(x, F);
		}else{
			insert_center(x, F);
		}
	}
}
void removeIndex(int x, List &F){
	
}
main() {
	List First;
	input(First);
	print(First);
	int s;
	while(1){
		cout << "--- CHUONG TRINH XXX ---" << endl;
		cout << "1.In ra danh sach." << endl;
		cout << "2.Xoa gia tri khoi danh sach." << endl;
		cout << "3. Sap xep danh sach tang dan." << endl;
		cout << "\t Nhap vao phim chuc nang: "; cin >> s;
		system("cls");
		if(s == 1){
			print(First);
		}else if (s == 2){
			removeIndex(int x, First);
		}else if (s == 3){
			
		}else{
			cout << "Nhap sai phim chuc nang!!!\n";
			cout << "Moi ban nhap lai!!!";
		} 
	}
}



