//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};

//input var
char input[256];


//----------------------------------Functions--------------------------------

void createStudent(char* fname, char* lname, int age, int id)
{

  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  Student* st = (Student*)malloc(sizeof(Student));
  st->firstName = malloc(strlen(fname));
  st->lastName = malloc(strlen(lname));
  strcpy(st->firstName, fname);
  strcpy(st->lastName, lname);
  st->age = age;
  st->id = id;
  students[numStudents] = st;
  numStudents++;

}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
  //this is actually supposed to be three lines long. fname, lname, set the pointer to 0.
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  for (int i=0; i<numStudents; i++)
  {
    deleteStudent(students[i]);
    students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  FILE* fp;
  char buff[256];

  fp = fopen("studentdata.txt", "w");
  if (fp)
  {
    for (int i=0; i<numStudents; i++){
      sprintf(buff, "%s %s %d %ld \n", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
      
      //encryption!!
      caesarEncrypt(buff, key);

      fprintf(fp, "%s \n", buff);
      }
    fclose(fp);
  }
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  deleteStudents();
  FILE* fp;
  fp = fopen("studentdata.txt", "r");
  if (fp)
  {
    while (1)
    {
      char buff[256];
      char *fname, *lname;
      int age;
      long id;
      fscanf(fp, "%s\n", buff);
      if (key != 0){
        caesarDecrypt(buff, key);
      }
      //below, I use %ms to allocate the right amt of memory
      if (sscanf(buff, "%ms %ms %d %ld \n", &fname, &lname, &age, &id) == 4) //# of things that match
      {
	createStudent(fname, lname, age, id);
	free(fname);
	free(lname);
      }
      else
      {
	printf("No more students in your save file!\n");
	printf("Loaded %d students.\n", numStudents);
	break;
      }
    }
  }
}


void printStudent(Student* student)
{
  printf("    Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id);
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




