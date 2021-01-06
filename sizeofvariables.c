#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char c = 'b';

  printf("int c value: %c and size: %lu bytes\n", c, sizeof(c));
}

