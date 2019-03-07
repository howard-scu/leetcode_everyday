#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "leetcode.h"
//
//TEST_CASE("isCompleteTree", "[single-file]")
//{
//	CHECK_THAT(isCompleteTree(stringToTreeNode("[1,2,3,4,5,6]")));
//	CHECK_THAT(!isCompleteTree(stringToTreeNode("[1,2,3,4,5,null,7]")));
//}
//
//TEST_CASE("sumNumbers", "[single-file]")
//{
//	CHECK_THAT(sumNumbers(stringToTreeNode("[1,2,3]")) == 25);
//	CHECK_THAT(sumNumbers(stringToTreeNode("[4,9,0,5,1]")) == 1026);
//}
//
//TEST_CASE("permute", "[single-file]")
//{
//	auto v = vector<int>{ 1, 2, 3 };
//	CHECK_THAT(permute(v),
//		Catch::Matchers::Equals(
//			vector<vector<int>>{ {1, 2, 3},
//			{ 1, 3, 2 },
//			{ 2, 1, 3 },
//			{ 2, 3, 1 },
//			{ 3, 2, 1 },
//			{ 3, 1, 2 }}));
//}
//
//TEST_CASE("permuteUnique", "[single-file]")
//{
//	auto v = vector<int>{ 1, 1, 2 };
//	CHECK_THAT(permuteUnique(v),
//		Catch::Matchers::Equals(
//			vector<vector<int>>{ {1, 1, 2},
//			{ 1, 2, 1 },
//			{ 2, 1, 1 }}));
//}

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