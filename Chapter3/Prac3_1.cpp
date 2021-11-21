#include<map>
#include<fstream>
#include<iostream>
#include<set>
#include<string>
#include<iterator>

using namespace std;

map<string , int> mp;
set<string>exclud_key{"a" ,"an","the","but","or","and","but",",","."};


void readWords(ifstream &in_file,  map<string, int>& mp, const set<string>& exclud_key)
{
    string name;
    while(in_file>>name)
    {
        // cout<<name<<" ";
        if(exclud_key.count(name)) continue;

        mp[name]++;
    }
}


void display(const map<string , int>& mp, ofstream& ofile)
{

    // for(auto pir : mp)
    // {
    //     ofile<<pir.first<<" "<<pir.second<<endl;
    // }
    for(auto it = mp.begin(); it!=mp.end(); it++)
    {
        ofile << it -> first << " " << it -> second << endl;
    }

}

void queryWord(const map<string , int>& mp)
{
    string name;
    while
    (cout<<"which word want to query? :"
    , cin>>name)
    {
        auto it = mp.find(name);
        if(it!=mp.end())
        {
            cout<<it->second<<endl;
        }
        else
        {
            cout<<"no this one"<<endl;
        }
    }
    
}

int main(int argc, char const *argv[])
{

    ifstream in_file("./prac3_1_file.txt");
    ofstream out_file("./prac3_1_out.txt");

    if(!in_file.is_open()||!out_file.is_open()) 
    {
        cerr<<"fail to read files";
        return -1;
    } 

    readWords(in_file, mp, exclud_key);

    queryWord(mp);

    display(mp, out_file);

    return 0;
}
