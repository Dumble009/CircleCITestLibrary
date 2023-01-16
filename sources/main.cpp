// ----------STLのinclude----------
#include <iostream> // 入出力
#include "test_lib.h"

int main(void)
{
    std::cout << "Hello World!" << std::endl;
    int a = 1, b = 2;
    std::cout << "1 + 2 = " << testLib::add(a, b) << std::endl;
}