/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	struct node *h1 = *head1, *h2 = *head2;
	if (h2 == NULL && h1 == NULL)
		return -1;
	else if (h1 == NULL){
		h1 = h2;
		int len = 1;
		while (h1->data <= h1->next->data)
			len++;
		*head1 = h1;
		return len;
	}
	else if (h2 == NULL){
		int len = 1;
		while (h1->data <= h1->next->data)
			len++;
		return len;
	}
	struct node *merge = (h1->data > h2->data) ? h2 : h1;
	h1 = (h1->data <= h2->data) ? h2 : h1;

	struct node *temp = merge;
	int len = 0;
	while ((merge->next != *head1 || merge->next != *head2) && (h1->next != *head1 || h1->next != *head2)){
		if (merge->next->data > h1->data){
			//insert the node when small
			h2 = h1->next;
			h1->next = merge->next;
			merge->next = h1;
			merge = h1;
			h1 = h2;
		}
		else
			//iter when node is bigger
			merge = merge->next;
		len++;
	}
	while (merge->next != *head1 || merge->next != *head2)
		//move to end
		merge = merge->next;
	if (h1->next != *head1 || h1->next != *head2)
		//add rest of nodes in head
		merge->next = h1;
	
	h1 = *head1, h2 = *head2;
	merge->next = (h1->data > h2->data) ? h2 : h1;
	return temp;
	
}