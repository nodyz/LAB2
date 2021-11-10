#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

   char name [100] ;

   for(int i=0; i<4; i++) {

   printf("enter your name :\n");
   scanf("%[^\n]%*c", name);


     pid_t pid = fork();
     if(pid==0) {

     printf("I am the Child Process => PPID=%d, PID=%d\n", getppid(), getpid());
     printf("Hi,%s!\n", name);
     exit(0);
     }

     else {
         printf("I am the Parent Process => PID=%d\n", getpid());
         printf("Waiting for child process to finish ... \n");
         wait(NULL);
         printf("Job is done \n");
      }
     }

      return EXIT_SUCCESS;
}


