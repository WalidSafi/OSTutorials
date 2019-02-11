#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <sys/random.h>
#include <time.h>

int main() {
  //cretes an integer array
  int ints[10];
  //creates file pointer
  FILE *fp;
  int x = 0;
  // determines size of the array
  int size = sizeof(ints)/sizeof(int);
//opens the file question2.txt with read only permission
  fp = fopen("question2.txt","r");

    if (fp == NULL) { // Checks if file is opened
      puts("Error opening the file");
    }else
    {
      while (size--) { //Loops through the size of the 
      fscanf(fp,"%d",&ints[x]);
      x++;
    }
    }

    for (int i = 0; i < 10; i++) {
      printf("%d\n",ints[i] );
    }
  return 0;
}
