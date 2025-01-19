#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {    
        bool swapped = false;
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
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

    bubbleSort(arr, n);
    cout << "Sorted Array: ";
    display(arr, n);
}