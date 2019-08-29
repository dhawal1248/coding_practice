#include <iostream>
#include<cmath>
#include "bst.hpp"
void width_tree(struct node* root,int *lwidth,int *rwidth,int hd)//hd-horizontal dist
{
	if(!root)
		return;
	if(hd == 0 && *lwidth==-1 && *rwidth==-1)
	{
		*lwidth=0;
		*rwidth=0;
	}
	if(hd < *lwidth)
		*lwidth = hd;
	if(hd > *rwidth)
		*rwidth = hd;
	width_tree(root->left,lwidth,rwidth,hd-1);
	width_tree(root->right,lwidth,rwidth,hd+1);
}
void print_2D_level(struct node* root,int lwidth,int rwidth,int hd,int level)//2D prints a level
{
	if(!root)
		return;
	if(level==0)
	{
		if(hd<0)
		{
			//
		}
		std::cout<<root->data;

	}
}
int main()
{
	struct node* root=create_bst();
	inorder(root);
	std::cout<<std::endl;
	int lw=0,rw=0;//left and right width
	width_tree(root,&lw,&rw,0);

}