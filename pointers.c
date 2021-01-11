#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);



  float d = 4;
  float e = 8;
  float * ptrtod;
  float * ptrtoe;

  ptrtod = &d;
  ptrtoe = &e;
  printf("the values of d and e are %f and %f respectively, and their addresses are %p and %p\n", d, e, ptrtod, ptrtoe);

  *ptrtod = 0;
  *ptrtoe = 2;

  printf("now, the variables contain the values %f and %f\n", d, e);
}
