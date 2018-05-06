#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

/*
//判断回文串
bool IsPalindrom(string s)
{
	int first = 0, last = s.size() - 1;
	while (first <= last)
	{
		while (!isalnum(s[first]) && first < last)
		{
			first++;
		}
		while (!isalnum(s[last]) && first < last)
		{
			last--;
		}
		if (toupper(s[first]) != toupper(s[last]))
			return false;
		first++;
		last--;
	}
	return true;
}

int strStr(string haystack, string needle)
{
	int m = haystack.size(), n = needle.size();
	if (n == 0)
		return 0;
	for (int i = 0; i < m - n + 1; i++)
	{
		int j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (j == n)
				return i;
		}
		j++;
	}
	return -1;
}

int my_atoi(const char* str)
{
	int num = 0;
	int sign = 1;
	const int n = strlen(str);
	int i = 0;

	while (str[i] == ' ' && i < n)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	for (; i < n; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return sign == -1 ? INT_MIN : INT_MAX;
		num = num * 10 + str[i] - '0';
	}
	return num * sign;
}

//二进制数相加
string addBinary(string a, string b)
{
	string result;
	const size_t n = a.size() > b.size() ? a.size() : b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (size_t i = 0; i < n; ++i)
	{
		const int ai = i < a.size() ? a[i] - '0' : 0;
		const int bi = i < b.size() ? b[i] - '0' : 0;
		const int val = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.insert(result.begin(), val + '0');
	}
	if (carry == 1)
		result.insert(result.begin(), '1');
	return result;
}

//最长回文串
string longestPalindrome(string s)
{
	string res = "";
	int len = s.size();
	if (len == 1)
		return s;
	int maxlen = 0, curlen = 0, sbegin;
	int left, right;
	for (int i = 0; i < len; ++i)
	{
		if (len % 2 == 0)
		{
			left = i - 1;
			right = i + 1;
		}
		else
		{
			left = i;
			right = i + 1;
		}
		while (left >= 0 && right < len && s[left] == s[right])
		{
			curlen = right - left;
			if (curlen > maxlen)
			{
				maxlen = curlen;
				sbegin = left;
			}
			left--;
			right++;
		}
	}
	res = s.substr(sbegin, maxlen + 1);  //substring()为前闭后开
	return res;
}

//求最后一个单词的长度 顺序扫描字符串，求出每个单词的长度
int lengthOflastWord(const char* s)
{
	int len = 0;
	while (*s)
	{
		if (*s != ' ')
			++len;
		else
			len = 0;
	}
	return len;
}

bool IsMatch(const char* s, const char* p)
{
	if (*p == '\0')
		return *s == '\0';
	//next char is not '*',then must match current character
	if (*(p + 1) != '*')
	{
		if (*p == *s || *p == '.' && *s != '\0')
		{
			return IsMatch(s + 1, p + 1);
		}
		else
			return false;
	}
	else
	{//next char is '*'
		while (*p == *s || (*p == '.' && *s != '\0'))
		{	
			if (IsMatch(s, p + 2))
				return true;
			s++;
		}
		return IsMatch(s, p + 2);
	}
}


//Longest Common Prefix
string longestCommonPrefix(vector<string> &str)
{
	if (str.empty())
		return "";
	int right_most = str[0].size() - 1;
	for (size_t i = 1; i < str.size(); ++i)
	{
		for (int j = 0; j <= right_most; j++)
		{
			if (str[i][j] != str[0][j])
				right_most = j - 1;
		}
	}
	return str[0].substr(0, right_most + 1);
}*/

#include<unordered_map>
vector<string> anagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> group;
	for (const auto &s : strs)
	{
		string key = s;
		sort(key.begin(), key.end());
		group[key].push_back(s);
	}
	vector<string> result;
	for (auto it = group.cbegin(); it != group.cend(); ++it)
	{
		if (it->second.size() > 1)
			result.insert(result.end(), it->second.begin(), it->second.end());
	}
	return result;
}

int main()
{
	vector<string> s;
	s = { "ate", "tae", "eat", "and", "end" };
	vector<string> ret = anagrams(s);
	vector<string>::iterator it = ret.begin();
	for (; it != ret.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}