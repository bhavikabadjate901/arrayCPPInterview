#include<bits/stdc++.h>
using namespace std;

// Maximum sum of i*arr[i] among all rotations of a given array
// Difficulty Level : Medium
// Last Updated : 02 Sep, 2021
// Given an array arr[] of n integers, find the maximum that maximizes the sum of the value of i*arr[i] where i varies from 0 to n-1.

// Examples:  

// Input: arr[] = {8, 3, 1, 2}
// Output: 29
// Explanation: Lets look at all the rotations,
// {8, 3, 1, 2} = 8*0 + 3*1 + 1*2 + 2*3 = 11
// {3, 1, 2, 8} = 3*0 + 1*1 + 2*2 + 8*3 = 29
// {1, 2, 8, 3} = 1*0 + 2*1 + 8*2 + 3*3 = 27
// {2, 8, 3, 1} = 2*0 + 8*1 + 3*2 + 1*3 = 17

// Input: arr[] = {3, 2, 1}
// Output: 7
// Explanation: Lets look at all the rotations,
// {3, 2, 1} = 3*0 + 2*1 + 1*2 = 4
// {2, 1, 3} = 2*0 + 1*1 + 3*2 = 7
// {1, 3, 2} = 1*0 + 3*1 + 2*2 = 7


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

int rotate_arr_sum(int arr[], int n)
{
	int sum = 0;
	for(int i = n - 1; i > 0; i--)
	{
		swap(arr[i], arr[i-1]);
	}
	for(int i =0; i < n; i++)
	{
		sum = sum + arr[i]*i;
	}
	return sum;
}

void max_sum_1(int arr[], int n)
{
	int maxi = 0;
	int x =n;

	while(n--){
		maxi = max(maxi, rotate_arr_sum(arr, x));  // O(2n*n) ==> O((2n)^2)
	}
	cout << maxi << endl;
}

void max_sum_2(int arr[], int n)
{
	int arr_sum = 0;
	for(int i =0; i < n; i++)
	{
		arr_sum += arr[i];
	}

	int arr_op_sum = 0;

	for(int i =0; i < n; i++)
	{
		arr_op_sum += arr[i]*i;
	}
	int res = arr_op_sum;

	int next_sum = 0;

	for(int i = 1; i < n; i++)
	{
		next_sum = arr_op_sum + arr[i-1]*(n-i) - (arr_sum - arr[i-1]);
		arr_op_sum = next_sum;
		res = max(res, next_sum);
	}
	cout << res << endl;
}

int main()
{
	int arr[4] = {8, 3, 1, 2};
	max_sum_1(arr,4);
	max_sum_2(arr, 4);
	return 0;
}



