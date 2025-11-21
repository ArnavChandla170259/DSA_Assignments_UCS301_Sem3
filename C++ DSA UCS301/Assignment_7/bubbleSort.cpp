#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		bool swapped = false;
		
		for(int j=0; j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}
}
int main(){
	int arr[] = {64,39,26,45};
	int n = 4;
	bubbleSort(arr,n);
	cout << "Sorted Array is: ";
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
/* Name - Arnav Chandla 
Roll no. - 1024170259*/
