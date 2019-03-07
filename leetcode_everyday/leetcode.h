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