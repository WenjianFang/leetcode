#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

static void merge_two_list_recu(struct ListNode *head, struct ListNode *l1, struct ListNode *l2)
{
	if (!l1) {
		head->next = l2;
		return;
	}
	if (!l2) {
		head->next = l1;
		return;
	}

	if (l1->val < l2->val) {
		head->next = l1;
		merge_two_list_recu(head->next, l1->next, l2);
	} else {
		head->next = l2;
		merge_two_list_recu(head->next, l1, l2->next);
	}

	return;
}
static struct ListNode *merge_two_list(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *head = NULL;

	if (!l1) {
		return l2;
	}

	if (!l2) {
		return l1;
	}

	if (l1->val < l2->val) {
		head = l1;
		merge_two_list_recu(head, l1->next, l2);
	} else {
		head = l2;
		merge_two_list_recu(head, l1, l2->next);
	}

	return head;
}

/**
 * recursively solve the problem
 * first list merge the merged list of the others
 */
static struct ListNode *merge(struct ListNode **lists, int listsSize, int curr_idx)
{
	struct ListNode *others_head = NULL;

	if (curr_idx == (listsSize - 1)) {
		return lists[curr_idx];
	}

	others_head = merge(lists, listsSize, curr_idx + 1);

	return merge_two_list(lists[curr_idx], others_head);
}


struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	if (listsSize == 0) {
		return NULL;
	}

	return merge(lists, listsSize, 0);
}

int main(void)
{
	int listsSize = 0;
	struct ListNode **lists = NULL;
	int listSize = 0;
	int i = 0;
	int j = 0;
	struct ListNode *p = NULL;
	struct ListNode *new_head = NULL;
	scanf("%d", &listsSize);
	lists = calloc(1, sizeof(struct ListNode *) * listsSize);

	for (i = 0; i < listsSize; i++) {
		scanf("%d", &listSize);
		for (j = 0; j < listSize; j++) {
			if (j == 0) {
				new_head = calloc(1, sizeof(struct ListNode));
				scanf("%d", &new_head->val);
				new_head->next = NULL;
				p = new_head;
				continue;
			}
			struct ListNode *new_node = calloc(1, sizeof(struct ListNode));
			scanf("%d", &new_node->val);
			new_node->next = NULL;
			p->next = new_node;
			p = p->next;
		}
		lists[i] = new_head;
	}

	struct ListNode *merge_head = mergeKLists(lists, listsSize);
	p = merge_head;
	while (merge_head) {
		printf("%d->", merge_head->val);
		p = merge_head;
		merge_head = merge_head->next;
		free(p);
	}
	return 0;
}
