#include <stdio.h> // For fille I/O
#include <stdlib.h> // For EXIT_SUCCESS and EXIT_FAILURE macros.
#include <unistd.h> // For getopt()
#include <string.h> // String Operations

// Read in number of args and array of args
int main(int argc, char*argv[])
{
  int c;
  // Create int var for each flag
  int c_flag = 0;
  int l_flag = 0;
  int w_flag = 0;
  int m_flag = 0;
  int err_flag = 0;

  // Counter variables
  long byte_count = 0; 
  long line_count = 0; 
  long word_count = 0; 
  long char_count = 0;
  
  char *filename = NULL;
  FILE *file_ptr = NULL;

  // this uses the optstring syntax
  while((c = getopt(argc, argv, ":clwm")) != -1) {
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
    fprintf(stderr, "Usage: %s [-c] [-l] [-w] [-m] [file]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  // Default Behavior is to count bytes, lines, and words
  if (!c_flag && !l_flag && !w_flag && !m_flag) {
    c_flag = 1;
    l_flag = 1;
    w_flag = 1;
  }






}
