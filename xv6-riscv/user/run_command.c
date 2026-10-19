#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

void execute_line(char** args) {

  // Use fork() to create a child process. Determine if the process
  // is a parent or a child, and run exec() if it is a child, and
  // run wait() if it is a parent.
  // For guidance, the model solution has 9 lines of code.
  int pid = fork();
  
  if (pid == 0) {
    // If child then try and exec() or print error message if error
    exec(args[0], args);
    fprintf(2, "Exec Error!\n");
    exit(1);
  }
  else if (pid > 0) {
    // If parent then wait for child
    wait(0);
  }
  else {
    // If not child or parent then fork error
    fprintf(2, "Fork Error!\n");
    exit(1);
  }
}


int main(int argc, char *argv[]) {

  // Two pointers: to a command and to a null terminator.
  char *args[2] = {0};
  // Fixed-size storage for reading in a line of input, and a pointer
  // to a particular character in this storage.
  char buf[512], *b;
  // Point b to the first character in the line.
  b = &buf[0];
  // Read characters from the standard input. When we find '\n' that
  // means one line has terminated - execute the command.
  fprintf(2, "Please enter command and press enter (type 'q' to exit):\n");
  while (read(0, b, 1) > 0) {
    // Check the current character in b. If it is not special, move the pointer
    // b to the next character and continue reading. If the command string has
    // been fully entered ('\n' is found in b), execute the command by calling
    // execute_line().
    // For guidance, the model solution has 10 lines of code in this loop.
    
    // If b is \n then replace it with \0 when being written into buf and execute
    if (*b == '\n') {
      *b = '\0';
      args[0] = buf;
      // If q is typed first and not part of a string then exit
      if (buf[0] == 'q' && buf[1] == '\0') {
        exit(0);
      }
      b = &buf[0];
      execute_line(args);
      fprintf(2, "Please enter command and press enter (type 'q' to exit):\n");
    }

    else {
      // Move the pointer to the next character
      b++;
    }
  }
  exit(0);
}
