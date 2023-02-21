#include <iostream>
#include <vector>
using namespace std;

// 定义链表的数据结构
struct ListNode {
	int val;  // 节点上存储的元素
	ListNode* next;  // 指向下一个节点的指针

	ListNode() : val(0), next(NULL) {}  // 节点的构造函数
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// Q203: 移除链表元素
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0);  // 创建虚拟头节点
		dummyHead->next = head;
		ListNode* cur = dummyHead;

		while (cur->next != NULL) {
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else {
				cur = cur->next;
			}
		}
		return dummyHead->next;
	}
};

// 打印链表
void printList(ListNode* head) {
	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->val << " -> ";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

int main() {

	ListNode* head = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(6);
	ListNode* node4 = new ListNode(3);
	ListNode* node5 = new ListNode(4);
	ListNode* node6 = new ListNode(5);
	ListNode* node7 = new ListNode(6);

	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;

	Solution solution;

	// Q203
	int val = 6;
	solution.removeElements(head, val);
	printList(head);




	return 0;
}
