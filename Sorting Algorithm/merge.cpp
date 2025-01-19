#include <iostream>
using namespace std;

void divideAndMerge(int arr[], int L, int m, int R) {
    int sizeL = m - L + 1;
    int sizeR = R - m;
    int left[sizeL], right[sizeR];

    for (int i = 0; i < sizeL; i++)
        left[i] = arr[L + i];
    for (int i = 0; i < sizeR; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = L;

    while (i < sizeL && j < sizeR) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < sizeL) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < sizeR) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int L, int R) {
    if (L < R) {
        int m = L + (R - L) / 2;
        mergeSort(arr, L, m);
        mergeSort(arr, m + 1, R);
        divideAndMerge(arr, L, m, R);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {69, 96, 80, 8, 11, 7, 18, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "OG array: ";
    display(arr, n);

    mergeSort(arr, 0, n-1);
    cout << "Sorted Array: ";
    display(arr, n);
}
