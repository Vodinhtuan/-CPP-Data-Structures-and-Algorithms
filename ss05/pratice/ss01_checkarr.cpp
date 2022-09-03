#include <iostream>
using namespace std;
void inputArr(int arr[], int &n){
	cout << "Enter the array length: " ;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cout << "array[" << i<< "]= ";
		cin >> arr[i];
	} 
}
void findMaxLenght(int arr[], int n)
{
    int Length = 1;
    int max = 1;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            Length++; 							/*neu dung thi tang do dai*/
            if (Length > max){					/*gan do max cho gioi han moi*/
                max = Length;
                start = i + 2 - Length; 		/*dam bao cac chi so ban dau chinh xac */
                end = i + 2;
            }

        }else{
            Length = 1; 
		}						/* Neu khong thi bat dau lai chieu dai va xet la tu dau*/
    }
   								/* do khi length < max thi end va start khong thay doi nen ta se duoc yeu cau bai toan */
   	cout << "So phan tu cua doan tang dai nhat là: " << max << endl;
    for (int i = start; i < end; i++)
        cout << arr[i] << " ";
}
main(){
	int arr[50], n;
	inputArr(arr,n);
	findMaxLenght(arr,n);
	
}
