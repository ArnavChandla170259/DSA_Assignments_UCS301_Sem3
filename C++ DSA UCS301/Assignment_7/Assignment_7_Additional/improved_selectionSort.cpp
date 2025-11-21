#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        for (int i = start + 1; i <= end; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        swap(arr[start], arr[minIndex]);

        if (maxIndex == start) {
            maxIndex = minIndex;
        }

        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

int main() {
    int arr[] = {23, 78, 45, 8, 32, 56, 1};
    int n = 7;
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
/* Name - Arnav Chandla 
Roll no. - 1024170259*/
