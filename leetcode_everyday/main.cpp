#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "leetcode.h"

TEST_CASE("isCompleteTree", "[single-file]")
{
	REQUIRE(isCompleteTree(stringToTreeNode("[1,2,3,4,5,6]")));
	REQUIRE(!isCompleteTree(stringToTreeNode("[1,2,3,4,5,null,7]")));
}

TEST_CASE("sumNumbers", "[single-file]")
{
	REQUIRE(sumNumbers(stringToTreeNode("[1,2,3]")) == 25);
	REQUIRE(sumNumbers(stringToTreeNode("[4,9,0,5,1]")) == 1026);
}
