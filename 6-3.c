#include <stdio.h>
#include <stdlib.h>

float f(float *a, int length, float *dest) {
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
    // 50% chance that a[i] is 0.0f, random value on the range
    // [0.75, 1.25] otherwise.
    float r = rand()/(float)RAND_MAX;
    a[i] = r < 0.5f ? 0.0f : r + 0.26f;
  }
  return a;
}