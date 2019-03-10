#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define numThreads 5

void *bellcurve(void *grade);


int main() {

  double grades[5];

  pthread_t threads[numThreads];

  puts("Enter the 5 students grades");


for (int i = 0; i < 5; i++) {
  printf("Student %d: \n",i + 1 );
  scanf("%lf",&grades[i]);
}

puts(" ");

for (int i = 0; i <  numThreads; i++) {
  pthread_create(&threads[i],NULL,bellcurve,&grades[i]);
}

for (int i = 0; i <  numThreads; i++) {
  pthread_join(threads[i],NULL);
}

/* for (int i = 0; i < 5; i++) {
  printf("%d\n",grades[i]);
} */

}

void *bellcurve(void *grade){

  double curve = 1.50;
  double g = *(double *)grade;

  double newGrade = g * curve;

  if (newGrade > 100) {
    newGrade = 100;
  }

  printf("%.1f\n", newGrade );
  return 0;

}
