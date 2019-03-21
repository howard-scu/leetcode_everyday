#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "leetcode.h"

#define TEST_ALL 0

#ifndef TEST_ALL
TEST_CASE("isCompleteTree", "[single-file]")
{
	CHECK(isCompleteTree(stringToTreeNode("[1,2,3,4,5,6]")));
	CHECK(!isCompleteTree(stringToTreeNode("[1,2,3,4,5,null,7]")));
}

TEST_CASE("sumNumbers", "[single-file]")
{
	CHECK(sumNumbers(stringToTreeNode("[1,2,3]")) == 25);
	CHECK(sumNumbers(stringToTreeNode("[4,9,0,5,1]")) == 1026);
}

TEST_CASE("permute", "[single-file]")
{
	auto v = vector<int>{ 1, 2, 3 };
	CHECK_THAT(permute(v),
		Catch::Matchers::Equals(
			vector<vector<int>>{ {1, 2, 3},
			{ 1, 3, 2 },
			{ 2, 1, 3 },
			{ 2, 3, 1 },
			{ 3, 2, 1 },
			{ 3, 1, 2 }}));
}

TEST_CASE("permuteUnique", "[single-file]")
{
	auto v = vector<int>{ 1, 1, 2 };
	CHECK_THAT(permuteUnique(v),
		Catch::Matchers::Equals(
			vector<vector<int>>{ {1, 1, 2},
			{ 1, 2, 1 },
			{ 2, 1, 1 }}));
}

TEST_CASE("nextPermutation", "[single-file]")
{
	auto v1 = vector<int>{ 1,2,3 };
	nextPermutation(v1);
	CHECK_THAT(v1, Catch::Matchers::Equals(vector<int>{1, 3, 2}));

	auto v2 = vector<int>{ 3, 2, 1 };
	nextPermutation(v2);
	CHECK_THAT(v2, Catch::Matchers::Equals(vector<int>{1, 2, 3}));

	auto v3 = vector<int>{ 1, 1, 5 };
	nextPermutation(v3);
	CHECK_THAT(v3, Catch::Matchers::Equals(vector<int>{1, 5, 1}));

	auto v4 = vector<int>{ 1, 2, 3,4 };
	nextPermutation(v4);
	CHECK_THAT(v4, Catch::Matchers::Equals(vector<int>{1, 2, 4, 3}));

	auto v5 = vector<int>{ 1,2 };
	nextPermutation(v5);
	CHECK_THAT(v5, Catch::Matchers::Equals(vector<int>{2, 1}));
}


TEST_CASE("mergeTwoLists", "[single-file]")
{
	ListNode* l1 = stringToListNode("[1,2,4]");
	ListNode* l2 = stringToListNode("[1,3,4]");
	ListNode* ret = mergeTwoLists(l1, l2);
	string out = listNodeToString(ret);
	auto vout = vector<int>{ 1, 1, 2, 3, 4, 4 };
	CHECK_THAT(vout, Catch::Matchers::Equals(stringToIntegerVector(out)));
}

TEST_CASE("merge", "[single-file]")
{
	auto v1 = vector<int>{ 1, 2, 3, 0, 0, 0 };
	auto v2 = vector<int>{ 2,5,6 };
	auto v3 = vector<int>{ 1, 2, 2, 3, 5, 6 };
	merge(v1, 3, v2, 3);
	CHECK_THAT(v3, Catch::Matchers::Equals(v1));
}

TEST_CASE("subarraySum", "[single-file]")
{
	auto v1 = vector<int>{ 1, 1, 1 };
	CHECK(subarraySum(v1, 2) == 2);

	auto v = vector<int>{ -624, -624, -624, -624, -624, -624, -624, -624, -624, -624 };
	CHECK(subarraySum(v, -624) == 10);
}
TEST_CASE("nextGreaterElement", "[single-file]")
{
	CHECK(nextGreaterElement(12) == 21);
	CHECK(nextGreaterElement(21) == -1);
}

TEST_CASE("isSymmetric", "[single-file]")
{
	CHECK(isSymmetric(stringToTreeNode("[1, 2, 2, 3, 4, 4, 3]")));
	CHECK(!isSymmetric(stringToTreeNode("[1,2,2,null,3,null,3]")));
}


TEST_CASE("levelOrder", "[single-file]")
{
	vector<vector<int>> v{ { 3 },{ 9,20 },{ 15,7 } };
	CHECK_THAT(v, Catch::Matchers::Equals(levelOrder(stringToTreeNode("[3,9,20,null,null,15,7]"))));
}


TEST_CASE("minPathSum", "[single-file]")
{
	vector<vector<int>> grid{
		{ 1,3,1 },
	{ 1,5,1 },
	{ 4,2,1 }
	};

	CHECK(7 == minPathSum(grid));
}

TEST_CASE("uniquePaths", "[single-file]")
{
	CHECK(3 == uniquePaths(3, 2));
	CHECK(28 == uniquePaths(7, 3));
}


TEST_CASE("minPathSum", "[single-file]")
{
	vector<vector<int>> grid
	{
		{ 0, 0, 0 },
	{ 0, 1, 0 },
	{ 0, 0, 0 }
	};

	CHECK(2 == uniquePathsWithObstacles(grid));

	vector<vector<int>> grid1{ { 1 } };
	CHECK(0 == uniquePathsWithObstacles(grid1));
}
TEST_CASE("isLongPressedName", "[single-file]")
{
	CHECK(true == isLongPressedName("alex", "aaleex"));
	CHECK(true == isLongPressedName("laiden", "laiden"));
	CHECK(true == isLongPressedName("leelee", "lleeelee"));
	CHECK(false == isLongPressedName("saeed", "ssaaedd"));
	CHECK(true == isLongPressedName("vtkgn", "vttkgnn"));
}


TEST_CASE("isLongPressedName", "[single-file]")
{
	CHECK(2 == minSubArrayLen(7, vector<int>{2, 3, 1, 2, 4, 3}));
	CHECK(1 == minSubArrayLen(4, vector<int>{1, 4, 4}));
}
TEST_CASE("containsNearbyAlmostDuplicate", "[single-file]")
{
	//CHECK(containsNearbyAlmostDuplicate(vector<int>{1, 2}, 0, 0));
	CHECK(containsNearbyAlmostDuplicate(vector<int>{1, 2, 3, 1}, 3, 0));
	CHECK(containsNearbyAlmostDuplicate(vector<int>{1, 0, 1, 1}, 1, 2));
	CHECK(!containsNearbyAlmostDuplicate(vector<int>{1, 5, 9, 1, 5, 9}, 2, 3));
}

TEST_CASE("containsNearbyDuplicate", "[single-file]")
{
	CHECK(containsNearbyDuplicate(vector<int>{1, 2, 3, 1}, 3));
	CHECK(containsNearbyDuplicate(vector<int>{1, 0, 1, 1}, 1));
	CHECK(!containsNearbyDuplicate(vector<int>{1, 2, 3, 1, 2, 3}, 2));
}


TEST_CASE("checkPossibility", "[single-file]")
{
	//CHECK(checkPossibility(vector<int>{4, 2, 3}));
	//CHECK(!checkPossibility(vector<int>{4, 2, 1}));
	CHECK(!checkPossibility(vector<int>{3, 4, 2, 3}));
	//CHECK(checkPossibility(vector<int>{-1, 4, 2, 3}));
}

TEST_CASE("diameterOfBinaryTree", "[single-file]")
{
	CHECK(diameterOfBinaryTree(stringToTreeNode("[1,2,null,4,5,6,7,8]")) == 4);
}

TEST_CASE("reverseVowels", "[single-file]")
{
	CHECK_THAT("holle", Catch::Matchers::Equals(reverseVowels("hello")));
	CHECK_THAT("leetcode", Catch::Matchers::Equals(reverseVowels("leotcede")));
}

TEST_CASE("longestPalindrome", "[single-file]")
{
	CHECK_THAT("bab", Catch::Matchers::Equals(longestPalindrome("babad")));
	CHECK_THAT("bb", Catch::Matchers::Equals(longestPalindrome("cbbd")));
	CHECK_THAT("bb", Catch::Matchers::Equals(longestPalindrome("bb")));
	CHECK_THAT("a", Catch::Matchers::Equals(longestPalindrome("a")));
	CHECK_THAT("", Catch::Matchers::Equals(longestPalindrome("")));
}

TEST_CASE("shortestPalindrome", "[single-file]")
{
	CHECK_THAT("aaacecaaa", Catch::Matchers::Equals(shortestPalindrome("aacecaaa")));
	CHECK_THAT("dcbabcd", Catch::Matchers::Equals(shortestPalindrome("abcd")));
}

TEST_CASE("maxProduct", "[single-file]")
{
	CHECK(6 == maxProduct(vector<int>{2, 3, -2, 4}));
	CHECK(0 == maxProduct(vector<int>{-2, 0, -1}));
}

TEST_CASE("convert", "[single-file]")
{
	CHECK_THAT("PAHNAPLSIIGYIR", Catch::Matchers::Equals(convert("PAYPALISHIRING", 3)));
	CHECK_THAT("PINALSIGYAHRPI", Catch::Matchers::Equals(convert("PAYPALISHIRING", 4)));
}
#else

//TEST_CASE("isNumber", "[single-file]")
//{
//	CHECK(isNumber("0"));
//	CHECK(isNumber(" 0.1 "));
//	CHECK(!isNumber("abc"));
//	CHECK(!isNumber("1 a"));
//	CHECK(isNumber("2e10"));
//	CHECK(isNumber(" -90e3   "));
//	CHECK(!isNumber(" 1e"));
//	CHECK(!isNumber("e3"));
//	CHECK(isNumber(" 6e-1"));
//	CHECK(isNumber(" 99e2.5 "));
//	CHECK(isNumber("53.5e93"));
//	CHECK(!isNumber(" --6 "));
//	CHECK(!isNumber("-+3"));
//	CHECK(!isNumber("95a54e53"));
//}


//string parse_blank(string s)
//{
//	int i = 0;
//	int j = s.length() - 1;
//	while (i < s.length() && s[i] == ' ')i++;
//	while (j >= 0 && s[j] == ' ')j--;
//	if (i > j)
//		return "";
//	else
//		return s.substr(i, j - i + 1);
//}
//
//bool parse_digit(string s)
//{
//	int digit = -1;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//			continue;
//		else if (digit < 0 && s[i] == '.')
//			digit = i;
//		else
//			return false;
//	}
//	if (digit == 0 || digit == s.length() - 1)
//		return false;
//	else
//		return true;
//}
//
//TEST_CASE("isNumber", "[single-file]")
//{
//	CHECK(parse_blank("a") == "a");
//	CHECK(parse_blank(" a") == "a");
//	CHECK(parse_blank("a e ") == "a e");
//	CHECK(parse_blank("   a") == "a");
//	CHECK(parse_blank("   a   ") == "a");
//	CHECK(parse_blank("  ") == "");
//	CHECK(parse_blank("") == "");
//
//	CHECK(parse_digit("0.1"));
//	CHECK(!parse_digit("0..2"));
//	CHECK(!parse_digit("2."));
//	CHECK(!parse_digit(".2"));
//}


TEST_CASE("rotateRight", "[single-file]")
{
	ListNode* l1 = stringToListNode("[1,2,3,4,5]");
	string out1 = listNodeToString(rotateRight(l1, 2));
	CHECK("[4, 5, 1, 2, 3]" == out1);

	ListNode* l2 = stringToListNode("[0,1,2]");
	string out2 = listNodeToString(rotateRight(l2, 4));
	CHECK("[2, 0, 1]" == out2);

	ListNode* l3 = stringToListNode("[1,2]");
	string out3 = listNodeToString(rotateRight(l3, 2));
	CHECK("[1, 2]" == out3);
}
#endif // !TEST_ALL
