#include <iostream>
#include "bst.hpp"

//dd-diagonal distance from the root.Increases when we move left,stays the same when we go right.
//in this case,level is taken at 45 degrees.dd can also be thought of current level at 45 deg.
int bottom_right_view(struct node* root,int dd,int max_level_so_far)
{
	if(!root)
		return max_level_so_far;
	
	max_level_so_far = bottom_right_view(root->right,dd,max_level_so_far);

	if(dd > max_level_so_far)
	{
		std::cout<<root->data<<"\t";
		max_level_so_far = dd;
	}

	bottom_right_view(root->left,dd+1,max_level_so_far);
}
int main()
{
	struct node* root = create_bst();
	inorder(root);
	std::cout<<std::endl;
	bottom_right_view(root,0,-1);
	std::cout<<std::endl;
}