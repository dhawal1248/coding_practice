#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#define PARENT(i) ((i-1)/2)
#define LCHILD(i) (2*i+1)
#define RCHILD(i) (2*i+2)

struct heap{
    int *arr;
    int size;
    int capacity;
};
void swap(int *arr,int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void adjust_max_heap(struct heap* h)
{
    h->capacity *=2;
    h->arr=(int*)realloc(h->arr,sizeof(int)*h->capacity);    
}
void increase_key(struct heap *h,int index,int data)
{
    if(h->arr[index]>data)
    {
        std::cout<<"Value at node : "<<index<<" is greater than provided : "<<data<<std::endl;
        return;
    }
    h->arr[index] = data;
    int i=index;
    while(i>=0 && h->arr[PARENT(i)] < h->arr[i])
    {
        swap(h->arr,i,PARENT(i));
        i=PARENT(i);
    }
}
void max_heap_insert(struct heap* h,int data)
{
    if(h->size==h->capacity)
        adjust_max_heap(h);
    h->arr[h->size]=INT_MIN;
    h->size += 1;
    increase_key(h,h->size-1,data);
}
void max_heapify(struct heap* h,int i)//expects children of i to be max heaps,makes i a max heap
{
    int lchild=LCHILD(i);
    int rchild=RCHILD(i);
    int largest=i;
    if(lchild < h->size && h->arr[lchild] > h->arr[i])
        largest=lchild;
    if(rchild < h->size && h->arr[rchild] > h->arr[largest])
        largest=rchild;
    if(largest != i)
    {
        swap(h->arr,i,largest);
        max_heapify(h,largest);
    }
}
int extract_max(struct heap* h)
{
    if(h->size)
    {
        swap(h->arr,0,h->size-1);
        int max_pos=h->size-1;
        h->size -= 1;
        max_heapify(h,0);
        return h->arr[max_pos];
    }
}
void  build_max_heap(struct heap* h)
{
    for(int i=ceil(h->size/2)-1;i>=0;i--)
    {
        max_heapify(h,i);
        for(int i=0;i<10;i++)
            std::cout<<h->arr[i]<<"\t";
        std::cout<<std::endl;
    }    
}
int main()
{
    struct heap h;
    h.size=h.capacity=0;
    h.arr = (int *)malloc(sizeof(int)*10);
    h.size=h.capacity=10;
    for(int i=0;i<10;i++)
        h.arr[i]=i;
    build_max_heap(&h);
    //for(int i=0;i<10;i++)
    //    std::cout<<h.arr[i]<<"\t";
    //std::cout<<"\n"<<extract_max(&h)<<std::endl;
    //std::cout<<"\n"<<extract_max(&h)<<std::endl;
    max_heap_insert(&h,11);
    for(int i=0;i<h.size;i++)
        std::cout<<h.arr[i]<<"\t";
    std::cout<<std::endl;
}
