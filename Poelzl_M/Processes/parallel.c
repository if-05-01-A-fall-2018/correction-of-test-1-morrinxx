#include <stdio.h>
#include <string.h>
#include <unistd.h>

char* arguments[] = {"ls", "df", "ps", "pwd"};


int main(int argc, char const *argv[]) {
  int count = 0;
  while (arguments[count] != 0) {
    int pid = fork();
    if(pid == 0){
      execvp(arguments[count], arguments);
    }
    else{
      int status;
      waitpid(-1, &status, 0);
    }

    count++;
  }
  printf("Done\n");

  return 0;
}
