#include <stdio.h>
#include <stdlib.h>

void inner(float *u, float *v, int length, float *dest) {
  float sum = 0.0f;
  for (int i = 0; i < length; ++i) {
    sum += u[i] * v[i];
  }
  *dest = sum;
}

float *createArray(int length) {
  float *a = (float *)malloc(length * sizeof(float));
  for (int i = 0; i < length; ++i) {
    a[i] = rand()/(float)RAND_MAX;
  }
  return a;
}