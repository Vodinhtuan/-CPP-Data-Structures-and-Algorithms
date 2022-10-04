#include <iostream>
using namespace std;
struct Node {
	int Data;
	Node *Next, *Prev;
};
typedef Node* List;

void insert_first(int x, List &F, List &L) {
	List p = new(Node);
	p->Next = p->Prev = NULL;
	p->Data = x;
	if(F = NULL) {
		F = L = p;
	} else {
		p->Next = F;
		F->Prev = p;
		F = p;
	}
}

void insert_last(int x, List &F, List &L) {
	List p = new(Node);
	p->Next = p->Prev = NULL;
	if(F = NULL) {
		F = L = p;
	} else {
		L->Next = p;
		p->Prev = L;
		L = p;
	}
}
void print_F(List F) {
	cout << "\nDanh Sach: ";
	List p = F;
	while(p) {
		cout << p->Data << " ";
		p = p->Next;
	}
}
void print_L(List L) {
	cout << "\nDanh Sach: ";
	List p = L;
	while(p) {
		cout << p->Data << " ";
		p = p->Prev;
	}
}
void delete_last(List &F, List &L) {
	List p = L;
	if(F == L) {
		F = L = NULL;
	} else {
		L = p->Prev; // L->Prev
		L->Next = NULL;
	}
	delete(p);
}
void input(List &F) {
	F = NULL;
	int x;
	while(1) {
		cout << "Nhap vao gia tri: "; cin >> x;
		if(x == 0) { 
			break;
		} else if(x % 2 == 0) {
			insert_first(x, F);
		} else {
			insert_last(x, F);
		}
	}
}
main() {
	List First;
	input(First);
	print(First);
}



