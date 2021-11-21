#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;
class LessString
{
private:

public:
    bool operator()(const string& a, const string& b)
    {
        return a.size()<b.size();
    }

};
void initVecotr(ifstream &in_file, vector<string>& vec)
{

    istream_iterator<string> ist( in_file );
    istream_iterator<string> eof;

    copy(ist, eof, back_inserter(vec));

}
void outPut2file(vector<string>& vec, ostream& ofile)
{
    ostream_iterator<string>os(ofile , " ");
    copy(vec.begin(), vec.end(), os);
}


int main(int argc, char const *argv[])
{
    vector<string>vec;
    ifstream in_file("./prac3_1_file.txt");
    ofstream out_file("prac3_2_out.txt");

    initVecotr(in_file, vec);
    // function object 的精髓就是重载() 调用运算符呐!
    // 所以可以当函数一样用, 其实调用的就是那个重载()运算符

    sort(vec.begin() , vec.end(), LessString());

    // for(auto elem:vec)
    // {
    //     out_file<<elem<<" ";
    // }

    outPut2file(vec,out_file);



    return 0;
}
