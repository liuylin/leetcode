#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<list>
#include<unordered_map>

//���ǹ�����
/*
class Solution
{
public:
	int candy(vector<int> &ratings)
	{
		int n = ratings.size();
		int sum;

		vector<int> nums(n, 1);
		for (int i = 1; i < n; i++)
		{
			if (ratings[i] > ratings[i + 1])
				nums[i + 1] = nums[i] + 1;
		}

		sum = nums[n - 1];
		for (int i = n - 2; i >= 0; i++)
		{
			if (ratings[i + 1] > ratings[i] && nums[i + 1] + 1 > nums[i])
				nums[i] = nums[i + 1] + 1;
			sum += nums[i];
		}
		return sum;
	}
};*/


//ֻ��һ�����ֳ���һ�Σ����඼��������
/*
class Solution
{
public:
	int SingleNumber(int A[], int n)
	{
		int count[32], result = 0;
		memset(count, 0, sizeof(int)* 32);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				count[j] += A[i] >> j & 0x1;
			}
		}
		for (int i = 0; i<32; i++)
		{
			result |= (count[i] % 3 << i);
		}
		return result;
	}
};*/

//������ڵ㶨�����£�
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x)
		:val(x)
		, next(nullptr)
	{}
};

//Add two Numbers
class Solution
{
public:
	//����������� ��Ӻ����������
	ListNode *AddTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode dummy(-1);//Ͷ�ڵ�
		int carry = 0;
		ListNode* prev = &dummy;
		for (ListNode* pa = l1, *pb = l2; pa != NULL || pb != NULL;
			pa = pa == nullptr ? 0 : pa->next, pb = pb == nullptr ? 0 : pb->next,
			prev = prev->next)
		{
			const int a = pa == nullptr ? 0 : pa->val;
			const int b = pb == nullptr ? 0 : pb->val;
			const int value = (a + b + carry) % 10;
			carry = (a + b + carry) / 10;
			prev->next = new ListNode(value);//β��
		}
		if (carry > 0)
			prev->next = new ListNode(carry);
		return dummy.next;
	}

	//��תm-n�����ڵ�����
	ListNode* reverseBetween(ListNode *head, int m, int n)
	{
		ListNode dummy(-1);
		dummy.next = head;

		ListNode *prev = &dummy;
		for (int i = 0; i < m - 1; i++)
		{
			prev = prev->next;
		}
		ListNode* const head2 = prev;

		prev = head2->next;
		ListNode* cur = prev->next;
		for (int i = m; i < n; i++)
		{
			prev->next = cur->next;
			cur->next = head2->next;
			head2->next = cur;
			cur = prev->next;
		}
		return dummy.next;
	}

	//��xС����ǰ�棬��x����ں���
	ListNode* partition(ListNode* head, int x)
	{
		ListNode left_dummy(-1);//ͷ���
		ListNode right_dummy(-1);//ͷ���

		auto left_cur = &left_dummy;
		auto right_cur = &right_dummy;

		for (ListNode* cur = head; cur; cur = cur->next)
		{
			if (cur->val < x)
			{
				left_cur->next = cur;
				left_cur = cur;
			}
			else
			{
				right_cur->next = cur;
				right_cur = cur;
			}
		}
		left_cur->next = right_dummy.next;
		right_cur->next = nullptr;
		return left_dummy.next;
	}

	//ʹ�ظ���Ԫ��ֻ����һ��
	ListNode *delDuplicates(ListNode* head)
	{
		if (head == nullptr)
			return nullptr;
		for (ListNode* prev = head, *cur = head->next; cur; cur = cur->next)
		{
			if (prev->val == cur->val)
			{
				prev->next = cur->next;
				delete cur;
			}
			else
				prev = cur;
		}
		return head;
	}

	//ʹ�������ظ���Ԫ��һ��Ҳ������
	ListNode* delDuplicate(ListNode* head)
	{
		if (!head || !head->next)
			return head;
		ListNode* p = head->next;
		if (head->val == p->val)
		{
			while (p && head->val == p->val)
			{
				ListNode* tmp = p;
				p = p->next;
				delete p;
			}
			delete head;
			return delDuplicate(p);
		}
		else
		{
			head->next = delDuplicate(head->next);
			return head;
		}
	}

	
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr || k == 0)
			return head;
		int len = 1;
		ListNode* p = head;
		while (p->next)
		{
			len++;
			p = p->next;
		}
		k = len - k%len;
		p->next = head; // ��β�������ɻ�
		for (int step = 0; step < k; step++)
		{
			p = p->next;//���������
		}
		head = p->next; //�µ��׽ڵ�
		p->next = nullptr;//�Ͽ���
		return head;
	}

	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return head;
		ListNode* tmp = head->next;
		head->next = swapPairs(tmp->next);
		tmp->next = head;
		return tmp;
	}

	//�ҵ��м�λ�ã���ת����������ϲ�
	void RecorderList(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return;
		ListNode* slow = head, *fast = head, *prev = NULL;
		while (fast && fast->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;//cut at middle
		slow = Reverse(slow);

		//merge two lists
		ListNode *cur = head;
		while (cur->next)
		{
			ListNode* tmp = cur->next;
			cur->next = slow;
			slow = slow->next;
			cur->next->next = tmp;
			cur = tmp;
		}
		cur->next = slow;
	}
private:
	ListNode* Reverse(ListNode* head)
	{
		ListNode dummy(-1);//ͷ�ڵ�
		dummy.next = head;
		ListNode* prev = head;
		ListNode* cur = prev->next;
		while (cur)
		{
			prev->next = cur->next;
			cur->next = dummy.next;
			dummy.next = cur;
			cur = prev->next;
		}
		return dummy.next;
	}

	ListNode *reverseKGroup(ListNode* head, int k)
	{
		if (head == NULL || head->next == NULL || k < 2)
			return NULL;
		ListNode *next_group = head;
		for (int i = 0; i < k; ++i)
		{
			if (next_group)
				next_group = next_group->next;
			else
				return head;
		}
		//next_group is the head of next_group
		//new_next_group is the new head of nex_group after reversion
		ListNode *new_next_group = reverseKGroup(next_group, k);
		ListNode* prev = NULL, *cur = head;
		while (cur != next_group)
		{
			ListNode* next = cur->next;
			cur->next = prev ? prev : new_next_group;
			prev = cur;
			cur = next;
		}
		return prev;
	}

	//������Ԫ��k��k������ת
	ListNode* reversekGroup(ListNode* head, int k)
	{
		if (!head || k == 1)
		{
			return head;
		}
		ListNode dummy(-1);
		ListNode* prev = &dummy, *cur = head;
		dummy.next = head;
		int i = 0;
		while (cur)
		{
			++i;
			if (i % k == 0)
			{
				prev = reverseOnegroup(prev, cur->next);
				cur = prev->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		return dummy.next;
	}

	ListNode* reverseOnegroup(ListNode* prev, ListNode* next)
	{
		ListNode *last = prev->next;
		ListNode *cur = last->next;
		while (cur != next)
		{
			last->next = cur->next;
			cur->next = prev->next;
			prev->next = cur;
			cur = last->next;
		}
		return last;
	}

};

class LRUcache
{
public:
	LRUcache(int capacity)
	{
		_capacity = capacity;
	}

	int get(int key)
	{
		if (cacheMap.find(key) == cacheMap.end())
			return -1;

		//�ѵ�ǰ���ʽڵ��Ƶ�����ͷ�������Ҹ���map�иýڵ��λ��
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}

	void set(int key, int value)
	{
		if (cacheMap.find(key) == cacheMap.end)
		{
			//ɾ������β���ڵ㣨���ٷ��ʵĽڵ�)
			if (cacheList.size() == _capacity)
			{
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			//�����½ڵ㵽����ͷ����������map�����Ӹýڵ�
			cacheList.push_front(CacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			//���½ڵ��ֵ���ѵ�ǰ���ʵĽڵ��Ƶ�����ͷ�������Ҹ���map�иýڵ�ĵ�ַ
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	struct CacheNode
	{
		int key;
		int value;
		CacheNode(int k, int v)
			:key(k)
			, value(v)
		{}
	};
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;
	int _capacity;
};