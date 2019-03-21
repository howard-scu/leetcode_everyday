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
			if(i == j)
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

	ListNode* odd  = new ListNode(0);
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