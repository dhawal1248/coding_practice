#include <iostream>
#include "bst.hpp"

struct node* append(struct node* a,struct node* b)
{
	//expects each list passed to be a circular list
	if(a==NULL && b!=NULL)
		return b;
	else if(a!=NULL && b==NULL)
		return a;
	struct node* a_last=a->left;
	struct node* b_last=b->left;
	a_last->right=b;
	b->left=a_last;
	a->left=b_last;
	b_last->right=a;
	return a;
}
struct node * treetolist(struct node* root)
{
	if(root==NULL)
		return NULL;
	struct node *list1,*list2;
	list1=treetolist(root->left);
	list2=treetolist(root->right);
	//making root a circular list of one node
	root->left=root;
	root->right=root;
	list1=append(list1,root);
	list1=append(list1,list2);
	return list1;	
}
void print_circular_list(struct node* head)
{
	struct node* curr=head;
	std::cout<<curr->data<<"\t";
	curr=curr->right;
	while(curr!=head)
	{
		std::cout<<curr->data<<"\t";
		curr=curr->right;
	}
	std::cout<<std::endl;
}
int main()
{
	struct node* root = create_bst();
	inorder(root);
	std::cout<<std::endl;
	root = treetolist(root);
	print_circular_list(root);
}