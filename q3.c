#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define numThreads 5

typedef struct{
  double grades;
  int student_id;
  char Student_name[10];
} Sinfo;

void *bellcurve(void *grade);

int main() {

  Sinfo *info =(Sinfo *) malloc(sizeof(Sinfo));


  puts("Enter the 5 students grades");


for (int i = 0; i < 5; i++) {

  printf("Student %d: \n",i + 1 );
  printf("Mark:");
  scanf("%le",&info[i].grades);
  printf("Student Id: ");
  scanf("%d",&info[i].student_id);
  printf("Name: ");
  scanf("%s",info[i].Student_name);
}

  pthread_t *threads = malloc(10*sizeof(pthread_t));

for (int i = 0; i <  numThreads; i++) {
  pthread_create(&threads[i],NULL,bellcurve,&info[i]);
}

for (int i = 0; i < numThreads; i++) {
  pthread_join(threads[i],NULL);
  }
}

void *bellcurve(void *grade){

  Sinfo *data =(Sinfo *) grade;
  double newGrade = 0;
  newGrade = data->grades;
  int id = data-> student_id;
  char* name = data->Student_name;

  newGrade = newGrade *1.5;

  if (newGrade > 100) {
    newGrade = 100;
  }

  printf("New Mark: %.1f\n",newGrade);
  printf("Student Id: %d\n",id );
  printf("StName: %s\n",name);
  return 0;
}
