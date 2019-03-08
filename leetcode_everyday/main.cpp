#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "leetcode.h"

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
	CHECK_THAT(v4, Catch::Matchers::Equals(vector<int>{1, 2, 4,3}));

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
