#include <iostream>
#include <vector>
struct node{
	int data;
	struct node *left,*right;
	node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

void k_sum_paths(struct node *root,std::vector<int> v,int k)
{
	if(!root)
		return;
	if(k == root->data)
	{
		if(!v.empty())
		{
			for(auto i=v.begin();i!=v.end();i++)
				std::cout<<*i<<"\t";
		}
		std::cout<<root->data<<std::endl;
		v.push_back(root->data);
		k_sum_paths(root->left,v,k-root->data);
		k_sum_paths(root->right,v,k-root->data);	
		return;
	}
	k_sum_paths(root->left,v,k);
	k_sum_paths(root->right,v,k);
	v.push_back(root->data);
	k_sum_paths(root->left,v,k-root->data);
	k_sum_paths(root->right,v,k-root->data);
}
int main()
{
	std::vector<int> v;
	node *root = new node(1); 
    root->left = new node(3); 
    root->left->left = new node(2); 
    root->left->right = new node(1); 
    root->left->right->left = new node(1); 
    root->right = new node(-1); 
    root->right->left = new node(4); 
    root->right->left->left = new node(1); 
    root->right->left->right = new node(2); 
    root->right->right = new node(5); 
    root->right->right->right = new node(2); 
    k_sum_paths(root,v,5);
}