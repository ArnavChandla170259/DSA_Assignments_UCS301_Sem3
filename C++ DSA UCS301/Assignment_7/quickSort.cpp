#include<iostream>
using namespace std;
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
  
	for(int j=low; j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}
void quickSort(int arr[], int low, int high){
	if(low<high){
		int pi = partition(arr, low, high);
		quickSort(arr,low, pi-1);
		quickSort(arr,pi+1, high);
  }
int main(){
	int arr[] = {10,18,7,6,50};
	int n = 5;
	quickSort(arr, 0 , n-1);
	cout << "Sorted array is: ";
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	return 0;
}
/* Name - Arnav Chandla 
Roll no. - 1024170259*/
