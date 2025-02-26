#include <iostream>
using namespace std;

// [a  b] [e  f]
// [c  d] [g  h]

void strassensmatrixMultiplication(int A[2][2], int B[2][2], int C[2][2])
{
    int a = A[0][0];
    int b = A[0][1];
    int c = A[1][0];
    int d = A[1][1];
    int e = B[0][0];
    int f = B[0][1];
    int g = B[1][0];
    int h = B[1][1];
    int P = (a + d)*(e + h);
    int Q = (c + d)*e;
    int R = a*(f - h);
    int S = d*(g - e);
    int T = (a + b)*h;
    int U = (c - a)*(e + f);
    int V = (b - d)*(g + h);
    C[0][0] = P + S - T + V;
    C[0][1] = R + T;
    C[1][0] = Q + S;
    C[1][1] = P + R - Q + U;
}
void display(int matrix[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int A[2][2] = {{1,3}, {5,7}};
    int B[2][2] = {{8,4}, {6,2}};
    int C[2][2] = {{0,0}, {0,0}};
    cout << "Original Matrices:" << endl;
    cout << "Matrix A:" << endl;
    display(A);
    cout << "Matrix B:" << endl;
    display(B);
    strassensmatrixMultiplication(A,B,C);
    cout << "Resultant Matrix:" << endl;
    display(C);
}