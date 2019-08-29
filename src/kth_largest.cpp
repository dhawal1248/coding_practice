#include<iostream>
#include<cstdlib>
#include<chrono>
void swap(int *arr,int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int *arr,int l,int r)
{
    int i=l-1;
    int pivot=arr[r];
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,j,i);
        }
    }
    i++;
    swap(arr,i,r);
    return i;
}
int rand_partition(int *arr,int l,int r)
{
    if(l<r)
    {
        int rand_pivot=(int)(l+rand()%(r-l));
        swap(arr,rand_pivot,r);
        return partition(arr,l,r);
    }
}
int quick_select(int *arr,int l,int r,int k)//k is the position in arr where the kth_largest/smallest element will be found(usually k-1)
{
    if(l<=k<=r)
    {
        int pos=rand_partition(arr,l,r);
        std::cout<<"Called quick select with l : "<<l<<" r : "<<r<<" k : "<<k<<" pos : "<<pos<<std::endl;
        if(pos == k)
            return arr[pos];
        if(pos > k)
            return quick_select(arr,l,pos-1,k);
        else
            return quick_select(arr,pos+1,r,k);
    }
}
int main()
{
    int arr[]={7,9,3,2,5,4,6};
    int n=7;
    for(int i=0;i<n;i++)
        std::cout<<arr[i]<<"\t";
    std::cout<<std::endl;
    srand(int(std::chrono::system_clock::now().time_since_epoch().count()));
    int k=2;
    //kth_largest 
    std::cout<<"Kth Largest : "<<quick_select(arr,0,n-1,n-1-(k-1))<<std::endl;
    //kth_smallest
    std::cout<<"Kth Smallest : "<<quick_select(arr,0,n-1,k-1)<<std::endl; 
}


