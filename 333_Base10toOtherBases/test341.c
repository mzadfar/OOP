#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimalToOtherBases(uint32_t inValue, uint16_t toBase, char *outValue);

int main(void) {
  uint32_t inValue = 60;
  uint16_t toBase = 16;
  char *outValue = (char *)malloc(33 * sizeof(char));
  printf("Decimal value of %d is equal to %s in base %d\n", inValue,
         decimalToOtherBases(inValue, toBase, outValue), toBase);
  return 0;
}

char *decimalToOtherBases(uint32_t inValue, uint16_t toBase, char *outValue) {
  char allValues[] = "0123456789ABCDEF";

  if ((toBase < 2) || (toBase > 16)) {
    printf("Enter a value for base between 2 and 16, you entered %d\n", toBase);
    exit(1);
  }

  outValue[32] = '\0';

  do {
    outValue--;
    uint16_t remVAlue = inValue % toBase;
    *outValue = allValues[remVAlue];
    inValue /= toBase;
  } while (inValue != 0);

  if (toBase == 16) {
    outValue--;
    *outValue = 'x';
    outValue--;
    *outValue = '0';
  }
  return outValue;
}