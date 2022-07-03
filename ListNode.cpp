#include "ListNode.h"
#include <string.h>;
#include <iostream>

using namespace std;
ListNode* ListNode::build(vector<int> vec)
{
	ListNode* head;
	head = new ListNode;
	ListNode* work;
	work = new ListNode;
	work = head;
	if (vec.size() == 0)
		return head;
	head->val = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		ListNode* p;
		p = new ListNode;
		p->val = vec[i];
		work->next = p;
		work = work->next;
	}
	work->next = nullptr;
	return head;
}
void print(ListNode *p)
{
	ListNode* m = p;
	int count = 0;
	if (!m)
		cout << "empty list";
	while (m->next)
	{
		cout << m->val << "->";
		m = m->next;
		count++;
		if (count == 10)
			cout << endl;
	}
	
	cout << m->val<<"-> nullptr";
}
ListNode* reverse(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode* s = nullptr;
	ListNode* n = head->next;
	while (head->next)
	{
		head->next = s;
		s = head;
		head = n;
		n = head->next;
	}
	head->next = s;
	return head;
}
ListNode* reverseKGroup(ListNode* head, int k) {
	int count = 0;
	ListNode prehead(0);
	ListNode* s = &prehead;
	s->next = head;
	ListNode* e = head;
	while (head)
	{
		count++;
		if (count == k)
		{
			e = head->next;
			head->next = nullptr;
			ListNode* m = s->next;
			s->next = reverse(s->next);
			m->next = e;
			s = m;
			count = 0;
			head = e;
		}
		else
			head = head->next;
	}
	return prehead.next;
}

TreeNode* buildTree(vector<string> vec)
{	
	if (vec[0] == "null")
		return nullptr;
	if (vec.size() % 2 == 0)
		vec.push_back("null");
	int index=0;
	TreeNode* root;
	root = new TreeNode;
	root->val = std::stoi(vec[0]);
	index++;
	//输入的vec为层序遍历顺序，所以使用栈来记录结点
	vector<TreeNode*> Stack;
	Stack.push_back(root);
	while (index != vec.size())
	{
		if (Stack[0] == nullptr)
		{
			Stack.erase(Stack.begin(), Stack.begin() + 1);
			continue;
		}
		TreeNode* left;
		left = new TreeNode;
		TreeNode* right;
		right = new TreeNode;
		if (vec[index] != "null")
			left->val = std::stoi(vec[index]);
		else
			left = nullptr;
		index++;
		if (vec[index] != "null")
			right->val = std::stoi(vec[index]);
		else
			right = nullptr;
		index++;
		if (Stack[0]) {
			Stack[0]->left = left;
			Stack[0]->right = right;
			Stack.push_back(left);
			Stack.push_back(right);
		}
		Stack.erase(Stack.begin(), Stack.begin() + 1);
	}
	return root;
}

