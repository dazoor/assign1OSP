
##
 # startup code provided by Paul Miller for COSC1114 - Operating Systems
 # Principles
 ##

# provide make targets here to build the two programs 

.default: all

all: copier

clean:
	find . -name '*.o' -type f -delete
	find . -name 'copier' -type f -delete
	find . -name 'mtcopier' - type f -delete

copier: copier_files/main.o copier_files/reader.o copier_files/writer.o
	g++ -Wall -Werror -std=c++20 -g -O -o $@ $^
