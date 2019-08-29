#include<iostream>
int* make_hash_map(int *arr,int n,int *max_ptr)
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    int *hash_map=new int[max+1]{};
    for(int i=0;i<n;i++)
        hash_map[arr[i]]++;
    *max_ptr=max;
    return hash_map;
}
void delete_hash_mmap(int *hash_map)
{
    delete hash_map;
}
int main()
{
    int arr[]={2,4,1,8,5,6};
    int n=6;
    int max;
    int *hm=make_hash_map(arr,n,&max);
    delete_hash_mmap(hm);
    *(hm+2)=2;
    std::cout<<*(hm+2)<<std::endl;
}
