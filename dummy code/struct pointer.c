#include <stdio.h>
#include <stdlib.h>

struct student{
	char name[30];
	float marks;
};

int main(){
	struct student *student_ptr;
	struct student real_student;
	char name[30];
	float mark;
	
	student_ptr = real_student;
	scanf("%s", name); // already an address (&name)
	scanf("%f", &mark);
	sprintf(student_ptr->name, name);
	student_ptr->marks = mark;
	
	printf("Name is %s\n", real_student.name);
	printf("Marks are %f\n", real_student.marks);
}