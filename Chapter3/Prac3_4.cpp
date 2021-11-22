/*
11/22/2021 Geng


find_if函数的实现如下
template<class InputIterator, class UnaryPredicate>
  InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (pred(*first)) return first;
    ++first;
  }
  return last;
}


*/


#include<iterator>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;


// fileter 泛型算法
template <typename InputIterator, typename OutputIterator, 
            typename Comp>
OutputIterator filter(InputIterator beginn, InputIterator endd, OutputIterator& tar,  Comp cmp)
{
    while( (beginn = find_if(beginn , endd, cmp)) != endd)
    {
        cout<<"found Val : "<<*beginn<<" ";
        *tar++ = *beginn++;
    }

    cout<<endl;
    return tar;
}

bool isOdd(int val)
{
    if(val % 2 == 0)return true;
    return false;
}

bool isEven(int val)
{
    if(val % 2 == 0)return false;
    return true;
}

void initVec(vector<int>& vec)
{
    // 定义两个 iostream iterator
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;

    // 使用泛型算法, 与iterator inserter 
    copy(is, eof, back_inserter(vec));

    return ;
}

int main(int argc, char const *argv[])
{


    ofstream odd_file("./prac3_4_out_odd.txt");
    ofstream even_file("./prac3_4_out_even.txt");
    ostream_iterator<int> odd_iter(odd_file, " ");
    ostream_iterator<int> even_iter(even_file, "\n");

    vector<int> nums;

    initVec(nums);

    cout<<"nums:";
    for(auto c: nums)
    {
        cout<<c<<" ";
    }
    // 两个保存结果的vector
    vector<int> odd_nums;
    vector<int> even_nums;

    back_insert_iterator<vector<int>> odd_inserter = back_inserter(odd_nums);
    back_insert_iterator<vector<int>> even_inserter = back_inserter(even_nums);

    // 如果第三个参数直接传back_inserter(odd_nums) 的话 会报错, 
    // 因为back_inserter()返回的这是个临时变量相当于 是个rvalue; 所以传过去后没法当作左值
    // 必须给他弄成左值之后再传参
    filter(nums.begin(), nums.end(), odd_inserter, isOdd );

    filter(nums.begin(), nums.end(), even_inserter, isEven );


    copy(odd_nums.begin(), odd_nums.end(), odd_iter);
    copy(even_nums.begin(), even_nums.end(), even_iter);
    

    for(auto c: odd_nums )
    cout<<c<<endl;
    return 0;
}
