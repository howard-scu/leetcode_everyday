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


TEST_CASE("MyLinkedList", "[single-file]")
{
	MyLinkedList linkedList;
	linkedList.addAtHead(5);
	linkedList.addAtHead(2);
	linkedList.deleteAtIndex(1);

	linkedList.addAtIndex(1, 9);

	linkedList.addAtHead(4);
	linkedList.addAtHead(9);
	linkedList.addAtHead(8);

	linkedList.get(3);
	linkedList.addAtTail(1);
	linkedList.addAtIndex(3, 6);
	linkedList.addAtHead(3);
	linkedList.print();
}
TEST_CASE("MyCircularQueue", "[single-file]")
{
	MyCircularQueue circularQueue(3); // set the size to be 3
	CHECK(circularQueue.enQueue(2));
	CHECK(circularQueue.Rear() == 2);
	CHECK(circularQueue.Front() == 2);
	CHECK(circularQueue.deQueue());

	CHECK(circularQueue.Front()==-1);
	CHECK(!circularQueue.deQueue());
	CHECK(circularQueue.Front() == -1);
	CHECK(circularQueue.enQueue(4));

	CHECK(circularQueue.enQueue(2));
	CHECK(circularQueue.enQueue(2));
	CHECK(!circularQueue.enQueue(3));
}


TEST_CASE("findMin", "[single-file]")
{
	CHECK(1 == findMin(vector<int>{3, 4, 5, 1, 2}));
	CHECK(0 == findMin(vector<int>{4, 5, 6, 7, 0, 1, 2}));
	CHECK(1 == findMin(vector<int>{1, 2, 3, 4, 5}));
	CHECK(1 == findMin(vector<int>{2, 1}));
	CHECK(1 == findMin(vector<int>{3, 1, 2}));
}

TEST_CASE("maxArea", "[single-file]")
{
	CHECK(49 == maxArea(vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7}));
}

TEST_CASE("threeSumClosest", "[single-file]")
{
	CHECK(2 == threeSumClosest(vector<int>{-1, 2, 1, -4}, 1));
	CHECK(3 == threeSumClosest(vector<int>{0, 1, 2}, 3));
}

TEST_CASE("fourSum", "[single-file]")
{
	fourSum(vector<int>{1, 0, -1, 0, -2, 2}, 0);
}

TEST_CASE("search", "[single-file]")
{
	CHECK(4 == search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 0));
	CHECK(-1 == search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 3));
	CHECK(-1 == search(vector<int>{1, 3}, 0));
	CHECK(-1 == search(vector<int>{1, 3}, 4));
}

TEST_CASE("isAnagram", "[single-file]")
{
	CHECK(isAnagram("anagram", "nagaram"));
	CHECK(!isAnagram("nan", "naa"));
	CHECK(isAnagram("tar", "rat"));
	CHECK(!isAnagram("tat", "rat"));
	CHECK(!isAnagram("b", "a"));
}

TEST_CASE("inorderTraversal", "[single-file]")
{
	auto t1 = stringToTreeNode("[1,null,2,3]");
	auto out1 = inorderTraversal(t1);
	CHECK(vector<int>{1, 3, 2} == out1);
}

TEST_CASE("BSTIterator", "[single-file]")
{
	auto root = stringToTreeNode("[7,3,15,null,null,9,20]");
	BSTIterator* obj = new BSTIterator(root);
	CHECK(obj->next() == 3);
	CHECK(obj->next() == 7);
	CHECK(obj->hasNext());
	CHECK(obj->next() == 9);
	CHECK(obj->hasNext());
	CHECK(obj->next() == 15);
	CHECK(obj->hasNext());
	CHECK(obj->next() == 20);
	CHECK(!obj->hasNext());
}


TEST_CASE("commonChars", "[single-file]")
{
	vector<string> ss = {
		"bbddabab","cbcddbdd","bbcadcab","dabcacad","cddcacbc","ccbdbcba","cbddaccc","accdcdbb"
	};
	vector<string> ans = commonChars(ss);
	for (auto s : ans)
		cout << s << endl;
}
TEST_CASE("removeOuterParentheses", "[single-file]")
{
	CHECK(removeOuterParentheses("(()())(())") == "()()()");
	CHECK(removeOuterParentheses("(()())(())(()(()))") == "()()()()(())");
	CHECK(removeOuterParentheses("()()") == "");
}

TEST_CASE("removeOuterParentheses", "[single-file]")
{
	CHECK(backspaceCompare("ab#c", "ad#c"));
	CHECK(backspaceCompare("ab##", "c#d#"));
	CHECK(backspaceCompare("a##c", "#a#c"));
	CHECK(!backspaceCompare("a#c", "b"));
}

TEST_CASE("buildTree", "[single-file]")
{
	CHECK("[3, 9, 20, null, null, 15, 7, null, null, null, null]" == treeNodeToString(buildTree(vector<int>{9, 3, 15, 20, 7}, vector<int>{9, 15, 7, 20, 3})));
}
TEST_CASE("toLowerCase", "[single-file]")
{
	CHECK("hello" == toLowerCase("Hello"));
	CHECK("lovely" == toLowerCase("LOVELY"));
}

TEST_CASE("strStr", "[single-file]")
{
	CHECK(2 == strStr("hello", "ll"));
	CHECK(-1 == strStr("aaaaa", "bba"));
	CHECK(-1 == strStr("aaa", "aaaa"));
}

TEST_CASE("uniqueMorseRepresentations", "[single-file]")
{
	CHECK(2 == uniqueMorseRepresentations(vector<string>{"gin", "zen", "gig", "msg"}));
}


TEST_CASE("findMinDifference", "[single-file]")
{
	CHECK(1 == findMinDifference(vector<string>{"23:59", "00:00"}));
}

TEST_CASE("countBinarySubstrings", "[single-file]")
{
	CHECK(6 == countBinarySubstrings("00110011"));
	CHECK(4 == countBinarySubstrings("10101"));
	CHECK(3 == countBinarySubstrings("00110"));
}


TEST_CASE("minMoves2", "[single-file]")
{
	CHECK(2 == minMoves2(vector<int>{1, 2, 3}));
}


TEST_CASE("hammingDistance", "[single-file]")
{
	CHECK(2 == hammingDistance(1, 4));
}

TEST_CASE("peakIndexInMountainArray", "[single-file]")
{
	CHECK(1 == peakIndexInMountainArray(vector<int>{0, 1, 0}));
	CHECK(1 == peakIndexInMountainArray(vector<int>{0, 2, 1, 0}));
}


TEST_CASE("findPeakElement", "[single-file]")
{
	CHECK(2 == findPeakElement(vector<int>{1, 2, 3, 1}));
	CHECK(5 == findPeakElement(vector<int>{1, 2, 1, 3, 5, 6, 4}));
}

#else


//TEST_CASE("uniqueMorseRepresentations", "[single-file]")
//{
//	CHECK(2 == numUniqueEmails(vector<string>{"test.email+alex@leetcode.com",
//		"test.e.mail+bob.cathy@leetcode.com", 
//		"testemail+david@lee.tcode.com"}));
//}

#endif // !TEST_ALL
