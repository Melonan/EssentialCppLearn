
#include"Prac2_2.h"
#include<iostream>
void getPentagonal(int len, std::vector<int> &vec)
{
    if(len > vec.max_size() || len<0)
    {
        std::cerr<<"Too much!"<<std::endl;
        return ;
    }

    for(int i = vec.size()?vec.size()+1:0 ; i<=len; i++)
    {
        vec.emplace_back ( i * (3 * i - 1)/2 );
    }
    return ;
}

void print(std::vector<int> &vec, const std::string &type)
{
    std::cout<<"Type: "<<type<<std::endl;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    
}