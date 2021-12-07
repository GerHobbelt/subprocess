#include <iostream>
#include <subprocess.hpp>

#include "monolithic_examples.h"

// no echo on windows, so we make this to help test the library

#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      subproc_printenv_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
    if (argc != 2) {
        std::cout << "printenv <var-name>\n    Will print out contents of that variable\n";
        std::cout << "    Returns failure code if variable was not found.\n";
        return 1;
    }
    std::string result = subprocess::cenv[argv[1]];
    if (result.empty())
        return 1;
    std::cout << result << "\n";
    return 0;
}
