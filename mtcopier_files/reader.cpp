/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"


/**
 * implement the functions needed for this class
 **/
std::ifstream reader::in;


reader::reader(writer& mywriter) : thewriter(mywriter) {}


void reader::init(const std::string& name) {
    in.open(name);
}

void reader::run(int numThreads) {
    pthread_t threads[numThreads];
    int rc;
    long t;
    for(t=0; t<numThreads; t++) {
        std::cout << " MAIN: creating reader thread %ld\n" << t;
    }
    rc = pthread_create(&threads[t], NULL, runner, (void *)t);
    if (rc) {
        std::cout << "ERROR; return code from pthread_create() is %d\n" << rc;
        exit(-1);
    }

    pthread_exit(NULL);
}

void* reader::runner(void* arg) { 
    long tid;
    std::string line;
    tid = (long)arg;
    if (in.is_open()) {
        std::getline(in, line);
        writer thewriter = *reinterpret_cast<writer*>(arg);
        thewriter.append(line);
        
    }
    pthread_exit(NULL); 
}
