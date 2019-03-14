
#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define numThreads 10

void *save_bellcurve(void *grade);

void *read_grades();

int total_grade = 0;
int total_bellcurve_grade = 0;
int counter;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barr;
int grades[numThreads];
FILE *fp;

int main() {

pthread_t threads[numThreads];
pthread_t readThread;


pthread_create(&readThread,NULL,read_grades,NULL);

pthread_barrier_init(&barr,NULL,numThreads+1);

 for (int i = 0; i <  numThreads; i++) {
  pthread_create(&threads[i],NULL,save_bellcurve,&grades[i]);
}

pthread_join(readThread,NULL);

 for (int i = 0; i <  numThreads; i++) {
  pthread_join(threads[i],NULL);
}


/*for (int i = 0; i < 10; i++) {
 printf("%d\n",grades[i]);
} */

printf("Total before curve =  %d\n",total_grade );
printf("Total after curve =  %d\n",total_bellcurve_grade );
printf("Average before:  %d\n",(total_grade/counter) );
printf("Average after %d\n",(total_bellcurve_grade/counter) );
printf("The counter: %d\n",counter );
}

void *read_grades(){

fp = fopen("grades.txt","r");
if (fp == NULL) {
    puts("error opening the file");
}else{
  for (int i = 0; i < 10;  i++) {
    fscanf(fp,"%d",&grades[i]);
    }
  }
  pthread_barrier_wait(&barr);
}
void *save_bellcurve(void *grade){

  pthread_barrier_wait(&barr);

  int g = *(int *)grade;

  pthread_mutex_lock(&mutex1);

  total_grade = total_grade + g;
  int bellcurve_grade = g *1.5;
  total_bellcurve_grade = total_bellcurve_grade + (g * 1.5);
  counter++;

  fp = fopen("bullcurve.txt","a");
  if (fp == NULL) {
      puts("error opening the file");
  }

  fprintf(fp, "%d\n",bellcurve_grade);

  printf("%d\n", counter);

  pthread_mutex_unlock(&mutex1);

}
