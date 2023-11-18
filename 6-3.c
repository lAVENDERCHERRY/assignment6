//Work Cited: ChatGPT, STACHOVERFLOW, AND GITHUB
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f(float *a, int length, float *dest) {
  float prod = 1.0f;
  for (int i = 0; i < length; ++i) {
    if (a[i] != 0.0f) {
      prod *= a[i];
    }
  }
  *dest = prod;
}

float *createArray(int length) {
  float *a = (float *)malloc(length * sizeof(float));
  for (int i = 0; i < length; ++i) {
    float r = rand()/(float)RAND_MAX;
    a[i] = r < 0.5f ? 0.0f : r + 0.26f;
  }
  return a;
}

// Helper function to replace 0.0f with 1.0f in the array
void replaceZeros(float *a, int length) {
  for (int i = 0; i < length; ++i) {
    if (a[i] == 0.0f) {
      a[i] = 1.0f;
    }
  }
}

// Procedure g without the zero check
void g(float *a, int length, float *dest) {
  float prod = 1.0f;
  for (int i = 0; i < length; ++i) {
    prod *= a[i];
  }
  *dest = prod;
}

// g(b) and f(a) Efficency Comparision
// The 'g' procedure calculates the product of elements in an array 'a' of length 'length'.
// In the 'main' function, 'g(b)' (where 'b' has zero elements replaced by 1.0f) is compared to 'f(a)' for efficiency analysis.

// Explanation for 'g(b)':
// - 'b' is an array similar to 'a' but with zero elements replaced by 1.0f using 'replaceZeros'.
// - 'g(b)' processes the entire 'b' array (of length 'length') after replacing zero elements with 1.0f.
// - Despite the replacements, 'g(b)' still iterates over the entire array 'b', performing multiplications, including by 1.0f,
//   which might introduce inefficiency compared to 'f(a)'.

// Explanation for 'f(a)':
// - 'f(a)' calculates the product of elements in array 'a' (original array, including zero elements).
// - It performs a conditional multiplication only when encountering non-zero elements in 'a'.

// Efficiency Comparison:
// - 'f(a)' might be more efficient than 'g(b)' due to the conditional multiplication strategy.
// - 'f(a)' processes only non-zero elements in 'a', avoiding unnecessary multiplications by 1.0f,
//   potentially resulting in better efficiency compared to 'g(b)'.

// Factors Affecting Efficiency:
// - Efficiency comparison between 'f(a)' and 'g(b)' depends on the percentage of zero elements in 'a'.
// - 'f(a)' might exhibit better efficiency when 'a' contains a significant number of zero elements,
//   as it avoids multiplication operations on these zero elements, unlike 'g(b)'.


// g(c) and g(b) Efficiency Comparision
// The 'g' procedure calculates the product of elements in an array 'a' of length 'length'.
// In the 'main' function, 'g(a)' is compared to 'g(b)' and 'g(c)' for efficiency analysis.

// Explanation for 'g(b)':
// - 'b' is an array similar to 'a' but with zero elements replaced by 1.0f using 'replaceZeros'.
// - The loop in 'g(b)' still iterates over the entire array 'b' (of length 'length') despite the replacements,
//   performing unnecessary multiplications by 1.0f, which might affect efficiency negatively.

// Explanation for 'g(c)':
// - 'c' is a subset array of 'a' containing only nonzero elements from 'a'.
// - 'g(c)' operates on a smaller 'c' array (of length 'cLength'), excluding zero elements.
// - By processing only nonzero elements, 'g(c)' avoids unnecessary multiplications by 1.0f,
//   potentially leading to improved efficiency compared to 'g(b)'.

// Possible Efficiency Comparison:
// - 'g(c)' might exhibit better efficiency than 'g(b)' due to processing a smaller array
//   (excluding zero elements) and avoiding unnecessary multiplications by 1.0f.
// - However, the actual efficiency gain could depend on factors like memory access patterns,
//   the percentage of zero elements in 'a', and the overhead of creating and processing 'c'.


int main() {
  srand(time(NULL));

  // Create array a
  int length = 10000;
  float *a = createArray(length);

  // Measure execution time for calling f(a) 10,000 times
  clock_t start = clock();
  for (int i = 0; i < 10000; ++i) {
    float result;
    f(a, length, &result);
  }
  clock_t end = clock();
  printf("Time for f(a): %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

  // Create array b with zeros replaced by 1.0f
  float *b = createArray(length);
  replaceZeros(b, length);

  // Measure execution time for calling g(b) 10,000 times
  start = clock();
  for (int i = 0; i < 10000; ++i) {
    float result;
    g(b, length, &result);
  }
  end = clock();
  printf("Time for g(b): %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

  // Create array c with only nonzero elements from a
  float *c = (float *)malloc(length * sizeof(float));
  int cLength = 0;
  for (int i = 0; i < length; ++i) {
    if (a[i] != 0.0f) {
      c[cLength++] = a[i];
    }
  }

  // Measure execution time for calling g(c) 10,000 times
  start = clock();
  for (int i = 0; i < 10000; ++i) {
    float result;
    g(c, cLength, &result);
  }
  end = clock();
  printf("Time for g(c): %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

  // Free allocated memory
  free(a);
  free(b);
  free(c);

  return 0;
}