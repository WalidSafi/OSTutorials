
#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define numThreads 10

void *class_total(void *grade);

int total_grade = 0;
int counter;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char const *argv[]) {

  int grades[10];

  pthread_t threads[numThreads];

  puts("Enter the 5 students grades");

for (int i = 0; i <10; i++) {
  printf("Student %d: ",i + 1 );
  scanf("%d",&grades[i]);
}

for (int i = 0; i <  numThreads; i++) {
  pthread_create(&threads[i],NULL,class_total,&grades[i]);
}

for (int i = 0; i <  numThreads; i++) {
  pthread_join(threads[i],NULL);
}

  printf("Total grades = : %d\n",total_grade );
  return 0;
}

void *class_total(void *grade) {

  int g = *(int *)grade;
  pthread_mutex_lock(&mutex1);
  total_grade = total_grade + g;
  counter++;
  printf("%d\n", counter);
  pthread_mutex_unlock(&mutex1);

  return 0;
}
