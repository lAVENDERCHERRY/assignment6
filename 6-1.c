//Work Cited: ChatGPT, STACkOVERFLOW, AND GITHUB
#include <stdio.h>
#include <stdlib.h>

long f(long a, long b, long c, long d, long n) {
  long result = 0;
  long ab = a * b;  // Calculate a * b before entering the loop
  long icd;  // Declare variable for i * c * d outside the loop
  for (long i = 0; i < n; i += 2) //increment by 2
  {
    icd = i * c * d;  // Calculate i * c * d inside the loop, but only once
    for (long j = 0; j < n; j += 2) { //nested loop that increments by 2 each time
      result += ab + icd + j; //updates the results
    }
  }
  return result; //final results returned 
}

int main(int argc, char *argv[]) {
  if (argc == 6) // Check if the number of arguments passed is 6
  { 
    //the arguements with function f
    long a = strtol(argv[1], NULL, 10);
    long b = strtol(argv[2], NULL, 10);
    long c = strtol(argv[3], NULL, 10);
    long d = strtol(argv[4], NULL, 10);
    long e = strtol(argv[5], NULL, 10);
    printf("f(%ld, %ld, %ld, %ld, %ld): %ld\n", a, b, c, d, e, f(a, b, c, d, e));
  } 
  else 
  {
    // Test cases with defined arguements

    printf("f(1, 2, 3, 4, 5): %ld\n", f(1, 2, 3, 4, 5));
    printf("f(2, 3, 4, 5, 6): %ld\n", f(2, 3, 4, 5, 6));
    printf("f(6, 5, 4, 3, 2): %ld\n", f(6, 5, 4, 3, 2));
    printf("f(5, 4, 3, 2, 1): %ld\n", f(5, 4, 3, 2, 1));
  }
  return 0;
}