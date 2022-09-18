#include<iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
const int Max_Size = 10000000;
float a[10000000];
int MyRandom(int a, int b) {
  int x = rand();
  return x % (b - a + 1) + a;
}
//Thuat toan tim kiem tuyen tinh
int LinearSearch(float a[], int n, int x) {
  int i = 1;
  while ((i < n) && (a[i] != x)) i++;
  if (a[i] == x) return i;
  else return -1;
}
//Thuat toan tim kiem nhi phan
int BinarySearch(float a[], int n, int x) {
  int l = 1, r = n, mid;
  do {
    mid = (l + r) / 2;
    if (x == a[mid]) return mid;
    else if (x < a[mid]) r = mid - 1;
    else l = mid + 1;
  }
  while (l <= r);
  return -1;
}
//----------------------------------------------------------
// Thuat toan sap xep chen truc tiep
void InsertionSort(float a[], int n) {
  //clock_t start = clock();
  float temp;
  for (int i = 2; i <= n; i++) {
    temp = a[i];
    int vt = i;
    while ((a[vt - 1] > temp) && (vt > 1)) {
      a[vt] = a[vt - 1];
      vt = vt - 1;
    }
    a[vt] = temp;
  }
  //clock_t finish = clock();
  //cout<<"\nthuat toan tren mat het "<<((finish - start) / CLOCKS_PER_SEC)<<" giay de thuc hien"<<endl;
}
//-------------------------------------------------------
//Thuat toan sap xep chon truc tiep
void SelectionSort(float a[], int n) {
  int min, temp; //la chi so phan tu nho nhat
  for (int i = 1; i <= n - 1; i++) {
    //tim phan tu nho nhat ben phai a[i], tu [a[i]+1->a[n]
    min = i + 1;
    for (int j = i + 2; j <= n; j++)
      if (a[j] < a[min]) min = j;
    if (a[min] < a[i]) {
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  }
}
//Thuat toan sap xep doi cho truc tiep
void InterChangeSort(float a[], int n) {
  int temp;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] > a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
}
//Thuat toan sap xep bang pp noi bot
void BubbleSort(float a[], int n) {
  int temp;
  for (int i = 1; i < n; i++)
    for (int j = n; j > i; j--)
      if (a[j] < a[j - 1]) {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
}
//Thuat toan sap xep bang pp ShakerSort
void ShakerSort(float a[], int n) {
  int l = 1, r = n, k = n;
  int temp;
  while (l < r) {
    for (int j = r; j > l; j--)
      if (a[j] < a[j - 1]) {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        k = j;
      }
    l = k;
    for (int j = l; j < r; j++)
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        k = j;
      }
    r = k;
  }
}
//---------------------------------------------------------
/* Thuat toan sap xep bang pp HeapSort
  1.Chinh Heap */
void ShiftHeap(float a[], int l, int r) {
  int x, i, j;
  i = l;
  j = 2 * i;
  x = a[i];
  while (j <= r) {
    if (j < r)
      if (a[j] < a[j + 1])
        j = j + 1;
    if (a[j] < x) break;
    else {
      a[i] = a[j];
      a[j] = x;
      i = j;
      j = 2 * i;
    }
  }
}
// 2.Tao Heap
void CreateHeap(float a[], int n) {
  int l;
  l = n / 2; //a[1] la phan tu ghep them
  while (l > 0) {
    ShiftHeap(a, l, n);
    l = l - 1;
  }
}
// 3.Sap Xep Tren Heap
void HeapSort(float a[], int n) {
  int temp, r;
  CreateHeap(a, n);
  r = n; // la vi tri dung cho phan tu nho nhat
  while (r > 0) {
    temp = a[1];
    a[1] = a[r];
    a[r] = temp;
    r = r - 1;
    ShiftHeap(a, 1, r);
  }
}
//----------------------------------------------------------
//Thuat toan sap xep chen nhi phan
void BInsertionSort(float a[], int n) {
  int l, r, m;
  int x; //luu gia tri a[i] tranh bi ghi de khi doi cho cac phan tu
  for (int i = 2; i <= n; i++) {
    x = a[i];
    l = 1;
    r = i - 1;
    while (i <= r) //tim vi tri can chen
    {
      m = (l + r) / 2; //tim vi tri thich hop m
      if (i < m) r = m - 1;
      else l = m + 1;
    }
    int vt = i;
    while ((a[vt - 1] > x) && (vt > 1)) {
      a[vt] = a[vt - 1];
      vt = vt - 1;
    }
    a[vt] = x;
  }
}
//Thuat toan sap xep bang pp ShellSort
void ShellSort(float a[], int n, int k) {
  int step, i, j;
  int x;
  for (step = 1; step <= k; step++) {
    for (i = 1; i <= n; i++) {
      x = a[i];
      j = i - 1;
      while ((x < a[j]) && (j >= 1)) {
        a[j + 1] = a[j];
        j = j - 1;
      }
      a[j + 1] = x;
    }
  }
}
//Thuat toan sap xep bang pp QuickSort
void QuickSort(float a[], int l, int r) {
  int i, j;
  int x;
  i = l;
  j = r;
  x = a[(l + r) / 2];
  do {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (j <= j) {
      if (i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
      i++;
      j--;
    }
  }
  while (i < j);
  if (l < j) QuickSort(a, l, j);
  if (i < r) QuickSort(a, i, r);
}
//-----------------------------------------------------
//Thuat toan Sap xep theo PP MergeSort 
//Tao Merge
void Merge(float a[], int first, int mid, int last) {
  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;
  int i = first1;
  int temp[Max_Size];
  for (i = first1; first1 <= last1 && first2 <= last2; i++) {
    if (a[first1] < a[first2]) {
      temp[i] = a[first1];
      first1++;
    } else {
      temp[i] = a[first2];
      first2++;
    }
  }
  for (; first1 <= last1; first1++, i++) temp[i] = a[first1];
  for (; first2 <= last2; first2++, i++) temp[i] = a[first2];
  for (i = first; i <= last; i++) a[i] = temp[i];
}
// Sap Merge
void MergeSort(float a[], int first, int last) {
  if (first < last) {
    int mid = (first + last) / 2;
    MergeSort(a, first, mid);
    MergeSort(a, mid + 1, last);
    Merge(a, first, mid, last);
  }
}
//-------------------------------------------------
//Sap xep theo PP RadixSort
//Tao lo cho tung phan tu cua day
int GetDigit(unsigned long n, int k) {
  switch (k) {
  case 0:
    return (n % 10);
  case 1:
    return ((n / 10) % 10);
  case 2:
    return ((n / 100) % 10);
  case 3:
    return ((n / 1000) % 10);
  case 4:
    return ((n / 10000) % 10);
  case 5:
    return ((n / 100000) % 10);
  case 6:
    return ((n / 1000000) % 10);
  case 7:
    return ((n / 10000000) % 10);
  case 8:
    return ((n / 100000000) % 10);
  case 9:
    return ((n / 1000000000) % 10);
  }
  return n; //Tra ve gia tri neu khong thuoc lo nao
}

//Tron lo & Sap lai lo thanh day moi
void RadixSort(float a[], int n, int m) {
  int j = 1, k = 0;
  int temp[Max_Size];
  do {
    for (int lo = 0; lo <= 9; lo++) //lo duoc don tu 0->9
      for (int i = 1; i <= n; i++) // so phan tu duoc quet lai toan bo theo lo
    {
      int n = GetDigit(a[i], k);
      if (lo == n) {
        temp[j] = a[i];
        j++;
      }
    }
    j = 1;
    for (int i = 1; i <= n; i++) a[i] = temp[i];
    k = k + 1;
  }
  while (k <= m);
}
//---------------------------------------------------
//Chuong trinh chinh
int main() {

  int n, x, vt;
  cout << "nhap vao so phan tu mang ";
  cin >> n;
  //-------------------------	
  for (int i = 0; i < n; i++)
    a[i] = MyRandom(1, 20);
  cout << "Mang ngau nhien:";
  for (int i = 0; i < n; i++) {
    //2cout<<a[i]<<" ";//xuat mang ngau nhien
  }
  cout << endl;
  //----------------------------------
  if (n > 0) {
    cout << "\n Nhap phan tu can tim: ";
    cin >> x;
    clock_t batdau = clock();
    vt = LinearSearch(a, n, x);
    cout << "---1. LinearSearch Thuat toan tim kiem tuyen tinh ---" << endl;
    if (vt == -1) cout << "Khong co phan tu can tim !" << endl;
    else {
      cout << "Co phan tu can tim la so " << x << " Nam tai vi tri thu: " << vt << "/" << n << " trong mang" << endl;
    }
    clock_t ketthuc = clock();
    cout << "thuat toan tren mat het " << ((ketthuc - batdau) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
    //-----------------------------------
    clock_t batdau1 = clock();
    vt = BinarySearch(a, n, x);
    cout << "---2. BinarySearch Thuat toan tim kiem nhi phan---" << endl;
    if (vt == -1) cout << "Khong co phan tu can tim !" << endl;
    else {
      cout << "Co phan tu can tim la so " << x << " Nam tai vi tri thu: " << vt << "/" << n << " trong mang" << endl;
    }
    clock_t ketthuc1 = clock();
    cout << "thuat toan tren mat het " << ((ketthuc1 - batdau1) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;

  }
  //-------------------------------------------   
  clock_t start = clock();
  InsertionSort(a, n);
  cout << "---3.  InsertionSort Thuat toan sap xep chen truc tiep ---" << endl;
  clock_t finish = clock();
  cout << "thuat toan tren mat het " << ((finish - start) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau2 = clock();
  SelectionSort(a, n);
  cout << "---4.  Thuat toan sap xep chon truc tiep SelectionSort---" << endl;
  clock_t ketthuc2 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc2 - batdau2) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau3 = clock();
  InterChangeSort(a, n);
  cout << "---5.  Thuat toan sap xep doi cho truc tiep InterChangeSort---" << endl;
  clock_t ketthuc3 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc3 - batdau3) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau4 = clock();
  BubbleSort(a, n);
  cout << "---6.  Thuat toan sap xep bang pp noi bot BubbleSort---" << endl;
  clock_t ketthuc4 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc4 - batdau4) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau5 = clock();
  ShakerSort(a, n);
  cout << "---7.  Thuat toan sap xep bang pp ShakerSort---" << endl;
  clock_t ketthuc5 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc5 - batdau5) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau6 = clock();
  HeapSort(a, n);
  cout << "---8.  Thuat toan sap xep bang pp HeapSort---" << endl;
  clock_t ketthuc6 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc6 - batdau6) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau7 = clock();
  BInsertionSort(a, n);
  cout << "---9.  Thuat toan sap xep chen nhi phan BInsertionSort---" << endl;
  clock_t ketthuc7 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc7 - batdau7) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau8 = clock();
  ShellSort(a, n, n);
  cout << "---10.  Thuat toan sap xep bang pp ShellSort---" << endl;
  clock_t ketthuc8 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc8 - batdau8) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau9 = clock();
  QuickSort(a, 1, n);
  cout << "---11.  Thuat toan sap xep bang pp QuickSort---" << endl;
  clock_t ketthuc9 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc9 - batdau9) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 
  clock_t batdau10 = clock();
  MergeSort(a, 1, n);
  cout << "---12.  Thuat toan Sap xep theo PP MergeSort---" << endl;
  clock_t ketthuc10 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc10 - batdau10) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;
  //---------------------------------- 

  clock_t batdau11 = clock();
  RadixSort(a, n, 4);
  cout << "---13.  Thuat toan Sap xep theo PP RadixSort---" << endl;
  clock_t ketthuc11 = clock();
  cout << "thuat toan tren mat het " << ((ketthuc11 - batdau11) / CLOCKS_PER_SEC) << " giay de thuc hien" << endl << endl;

}
