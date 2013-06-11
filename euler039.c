//Tiffany Behmer
//June 11, 2013
//Project Euler Problem #39
//www.projecteuler.net

//If p is the perimeter of a right angle triangle with integral length
//sides, {a,b,c}, there are exactly three solutions for p = 120.

//{20,48,52}, {24,45,51}, {30,40,50}

//For which value of p <= 1000, is the number of solutions maximised?

//---------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>

bool isRightTriangle(int a, int b, int c){
  if (a*a + b*b == c*c){
    return true;
  }
  return false;
}

int main(void){

  int perimeter;
  int a, b, c;
  int num_of_solutions;

  int max_solutions = 0;
  int max_perimeter;

  int half_perimeter;

  for (perimeter = 1; perimeter <= 1000; perimeter++){
    //if (perimeter % 50 == 0)
    //  printf("p = %i \n", perimeter);
    num_of_solutions = 0;

    //no side length can be more than half the perimeter of a triangle,
    //so we don't need to check cases where a, b, or c is > perimeter/2
    half_perimeter = perimeter / 2;

    for (a = 1; a < half_perimeter; a++){
      for (b = a; b < half_perimeter; b++){
        for (c = b; c < half_perimeter; c++){
          if (a + b + c == perimeter){
            if (isRightTriangle(a, b, c)){
              //printf("%i + %i + %i = %i \n", a, b, c, perimeter);
              num_of_solutions++;
              }
            }
          }
        }
      }

    if (num_of_solutions > max_solutions){
      max_solutions = num_of_solutions;
      max_perimeter = perimeter;
    }
  }

  printf("\nmax solutions = %i for perimeter = %i\n",
         max_solutions, max_perimeter);

  return 0;
}


