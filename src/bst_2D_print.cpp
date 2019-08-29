#include <iostream>
#include "bst.hpp"

void two_D_print(struct node* root,int current_depth=0)//depth of the current node..no. of paths from root to node 
{
	if(!root)
		return;
	
	two_D_print(root->right,current_depth+1);

	int i = current_depth;
	while(i--)
		std::cout<<"\t";
	std::cout<<root->data<<std::endl;

	two_D_print(root->left,current_depth+1);
}

int main()
{
	struct node* root=create_bst();
	inorder(root);
	std::cout<<std::endl;
	two_D_print(root);
}