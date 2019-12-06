/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

void merge(struct ListNode *l1, struct ListNode *l2, struct ListNode *p)
{
	if (!l1) {
		p->next = l2;
		return;
	}
	if (!l2) {
		p->next = l1;
		return;
	}

	if (l1->val < l2->val) {
		p->next = l1;
		p = p->next;
		merge(l1->next, l2, p);
	} else {
		p->next = l2;
		p = p->next;
		merge(l1, l2->next, p);
	}

	return;
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	if (!l1) {
		return l2;
	}

	if (!l2) {
		return l1;
	}

	struct ListNode *head = NULL;
	struct ListNode *p = NULL;

	if (l1->val < l2->val) {
		head = l1;
		l1 = l1->next;
	} else {
		head = l2;
		l2 = l2->next;
	}

	p = head;
	merge(l1, l2, p);

	return head;
}
