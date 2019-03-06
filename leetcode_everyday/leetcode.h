#include <iostream>
#include "helper.h"

/*
* 算法思路：
*	1.如果树为空，则直接返回错
*	2.如果树不为空：层序遍历二叉树
*		2.1.如果一个结点左右孩子都不为空，则pop该节点，将其左右孩子入队列
*		2.2.如果遇到一个结点，左孩子为空，右孩子不为空，则该树一定不是完全二叉树
*		2.3.如果遇到一个结点，左孩子不为空，右孩子为空；或者左右孩子都为空；
*			则该节点之后的队列中的结点都为叶子节点；
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
//		// 叶子节点
//		if (!node->left && !node->right)
//		{
//			// 遍历ts
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

