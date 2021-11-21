#include<iostream>
#include<vector>

using namespace std;

bool check(const int &len)
{
    if(len<0 || len >= std::vector<int>().max_size())
    return false;

    return true;
}


const std::vector<int>& getPentagonal(int len)
{
    static std::vector<int>pentagonal;

    for(int  i = len>=pentagonal.size() ? pentagonal.size():len+1; i<=len; i++)
    pentagonal.emplace_back ( i * (3 * i - 1)/2 );

    return pentagonal;
}

int get_elem( int posi )
{
    if(!check(posi)) return 0;


    // 若getPentagonal返回的是指针
    // auto it =  getPentagonal(posi);

    // return (*it)[posi];

    // 若返回的是引用

    return getPentagonal(posi)[posi];
}

int main(int argc, char const *argv[])
{
    int posi;
    // 逗号运算符 计算第一个并且丢弃结果, 计算第二个并返回
    while (cout<<"Which one in pentagonal: ", 
    cin>>posi)
    {   
        cout<<"it's "<< get_elem(posi)<<endl;
    }

    return 0;
}
