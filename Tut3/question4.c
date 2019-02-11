#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <sys/random.h>
#include <time.h>

int main() {

  int *grades;
  int *student_ids;
  int num_Students=0;
  char *professor =(char*)calloc(256,sizeof(char));

  puts("Enter your name");
  scanf("%s",professor);

  puts("Enter The amount of students to mark");
  scanf("%d",&num_Students);

  printf("Your name is: %s\n",professor);
  printf("The amount of students to mark is: %d\n", num_Students);

  grades = malloc(num_Students);
  student_ids = malloc(num_Students);

  free(professor);
  free(grades);
  free(student_ids);

  return 0;
}
