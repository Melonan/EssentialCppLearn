#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template <typename shari>
shari max(shari a, shari b)
{
    return a>b?a:b;
}

template <typename sharuan>
sharuan max(const vector<sharuan>& vec)
{
    return *(max_element(vec.begin(), vec.end()));
}


template <typename naocan>
naocan max(const naocan a[], int len)
{
    return *(max_element(a, a+len));
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

   auto intMax = max(intArray , 5);
    intMax = ::max(intMax , max(intVec));
   
   auto douMax = max(douArray, 5);
   douMax = ::max(douMax , max(douVec));

    auto strMax = max(strArray , 5);
    strMax = ::max(strMax, max(strVec));

	cout << "The max of integers is " << intMax << endl;
	cout << "The max of doubles is " << douMax << endl;
	cout << "The max of strings is " << strMax << endl;
	return 0;
}