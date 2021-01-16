#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float radius)
{
  float area = M_PI * (radius * radius);
  return area;
}



int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  char input[256];
  float start;
  printf("enter a value for the radius: ");
  while (1)
  {
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &start)) break;
    printf("Invalid number try again: ");
  }

  int reps = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
  
  // add your code below to call areaOfCircle function with values between
  // start and end
  for(int i=0; i<reps; i++)
  {
    float newArea = areaOfCircle(start);
    printf("the area of the circle with radius %f is %f\n", start, newArea);
    start += 1;
  }

}
