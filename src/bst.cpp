#include<iostream>
#include "bst.hpp"

struct node* insert(struct node* root,int data)
{
	if(root==NULL)
	{
		root=new(struct node);
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(data>root->data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
	return root;
}
struct node* create_bst(int n)
{
	int data;
	struct node* root=NULL;
	while(n--)
	{	
		std::cin>>data;
		root=insert(root,data);
	}
	return root;
}
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		std::cout<<root->data<<"\t";
		inorder(root->right);
	}
}

struct node* find_min(struct node* root)
{
    if(root && !root->left)
        return root;

    return find_min(root->left);
}
struct node* delete_node(struct node* root,int data)
{
    if(root==NULL)
        return NULL;

    if(data < root->data)
        root->left=delete_node(root->left,data);
    
    else if(data > root->data)
        root->right=delete_node(root->right,data);
    else
    {
        if(root->left && root->right)
        {
            struct node* successor=find_min(root->right);
            root->data=successor->data;
            root->right=delete_node(root->right,successor->data);
        }
        if(root->left && !root->right)
        {
            struct node* temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            struct node* temp=root;
            root=root->right;
            delete temp;
        }
    }
    return root;
}