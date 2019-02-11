#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <sys/random.h>
#include <time.h>


int main() {

  char name[256];
  int age = 0;
  float height = 0;
  puts("Enter your Name, Age and Height(m) sperated by a space");
  scanf("%s %d %f",name,&age,&height );
  puts("Information specified:");
  printf("Name: %s\nAge: %d\nHeight: %.2fm\n",name,age,height);
  return 0;
}
