#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

void upSampler(double *inSample, int inLength, int upSampleFactor,
               double *outSample, int *outLength) {
  if (inLength > 0) {
    double step = 1.0 / upSampleFactor;
    double y0 = inSample[0];
    outSample[(*outLength)++] = y0;
    for (int i = 1; i < inLength; i++) {
      double y = inSample[i];
      double dY = (y - y0) * step;
      for (int j = 0; j < upSampleFactor - 1; j++) {
        y0 += dY;
        outSample[(*outLength)++] = y0;
      }
      y0 = y;
      outSample[(*outLength)++] = y0;
    }
  }
}
int main() {
  int inLength = 20;
  double inSample[inLength];
  for (int i = 0; i < inLength; i++) {
    inSample[i] = sin(2 * M_PI * i / 10);
  }

  int upSampleFactor = 3;
  double outSample[upSampleFactor * inLength];
  int outLength = 0;

  upSampler(inSample, inLength, upSampleFactor, outSample, &outLength);
  printf("\nUp sampling: \n");
  for (int i = 0; i < outLength; i++) {
    printf("output[%d] = %f \n", i, outSample[i]);
  }
  printf("\nDown sampling: \n");
  int downSampleFactor = 3;
  for (int i = 0; i < inLength; i += downSampleFactor) {
    printf("output[%d] = %f \n", i / downSampleFactor, inSample[i]);
  }
  return 0;
}
