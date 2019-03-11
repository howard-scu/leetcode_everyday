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
	int i = m - 1;
	int j = n - 1;
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

int nextGreaterElement(int n)
{
	//int t = n;
	//vector<unsigned char> digits;
	//while (t)
	//{
	//	digits.push_back(t % 10);
	//	t /= 10;
	//}
	//std::reverse(digits.begin(), digits.end());
	//std::next_permutation(digits.begin(), digits.end());
	//
	//long sum = 0;
	//for (int i = 0; i < digits.size(); i++)
	//	sum = sum * 10 + digits[i];

	//if (sum > std::numeric_limits<int>::max()) return -1;
	//else if (sum <= n) return -1;
	//else return sum;
	auto digits = to_string(n);
	next_permutation(begin(digits), end(digits));
	auto res = stoll(digits);
	return (res > INT_MAX || res <= n) ? -1 : res;
}


void reverseTree(TreeNode* root)
{
	if (root == nullptr) return;
	auto p = root->left;
	auto q = root->right;
	reverseTree(p);
	reverseTree(q);
	root->left = q;
	root->right = p;
}

bool compareTree(TreeNode* t1, TreeNode* t2)
{
	if (t1 == nullptr && t2 == nullptr) return true;
	else if (t1 && t2)
		return (t1->val == t2->val) &&
		compareTree(t1->left, t2->left)
		&& compareTree(t1->right, t2->right);
	else
		return false;
}

bool isSymmetric(TreeNode* root)
{
	if (root == nullptr) return true;
	else
	{
		// 逆转右子树
		reverseTree(root->right);

		// 比较左右子树
		return compareTree(root->left, root->right);
	}
}


vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> rets;
	if (root == nullptr) return rets;
	queue<TreeNode*> tq;
	tq.push(root);

	while (!tq.empty())
	{
		int n = tq.size();
		vector<int> row;
		for (int i = 0; i < n; i++)
		{
			auto node = tq.front();
			tq.pop();
			if (node->left)  tq.push(node->left);
			if (node->right) tq.push(node->right);
			row.push_back(node->val);
		}
		rets.push_back(row);
	}
	return rets;
}

//void pathSum(vector<vector<int>>& grid, int n, int m, int& sum)
//{
//	if (n == 1)
//	{
//		for (int i = 0; i < m; i++)
//			sum += grid[n - 1][i];
//		return;
//	}
//	else if (m == 1)
//	{
//		for (int i = 0; i < n; i++)
//			sum += grid[i][m - 1];
//		return;
//	}
//	else
//	{
//		int s1 = sum;
//		int s2 = sum;
//
//		pathSum(grid, n - 1, m, s1);
//		pathSum(grid, n, m - 1, s2);
//
//		sum = min(s1, s2) + grid[n - 1][m - 1];
//	}
//}
//
//int minPathSum(vector<vector<int>>& grid)
//{
//	int n = grid.size();
//	int m = grid[0].size();
//
//	int sum = 0;
//	pathSum(grid, n, m, sum);
//	return sum;
//}

int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
	for (int i = 1; i < m; i++)
		sum[i][0] = sum[i - 1][0] + grid[i][0];
	for (int j = 1; j < n; j++)
		sum[0][j] = sum[0][j - 1] + grid[0][j];
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
	return sum[m - 1][n - 1];
}


int uniquePaths(int m, int n)
{
	vector<vector<int> > nPath(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			nPath[i][j] = nPath[i - 1][j] + nPath[i][j - 1];
	return nPath[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int> > nPath(m, vector<int>(n, 1));
	
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			nPath[i][j] = nPath[i - 1][j] + nPath[i][j - 1];
	return nPath[m - 1][n - 1];
}