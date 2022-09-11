#include <iostream>
using namespace std;
void xuLy(int A[][200], int n) {
	int d = n/2;
	int c = n - d ;
	int i = 1;
	while(i <= n*n){
		if(i % n != 0){				// Neu i khong chia het cho n thi ta gan
			A[d][c] = i++;			// A[d][c] = i++
			d--;					// Sau do ta giam so dong
			c++;					// Va tang so cot de xu li phan tu tiep theo
			
		}else{						// Neu i chia het cho n thi ta tang i va tang so cot len 2 don vi
			if(A[d][c] % n == 0){	// Dieu kien nay dung de giu vi tri cua so chia het cho n
				A[d][c] = i;
			}
			i++;
			c = c + 2;
		}

		if (c == n){				// Neu so tiep theo di ra ben phai cua hinh vuong ta se dua so do ve dau cot bang cach gan c = n - n; 
			c = n - n;
		}
			
	    if (d < 0){					// Neu so tiep theo di ra phia tren cua hinh vuong ta se dua so do ve cuoi dong bang cach gan d = n - 1;
	        d = n - 1;
		}	
			
		if(c > n){					// Neu truong hop so i chia het cho n va so cot tang 2 don vi ta dung dieu kien nay de dua so tiep theo ve cot (n-n) + 1
			c = (n-n) + 1;
		}
	}
}

void xuatMang(int A[][200], int n){
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n ; j++){
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}

main(){
	int A[200][200],n;
	cin >> n;
	xuLy(A,n);
	xuatMang(A,n);
}
