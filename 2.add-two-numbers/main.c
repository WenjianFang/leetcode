#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
	int val;
	struct ListNode *next;
};

#define DECIMAL 10

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry = 0, sum = 0;
	struct ListNode *p_l1 = l1, *p_l2 = l2, *p_l = NULL;
	struct ListNode *head = NULL, *prev_node = NULL, *new_node = NULL;

	if ((!l1) || (!l2)) {
		return NULL;
	}

	head = malloc(sizeof(struct ListNode));
	sum = p_l1->val + p_l2->val;
	carry = sum / DECIMAL;
	head->val = sum % DECIMAL;
	head->next = NULL;

	p_l1 = p_l1->next;
	p_l2 = p_l2->next;
	prev_node = head;

	while (p_l1 && p_l2) {
		new_node = malloc(sizeof(struct ListNode));

		sum = p_l1->val + p_l2->val + carry;
		carry = sum / DECIMAL;
		new_node->val = sum % DECIMAL;
		new_node->next = NULL;
		prev_node->next = new_node;

		prev_node = prev_node->next;
		p_l1 = p_l1->next;
		p_l2 = p_l2->next;
	}

	if (p_l1) {
		p_l = p_l1;
	} else {
		p_l = p_l2;
	}

	while (p_l) {
		new_node = malloc(sizeof(struct ListNode));

		sum = p_l->val + carry;
		carry = sum / DECIMAL;
		new_node->val = sum % DECIMAL;
		new_node->next = NULL;
		prev_node->next = new_node;

		prev_node = prev_node->next;
		p_l = p_l->next;
	}

	if (carry) {
		new_node = malloc(sizeof(struct ListNode));
		new_node->val = carry;
		new_node->next = NULL;
		prev_node->next = new_node;
	}

	return head;
}

int main(void)
{
	struct ListNode *p_l1_head = NULL, *p_l2_head = NULL;
	struct ListNode *p_l1 = NULL, *p_l2 = NULL;
	int l1_len = 0, l2_len = 0, i = 0;

	scanf("%d %d", &l1_len, &l2_len);

	for (i = 0; i < l1_len; i++) {
		struct ListNode *new_node = malloc(sizeof(struct ListNode));
		scanf("%d", &new_node->val);
		new_node->next = NULL;

		if (!p_l1_head) {
			p_l1_head = new_node;
			p_l1 = p_l1_head;
		} else {
			p_l1->next = new_node;
			p_l1 = p_l1->next;
		}
	}

	for (i = 0; i < l2_len; i++) {
		struct ListNode *new_node = malloc(sizeof(struct ListNode));
		scanf("%d", &new_node->val);
		new_node->next = NULL;

		if (!p_l2_head) {
			p_l2_head = new_node;
			p_l2 = p_l2_head;
		} else {
			p_l2->next = new_node;
			p_l2 = p_l2->next;
		}
	}

	struct ListNode *p = addTwoNumbers(p_l1_head, p_l2_head);
	struct ListNode *prev = p;

	while (p) {
		printf("%d", p->val);
		prev = p;
		p = p->next;
		free(prev);
	}
	printf("\n");

	p_l1 = p_l1_head;
	while (p_l1) {
		prev = p_l1;
		p_l1 = p_l1->next;
		free(prev);
	}

	p_l2 = p_l2_head;
	while(p_l2) {
		prev = p_l2;
		p_l2 = p_l2->next;
		free(prev);
	}
	return 0;
}
