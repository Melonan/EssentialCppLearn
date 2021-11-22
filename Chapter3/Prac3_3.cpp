#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void initMap(ifstream& in_file, map<string , vector<string>>& mp)
{
    string line;
    while(getline(in_file, line , '\n'))
    {
        string familyName ;
        string::size_type pos = 0, last_pos = line.size();
        if(!last_pos) continue;
        cout<<line<<" "<<last_pos<<endl;



        while((pos = line.find_last_of(' ', last_pos-1)) != string::npos)
        {
            cout<<"pos: "<<pos<<endl;
            cout<<"last pos: "<<last_pos<<endl;
            if(last_pos == line.size())
            {
                familyName = line.substr(pos+1, last_pos - pos - 1);
                last_pos = pos;
                mp[familyName] = vector<string>();

                cout<<"family :"<<familyName<<endl;
                continue;
            }

            mp[familyName].emplace_back(line.substr(pos+1, last_pos - pos - 1));
            last_pos = pos;

            
        }

        if(last_pos == line.size())
        {
            // 证明此时line中只有一个单词, pos == string::npos 一个<space>都没搜索到
            familyName = line.substr(0, last_pos - 0 );
            last_pos = pos;
            mp[familyName] = vector<string>();
                
        }
        else
        {
            // 类似的, 此时到了最前一个单词, 没有<space>了 pos == string::npos
            mp[familyName].emplace_back(line.substr(0, last_pos));
        }   

        cout<<"this family: "<<endl;    
        for(auto child: mp[familyName])
        {
            cout<<child<<" ";
        }
        
        
        cout<<endl<<endl;
    }

}


void displayMap(ofstream& ofs, map<string , vector<string>>& mp)
{
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        ofs<<"Family: "<<it->first<<endl;
        
        for(auto i : it->second)
        {
            ofs<<i<<" ";
        }
        ofs<<endl;
    }



}
bool queryFamily(const string& familyName, map<string, vector<string>>& mp)
{
    if(mp.count(familyName) == 0)
    {
        cout<<"No this family" ; 
        return false;
    }
    
    for(auto now : mp[familyName])
    {
        cout<<now<<" ";
    }
    cout<<endl;

    return true;



}

int main(int argc, char const *argv[])
{

    ifstream in_file("./prac3_3.txt");
    ofstream out_file("./prac3_3_out.txt");
    map<string , vector<string> >family;

    initMap(in_file, family);

    displayMap(out_file, family);
    
    string familyName;
    while(cout<< "Enter the Family you want to query: ", cin>>familyName )
    {
        queryFamily(familyName,family);
    }

    return 0;
}
