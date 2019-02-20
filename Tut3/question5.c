#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <sys/random.h>
#include <time.h>

struct grade {
  int student_id;
  int mark;
};
void grade_students(struct grade* grades,int num_Students) {

  double sum = 0;
  double average = 0;
  double dev = 0;
  double var = 0;
  //opens grades.txt in write mode
  FILE *fp = fopen("grades.txt","w");
//iterates through the amount of students
    for (int i = 0; i < num_Students; i++) {

      sum += grades[i].mark; // Adds the marks
      //Prints the student Id and marks of each student in the struct
      fprintf(fp," ID: %d, Mark: %d\n",grades[i].student_id,grades[i].mark);
  }
  //Calculate mean
  average = sum / (double) num_Students;

  //Cacluate variance
  for (int i = 0; i < num_Students; i++) {
    var = var + pow((grades[i].mark - average),2);
  }
  //Calculate standard deviation
  dev = sqrt(var);

  fprintf(fp,"The average Mark is : %.1f\n",average );
  fprintf(fp,"The average Variance is : %.1f\n",var);
  fprintf(fp,"The average Standard Deviation is : %.1f\n",dev);
}

int main() {

  struct grade *grades = (struct grade *)malloc(sizeof(struct grade));
  char *professor = (char*)calloc(256,sizeof(char));
  int num_Students = 0;

  // takes in user Information
  puts("Enter your name");
  scanf("%s",professor);

  puts("Enter The amount of students to mark");
  scanf("%d",&num_Students);

  int i = 0;

  puts("Please enter The students ID and grade");
 // Takes in studen id and mark for each student
  for (i = 0; i < num_Students; i++) {
    printf("Student : %d\n",i+1 );
    printf("ID: ");
    scanf("%d",&grades[i].student_id);
    printf("Mark: ");
    scanf("%d",&grades[i].mark);
  }

  grade_students(grades,num_Students);
  
  free(professor);
  free(grades);

  return 0;
}
