#include<bits/stdc++.h>
using namespace std;
#define N 4
#define M 6

// Maximum path sum in matrix
// Examples: 

// Input : mat[][] = 10 10  2  0 20  4
//                    1  0  0 30  2  5
//                    0 10  4  0  2  0
//                    1  0  2 20  0  4
// Output : 74
// The maximum sum path is 20-30-4-20.

// Input : mat[][] = 1 2 3
//                   9 8 7
//                   4 5 6
// Output : 17
// The maximum sum path is 3-8-6.

int main()
{
    int mat1[N][M] = { { 10, 10, 2, 0, 20, 4 },
                    { 1, 0, 0, 30, 2, 5 },
                    { 0, 10, 4, 0, 2, 0 },
                    { 1, 0, 2, 20, 0, 4 } };

    for(int i= 1; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // if the matrix have all possible 3 options
            if(j > 0 && j < M-1)
            {
                 mat1[i][j] += max(mat1[i - 1][j],
                              max(mat1[i - 1][j - 1],
                              mat1[i - 1][j + 1]));
            }

            // if matrix cannot have left case
            else if(j > 0)
            {
                 mat1[i][j] += max(mat1[i - 1][j],
                            mat1[i - 1][j - 1]);
            }

            // if matrix cannot have right case
            else if(j < M-1)
            {
                mat1[i][j] += max(mat1[i - 1][j],
                            mat1[i - 1][j + 1]);
            }
        }
    }
     int res = 0;
    for (int j = 0; j < M; j++)
        res = max(mat1[N-1][j], res);
    cout << res << endl;
}