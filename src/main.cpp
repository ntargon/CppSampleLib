#include <iostream>
#include "func.h"
#include "lib1/lib1.h"

int main(void)
{

    int val = add(lib1_func(), 2);

    std::cout<< "hello world\n";
    std::cout<< "add(1, 2) = " << val << "\n";

    return 0;
}