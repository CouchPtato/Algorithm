#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
   for (int i = 1; i < n; i++)
   {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
   } 
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {69, 96, 80, 8, 11, 7, 18, 13};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "OG array: ";
    display(arr, n);

    insertionSort(arr, n);
    cout << "Sorted Array: ";
    display(arr, n);
}