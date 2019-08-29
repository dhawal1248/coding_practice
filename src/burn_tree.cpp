#include<iostream>
#include <queue>
#include "bst.hpp"

void print_append_and_clear_queue(std::queue<struct node*> &q)//does remove the elements that this function pushes into queue
//prints queue,pushes children of nodes originally in queue into queue
{
	if(!q.empty())
	{
		int qsize = q.size();
		struct node* temp;
		while(qsize--)
		{
			temp = q.front();
			std::cout<<temp->data<<"\t";
			q.pop();
			if(temp->left)
				q.push(temp->left);//not removed(not cleared)
			if(temp->right)
				q.push(temp->right);//not removed(not cleared)
		}
	}
	std::cout<<std::endl;
}
//return of 1 indicates-burning has started.
//return of 1 aslo helps to determine which side has started burning
int burn_tree_util(struct node* root,int target,std::queue<struct node*> &q)
{
	if(!root)
		return 0;
	if(root->data == target)
	{
		std::cout<<root->data<<std::endl;//burning target node
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
		return 1;//burning starts
	}
	int burn_node_is_in_left_subtree = burn_tree_util(root->left,target,q);
	if(burn_node_is_in_left_subtree)
	{
		//print the current node followed by the nodes already in queue
		std::cout<<root->data<<"\t";
		print_append_and_clear_queue(q);
		if(root->right)
			q.push(root->right);
		return 1;
	}
	else
	{
		int burn_node_is_in_right_subtree = burn_tree_util(root->right,target,q);
		if(burn_node_is_in_right_subtree)
		{
			//print the current node followed by the nodes already in queue
			std::cout<<root->data<<"\t";
			print_append_and_clear_queue(q);
			if(root->left)
				q.push(root->left);
			return 1;	
		}
		if(burn_node_is_in_left_subtree == 0 && burn_node_is_in_right_subtree == 0)
			return 0;
	}
}
void burn_tree(struct node* root,int target)
{
	std::queue<struct node*> q;
	burn_tree_util(root,target,q);
	while(!q.empty())
		print_append_and_clear_queue(q);
}
int main()
{
	struct node* root = create_bst();
	inorder(root);
	std::cout<<std::endl;
	int target;
	std::cout<<"Enter the node to burn"<<std::endl;
	std::cin>>target;
	burn_tree(root,target);
}