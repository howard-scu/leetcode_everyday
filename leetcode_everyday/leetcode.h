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
	vector<vector<long> > path(m, vector<long>(n, 0));

	bool flag = true;
	for (int i = 0; i < m; i++)
	{
		if (obstacleGrid[i][0])
			flag = false;
		if (flag)
			path[i][0] = 1;
		else
			path[i][0] = 0;
	}

	flag = true;
	for (int i = 0; i < n; i++)
	{
		if (obstacleGrid[0][i])
			flag = false;
		if (flag)
			path[0][i] = 1;
		else
			path[0][i] = 0;
	}

	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			if (obstacleGrid[i][j] == 0)
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			else
				path[i][j] = 0;
	return path[m - 1][n - 1];
}


void helper(vector<vector<int>>& result, vector<int>& lst, vector<int>& candidates, int target, int sum, int pos)
{
	if (pos == candidates.size() && sum != target)
	{
		return;
	}
	//结果可行的条件，需维护一个当前所有数的sum
	if (sum == target)
	{
		result.push_back(lst);
		return;
	}
	//和subsets一样，从当前位置向后取
	for (int i = pos; i < candidates.size(); i++)
	{
		//当前的数加上当前取出的数的和小于等于target时才继续向下
		if (sum + candidates[i] <= target)
		{
			lst.push_back(candidates[i]);

			//每个数能取多次，因此传递的pos就是当前数的位置，这样下次可能再取
			helper(result, lst, candidates, target, sum + candidates[i], i);
			lst.erase(lst.end() - 1);
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	// 排序
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> lst;
	int sum = 0;
	helper(result, lst, candidates, target, 0, 0);

	return result;
}

void combine_helper(int n, int k, vector<vector<int>>& result, vector<int>& lst, int pos)
{
	//// 不满足条件
	//if (pos == n && lst.size() != k)
	//	return;

	// 满足条件
	if (lst.size() == k)
	{
		result.push_back(lst);
	}

	for (int i = pos; i < n; i++)
	{
		if (lst.size() < k)
		{
			lst.push_back(i + 1);
			combine_helper(n, k, result, lst, i + 1);
			lst.pop_back();
		}
	}
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> result;
	vector<int> com;
	combine_helper(n, k, result, com, 0);
	return result;
}

void combinationSum2_helper(vector<int>& candidates, int target,
	vector<vector<int>>& results, vector<int>& combination, int sum, int pos)
{
	// 失败组合条件
	if (pos == candidates.size() && sum > target)
		return;

	// 成功组合条件
	if (sum == target)
		results.push_back(combination);

	// 迭代
	for (int i = pos; i < candidates.size(); i++)
	{
		if (i > pos && candidates[i] == candidates[i - 1]) continue;
		if (sum < target)
		{
			combination.push_back(candidates[i]);
			combinationSum2_helper(candidates, target, results, combination, sum + candidates[i], i + 1);
			combination.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());

	vector<vector<int>> result;
	vector<int>			combination;
	combinationSum2_helper(candidates, target, result, combination, 0, 0);
	return result;
}

void combinationSum3_helper(int k, int n,
	vector<vector<int>>& results, vector<int>& combination, int sum, int pos)
{
	if (combination.size() > k || sum > n) return;

	if (sum == n && combination.size() == k)
	{
		results.push_back(combination);
	}

	for (int i = pos; i < 9; i++)
	{
		if (sum < n)
		{
			combination.push_back(i + 1);
			combinationSum3_helper(k, n, results, combination, sum + i + 1, i + 1);
			combination.pop_back();
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> results;
	vector<int>			combination;
	combinationSum3_helper(k, n, results, combination, 0, 0);
	return results;
}

void subsets_helper(vector<int>& nums,
	vector<vector<int>>& results, vector<int>& subset, int begin)
{
	if (subset.size() > nums.size())return;
	else if (subset.size() <= nums.size())
		results.push_back(subset);

	for (int i = begin; i < nums.size(); i++)
	{
		if (subset.size() < nums.size())
		{
			subset.push_back(nums[i]);
			subsets_helper(nums, results, subset, i + 1);
			subset.pop_back();
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> results;
	vector<int> subset;
	subsets_helper(nums, results, subset, 0);
	return results;
}

void subsetsWithDup_helper(vector<int>& nums,
	vector<vector<int>>& results, vector<int>& subset, int begin)
{
	if (subset.size() > nums.size())
		return;
	else if (subset.size() <= nums.size())
		results.push_back(subset);

	for (int i = begin; i < nums.size(); i++)
	{
		if (i > begin && nums[i] == nums[i - 1])
			continue;

		if (subset.size() < nums.size())
		{
			subset.push_back(nums[i]);
			subsetsWithDup_helper(nums, results, subset, i + 1);
			subset.pop_back();
		}
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	vector<vector<int>> results;
	vector<int>			subset;
	subsetsWithDup_helper(nums, results, subset, 0);
	return results;
}

#include <unordered_map>

void letterCombinations_helper(string& digits,
	vector<string>& results, string ss, int begin)
{
	unordered_map <char, string> dm{ { '2',"abc" }, {'3',"def"},{'4',"ghi"},
	{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };

	if (begin > digits.length()) return;

	if (ss.length() == digits.length())
		results.push_back(ss);

	for (int i = begin; i < digits.length(); i++)
	{
		auto ts = dm[digits[begin]];
		for (int j = 0; j < ts.length(); j++)
		{
			if (ss.length() < digits.length())
			{
				ss.push_back(ts[j]);
				letterCombinations_helper(digits, results, ss, i + 1);
				ss.pop_back();
			}
		}
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string>	results;
	string			ss;
	letterCombinations_helper(digits, results, ss, 0);
	return results;
}

bool isLongPressedName(string name, string typed)
{
	// alex
	// aallex
	int i = 0;
	int j = 0;

	while (i < name.length() || j < typed.length())
	{
		if (name[i] == typed[j])
		{
			i++;
			j++;
		}
		else if (typed[j] != name[i] && typed[j] == name[i - 1])
		{
			j++;
		}
		else
			return false;
	}
	if (i == name.length() && j == typed.length())
		return true;
	else
		return false;
}

int minSubArrayLen(int s, vector<int> nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	int ans = INT_MAX;
	vector<int> sums(n + 1, 0);
	for (int i = 1; i <= n; i++)
		sums[i] = sums[i - 1] + nums[i - 1];
	for (int i = 1; i <= n; i++)
	{
		int to_find = s + sums[i - 1];
		auto bound = lower_bound(sums.begin(), sums.end(), to_find);
		if (bound != sums.end())
		{
			ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
		}
	}
	return (ans != INT_MAX) ? ans : 0;
}

void rangeSumBST_helper(TreeNode* root, int L, int R, int& sum)
{
	if (root == nullptr) return;

	// Approach 1:
	//rangeSumBST_helper(root->left, L, R, sum);
	//if (root->val >= L || root->val <= R)
	//	sum += root->val;
	//rangeSumBST_helper(root->right, L, R, sum);

	// Approach 2:
	if (root->val >= L && root->val <= R)
	{
		rangeSumBST_helper(root->left, L, R, sum);
		sum += root->val;
		rangeSumBST_helper(root->right, L, R, sum);
	}
	else if (root->val < L)
	{
		rangeSumBST_helper(root->right, L, R, sum);
	}
	else
	{
		rangeSumBST_helper(root->left, L, R, sum);
	}
}

int rangeSumBST(TreeNode* root, int L, int R)
{
	int sum = 0;
	rangeSumBST_helper(root, L, R, sum);
	return sum;
}

bool containsNearbyAlmostDuplicate(vector<int> nums, int k, int t)
{
	set<long> window;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) window.erase(nums[i - k - 1]);
		auto pos = window.lower_bound((long)nums[i] - t);
		if (pos != window.end() && t >= *pos - nums[i])
			return true;
		window.insert(nums[i]);
	}
	return false;
	//for (int i = 0; i < nums.size() - k; i++)
	//{
	//	vector<int> subvec(nums.begin() + i, nums.begin() + i + k + 1);
	//	sort(subvec.begin(), subvec.end());
	//	for (int j = 0; j < subvec.size() - 1; j++)
	//	{
	//		auto d = abs(subvec[j + 1] - subvec[j]);
	//		if (d <= t)
	//			return true;
	//	}
	//}
	//return false;
}


bool containsNearbyDuplicate(vector<int> nums, int k)
{
	set<int> vset;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) vset.erase(nums[i - k - 1]);
		auto it = vset.lower_bound(nums[i]);
		if (it != vset.end() && *it == nums[i])
			return true;

		vset.insert(nums[i]);
	}
	return false;
}


bool checkPossibility(vector<int> nums)
{
	int pos = 0;
	int cnt = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] - nums[i - 1] < 0)
		{
			pos = i - 1;
			cnt++;
		}
	}
	if (cnt >= 2) return false;
	else if (cnt == 0) return true;
	else
	{
		if (pos == 0) return true;
		else if (pos == nums.size() - 2) return true;
		else if (nums[pos - 1] <= nums[pos + 1] || nums[pos] <= nums[pos + 2])
			return true;

	}
	return false;
}


int diameterOfBinaryTree_helper(TreeNode* root, int& result)
{
	if (root == nullptr)
		return 0;
	else
	{
		auto l = diameterOfBinaryTree_helper(root->left, result);
		auto r = diameterOfBinaryTree_helper(root->right, result);
		result = result > (l + r + 1) ? result : (l + r + 1);
		return (l > r ? l : r) + 1;
	}
}

int diameterOfBinaryTree(TreeNode* root)
{
	int result = 1;
	diameterOfBinaryTree_helper(root, result);
	return result - 1;
}

int maxDepth(Node* root)
{
	if (root == nullptr) return 0;
	else
	{
		int depth = 1;
		for (int i = 0; i < root->children.size(); i++)
		{
			auto d = maxDepth(root->children[i]) + 1;
			if (depth < d) depth = d;
		}
		return depth;
	}
}


unordered_map<char, bool> dict{
	make_pair('a',true),
	make_pair('e',true),
	make_pair('i',true),
	make_pair('o',true),
	make_pair('u',true) };

string reverseVowels(string s)
{
	int i = 0;
	int j = s.length() - 1;
	while (i < j)
	{
		if (dict[s[i]] != true) i++;
		if (dict[s[j]] != true) j--;
		if (dict[s[i]] && dict[s[j]])
			swap(s[i++], s[j--]);
	}
	return s;
}

string longestPalindrome(string s)
{
	if (s.length() <= 1) return s;
	vector<vector<bool>> bvec(s.length(), vector<bool>(s.length(), false));
	int maxLen = 0;
	int max_i = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		for (int j = i; j < s.length(); j++)
		{
			if (i == j)
				bvec[i][j] = true;
			else if (j == i + 1)
				bvec[i][j] = (s[i] == s[j]);
			else if (j > i + 1)
			{
				bvec[i][j] = (bvec[i + 1][j - 1] && (s[i] == s[j]));
			}
			if (bvec[i][j] && maxLen < (j - i + 1))
			{
				maxLen = (j - i + 1);
				max_i = i;
			}
			//cout << i << "," << j << "," << bvec[i][j] << "," << s.substr(i, j - i + 1) << endl;
		}
	}
	return s.substr(max_i, maxLen);
}


string shortestPalindrome(string s)
{
	if (s.length() <= 1) return s;
	vector<vector<bool>> bvec(s.length(), vector<bool>(s.length(), false));
	int max_i = 0;
	int maxLen = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		for (int j = i; j < s.length(); j++)
		{
			if (i == j)
				bvec[i][j] = true;
			else if (j == i + 1)
				bvec[i][j] = (s[i] == s[j]);
			else if (j > i + 1)
			{
				bvec[i][j] = (bvec[i + 1][j - 1] && (s[i] == s[j]));
			}
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (bvec[0][i])
		{
			max_i = i;
			maxLen = i - 0 + 1;
		}
	}
	auto tail = s.substr(max_i + 1, s.length() - maxLen);
	reverse(tail.begin(), tail.end());
	return  tail + s;
}


int thirdMax(vector<int>& nums)
{
	set<int> top3;
	for (int i = 0; i < nums.size(); i++)
	{
		top3.insert(nums[i]);
		if (top3.size() > 3)
			top3.erase(top3.begin()); // the minimun
	}
	return *top3.begin();
}


int maxProduct(vector<int> nums)
{
	//int result = numeric_limits<int>::min();
	//vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
	//for (int i = 0; i < nums.size(); i++)
	//{
	//	for (int j = i; j < nums.size(); j++)
	//	{
	//		if (i == j)
	//			dp[i][j] = nums[i];
	//		else
	//			dp[i][j] = dp[i][j - 1] * nums[j];
	//		if (result < dp[i][j])
	//			result = dp[i][j];
	//	}
	//}
	//return result;

	int imax = nums[0];
	int imin = nums[0];
	int r = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < 0)
			swap(imax, imin);
		imax = max(nums[i], imax*nums[i]);
		imin = min(nums[i], imin*nums[i]);
		r = max(imax, r);
	}
	return r;
}

string convert(string s, int numRows)
{
	//A     G
	//B   F H
	//C E   I
	//D 
	//string result(s);
	//int c = 2 * numRows - 2;
	//for (int i = 0; i < numRows; i++)
	//{
	//	for (int j = i; j < s.length(); j+=c)
	//	{
	//		result[i] = s[j];
	//		if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
	//			ret += s[j + cycleLen - i];
	//	}
	//}

	if (numRows == 1) return s;

	string ret;
	int n = s.size();
	int cycleLen = 2 * numRows - 2;

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j + i < n; j += cycleLen)
		{
			ret += s[j + i];
			if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
				ret += s[j + cycleLen - i];
		}
	}
	return ret;
}


ListNode* rotateRight(ListNode* head, int k)
{
	if (head == nullptr || k == 0) return head;

	// 计算长度
	ListNode* p = head;
	int len = 0;
	while (p)
	{
		p = p->next;
		len++;
	}

	k = k % len;
	if (k == 0)
		return head;

	k = len - k;

	// 找kth-node
	p = head;
	ListNode* q = p;
	for (int i = 0; i < k; i++)
	{
		q = p;
		p = p->next;
	}
	q->next = nullptr;

	q = p;
	while (q->next)
	{
		q = q->next;
	}

	q->next = head;
	return p;
}


vector<ListNode*> splitListToParts(ListNode* root, int k)
{
	if (root == nullptr)
		return vector<ListNode*>(k, nullptr);

	vector<ListNode*> result;

	// 计算长度
	ListNode* p = root;
	int len = 0;
	while (p)
	{
		p = p->next;
		len++;
	}

	int n = len / k;
	int m = len % k;

	// 前面[m]个list每个包含[n+1]个节点
	// 后面[k-m]个list每个包含[n]个节点
	if (n == 0)
	{
		ListNode* t = root;
		ListNode* s = root;
		for (int i = 0; i < m; i++)
		{
			s = t->next;
			t->next = nullptr;
			result.push_back(t);
			t = s;
		}
		for (int i = 0; i < k - m; i++)
		{
			result.push_back(nullptr);
		}
		return result;
	}
	p = root;
	ListNode* q = root;
	for (int i = 0; i < m; i++)
	{
		p = q;
		for (int j = 0; j < n; j++)
		{
			p = p->next;
		}
		ListNode* t = p->next;
		p->next = nullptr;
		result.push_back(q);
		q = t;
	}

	for (int i = 0; i < k - m; i++)
	{
		p = q;
		for (int j = 0; j < n - 1; j++)
		{
			p = p->next;
		}
		ListNode* t = p->next;
		p->next = nullptr;
		result.push_back(q);
		q = t;
	}
	return result;
}

void printList(ListNode* head)
{
	ListNode* p = head;
	while (p)
	{
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << " null " << endl;
}

ListNode* oddEvenList(ListNode* head)
{
	if (head == nullptr) return head;

	ListNode* odd = new ListNode(0);
	ListNode* even = new ListNode(0);

	ListNode* t = odd;
	ListNode* s = even;
	int id = 0;
	ListNode* p = head;
	while (p)
	{
		id++;

		ListNode* q = p;
		p = p->next;
		q->next = nullptr;

		if (id % 2 == 1)
		{
			t->next = q;
			t = t->next;
		}
		else
		{
			s->next = q;
			s = s->next;
		}
	}
	t->next = even->next;
	delete even;
	head = odd->next;
	delete odd;
	return head;
}


class MyLinkedList
{
public:
	/** Initialize your data structure here. */
	MyLinkedList()
	{
		head = new LNode(0);
		tail = head;
		length = 0;
	}

	~MyLinkedList()
	{
		LNode* p = head;
		while (p)
		{
			LNode* q = p->next;
			delete p;
			p = q;
		}
	}

	void print()
	{
		LNode* p = head->next;
		while (p)
		{
			cout << p->val << " -> ";
			p = p->next;
		}
		cout << "null" << endl;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index <0 || index > length - 1)
			return -1;

		LNode* p = head;
		while (index >= 0)
		{
			p = p->next;
			index--;
		}
		return p->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		if (head == tail)
			addAtTail(val);
		else
		{
			LNode* p = new LNode(val);
			LNode* q = head->next;
			head->next = p;
			p->next = q;
			length++;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		LNode* p = new LNode(val);
		tail->next = p;
		tail = tail->next;
		length++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index <0 || index > length)
			return;

		if (index == length)
		{
			print();
			addAtTail(val);
			print();
		}
		else
		{
			LNode* p = head;
			while (index > 0)
			{
				p = p->next;
				index--;
			}
			LNode* q = new LNode(val);
			LNode* t = p->next;
			p->next = q;
			q->next = t;
			length++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index < 0 || index >= length)
			return;

		LNode* p = head;
		while (index > 0)
		{
			p = p->next;
			index--;
		}
		LNode* q = p->next;
		p->next = q->next;
		if (q == tail)
			tail = p;
		delete q;
		length--;
	}

private:
	typedef struct LNode
	{
		int		val;
		LNode*	next;
		LNode(int x) : val(x), next(nullptr) {}
	}LNode;

	LNode* head;
	LNode* tail;
	int	   length;
};


vector<int> plusOne(vector<int>& digits)
{
	vector<int> result(digits.size(), 0);

	int carry = 1;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		auto s = digits[i] + carry;
		result[i] = s % 10;
		carry = s / 10;
	}
	if (carry != 0)
		result.insert(result.begin(), carry);
	return result;
}

int trailingZeroes(int n)
{
	int c = 0;
	while (n)
	{
		c += (n / 5);
		n /= 5;
	}
	return c;
}

class MinStack
{
public:
	/** initialize your data structure here. */
	MinStack()
	{
		imin = -1;
		itop = -1;
	}

	void push(int x)
	{
		if (imin < 0)
		{
			istack.push_back(x);
			imin = 0;
			itop = 0;
		}
		else
		{
			istack.push_back(x);
			itop++;
			if (istack[imin] > x)
				imin = itop;
		}
	}

	void pop()
	{
		if (itop >= 0)
		{
			if (imin == itop)
			{
				// update imin
				auto min = numeric_limits<int>::max();
				for (int i = 0; i < itop; i++)
				{
					if (min > istack[i])
					{
						min = istack[i];
						imin = i;
					}
				}
			}
			istack.erase(istack.begin() + itop);
			itop--;
		}
	}

	int top()
	{
		if (itop >= 0)
			return istack[itop];
		else
			return 0;
	}

	int getMin()
	{
		if (imin >= 0)
			return istack[imin];
		else
			return 0;
	}

	void print()
	{
		for (int i = 0; i < istack.size(); i++)
			cout << istack[i] << ",";

		cout << endl;
		cout << "imin = " << imin << endl;
		cout << "itop = " << itop << endl;
		cout << "--------------" << endl;
	}

private:
	int				imin;
	int				itop;
	vector<int>		istack;
};


bool hasCycle(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return false;

	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast != slow)
	{
		if (!fast || !fast->next)
			return false;

		fast = fast->next->next;
		slow = slow->next;
	}
	return true;
}


ListNode *detectCycle(ListNode *head)
{
	// _____ ____
	//  x1  | x2 |
	//      |____|
	//        x3 
	// x1 + x2 + x3 + x2 = 2*(x1+x2)
	// ==>   x1 = x3
	if (head == nullptr || head->next == nullptr)
		return nullptr;

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast && slow)
	{
		if (slow->next)
			slow = slow->next;
		else return nullptr;

		if (fast->next && fast->next->next)
			fast = fast->next->next;
		else return nullptr;

		if (fast == slow)
			break;
	}

	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

vector<vector<int>> generate(int n)
{
	vector<vector<int>> result;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			result.push_back(vector<int>{1});
		else if (i == 1)
			result.push_back(vector<int>{1, 1});
		else
		{
			vector<int> line(i + 1, 1);
			for (int j = 1; j < i; j++)
			{
				line[j] = result[i - 1][j - 1] + result[i - 1][j];
			}
			result.push_back(line);
		}
	}
	return result;
}

vector<int> getRow(int rowIndex)
{
	vector<int> res;
	for (int i = 0; i <= rowIndex; i++)
	{
		res.push_back(1);
		for (int j = i - 1; j >= 1; --j)
			res[j] = res[j] + res[j - 1];
	}
	return res;
}
int height(TreeNode* root)
{
	if (root == nullptr) return 0;
	int l = height(root->left) + 1;
	int r = height(root->right) + 1;
	return max(l, r);
}
bool isBalanced(TreeNode* root)
{
	if (root == nullptr) return true;
	int l = height(root->left);
	int r = height(root->right);
	return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

vector<int> leaf_sequence(TreeNode* root)
{
	if (root == nullptr) return vector<int>();
	else if (!root->left && !root->right) return vector<int>(root->val);
	else
	{
		auto l = leaf_sequence(root->left);
		auto r = leaf_sequence(root->right);
		l.insert(l.end(), r.begin(), r.end());
		return l;
	}
}

bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
	auto l = leaf_sequence(root1);
	auto r = leaf_sequence(root1);
	if (l.size() != r.size()) return false;
	for (int i = 0; i < l.size(); i++)
		if (l[i] != r[i]) return false;
	return true;
}

#include <queue>

class MyStack
{
public:
	/** Initialize your data structure here. */
	MyStack()
	{
		use = 1;
	}

	/** Push element x onto stack. */
	void push(int x)
	{
		if (use == 1)
		{
			q1.push(x);
		}
		else
		{
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		if (empty())
			return 0;
		if (use == 1)
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			auto itop = q1.front();
			q1.pop();
			use = 2;
			return itop;
		}
		else
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			auto itop = q2.front();
			q2.pop();
			use = 1;
			return itop;
		}
		return 0;
	}

	/** Get the top element. */
	int top()
	{
		if (empty())
			return 0;
		if (use == 1)
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			auto itop = q1.front();
			q2.push(q1.front());
			q1.pop();
			use = 2;
			return itop;
		}
		else
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			auto itop = q2.front();
			q1.push(q2.front());
			q2.pop();
			use = 1;
			return itop;
		}
		return 0;
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return (q1.empty() && q2.empty());
	}

private:
	queue<int>	q1;
	queue<int>	q2;
	int use;
};


class MyQueue
{
public:
	/** Initialize your data structure here. */
	MyQueue()
	{
	}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		if (empty()) return 0;

		if (!s2.empty())
		{
			auto top = s2.top();
			s2.pop();
			return top;
		}
		else
		{
			while (!s1.empty())
			{
				auto top = s1.top();
				s2.push(top);
				s1.pop();
			}
			auto top = s2.top();
			s2.pop();
			return top;
		}
	}

	/** Get the front element. */
	int peek()
	{
		if (empty()) return 0;

		if (!s2.empty())
		{
			auto top = s2.top();
			return top;
		}
		else
		{
			while (!s1.empty())
			{
				auto top = s1.top();
				s2.push(top);
				s1.pop();
			}
			auto top = s2.top();
			return top;
		}
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return s1.empty() && s2.empty();
	}

private:
	stack<int>	s1;
	stack<int>	s2;
};


class MyCircularQueue
{
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k)
	{
		que.resize(k + 1);
		front = 0;
		rear = 0;
		size = k;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value)
	{
		if (isFull()) return false;
		else
		{
			que[rear] = value;
			rear = (rear + 1) % (size + 1);
			return true;
		}
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue()
	{
		if (isEmpty()) return false;
		else
		{
			front = (front + 1) % (size + 1);
			return true;
		}
	}

	/** Get the front item from the queue. */
	int Front()
	{
		if (isEmpty()) return -1;
		else
			return que[(front) % (size + 1)];
	}

	/** Get the last item from the queue. */
	int Rear()
	{
		if (isEmpty()) return -1;
		else
			return que[(rear + size) % (size + 1)];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty()
	{
		return front == rear;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull()
	{
		return front == ((rear + 1) % (size + 1));
	}

private:
	vector<int> que;
	int front;
	int rear;
	int size;
};


int numFriendRequests(vector<int>& ages)
{
	vector<int> count(121, 0);

	for (auto age : ages)
		count[age]++;

	int ans = 0;
	for (int ageA = 0; ageA <= 120; ageA++)
	{
		int countA = count[ageA];
		for (int ageB = 0; ageB <= 120; ageB++)
		{
			int countB = count[ageB];
			if (ageA * 0.5 + 7 >= ageB) continue;
			if (ageA < ageB) continue;
			if (ageA < 100 && 100 < ageB) continue;
			ans += countA * countB;
			if (ageA == ageB) ans -= countA;
		}
	}

	return ans;
}


int findMin_helper(vector<int>& nums, int l, int r)
{
	if (l == r)
		return nums[l];
	if (nums[l] < nums[r])
		return nums[l];

	int mid = (l + r) / 2;
	if (nums[l] > nums[mid])
		return findMin_helper(nums, l, mid);
	return findMin_helper(nums, mid + 1, r);
}

int findMin(vector<int> nums)
{
	return findMin_helper(nums, 0, nums.size() - 1);
}

int maxArea(vector<int> height)
{
	int result = 0;
	// 1, 8, 6, 2, 5, 4, 8, 3, 7
	int i = 0;
	int j = height.size() - 1;
	while (i < j)
	{
		int h = height[i] < height[j] ? height[i] : height[j];
		if (result < h*(j - i)) result = h * (j - i);

		height[i] < height[j] ? i++ : j--;
	}
	return result;
}

vector<vector<int> > threeSum(vector<int> &num)
{

	vector<vector<int> > res;

	std::sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++)
	{

		int target = -num[i];
		int front = i + 1;
		int back = num.size() - 1;

		while (front < back)
		{

			int sum = num[front] + num[back];

			// Finding answer which start from number num[i]
			if (sum < target)
				front++;

			else if (sum > target)
				back--;

			else {
				vector<int> triplet(3, 0);
				triplet[0] = num[i];
				triplet[1] = num[front];
				triplet[2] = num[back];
				res.push_back(triplet);

				// Processing duplicates of Number 2
				// Rolling the front pointer to the next different number forwards
				while (front < back && num[front] == triplet[1]) front++;

				// Processing duplicates of Number 3
				// Rolling the back pointer to the next different number backwards
				while (front < back && num[back] == triplet[2])  back--;
			}

		}

		// Processing duplicates of Number 1
		while (i + 1 < num.size() && num[i + 1] == num[i])
			i++;

	}

	return res;

}

int threeSumClosest(vector<int> nums, int target)
{
	sort(nums.begin(), nums.end());
	int abs_diff = numeric_limits<int>::max();
	if (nums.size() < 3) return 0;
	int result = nums[0] + nums[1] + nums[2];
	for (int i = 0; i < nums.size(); i++)
	{
		int front = i + 1;
		int back = nums.size() - 1;
		while (front < back)
		{
			auto sum = target - nums[i];
			if (abs_diff > abs(sum - nums[front] - nums[back]))
			{
				abs_diff = abs(sum - nums[front] - nums[back]);
				result = nums[i] + nums[front] + nums[back];
			}
			if (sum > nums[front] + nums[back])
				front++;
			else if (sum < nums[front] + nums[back])
				back--;
			else
				return target;
		}
	}
	return result;
}

vector<vector<int>> fourSum(vector<int> nums, int target)
{
	if (nums.size() < 4) return vector<vector<int>>();
	// 1, 0, -1, 0, -2, 2
	std::sort(nums.begin(), nums.end());
	// -2,-1,0,0,1,2 
	vector<vector<int>> result;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			int l = j + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				if (nums[i] + nums[j] + nums[l] + nums[r] < target)
					l++;
				else if (nums[i] + nums[j] + nums[l] + nums[r] > target)
					r--;
				else
				{
					result.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
					do { l++; } while (l < r && nums[l] == nums[l - 1]);
					do { r--; } while (l < r && nums[r] == nums[r + 1]);
				}
			}
			while (j + 1 < nums.size() && nums[j + 1] == nums[j])
				j++;
		}
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			i++;
	}
	return result;
}


int search(vector<int> nums, int target)
{
	if (nums.size() == 0) return -1;
	int l = 0;
	int r = nums.size() - 1;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (nums[l] < nums[r]) break;
		else if (nums[l] > nums[m]) r = m;
		else l = m + 1;
	}

	// binary search
	int n = nums.size();
	r = (l + n - 1) % n;
	int size = n;
	while (size > 0)
	{
		int m = (l + ((r - l + n) % n) / 2) % n;
		if (nums[m] < target)
			l = (m + 1) % n;
		else if (nums[m] > target)
			r = (m - 1 + n) % n;
		else
			return m;
		size = (r - l + n + 1) % n;
	}
	return -1;
}

vector<int> sortedSquares(vector<int>& nums)
{
	// std::for_each(nums.begin(), nums.end(), [](int &n){ n = abs(n); n*=n;});
	// sort(nums.begin(),nums.end());
	// return nums;
	vector<int> res(nums.size());
	int i = 0;
	int j = nums.size() - 1;
	int t = nums.size() - 1;
	while (i <= j)
	{
		if (abs(nums[i]) >= abs(nums[j]))
		{
			res[t] = nums[i] * nums[i];
			i++;
			t--;
		}
		else
		{
			res[t] = nums[j] * nums[j];
			j--;
			t--;
		}
	}
	return res;
}

vector<int> sortArrayByParity(vector<int>& nums)
{
	int i = 0;
	int j = nums.size() - 1;
	while (i < j)
	{
		while (i < j && nums[i] % 2 == 0) i++;
		while (i < j && nums[j] % 2 == 1) j--;
		swap(nums[i++], nums[j--]);
	}
	return nums;
}


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
{
	vector<vector<int>> result;
	int n = A[0].size();
	for (int i = 0; i < A.size(); i++)
	{
		vector<int> line(A[0].size());
		for (int j = 0; j < A[0].size(); j++)
		{
			line[j] = 0x1 & (~A[i][n - j - 1]);
		}
		result.push_back(line);
	}
	return result;
}

vector<vector<int>> transpose(vector<vector<int>>& A)
{
	vector<vector<int>> result;
	int n = A[0].size();
	for (int i = 0; i < A[0].size(); i++)
	{
		vector<int> line(A.size());
		for (int j = 0; j < A.size(); j++)
		{
			line[j] = A[j][i];
		}
		result.push_back(line);
	}
	return result;
}
vector<int> sortArrayByParityII(vector<int> A)
{
	int i = 0;
	int j = A.size() - 1;

	while (i < A.size() && j >= 0)
	{
		while ((i < A.size()) && (i % 2 == 0) && (A[i] % 2 == 0))
			i += 2;
		while ((j >= 0) && (j % 2 == 1) && (A[j] % 2 == 1))
			j -= 2;
		if ((i < A.size()) && (j >= 0))
		{
			swap(A[i], A[j]);
			i += 2;
			j -= 2;
		}
	}
	return A;
}

//bool isAnagram(string s, string t)
//{
//	if (s.length() != t.length()) return false;
//	unordered_map<char, int> cmap;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (cmap[s[i]] == 0) cmap[s[i]] = 1;
//		else cmap[s[i]]++;
//	}
//	for (int i = 0; i < t.length(); i++)
//	{
//		if (cmap[t[i]] == 0) return false;
//		else cmap[t[i]]--;
//	}
//	auto it = cmap.begin();
//	while (it != cmap.end())
//	{
//		if (it->second != 0)
//			return false;
//		++it;
//	}
//	return true;
//}


bool isAnagram(string s, string t)
{
	if (s.length() != t.length()) return false;
	unordered_map<char, int> cmap;
	for (int i = 0; i < s.length(); i++)
	{
		if (cmap[s[i]] == 0) cmap[s[i]] = 1;
		else cmap[s[i]]++;
		if (cmap[t[i]] == 0) cmap[t[i]] = -1;
		else cmap[t[i]]--;
	}

	auto it = cmap.begin();
	while (it != cmap.end())
	{
		if (it->second != 0)
			return false;
		++it;
	}
	return true;
}

void inorderTraversal_helper(TreeNode* root, vector<int>& result)
{
	if (root == nullptr) return;
	else
	{
		inorderTraversal_helper(root->left, result);
		result.push_back(root->val);
		inorderTraversal_helper(root->right, result);
	}
}
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> result;
	inorderTraversal_helper(root, result);
	return result;
}

void preorderTraversal_helper(TreeNode* root, vector<int>& result)
{
	if (root == nullptr) return;
	else
	{
		result.push_back(root->val);
		preorderTraversal_helper(root->left, result);
		preorderTraversal_helper(root->right, result);
	}
}

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> result;
	preorderTraversal_helper(root, result);
	return result;
}

class BSTIterator
{
public:
	BSTIterator(TreeNode* root)
	{
		addTree(root);
	}

	/** @return the next smallest number */
	int next()
	{
		if (!tStack.empty())
		{
			auto top = tStack.top();
			tStack.pop();
			addTree(top->right);
			return top->val;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !tStack.empty();
	}
private:
	void addTree(TreeNode* root)
	{
		if (root == nullptr)
			return;
		else
		{
			auto p = root;
			while (p)
			{
				tStack.push(p);
				p = p->left;
			}
		}
	}
	TreeNode *			tRoot;
	stack<TreeNode*>	tStack;
};


TreeNode* newroot, *curr;
TreeNode * increasingBST(TreeNode* root)
{
	if (root == NULL) return NULL;
	increasingBST(root->left);

	if (newroot == NULL) {
		newroot = new TreeNode(root->val);
		curr = newroot;
	}
	else {
		curr->right = new TreeNode(root->val);
		curr = curr->right;
	}

	increasingBST(root->right);
	return newroot;
}

int rob(vector<int>& nums)
{
	if (nums.size() == 0)return 0;
	if (nums.size() == 1)return nums[0];

	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
	int ans = dp[1];
	for (int i = 2; i < nums.size(); i++)
	{
		auto r1 = dp[i - 2] + nums[i];
		auto r2 = dp[i - 1];

		dp[i] = max(r1, r2);
		if (ans < dp[i])
			ans = dp[i];
	}
	return ans;
}

int rob_helper(vector<int>& nums, int lo, int hi)
{
	int include = 0, exclude = 0;
	for (int j = lo; j <= hi; j++)
	{
		int i = include, e = exclude;
		include = e + nums[j];
		exclude = max(e, i);
	}
	return max(include, exclude);
}
int rob2(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];
	return max(
		rob_helper(nums, 0, nums.size() - 2),
		rob_helper(nums, 1, nums.size() - 1)
	);
}


vector<int> preorder(Node* root)
{
	vector<int> result;
	stack<Node*> ns;
	if (root != nullptr)	ns.push(root);
	while (!ns.empty())
	{
		auto node = ns.top();
		ns.pop();
		result.push_back(node->val);
		// 注意同一层要从最后开始入栈
		for (int i = node->children.size() - 1; i >= 0; i--)
		{
			ns.push(node->children[i]);
		}
	}
	return result;
}


void postorder_helper(Node* root, vector<int>& result)
{
	if (root == nullptr) return;
	for (int i = 0; i < root->children.size(); i++)
	{
		postorder_helper(root->children[i], result);
	}
	result.push_back(root->val);
}

vector<int> postorder(Node* root)
{
	vector<int> result;
	postorder_helper(root, result);
	return result;
}


vector<vector<int>> levelOrder(Node* root)
{
	vector<vector<int>> result;
	queue<Node*> nq;
	if (root != nullptr)	nq.push(root);
	while (!nq.empty())
	{
		int size = nq.size();
		vector<int> curLevel;
		// 这个是最关键操作
		for (int i = 0; i < size; i++)
		{
			Node* tmp = nq.front();
			nq.pop();
			curLevel.push_back(tmp->val);
			for (auto n : tmp->children)
				nq.push(n);
		}
		result.push_back(curLevel); // Store the current level values to res.
	}
	return result;
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> result;
	queue<TreeNode*>    nq;
	if (root == nullptr) return result;
	nq.push(root);

	while (!nq.empty())
	{
		int size = nq.size();
		vector<int> row;
		for (int i = 0; i < size; i++)
		{
			auto node = nq.front();
			nq.pop();
			row.push_back(node->val);
			if (node->left)     nq.push(node->left);
			if (node->right)    nq.push(node->right);
		}
		result.push_back(row);
	}
	reverse(result.begin(), result.end());
	return result;
}

TreeNode* addOneRow(TreeNode* root, int v, int d)
{
	queue<TreeNode*>		nq;
	if (root == nullptr)	return new TreeNode(v);

	nq.push(root);
	int level = 1;

	if (d == 1)
	{
		auto new_node = new TreeNode(v);
		new_node->left = root;
		return new_node;
	}

	while (!nq.empty())
	{
		int n = nq.size();
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			auto node = nq.front();
			nq.pop();

			if (level == d - 1)
			{
				flag = true;

				auto new_node1 = new TreeNode(v);
				new_node1->left = node->left;
				node->left = new_node1;

				auto new_node2 = new TreeNode(v);
				new_node2->right = node->right;
				node->right = new_node2;
			}
			else
			{
				if (node->left)  nq.push(node->left);
				if (node->right) nq.push(node->right);
			}
		}
		if (flag) break;
		level++;
	}
	return root;
}


int numJewelsInStones(string J, string S)
{
	int JArr[256] = { 0 };
	for (auto c : J)
		JArr[c] = 1;
	int ans = 0;
	for (auto c : S)
		if (JArr[c] != 0)
			ans++;
	return ans;
}

vector<string> commonChars(vector<string>& A)
{
	int cn[26] = { 0 };
	for (auto c : A[0])
		cn[c - 'a']++;

	for (int i = 1; i < A.size(); i++)
	{
		int cn_t[26] = { 0 };
		for (auto c : A[i]) cn_t[c - 'a']++;
		for (int j = 0; j < 26; j++)
		{
			if (cn[j] == 0 || cn_t[j] == 0)
				cn[j] = 0;
			else
				cn[j] = cn[j] < cn_t[j] ? cn[j] : cn_t[j];
		}
	}
	vector<string> result;
	for (int i = 0; i < 26; i++)
	{
		cn[i] /= A.size();
		for (int j = 0; j < cn[i]; j++)
			result.push_back(string(1, char(i + 'a')));
	}
	return result;
}

string removeOuterParentheses(string S)
{
	string ans = "";
	stack<char> cs;
	int sign = 0;
	for (auto c : S)
	{
		if (c == '(')
			sign += 1;
		else
			sign -= 1;
		cs.push(c);
		if (sign == 0)
		{
			cs.pop();
			string tmp = "";
			while (cs.size() != 1)
			{
				tmp += cs.top();
				cs.pop();
			}
			cs.pop();
			reverse(tmp.begin(), tmp.end());
			ans += tmp;
		}
	}
	return ans;
}

bool backspaceCompare(string S, string T)
{
	stack<char> cs1, cs2;
	for (auto c : S)
	{
		if (c != '#')
			cs1.push(c);
		else if(!cs1.empty())
			cs1.pop();
	}
	for (auto c : T)
	{
		if (c != '#')
			cs2.push(c);
		else if (!cs2.empty())
			cs2.pop();
	}
	if (cs1.size() != cs2.size())
		return false;
	else
	{
		while (!cs1.empty())
		{
			if (cs1.top() != cs2.top())return false;
			cs1.pop();
			cs2.pop();
		}
		return true;
	}
}

class KthLargest
{
public:

	KthLargest(int k, vector<int> nums)
	{
		size = k;
		for (int i = 0; i < nums.size(); i++)
		{
			pq.push(nums[i]);
			if (pq.size() > k)
				pq.pop();
		}
	}

	int add(int val)
	{
		pq.push(val);
		if (pq.size() > size)
			pq.pop();
		return pq.top();
	}
private:
	priority_queue<int, vector<int>, greater<int>> pq;
	int size;
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> ans;
	queue<TreeNode*> nodeQue;
	nodeQue.push(root);
	int flag = 0;
	while (!nodeQue.empty())
	{
		int n = nodeQue.size();
		vector<int> row(n, 0);
		for (int i = 0; i < n; i++)
		{
			auto t = nodeQue.front();
			if (t->left)	nodeQue.push(t->left);
			if (t->right)	nodeQue.push(t->right);
			if (flag % 2 != 0)
				row[n - i - 1] = t->val;
			else
				row[i] = t->val;
		}
		ans.push_back(row);
		flag++;
	}
	return ans;
}

TreeNode* buildTree_helper(vector<int>& inorder, int li, int ri, vector<int>& postorder, int lp, int rp)
{
	if (rp < lp)  return nullptr;

	auto root = new TreeNode(postorder[rp]);

	// 中序找根
	int  id = li;
	for (; id <= ri; id++)
		if (inorder[id] == root->val)
			break;

	int size = id - li;
	root->left = buildTree_helper(inorder, li, id - 1, postorder, lp, lp + size - 1);
	root->right = buildTree_helper(inorder, id + 1, rp, postorder, lp + size, rp - 1);
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return buildTree_helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

