//Work Cited: ChatGPT, STACkOVERFLOW, AND GITHUB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Original inner procedure
void inner(float *u, float *v, int length, float *dest) {
  float sum = 0.0f;
  for (int i = 0; i < length; ++i) {
    sum += u[i] * v[i];
  }
  *dest = sum;
}

// Inner procedure with four-way loop unrolling
void inner2(float *u, float *v, int length, float *dest) {
  float sum1 = 0.0f, sum2 = 0.0f, sum3 = 0.0f, sum4 = 0.0f;

  // Unrolled loop by a factor of 4
  for (int i = 0; i < length; i += 4) {
    sum1 += u[i] * v[i];
    sum2 += u[i + 1] * v[i + 1];
    sum3 += u[i + 2] * v[i + 2];
    sum4 += u[i + 3] * v[i + 3];
  }

  // Combine partial sums
  *dest = sum1 + sum2 + sum3 + sum4;
}

// Inner procedure with eight-way loop unrolling
void inner3(float *u, float *v, int length, float *dest) {
  float sum1 = 0.0f, sum2 = 0.0f, sum3 = 0.0f, sum4 = 0.0f;
  float sum5 = 0.0f, sum6 = 0.0f, sum7 = 0.0f, sum8 = 0.0f;

  // Unrolled loop by a factor of 8
  for (int i = 0; i < length; i += 8) {
    sum1 += u[i] * v[i];
    sum2 += u[i + 1] * v[i + 1];
    sum3 += u[i + 2] * v[i + 2];
    sum4 += u[i + 3] * v[i + 3];
    sum5 += u[i + 4] * v[i + 4];
    sum6 += u[i + 5] * v[i + 5];
    sum7 += u[i + 6] * v[i + 6];
    sum8 += u[i + 7] * v[i + 7];
  }

  // Combine partial sums
  *dest = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
}

// Helper function to create an array
float *createArray(int length) {
  float *a = (float *)malloc(length * sizeof(float));
  for (int i = 0; i < length; ++i) {
    a[i] = rand() / (float)RAND_MAX; // random float number between 0 and 1
  }
  return a;
}

int main() {
  srand(time(NULL)); //random number generator

  int length = 100000;
  float *u = createArray(length); //random value
  float *v = createArray(length);// random value

  // Timing for inner
  clock_t start = clock();
  for (int i = 0; i < 10000; ++i) {
    float result;
    inner(u, v, length, &result);
  }
  clock_t end = clock();
  printf("Time for inner: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC); //execution time for inner

  // Timing for inner2
  start = clock();
  for (int i = 0; i < 10000; ++i) {
    float result;
    inner2(u, v, length, &result);
  }
  end = clock();
  printf("Time for inner2: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC); //execution time for inner2

  // Timing for inner3
  start = clock();
  for (int i = 0; i < 10000; ++i) {
    float result;
    inner3(u, v, length, &result);//calls function 10000 times
  }
  end = clock(); //recording time 
  printf("Time for inner3: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC); //exectuion time for inner3

  // Free allocated memory
  free(u);
  free(v);

  return 0;
}

// Time for inner: 3.542103 seconds
// Time for inner2: 1.873826 seconds
// Time for inner3: 1.716884 seconds
// What I noticed was that the original 'inner' procedure computes the dot product of two arrays without loop unrolling,
// resulting in a longer execution time compared to loop-unrolled versions ('inner2' and 'inner3').
// It processes each element individually in a loop, leading to more instructions and increased overhead.
// The lack of loop unrolling restricts parallelism, causing a relatively slower execution time.
// And my findings were that the most efficent at least for run time was inner3 because it has
// a larger parallelism with its funciton as it has 8. These optimizations benefit from reduced loop overhead and better 
// SIMD (Single Instruction, Multiple Data) utilization, summing multiple elements in parallel.
// However, the limiting factor with this function is that even though it has the best run time, its space complexity is not the best because
// the amount of registers is increased and the amount of data fetched from memory also increases