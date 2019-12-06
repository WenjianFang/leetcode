#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	if (!head) {
		return head;
	}

	struct ListNode *p_front = head;
	struct ListNode *p_tail = head;
	struct ListNode *new_head = head;
	struct ListNode *p_del = NULL;
	int len = 0;

	/* len == n or p_front is NULL stop loop */
	while ((len < n) && p_front) {
		p_front = p_front->next;
		len++;
	}

	/* delete node is head */
	if ((!p_front) && (len == n)) {
		new_head = p_tail->next;
		free(p_tail);
		return new_head;
	}

	if (len == n) {
		/* p_front and p_tail loop until p_front->next is NULL
		 * p_front->next is to delete
		 */
		while (p_front->next) {
			p_tail = p_tail->next;
			p_front = p_front->next;
		}

		/* delete p_tail->next node */
		p_del = p_tail->next;
		p_tail->next = p_tail->next->next;
		free(p_del);
	}

	return new_head;
}

int main(void)
{
	struct ListNode *head = NULL;
	struct ListNode *p = NULL;
	struct ListNode *new_node = NULL;
	int i = 0;
	int n = 0;
	int list_len = 0;

	scanf("%d %d", &list_len, &n);
	for (i = 0; i < list_len; i++) {
		new_node = calloc(1, sizeof(struct ListNode));
		scanf("%d", &new_node->val);
		if (i == 0) {
			head = new_node;
			p = head;
			continue;
		}
		p->next = new_node;
		p = p->next;
	}

	struct ListNode *new_head = removeNthFromEnd(head, n);
	p = new_head;
	while (p) {
		printf("%d ", p->val);
		new_node = p;
		p = p->next;
		free(new_node);
	}

	return 0;
}
