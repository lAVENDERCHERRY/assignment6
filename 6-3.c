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
