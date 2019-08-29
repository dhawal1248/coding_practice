#include <iostream>
#include<stack>
#include "bst.hpp"

void tree_to_array(struct node* root,int *arr,int *c)//c-pointer to a int used for as a counter
{
	if(!root)
		return;
	tree_to_array(root->left,arr,c);
	arr[*c] = root->data;
	*c+=1;
	tree_to_array(root->right,arr,c);
}
void find_k_sum_pairs(int *arr,int n,int k)
{
	int l=0,r=n-1,sum;
	while(l<r)
	{
		sum = arr[l]+arr[r];
		if(sum == k)
		{
			std::cout<<arr[l]<<","<<arr[r]<<std::endl;
			l++;
			r--;
		}
		else
		{
			if(sum < k)
				l++;
			else
				r--;
		}
	}
}
void find_k_sum_pairs_pointer(struct node *root,int k)
{
	if(!root)
		return;
	struct node *inorder_ptr,*rev_inorder_ptr,*temp;
	std::stack<struct node*> inorder_stack,rev_inorder_stack;
	inorder_ptr = root->left;
	rev_inorder_ptr = root->right;
	temp = root;
	while(temp!=NULL)
	{
		inorder_stack.push(temp);
		temp=temp->left;
	}
	temp=root;
	while(temp!=NULL)
	{
		rev_inorder_stack.push(temp);
		temp=temp->right;
	}

	while(inorder_stack.top() != rev_inorder_stack.top())
	{
		int val1 = inorder_stack.top()->data;
		int val2 = rev_inorder_stack.top()->data;

		if(val1+val2 == k)
		{
			std::cout<<val1<<","<<val2<<std::endl;
		}
		if(val1+val2 <= k)
		{
			temp = inorder_stack.top()->right;
			inorder_stack.pop();
			if(temp)
			{
				inorder_stack.push(temp);
				temp = temp->left;
			}
		}
		else
		{
			temp = rev_inorder_stack.top()->left;
			rev_inorder_stack.pop();
			while(temp)
			{
				rev_inorder_stack.push(temp);
				temp = temp->right;
			}
		}
	}
}
int main()
{
	int n;
	std::cin>>n;
	struct node* root = create_bst(n);
	inorder(root);
	std::cout<<std::endl;
	int arr[n];
	int c=0;
	tree_to_array(root,arr,&c);
	int k=6;
	find_k_sum_pairs(arr,n,k);
	find_k_sum_pairs_pointer(root,k);
}