#include <iostream>
using namespace std;
struct Node {
	int Data;
	Node *Next;
};
typedef Node* List;

void insert_first(int x, List &F) {
	List p = new(Node);
	p->Data = x;
	p->Next = F;
	F = p;
}

void insert_last(int x, List &F) {
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
void print(List F) {
	cout << "\nDanh Sach: ";
	List p = F;
	while(p) {
		cout << p->Data << " ";
		p = p->Next;
	}
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



