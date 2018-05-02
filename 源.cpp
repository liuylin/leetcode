#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
class Solution4
{
public:
	int LongestConsecutive(const vector<int> & num)
	{
		unordered_map<int, bool> used;
		for (auto i : num)
			used[i] = false;
		int longest = 0;
		for (auto i : num)
		{
			if (used[i])
				continue;
			int length = 1;
			used[i] = true;
			for (int j = i + 1; used.find(j) != used.end(); ++j)
			{
				used[j] = true;
				++length;
			}
			for (int j = i - 1; used.find(j) != used.end(); --j)
			{
				used[j] = true;
				++length;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};


int main()
{
	int arr[] = { 100, 4, 200, 2, 1, 3 };
	Solution4 s;
	vector<int> a;
	for (int i = 0; i < 6; i++)
	{
		a.push_back(arr[i]);
	}
	int ret = s.LongestConsecutive(a);
	cout << ret;
	cout << endl;
	system("pause");
	return 0;
}
*/

//�����к�Ϊ0��������
/*
class Solution5
{
public:
	vector<vector<int>> threeSum(vector<int>& num)
	{
		vector<vector<int>> result;
		if (num.size() < 3)
			return result;
		sort(num.begin(), num.end());
		const int target = 0;

		auto last = num.end();
		for (auto i = num.begin(); i < last - 2; i++)
		{
			auto j = i + 1;
			//�����ظ�����
			if (i > num.begin() && *i == *(i - 1))
				continue;
			auto k = last - 1;
			while (j < k)
			{
				if (*i + *j + *k < target)
				{
					++j;
					//�����ظ�����
					while (*j == *(j - 1) && j < k)
						++j;
				}
				else if (*i + *j + *k > target)
				{
					--k;
					//�����ظ�����
					while (*k == *(k - 1) && j < k)
						--k;
				}
				else
				{
					result.push_back({ *i, *j, *k });
					++j;
					--k;
					while (*j == *(j - 1) && *k == *(k + 1) && j < k)
						++j;
				}
			}
		}
		return result;
	}
};

int main()
{
	vector<int> a;
	a.push_back(-1);
	a.push_back(-1);
	a.push_back(-1);
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	Solution5 s;
	vector<vector<int>> b = s.threeSum(a);
	cout << b.size() << endl;
	system("pause");
	return 0;
}
*/

/*
class Solution
{
public:
	//˳ʱ��
	void rotate1(vector<vector<int>>& matrix)
	{
		const int n = matrix.size();//������
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - i; j++)//���Ÿ�������ת
			{
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
			}
		}
		for (int i = 0; i < n / 2; ++i)//����ˮƽ����ת
		{
			for (int j = 0; j < n; ++j)
			{
				swap(matrix[i][j], matrix[n - 1 - i][j]);
			}
		}
	}

	//��ʱ��
	void rotate2(vector<vector<int>>& matrix)
	{
		const int n = matrix.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
	}
};
*/

//���������м�1
/*
class Solution
{
public:
	vector<int> plusOne(vector<int> &digits)
	{
		add(digits, 1);
		return digits;
	}
private:
	void add(vector<int>& digits, int digit)
	{
		int c = digit; //c��ʾ��λ
		for (auto it = digits.rbegin(); it != digits.rend(); it++)
		{
			*it += c;
			c = *it / 10;
			*it %= 10;
		}
		if (c > 0)
		{
			digits.insert(digits.begin(), 1);
		}
	}
};
*/

//����0 O(m+n)
/*
class Solution
{
public:
	void setZeroes(vector <vector<int>>&matrix)
	{
		const size_t m = matrix.size();//����
		const size_t n = matrix[0].size();//����
		vector<bool> row(m, false);//��Ǹ����Ƿ����0
		vector<bool> col(n, false);//��Ǹ����Ƿ����0
		for (size_t i = 0; i < m; ++i)
		{
			for (size_t j = 0; i < n; ++j)
			{
				if (matrix[i][j] == 0)
					row[i] = col[j] = true;
			}
		}
		for (size_t i = 0; i < m; i++)
		{
			if (row[i])
				fill(&matrix[i][0], &matrix[i][0] + n,0);
		}
		for (size_t j = 0; j < n; j++)
		{
			if (col[j])
			{
				for (size_t i = 0; i < m; ++i)
					matrix[i][j] = 0;
			}
		}
	}
};
*/

//����0 O(1)
//class Solution
//{
//public:
//	void SetZeroes(vector<vector<int>>& matrix)
//	{
//		const size_t m = matrix.size();//����
//		const size_t n = matrix[0].size();//����
//		bool row_has_zero = false;//��һ���Ƿ����0
//		bool col_has_zero = false;//��һ���Ƿ����0
//		for (size_t i = 0; i < n; i++)
//		{
//			if (matrix[0][i] == 0)
//			{
//				row_has_zero = true;
//				break;
//			}
//		}
//		for (size_t i = 0; i < n; i++)
//		{
//			if (matrix[i][0] == 0)
//			{
//				col_has_zero = true;
//				break;
//			}
//		}
//		for (size_t i = 1; i < m; i++)
//		{
//			for (size_t j = 1; j < n; j++)
//			{
//				//�����Ӧ�ĵ�һ�е�һ����1
//				if (matrix[i][j] == 0)
//				{
//					matrix[0][j] = 0;
//					matrix[i][0] = 0;
//				}
//			}
//		}
//		for (size_t i = 1; i < m; i++)
//		{
//			for (size_t j = 1; j < n; j++)
//			{
//				if (matrix[i][0] == 0 || matrix[0][j] == 0)
//				{
//					//�����һ�л��һ���д�λ��Ϊ0����0
//					matrix[i][j] = 0;
//				}
//			}
//		}
//		if (row_has_zero)
//		{
//			for (size_t i = 0; i < n; i++)
//				matrix[0][i] = 0;
//		}
//		if (col_has_zero)
//		{
//			for (size_t i = 0; i < m; i++)
//				matrix[i][0] = 0;
//		}
//	}
//};

class Solution
{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int>& cost)
	{
		int total = 0;
		int start = -1;
		for (int i = 0, sum = 0; i < gas.size(); i++)
		{
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0)
			{
				start = i;
				sum = 0;
			}
		}
		return total >= 0 ? start + 1 : -1;
	}
};