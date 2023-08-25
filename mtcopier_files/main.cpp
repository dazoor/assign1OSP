/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"
#include "writer.h"
#include <cstdlib>
/**
 * these need to be global variables as you'll need handle cleaning them up in
 *cleanup which will automatically be called on program exit
 **/
writer* writers;
reader* readers = new reader(*writers);

void cleanup() {
    /**
     * perform any cleanup you need to do here for global pointers
     **/
    delete readers;
    delete writers;
}

int main(int argc, char** argv) {
    atexit(cleanup);
    /**
     * check command line arguments
     **/
    if (argc == 4) {

        readers->init(argv[2]);
        writers->init(argv[3]);
        const int NUM_THREADS = std::stoi(argv[1]);
        
        readers->run(NUM_THREADS);
        writers->run(NUM_THREADS);
    }
    /**
     * process command line arguments
     **/
    /**
     * initiliaze the reader and writer classes
     **/
    /**
     * initialize the running of each thread. Note you just call run() on each
     * object here, you'll call pthread_create itself in the run function.
     **/

    /**
     *
     * have loop here waiting for the threads to bomplete. Please see
     * section on avoiding busy waiting on the assignment specification to see
     * what need to be done here
      **/
    return EXIT_SUCCESS;
}
