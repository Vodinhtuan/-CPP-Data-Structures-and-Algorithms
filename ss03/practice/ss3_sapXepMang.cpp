//cau 3: 

#include <iostream>
using namespace std;

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
main(){
	int a[5] = {1, 7, 2, 3, 5};
	int k = 2;
	for(int i= 0;i<5;i++){
		cout<<arr[i];
		}
	
	sort(a,k);
	for(int i= 0;i<k;i++){
		cout<<arr[i];
		}
}
