#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<typeinfo>
using namespace std;

int main(int argc, char const *argv[])
{
    string sb = "woshiyige dashabi";

    cout<< typeid(sb.find_last_of('z', sb.size())).name();

    cout<<endl<<typeid(string::npos).name();
    return 0;
}
