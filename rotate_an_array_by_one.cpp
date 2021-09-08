#include<bits/stdc++.h>
using namespace std;

// Program to cyclically rotate an array by one
// Given an array, cyclically rotate the array clockwise by one. 

// Examples:  
// Input:  arr[] = {1, 2, 3, 4, 5}
// Output: arr[] = {5, 1, 2, 3, 4}


void print_arr(int arr[], int n)
{
	for(int i =0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void rotate_arr_1(int arr[], int n)
{
	int tmp = arr[n-1];

	for(int i = n-2; i >=0; i--)
	{
		arr[i + 1] = arr[i]; 
	}
	arr[0] = tmp;
}

void rotate_arr_2(int arr[], int n)
{
	for(int i = n - 1; i > 0; i--)
	{
		swap(arr[i], arr[i-1]);
	}
}

int main()
{
	int arr[6] = {1,2,3,4,5, 6};

	print_arr(arr, 6);

	rotate_arr_2(arr, 6);

	print_arr(arr, 6);

	return 0;
}



