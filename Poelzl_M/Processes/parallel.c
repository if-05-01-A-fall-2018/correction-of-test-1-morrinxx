#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char* arguments[] = {"ls", "df", "ps", "pwd", 0};
char* command;


int main(int argc, char const *argv[]) {
  int count = 0;
  while (arguments[count] != 0) {
    int status;
    if(fork() != 0){
      waitpid(-1, &status, 0);
    }
    else{
      command = arguments[count];
      char* commandArray[2] = {command, 0};
      execvp(command, commandArray);

      printf("FEHLER!!!\n");

    }

    count++;
  }
  printf("Done\n");

  return 0;
}
