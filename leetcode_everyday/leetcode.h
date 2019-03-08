#include <iostream>
#include "helper.h"

/*
* �㷨˼·��
*	1.�����Ϊ�գ���ֱ�ӷ��ش�
*	2.�������Ϊ�գ��������������
*		2.1.���һ��������Һ��Ӷ���Ϊ�գ���pop�ýڵ㣬�������Һ��������
*		2.2.�������һ����㣬����Ϊ�գ��Һ��Ӳ�Ϊ�գ������һ��������ȫ������
*		2.3.�������һ����㣬���Ӳ�Ϊ�գ��Һ���Ϊ�գ��������Һ��Ӷ�Ϊ�գ�
*			��ýڵ�֮��Ķ����еĽ�㶼ΪҶ�ӽڵ㣻
*/
bool isCompleteTree(TreeNode* root)
{
	if (root == nullptr) return false;

	queue<TreeNode*> tq;
	tq.push(root);

	bool leaf = false;
	while (!tq.empty())
	{
		auto node = tq.front();
		tq.pop();

		if (leaf && (node->left != nullptr || node->right != nullptr))
		{
			return false;
		}

		if (node->left == nullptr && node->right != nullptr)		return false;
		else if (node->left == nullptr && node->right == nullptr)	leaf = true;
		else if (node->left != nullptr && node->right == nullptr)
		{
			leaf = true;
			tq.push(node->left);
		}
		else if (node->left != nullptr && node->right != nullptr)
		{
			tq.push(node->left);
			tq.push(node->right);
		}
	}
	return true;
}


int treeSum(TreeNode* root, int sum)
{
	if (root == nullptr) return 0;

	if (root->left == nullptr && root->right == nullptr)
	{
		return sum * 10 + root->val;
	}
	else
	{
		sum = sum * 10 + root->val;
		int total = 0;
		if (root->left != nullptr)
		{
			total += treeSum(root->left, sum);
		}
		if (root->right != nullptr)
		{
			total += treeSum(root->right, sum);
		}
		return total;
	}
}

int sumNumbers(TreeNode* root)
{
	return treeSum(root, 0);
}

void make_permuteUnique(vector<int>& nums, vector<vector<int>>& permutes, int p, int q)
{
	if (p == q)
	{
		return permutes.push_back(nums);
	}
	for (int i = p; i <= q; i++)
	{
		bool do_swap = true;
		for (int j = i + 1; j <= q; j++)
		{
			if (nums[i] == nums[j])
			{
				do_swap = false;
				break;
			}
		}
		if (do_swap)
		{
			swap(nums[p], nums[i]);
			make_permuteUnique(nums, permutes, p + 1, q);
			swap(nums[p], nums[i]);
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> permutes;
	make_permuteUnique(nums, permutes, 0, nums.size() - 1);
	return permutes;
}

void make_permute(vector<int>& nums, vector<vector<int>>& permutes, int p, int q)
{
	if (p == q)
	{
		return permutes.push_back(nums);
	}
	for (int i = p; i <= q; i++)
	{
		swap(nums[p], nums[i]);
		make_permute(nums, permutes, p + 1, q);
		swap(nums[p], nums[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> permutes;
	make_permute(nums, permutes, 0, nums.size() - 1);
	return permutes;
}

void nextPermutation(vector<int>& nums)
{
	// 1.Find the largest index k such that a[k] < a[k + 1]. 
	//   If no such index exists, the permutation is the last permutation.
	int k = -1;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] < nums[i + 1]) k = i;
	}

	if (k != -1)
	{
		// 2.Find the largest index l greater than k such that a[k] < a[l].
		int l = k;
		for (int i = k; i < nums.size(); i++)
		{
			if (nums[k] < nums[i]) l = i;
		}

		// 3.Swap the value of a[k] with that of a[l].
		swap(nums[k], nums[l]);

		// 4.Reverse the sequence from a[k + 1] up to and including the final element a[n].
		int p = k + 1;
		int q = nums.size() - 1;
		while (p < q)
		{
			swap(nums[p++], nums[q--]);
		}
	}
	else
	{
		int p = 0;
		int q = nums.size() - 1;
		while (p < q)
		{
			swap(nums[p++], nums[q--]);
		}
	}
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == nullptr) return l2;
	else if (l2 == nullptr) return l1;
	else
	{
		ListNode* header = new ListNode(0);
		ListNode* pNode = header;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				pNode->next = l1;
				l1 = l1->next;
				pNode = pNode->next;
			}
			if (l1 != nullptr && l2->val < l1->val)
			{
				pNode->next = l2;
				l2 = l2->next;
				pNode = pNode->next;
			}
		}
		while (l1 != nullptr)
		{
			pNode->next = l1;
			l1 = l1->next;
			pNode = pNode->next;
		}
		while (l2 != nullptr)
		{
			pNode->next = l2;
			l2 = l2->next;
			pNode = pNode->next;
		}
		pNode = header;
		header = header->next;
		delete pNode;
		return header;
	}
}


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = m-1;
	int j = n-1;
	int k = m + n - 1;

	while (i >= 0 && j >= 0)
	{
		if (nums1[i] >= nums2[j])
		{
			nums1[k] = nums1[i];
			i--;
		}
		else
		{
			nums1[k] = nums2[j];
			j--;
		}
		k--;
	}
	while (i >= 0)
	{
		nums1[k] = nums1[i];
		i--;
		k--;
	}
	while (j >= 0)
	{
		nums1[k] = nums2[j];
		j--;
		k--;
	}
}


int subarraySum(vector<int>& nums, int k)
{
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int sum = 0;
		for (int j = i; j < nums.size(); j++)
		{
			sum += nums[j];
			if (sum == k)
				count++;
		}
	}
	return count;
}