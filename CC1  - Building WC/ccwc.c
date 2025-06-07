#include <stdio.h> // For fille I/O
#include <unistd.h> // For getopt()
#include <string.h> // String Operations

// Read in number of args and array of args
int main(int argc, char*argv[])
{
  // Create int var for each flag
  int c_flag, l_flag, w_flag, m_flag, err_flag;
  // Counter variables
  int byte_count, line_count, word_count, char_count;
  
  char *filename = NULL;
  FILE *file_ptr = NULL;

  // this uses the optstring syntax
  while((c = getopt(argc, argc, ":clwm")) != -1) {
    switch(c) {
      case 'c':
        c_flag = 1;
        break;
      case 'l':
        l_flag = 1;
        break;
      case 'w':
        w_flag = 1;
        break;
      case 'm':
        m_flag = 1;
        break;
      // Unknown flag provided
      case '?':
        err_flag = 1;
        // optopt is a global integer variable in unistd.h which contains the unknown char
        fprintf(stderr, "Unrecognized option: -%c\n", optopt);
        break;
      default:
        break;
    }
  }
  // Exit without any output when err_flag raised
  if (err_flag) {
    fprintf(stderr, "Unknown flag provided! Exiting!");
  }



}
