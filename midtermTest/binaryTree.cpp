#include <iostream>
#include <fstream>
using namespace std;
struct Node {
	int Data;
	Node *Left, *Right;
};
typedef Node* Tree;

void them(int x, Tree &t) {
	Tree p = new(Node);
	p -> Left = p -> Right = NULL;
	p -> Data = x;
	if(t == NULL) {
		t = p;
	}else{
		if(x < t -> Data) {
			them(x,t -> Left);
		}else if(x > t -> Data) {
			them(x,t -> Right);
		}
	}
}

void duyet_NLR(Tree t) {    // Tien tu
	if(t != NULL) {
		cout << t -> Data << " ";
		duyet_NLR(t -> Left);
		duyet_NLR(t -> Right);
	}
}

void duyet_NRL(Tree t) {	//	
	if(t != NULL) {
		cout << t -> Data << " ";
		duyet_NRL(t -> Right);
		duyet_NRL(t -> Left);
	}
}

void duyet_LNR(Tree t) {	// Trung tu
	if(t != NULL) {
		duyet_LNR(t -> Left);
		cout << t -> Data << " ";
		duyet_LNR(t -> Right);
	}
}
 
void duyet_RNL(Tree t) {
	if(t != NULL) {
		duyet_RNL(t -> Right);
		cout << t -> Data << " ";
		duyet_RNL(t -> Left);
	}
}

void duyet_RLN(Tree t) {
	if(t != NULL) {
		duyet_RLN(t -> Right);
		duyet_RLN(t -> Left);
		cout << t -> Data << " ";
	}
}

void duyet_LRN(Tree t) {  	// Hau tu
	if(t != NULL) {
		duyet_LRN(t -> Left);
		duyet_LRN(t -> Right);
		cout << t -> Data << " ";
	}
}

void xuatNodeHaiCon(Tree t) {
	if(t != NULL) {
		if(t -> Left != NULL && t -> Right != NULL) {
			cout << t -> Data << " ";
		}
		xuatNodeHaiCon(t -> Left);
		xuatNodeHaiCon(t -> Right);
	}
}

void xuatNodeMotCon(Tree t) {
	if(t != NULL) {
		if((t -> Left == NULL && t -> Right != NULL) || (t -> Left != NULL && t -> Right == NULL)) {
			cout << t -> Data << " ";
		}
		xuatNodeMotCon(t -> Left);
		xuatNodeMotCon(t -> Right);
	}
}

void xuatNodeLa(Tree t) {
	if(t != NULL) {
		if(t -> Left == NULL && t -> Right == NULL) {
			cout << t -> Data << " ";
		}
		xuatNodeLa(t -> Left);
		xuatNodeLa(t -> Right);
	}
}

int max_NODE(Tree t) {
	while(t -> Right != NULL)
		t = t -> Right;
	return t -> Data;
}

int min_NODE(Tree t) {
	while(t -> Left != NULL)
		t = t -> Left;
	return t -> Data;
}

void DiTimNodeTheMang(Tree &p, Tree &q) {
	if(q -> Left != NULL) 
		DiTimNodeTheMang(p,q -> Left);
	else {
		p -> Data = q -> Data;
		p = q;
		q = q -> Right;
	}
//	if(q -> Right != NULL) 
//		DiTimNodeTheMang(p,q -> Right);
//	else {
//		p -> Data = q -> Data;
//		p = q;
//		q = q -> Left;
//	}
}

void xoaMotNode(int x, Tree &t) {
	if(t != NULL) {
		if(x > t -> Data)
			xoaMotNode(x,t -> Right);
		if(x < t -> Data)
			xoaMotNode(x,t -> Left);
		if(x == t -> Data) {
			Tree p = new(Node);
			p = t;
			if(t -> Left == NULL)
				t = t -> Right;
			else if(t -> Right == NULL)
				t = t -> Left;
			else{
				// C1: di tim NODE trai nhat cua cay con phai 
				DiTimNodeTheMang(p,t -> Right);
				// C2 : di tim NODE phai nhat cua cay con trai
//				DiTimNodeTheMang(p,t -> Left);
			}
			delete p;
		}
	}
}

int kiemTraPT(int &count, Tree t) {
	if(t != NULL) {
		count ++;
		kiemTraPT(count, t -> Left);
		kiemTraPT(count, t -> Right);
	}
	return count;
}

int search(int x, Tree t) {
	while(t != NULL) {
		if(x == t -> Data) 
			return true;
		else{
			if(x < t -> Data) 
				t = t -> Left;
			else
				t = t -> Right;
		}
	}
	return false;
}	

int height_tree(Tree t) {
	if(t == NULL || (t -> Left == NULL && t -> Right == NULL))
		return 0;
	else {
		int leftHeight = height_tree(t -> Left);
		int rightHeight = height_tree(t -> Right);
		return max(leftHeight,rightHeight) + 1;
	}
}

void xoa(Tree &t) {
	if(t != NULL) {
		xoa(t -> Left);
		xoa(t -> Right);
		t = NULL;
		delete(t);
	}
}

void xoaNhanh(int x,Tree &t) {
	if(t != NULL) {
		if(x > t -> Data)
			xoaNhanh(x,t -> Right);
		if(x < t -> Data)
			xoaNhanh(x,t -> Left);
		if(x == t -> Data) {
			Tree p = t;
			xoa(p);
			t = p;
		}
	}
}

main() {
	Tree t;
	char select;
	int x;
	t = NULL;
	ifstream input("input.txt");
	while(true) {
		cout << "\n------------------MENU------------------";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Chon cach duyet cay";
		cout << "\n3. Xuat cac Node (hai con, mot con, la') trong cay";
		cout << "\n4. Xoa mot NODE trong cay";
		cout << "\n5. Xoa mot nhanh trong cay";
		cout << "\n6. Dem so phan tu trong cay";
		cout << "\n7. Tim gia tri MAX - MIN trong cay";
		cout << "\n8. Tim gia tri trong cay";
		cout << "\n9. Kiem tra do cao cua cay";
		cout << "\n0. Thoat";
		cout << "\nNhap lua chon: "; cin >> select;
		system("cls");
		if(select == '1') {
			while(1) {
				input >> x;
				if(x == 0)
					break;
				them(x,t);
			}
		}
		
		if(select == '2') {
			system("cls");
			while(true) {
				char select2;
				cout << "\n------------------MENU------------------";
				cout << "\n1. Duyet cay theo NLR";
				cout << "\n2. Duyet cay theo NRL";
				cout << "\n3. Duyet cay theo LNR";
				cout << "\n4. Duyet cay theo RNL";
				cout << "\n5. Duyet cay theo RLN";
				cout << "\n6. Duyet cay theo LRN";
				cout << "\n7. Thoat";
				cout << "\nNhap lua chon: "; cin >> select2;
				system("cls");
				if(select2 == '1') { 
					cout << "Duyet cay theo NLR" << "\n";
					duyet_NLR(t);
				}
				if(select2 == '2') {
					cout << "Duyet cay theo NRL" << "\n";
					duyet_NRL(t);
				}
				if(select2 == '3') {
					cout << "Duyet cay theo LNR" << "\n";
					duyet_LNR(t);
				}
				if(select2 == '4') {
					cout << "Duyet cay theo RNL" << "\n";
					duyet_RNL(t);
				}
				if(select2 == '5'){
					cout << "Duyet cay theo RLN" << "\n";
					duyet_RLN(t);	
				}
				if(select2 == '6'){
					cout << "Duyet cay theo LRN" << "\n";
					duyet_LRN(t);
				}
				if(select2 == '7')
					break;
			}
		}
		
		if(select == '3'){
			cout << "Cac Node co hai con: " << "\n";
			xuatNodeHaiCon(t);
			cout << "\nCac Node co mot con: " << "\n";
			xuatNodeMotCon(t);
			cout << "\nCac Node la: " << "\n";
			xuatNodeLa(t);
		}
		
		if(select == '4') {
			int k;
			cout << "Nhap so can xoa: "; cin >> k;
			xoaMotNode(k,t);
		}
		if(select == '5') {
			int x;
			cout << "Nhap nhanh can xoa: "; cin >> x;
			xoaNhanh(x,t);
		}
		
		if(select == '6') {
			int count = 0;
			cout << "So phan tu trong cay: " << kiemTraPT(count,t);
		}
		
		if(select == '7') {
			cout << "MAX trong cay: " << max_NODE(t) << "\n";
			cout << "MIN trong cay: " << min_NODE(t) << "\n";
		}
		if(select == '8') {
			int y;
			cout << "Nhap gia tri can tim: "; cin >> y;
			if(search(y,t))
				cout << y << " Co nam trong cay";
			else
				cout << y << " Khong nam trong cay";
		}
		
		if(select == '9') {
			cout << "Do cao cua cay: " << height_tree(t);
		}
		
		if(select == '0')
			break;
	}
}
