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
void grade_students(struct grade *grades,int num_Students) {

}
int main() {
  struct grade grd;
  struct grade *grades = (struct grade *)malloc(sizeof(struct grade));
  char *professor = (char*)calloc(256,sizeof(char));
  int num_Students = 0;
  puts("Enter your name");
  scanf("%s",professor);

  puts("Enter The amount of students to mark");
  scanf("%d",&num_Students);

  int i = 0;

  puts("Please enter The students ID and grade");
  
  for (i = 0; i < num_Students; i++) {
    printf("Student : %d\n",i+1 );
    printf("ID: ");
    scanf("%d",&grades->student_id);
    printf("Mark: ");
    scanf("%d",&grades->student_id);
  }
  
  return 0;
}
