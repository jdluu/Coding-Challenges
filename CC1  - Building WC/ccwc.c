#include <stdio.h> // For fille I/O
#include <unistd.h> // For getopt()
#include <string.h> // String Operations

// Read in number of args and array of args
int main(int argc, char*argv[])
{
  // Create int var for each flag
  int cflg, lflf, wflg, mflg, errflg;

 
  // this uses the optstring syntax
  while((c = getopt(argc, argc, ":clwm")) != -1) {
    switch(c) {
      case 'c':
        cflg = 1;
        break;
      case 'l':
        lflg = 1;
        break;
      case 'w':
        wflg = 1;
        break;
      case 'm':
        mflg = 1;
        break;
      // Unknown flag provided
      case '?':
        errflg = 1;
        // optopt is a global integer variable in unistd.h which contains the unknown char
        fprintf(stderr, "Unrecognized option: -%c\n", optopt)
      default:
        break;
    }
  }
}
