#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int max(int a, int b)
{
    return a>b? a: b;
}
double max(double a, double b)
{
    return a>b? a: b;
}
string max(string a, string b)
{
    return a>b? a: b;
}
int max(const vector<int>& vec)
{
    return *(max_element(vec.begin(), vec.end()));
}

double max(const vector<double>& vec)
{
    return *(max_element(vec.begin(), vec.end()));
}


string max(const vector<string>& vec)
{
    return *(max_element(vec.begin(), vec.end()));
}

int max(const int a[], int len)
{
    return *(max_element(a, a+len));
}

double max(const double a[], int len)
{
    return *(max_element(a, a+len));
}

// 字符串数组
string max(const string *array, int size)
{
	return *max_element(array, array + size);
}

int main(int argc, char const *argv[])
{
	int intArray[] = { 5, 10, 15, 20, 25 };
	vector<int> intVec(intArray, intArray + 5);
	double douArray[] = { 5.1, 5.5, 10.3, 15.6, 20.8 };
	vector<double> douVec(douArray, douArray + 5);
	string strArray[] = { 
		"we", 
		"were", 
		"going", 
		"to", 
		"school" 
	};
	vector<string> strVec(strArray, strArray + 5);

    for(auto i:strVec)
    cout<<i<<endl;

    cout<<endl;

    
    cout<<max(intVec)<<" "<<max(intArray,5)<<endl;

	int intMax = max(max(intVec), max(intArray, 5));
	double douMax = max(max(douVec), max(douArray, 5));
	string strMax = max(max(strVec), max(strArray, 5));


	cout << "The max of integers is " << intMax << endl;
	cout << "The max of doubles is " << douMax << endl;
	cout << "The max of strings is " << strMax << endl;
	return 0;
}