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