/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"
#include "writer.h"
#include <cstdlib>
/* global variables if needed go here */
int main(int argc, char** argv) {
    /* check command line arguments */
    /* load the file and copy it to the destination */
    if (argc == 3) {
        writer* myWriter = new writer(argv[2]);
        reader* myReader = new reader(argv[1], *myWriter);

        myReader->run();

        delete myReader;
        delete myWriter;
    }
    else {
        std::cout << "\nincorrect number of arguments entered, please try again." << std::endl;
    }
    return EXIT_SUCCESS;
}
