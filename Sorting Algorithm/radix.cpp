#include <iostream>
using namespace std;
int Max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countSort(int arr[], int n, int exp)
{
    int output[n];  
    // int m = Max(arr, n);
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/ exp) % 10] += 1;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i]/ exp) % 10;
       
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int n)
{
    int m = Max(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout << "Original array: ";
    display(arr, n);
    cout << endl;
    // countSort(arr, n);
    radixSort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}
