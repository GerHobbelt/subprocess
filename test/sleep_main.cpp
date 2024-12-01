#include <cstdio>
#include <cstring>
#include <chrono>
#include <charconv>
#include <thread>
#include <string>
#include <iostream>

#include "monolithic_examples.h"

void sleep_seconds(double seconds) {
    std::chrono::duration<double> duration(seconds);
    std::this_thread::sleep_for(duration);
}


#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      subproc_sleep_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
    bool print_space = false;
	if (argc != 2) {
		std::cerr << "subprocess::sleep [seconds]: missing parameter.\n";
		return 1;
	}
    double seconds = std::stod(argv[1]);
    sleep_seconds(seconds);
    return 0;
}
