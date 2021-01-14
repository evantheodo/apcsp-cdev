# include <stdio.h>
# include <string.h>
char str1[25];
char str2[] = "abcdefghijklmnopqrstuvwxyz";
char str3[51];


int main()
{
  for(int i=0; i<26; i++)
  {
    char c = 'a' + i;
    str1[i] = c;
  }
printf("str1: %s\nstr2: %s\n", str1, str2);
  if(strcmp(str1, str2) == 0)
    printf("these strings are identical\n");
  else
    printf("they're not identical\n");


  for(int i=0; i<26; i++)
  {
    str1[i] -= 32;
  }
  printf("updated str1: %s\n", str1);

  strcpy(str3, str1);
  strcat(str3, str2);

  printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);

}
