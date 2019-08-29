#include<iostream>
struct node{
	int data;
	struct node *left,*right;
};
struct node* insert(struct node*,int);
struct node* create_bst(int);
void inorder(struct node*);
struct node* find_min(struct node*);
struct node* delete_node(struct node*,int);