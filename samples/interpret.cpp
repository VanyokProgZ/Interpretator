//#include <chrono>
#include "processor.h"

int main(int argc, char* argv[])
{
    try {
        if (argc == 1) {
            throw j_error("Need filename, pls start: 'interpret.exe <filename>' for normal mode and 'interpret.exe <filename> <anything>' for debug mode");
        }
        Processor processor(argv[1]);
        if (argc > 2) processor.__DEBUG__STATE__ = true;
        //auto start = std::chrono::high_resolution_clock::now();
        processor.run();
        //auto end = std::chrono::high_resolution_clock::now();
        //auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "duration: " << duration.count() << " microsec" << std::endl;
    }
    catch (std::exception& e) {
        std::cout <<'\n'<< e.what() << '\n';
    }
}
