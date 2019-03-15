#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <string>
#include <limits>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Node 
{
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) 
	{
		val = _val;
		children = _children;
	}
};


void trimLeftTrailingSpaces(string &input)
{
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
	{
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input)
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
	{
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode* stringToTreeNode(string input)
{
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size())
	{
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true)
	{
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ','))
		{
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null")
		{
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ','))
		{
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null")
		{
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}


vector<int> stringToIntegerVector(string input)
{
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim))
	{
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input)
{
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node)
{
	if (node == nullptr)
	{
		return "[]";
	}

	string result;
	while (node)
	{
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

//#include <stack>
//#include <queue>
//#include <ostream>
//
//template <class Container, class Stream>
//Stream& printOneValueContainer
//(Stream& outputstream, const Container& container)
//{
//	typename Container::const_iterator beg = container.begin();
//
//	outputstream << "[";
//
//	while (beg != container.end())
//	{
//		outputstream << " " << *beg++;
//	}
//
//	outputstream << " ]";
//
//	return outputstream;
//}
//
//template < class Type, class Container >
//const Container& container
//(const std::stack<Type, Container>& stack)
//{
//	struct HackedStack : private std::stack<Type, Container>
//	{
//		static const Container& container
//		(const std::stack<Type, Container>& stack)
//		{
//			return stack.*&HackedStack::c;
//		}
//	};
//
//	return HackedStack::container(stack);
//}
//
//template < class Type, class Container >
//const Container& container
//(const std::queue<Type, Container>& queue)
//{
//	struct HackedQueue : private std::queue<Type, Container>
//	{
//		static const Container& container
//		(const std::queue<Type, Container>& queue)
//		{
//			return queue.*&HackedQueue::c;
//		}
//	};
//
//	return HackedQueue::container(queue);
//}
//
//template
//< class Type
//	, template <class Type, class Container = std::deque<Type> > class Adapter
//	, class Stream
//>
//Stream& operator<<
//(Stream& outputstream, const Adapter<Type>& adapter)
//{
//	return printOneValueContainer(outputstream, container(adapter));
//}