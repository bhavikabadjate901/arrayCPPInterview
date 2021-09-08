#include<bits/stdc++.h>
using namespace std;

// Given a sorted array of positive integers, rearrange the array alternately 
// i.e first element should be maximum value, second minimum value, third second max, fourth second min and so on. 

// Examples: 

// Input: arr[] = {1, 2, 3, 4, 5, 6, 7} 
// Output: arr[] = {7, 1, 6, 2, 5, 3, 4}

// Input: arr[] = {1, 2, 3, 4, 5, 6} 
// Output: arr[] = {6, 1, 5, 2, 4, 3} 

void print_arr(int arr[], int n)
{
	for(int i =0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void rearrange_arr_1(int arr[], int n)
{
	int start = 0;
	int end = n-1;

	int arr1[n];

	for(int i =0; i < n; i = i+2)
	{
		if(start <= end)
		{
			arr1[i] = arr[end];
			arr1[i + 1] =  arr[start];
			start++;
			end--;
		}
	}
	print_arr(arr1, n);
}

void rearrange_arr_2(int arr[], int n)
{
	int start = 0;
	int end = n-1;
	int max_ele = arr[n-1] + 1;

	for(int i =0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			// the formula is based upon 
			// divident = quotient * divisor + remainder
			// quotient --> new values
			// remainder --> old values
			// divident / diviser == quotient
			// divident % diviser == remainder
			arr[i] = arr[i] + (arr[end] % max_ele) * max_ele; 
			end--;
		}
		else
		{
			arr[i] = arr[i] + (arr[start] % max_ele) * max_ele; 
			start++;
		}
	}
	print_arr(arr, n);

	for(int i =0; i < n; i++)
	{
		arr[i] = arr[i] / max_ele; // to get all new values 
	}
	print_arr(arr, n);
}

int main()
{
	int arr[6] = {1, 2, 3, 4, 5, 6};
	rearrange_arr_1(arr, 6);
	rearrange_arr_2(arr, 6);
	return 0;
}


