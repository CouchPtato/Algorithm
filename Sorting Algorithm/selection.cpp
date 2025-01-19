#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {    
        int min_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
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

    selectionSort(arr, n);
    cout << "Sorted Array: ";
    display(arr, n);
}