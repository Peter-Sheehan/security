#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void insecurefunction()
{
  printf("I haven't been called in so long, do the users hate me?\n");
  fflush(stdout);
}

void processinput(char *input)
{
  char safebuffer[512];

  printf("Copying this user input into our secure database: ");
  printf(input);

  strcpy(safebuffer, input);
  printf("Copy complete, security is assured!");

}

int main(int argc, char **argv)
{
  processinput(argv[1]);
  exit(1);
}
