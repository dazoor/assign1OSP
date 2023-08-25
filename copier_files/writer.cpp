/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/

#include "writer.h"

/**
 * provide your implementation for the writer functions here
 **/
writer::writer(const std::string& name) {
    out.open(name);
}

void writer::run() {
    for (const std::string& str : queue) {
        out << str << std::endl;
    }
    out.close();
}

void writer::append(const std::string& line) {
    queue.push_back(line);
}
