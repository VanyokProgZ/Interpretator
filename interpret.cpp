#include <iostream>
#include "processor.h"

int main(int argc, char* argv[])
{
    try {
        
        Processor processor("test.txt");
        if (argc > 1) processor.__DEBUG__STATE__ = true;
        processor.run();
    }
    catch (std::exception& e) {
        std::cout <<'\n'<< e.what() << '\n';
    }
}
