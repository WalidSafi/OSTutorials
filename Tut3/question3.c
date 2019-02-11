#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <sys/random.h>
#include <time.h>

struct student{
  char student_id[20];
  int age;
  int year;
};

void save_student(struct student s,FILE*fp) {

 if (fp == NULL) {
   puts("Error opening file");
 } else {
   puts("Data was transferred into the file");
   fprintf(fp,"%s,%d,%d",s.student_id,s.age,s.year );
 }
}

int main() {

  FILE* fp;
  fp = fopen("students.txt","a");

  struct student s;

  puts("Enter your student ID:");
  scanf("%s",s.student_id);

  puts("Enter your age:");
  scanf("%d",&s.age);

  puts("Enter the year you started studying at UOIT");
  scanf("%d",&s.year );

  save_student(s,fp);

  return 0;
}
