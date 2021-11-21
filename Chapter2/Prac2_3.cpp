#include<vector>
#include<iostream>

inline
bool check(const int &len)
{
    if(len<0 || len >= std::vector<int>().max_size())
    return false;

    return true;
}

void getPentagonal(int len, std::vector<int> &vec)
{
    if(!check(len))
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

int main(int argc, char const *argv[])
{
    std::vector<int> vecPentagonal;
    int pos;
    std::cout << "Please enter a position: ";
    std::cin >> pos;
    const std::string title("Pentagonal Numeric Series");
    if (check( pos)) {
        getPentagonal(pos, vecPentagonal);
        print(vecPentagonal, title);
    }
    return 0;
}
