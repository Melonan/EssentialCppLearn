#include "Prac2_2.h"


int main(int argc, char const *argv[])
{
    std::vector<int> vec;

    
    getPentagonal(100 , vec);

    print(vec, std::string("Pentagonal"));    

    return 0;
}