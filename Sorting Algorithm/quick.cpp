#include <iostream>
using namespace std;

int findCorrectPivot(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }   
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int Pivot = findCorrectPivot(array, start, end);
        quickSort(array, start, Pivot - 1);
        quickSort(array, Pivot + 1, end);
    }
}

void display(int array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {8,2,4,7,1,3,9,6,5};
    int n = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, n-1);
    display(array, n);
}