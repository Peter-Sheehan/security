#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

unsigned int globalcanary;

void lonelyfunction()
{
  printf("Nobody ever calls me, I'm so bored.\n");
  fflush(stdout);
}


void getpath()
{
  volatile unsigned int xorcanary;
  char buffer[64];
  unsigned int ret;
  unsigned int studentid;

  studentid = 297366; //***REPLACE WITH YOUR ACTUAL STUDENT ID BEFORE COMPILING THE CODE***
  srand(studentid);
  globalcanary = rand(); //assign a random value to globalcanary (based upon your student id as the rng seed)

  ret = __builtin_return_address(0); //set ret to the original return address

  xorcanary = globalcanary ^ ret; //XOR of the globalcanary and the current return address

  printf("Enter input: "); fflush(stdout);

  gets(buffer);

  printf("Received input:");
  printf(buffer);

  ret = __builtin_return_address(0); //update ret to the current return address

  if( xorcanary != (globalcanary ^ ret) ) {
      printf("***Stack Smashing Detected *** (%p)\n", xorcanary);
      _exit(1);
  }
}

int main(int argc, char **argv)
{

  getpath();

}