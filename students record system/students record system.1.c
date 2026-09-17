#include <stdio.h>
#include <string.h>

struct Student {
 int rollNo;
 char name[20];
 float marks;
};

void addStudent();
void displayStudent();
void searchStudent();

int main(){
 int choice;
 while(1){
  printf("\n--Student Record Management System --\n");
  printf("1. Add Student\n");
  printf("2. Display Student\n");
  printf("3. Search Student\n");
  printf("4. Exit\n");

  printf("Enter you choice: ");
  scanf("%d",&choice);

  switch(choice){
   case 1: addStudent(); break;
   case 2: displayStudent(); break;
   case 3: searchStudent(); break;
   case 4: return 0;
   default: printf("Invalid choice! Try again.\n");
  }
 }
}


void addStudent(){
 struct Student s;
 FILE *fp = fopen("students.txt","a");

 if(fp == NULL){
  printf("Error opening file!\n");
  return;
 }

 printf("Enter Roll Number: ");
 scanf("%d",&s.rollNo);

 printf("Enter Name: ");
 scanf("%s",&s.name);

 printf("Enter Marks: ");
 scanf("%f",&s.marks);

 fprintf(fp,"%d %s %.2f\n",s.rollNo, s.name, s.marks);

 fclose(fp);

 printf("Student record added successfully!\n");
}


void displayStudent(){
 struct Student s;
 FILE *fp = fopen("students.txt","r");

 if(fp == NULL){
  printf("No records found! (File is empty or doesn't exist yet)\n");
  return;
 }

 printf("\n-- Student Records --\n");

 while(fscanf(fp,"%d %s %f", &s.rollNo, s.name, &s.marks) == 3){
  printf("%d %s %.0f\n", s.rollNo, s.name, s.marks);
 }

 fclose(fp);
}


void searchStudent(){
 struct Student s;
 int searchRoll,found=0;
 FILE *fp = fopen("students.txt","r");

 if(fp == NULL){
  printf("No records found to search!\n");
  return;
 }

 printf("Enter Roll Number to search: ");
 scanf("%d",&searchRoll);

 while(fscanf(fp,"%d %s %f",&s.rollNo, s.name, s.marks) <= 3){

  if(s.rollNo == searchRoll){
   printf("\nRecord Found: \n");
   printf("Roll No: %d\n", s.rollNo);
   printf("Name: %s\n",s.name);
   printf("Marks: %.2f\n", s.marks);
   found = 1;
   break;
  }
 }
 fclose(fp);

 if(!found){
  printf("Student with Roll Number %d not found.\n", searchRoll);
 }
}

