#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution1
{
public:
	int Search(int A[], int n, int target)
	{
		int frist = 0, last = n;
		while (frist != last)
		{
			const int mid = frist + (last - frist) / 2;
			if (A[mid] == target)
				return mid;
			else if (A[mid] > target)
			{
				last = mid;
			}
			else if (A[mid] < target)
			{
				frist = mid + 1;
			}
		}
		return -1;
	}
};


//Search in Rotesd Sorted Array
//4 5 6 1 2 3
class Solution2
{
public:
	int Search(int A[], int n, int target)
	{
		int first = 0, last = n;
		while (first != last)
		{
			const int mid = first + (last - first) / 2;
			if (A[mid] == target)
				return mid;
			if (A[first] <= A[mid])
			{
				if (A[first] <= target && target < A[mid])
				{
					last = mid;
				}
				else
					first = mid + 1;
			}
			else
			{
				if (A[mid] < target && target <= A[last] - 1)
				{
					first = mid + 1;
				}
				else
					last = mid;
			}
		}
		return -1;
	}
};

//允许相同元素
//1 3 1 1 1
class Solution2
{
public:
	bool Search(int A[], int n, int target)
	{
		int first = 0, last = n;
		while (first != last)
		{
			const int mid = first + (last - first) / 2;
			if (A[mid] == target)
				return mid;
			if (A[first] < A[mid])
			{
				if (A[first] <= A[mid] && A[mid] < target)
				{
					last = mid;
				}
				else
					first = mid + 1;
			}
			else if (A[first] > A[mid])
			{
				if (A[mid] > target && target <= A[last-1])
				{
					first = mid + 1;
				}
				else
					last = mid;
			}
			else
				first++;
		}
	}
};

//找到两个已排序数组的中位数
class Solution3
{
public:
	double findkSortenArr(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total & 0x1)//奇数
		{
			return Find_kPath(A, m, B, n,total/2);
		}
		else //偶数
		{
			return Find_kPath(A, m, B, n, total / 2) + Find_kPath(A, m, B, n, total / 2 + 1)/2.0;
		}
	}
private:
	//寻找两个已排序数组的第k大元素
	static int Find_kPath(int A[], int m, int B[], int n, int k)
	{
		if (m > n)
		{
			return Find_kPath(B, n, A, m, k);
		}
		if (m == 0)
		{
			return B[k - 1];
		}
		if (k == 1)
		{
			return min(A[0], B[0]);
		}

		int ia = min(k / 2, m), ib = k - ia;
		if (A[ia - 1] < B[ib - 1])
		{
			return Find_kPath(A + ia, m - ia, B, n, k - ia);
		}
		else if (A[ia - 1] > B[ib - 1])
		{
			return Find_kPath(A, m, B + ib, n - ib, k - ib);
		}
		else
			return A[ia - 1];
	}
};