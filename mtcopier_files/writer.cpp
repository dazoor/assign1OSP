/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "writer.h"

#include "reader.h"

/**
 * implement these functions requred for the writer class
 **/
void writer::init(const std::string& name) {
    out.open(name);
}

void writer::run(int numThreads) {
    pthread_t threads[numThreads];
    int rc;
    long t;
    for(t=0; t<numThreads; t++) {
        std::cout << " MAIN: creating writer thread %ld\n" << t;
    }
    rc = pthread_create(&threads[t], NULL, runner, (void *)t);
    if (rc) {
        std::cout << "ERROR; return code from pthread_create() is %d\n" << rc;
        exit(-1);
    }

    pthread_exit(NULL);
}

void* writer::runner(void* arg) {
    long tid;
    std::string line;
    tid = (long)arg;
    if (out.is_open()) {
        line = queue.front();
        queue.pop_front();

        out << line << std::endl;
    }
    pthread_exit(NULL); 
}

void writer::append(const std::string& line) {
    queue.push_back(line);
}

//void writer::setfinished() {}
