#include<iostream>
#include<limits>
int abc(int n)
{
    if(n)
        return 1;
    else
        return 100;
}
int main()
{
    int n = std::numeric_limits<int>::quiet_NaN();
    std::cout<<"Enter"<<std::endl;
    std::cin>>n;
    abc(n);
}
