#pragma once
#include <vector>
#include <string>
using namespace std;
class ListNode
{
public: 
	int val;
	ListNode* next;
	//
	//construct function the same as ListCode example
	ListNode()
	{
		this->val = 0;
		this->next = nullptr;
	}
	ListNode(int i)
	{
		this->val = i;
		this->next = nullptr;
	}
	ListNode(int i, ListNode* next)
	{
		this->val = i;
		this->next = next;
	}
	//return the *head* of a list in the same order of vec
	// 
	//e.g. in {2,3,4,6} out the head of 2->3->4->6->nullptr 
	static ListNode* build(vector<int>vec);
	//print the list result from current node until nullptr;
	static void print(ListNode* p);
	
	
};
// reverse the list
ListNode* reverse(ListNode* head);

// reverse the list in group k
// e.g 2->3->4->5 k =2 then 3->2->5->4
//     2->3->4->5->6 k=3 then 4->3->2->5->6
//     2->3->4  k=1 then 2->3->4
ListNode* reverseKGroup(ListNode* head, int k);




class TreeNode
{
public:
	//TreeNode* root;
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* next = nullptr;
	TreeNode()
	{
		this->left = nullptr;
		this->right = nullptr;
		this->val = 0;
	}
};

// build the tree in level order(root->leaves) and return the root
TreeNode* buildTree(vector<string> vec);
