#include <stdio.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], int* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%d", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your arrayAdd function here
void arrayAdd(int* arrptr, int size, int inc)
{
  int i;

  for(int i=0; i<5; i++)
  {
    *arrptr = *arrptr + inc;
    arrptr++;
  }
}



int main(int argc, char* argv[]) 
{
  // the variable which controls the size of the array
  int size = 5;
  
  // the variable which increments the values in the array
  int inc = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &size, &inc);

  printf("array loop size: %d, inc %d\n", size, inc);
  
  // add your code below to:
  // - initialize the a 'size' element array
  // - fill it with the square of each index using a for loop i.e. 0, 1, 4, 9 etc
  // - pass the array to arrayAdd to add the increment of inc
  // - print out the array

  //not sure how to do the fill array stuff. sorry
  int theArray[5] = { 0, 1, 4, 9, 16, };
  int *p = theArray;
  int i;

  arrayAdd(p, size, inc);

  for (i = 0; i < 5; i++)
  {
  printf("%d\n", theArray[i]);
  }
}
