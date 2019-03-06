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



//int sumNumbers(TreeNode* root)
//{
//	if (root == nullptr) return 0;
//
//	stack<TreeNode*> ts;
//	ts.push(root);
//	stack<TreeNode*> tmp;
//	int sum = 0;
//	while (!ts.empty())
//	{
//		auto node = ts.top();
//
//		// Ҷ�ӽڵ�
//		if (!node->left && !node->right)
//		{
//			// ����ts
//			int cn = 0;
//			while (!ts.empty())
//			{
//				auto top = ts.top();
//				sum += top->val* pow(10, cn++);
//				tmp.push(top);
//				ts.pop();
//			}
//
//			while (!tmp.empty())
//			{
//				ts.push(tmp.top());
//				tmp.pop();
//			}
//		}
//		if (node->left)ts.push(node->left);
//		if (node->right)ts.push(node->right);
//		ts.pop();
//	}
//	return sum;
//}


int treeSum(TreeNode* root, int sum)
{
	if (root == nullptr) return 0 ;

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

