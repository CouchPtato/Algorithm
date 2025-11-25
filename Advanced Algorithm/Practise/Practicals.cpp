#include <bits/stdc++.h>
using namespace std;

int comparisons = 0;

int partition(vector<int> &Array, int start, int end)
{
    int x = Array[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        comparisons++;
        if (Array[j] <= x)
        {
            i = i + 1;
            swap(Array[i], Array[j]);
        }
    }
    swap(Array[i+1], Array[end]);
    return (i+1);
}

int randomizedPartition(vector<int> &Array, int start, int end)
{
    int j = start + rand() % (end - start + 1);
    swap(Array[end], Array[j]);
    return partition(Array, start, end);
}

// void quickSort(vector<int> &A, int p, int r)
// {
//     if (p < r)
//     {
//         int q = randomizedPartition(A, p, r);
//         quickSort(A, p, q - 1);
//         quickSort(A, q + 1, r);
//     }
// }

// int main()
// {
//     vector<int> A = {8,7,6,5,4,3,2,1,0};
//     int n = A.size();

//     quickSort(A, 0, n - 1);
    
//     for (int x : A)
//     {
//         cout << x << " ";
//     }

//     cout << "\nComparisons: " << comparisons;

//     return 0;
// }

// int rSelect(vector<int> &A, int p, int r, int i)
// {
//     comparisons++;
//     if (p == r) // if there is only one element.
//     {
//         return A[p];
//     }

//     int q = randomizedPartition(A, p, r);
//     int k = q - p + 1;

//     comparisons++;
//     if (i == k)
//     {
//         return A[q];
//     }
//     else if (i < k)
//     {
//         rSelect(A, p, q - 1, i);
//     }
//     else
//     {
//         rSelect(A, q + 1, r, i - k);
//     }
    
// }

// int main()
// {
//     vector<int> A = {8,7,6,5,4,3,2,1,0};
//     int n = A.size();
//     int i = 5;

//     int result = rSelect(A, 0, n - 1, i);

//     cout << i << "-th smallest element: " << result;
//     cout << "\nComparisons: " << comparisons;

//     return 0;
// }