#include <cstdio>
#include <cstring>
#include <subprocess.hpp>

#include "monolithic_examples.h"

// Test stdin/stdout/stderr redirection to/from subprocesses using large amounts of data:
// I noticed that this is, at least on MSWindows, *blocking* in some other implementations/applications
// due to system buffers becoming filled up while the caller app does not read/flush its incoming
// stdout/stderr redirect pipes.
//
// This app is designed to test that observation and test ways to prevent the lockup from occurring.

#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      subproc_stdioblaster_test_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
	// TODO
	
	
	
	
    bool print_space = false;
    std::string use_cerr_str = subprocess::cenv["USE_CERR"];
    bool use_cerr = use_cerr_str == "1";
    auto output_file = use_cerr? stderr : stdout;
    for (int i = 1; i < argc; ++i) {
        if (print_space)
            fwrite(" ", 1, 1, output_file);
        fwrite(argv[i], 1, strlen(argv[i]), output_file);
        print_space = true;
    }
    fwrite("\n", 1, 1, output_file);
    return 0;
}
