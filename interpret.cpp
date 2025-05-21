#include <iostream>
#include "processor.h"
int main()
{
    try {
        Processor processor("test.txt");
        processor.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
