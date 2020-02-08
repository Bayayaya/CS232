/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float rm,ri, a, d;

  printf("Enter radius (in mm):\n"); //\n means newline

  float* rmptr = &rm; // created a pointer to r
  scanf("%f", rmptr); //write to r, &r indicate where r is saved (pointer)
  ri = rm / 25.4;

  a = PI * ri * ri;
  d = 2 * PI * ri;

  printf("Circle's area is %3.2f (sq in).\n", a); 
  //[parameter][flags][width][.precision][length]type => 3 is width .2 is precision
  printf("Its circumference is %3.2f (in).\n", d);

}
