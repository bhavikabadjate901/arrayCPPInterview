#include<bits/stdc++.h>
using namespace std;
#define N 2

// Swap major and minor diagonals of a square matrix
// Given a square matrix, swap the element of major and minor diagonals.
 

// Example : 
// Input : 0 1 2
//         3 4 5
//         6 7 8

// Output : 2 1 0
//          3 4 5
//          8 7 6


int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
	#endif

	int arr[N][N];

	for(int i =0; i < N; i++)
	{
		for(int j =0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for(int i =0; i < N; i++)
	{
		swap(arr[i][i], arr[i][N-1-i]);
	}

	for(int i =0; i < N; i++)
	{
		for(int j =0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}