#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define RING_BUFFER_SIZE (8)

typedef struct ringBuffer_t {
  uint8_t *buffer;
  uint32_t mask;
  uint32_t readIndex;
  uint32_t writeIndex;
} ringBuffer_t;

void Ring_Buffer_Setup(ringBuffer_t *ringBuffer, uint8_t *buffer,
                       uint32_t size);
bool Ring_Buffer_Empty(ringBuffer_t *ringBuffer);
bool Ring_Buffer_Full(ringBuffer_t *ringBuffer);
bool Ring_Buffer_Write(ringBuffer_t *ringBuffer, uint8_t byte);
bool Ring_Buffer_Read(ringBuffer_t *ringBuffer, uint8_t *byte);

void Ring_Buffer_Setup(ringBuffer_t *ringBuffer, uint8_t *buffer,
                       uint32_t size) {
  ringBuffer->buffer = buffer;
  ringBuffer->readIndex = 0;
  ringBuffer->writeIndex = 0;
  ringBuffer->mask = size - 1; // size is a power of 2
}

bool Ring_Buffer_Empty(ringBuffer_t *ringBuffer) {
  return ringBuffer->readIndex == ringBuffer->writeIndex;
}
bool Ring_Buffer_Full(ringBuffer_t *ringBuffer) {
  return ringBuffer->readIndex ==
         ((ringBuffer->writeIndex + 1) & ringBuffer->mask);
}

bool Ring_Buffer_Write(ringBuffer_t *ringBuffer, uint8_t byte) {
  uint32_t localReadIndex = ringBuffer->readIndex;
  uint32_t localWriteIndex = ringBuffer->writeIndex;

  uint32_t nextWriteIndex = (localWriteIndex + 1) & ringBuffer->mask;

  if (nextWriteIndex == localReadIndex) {
    return false; // we write on not-used/read index
  }

  ringBuffer->buffer[localWriteIndex] = byte;
  ringBuffer->writeIndex = nextWriteIndex;

  return true;
}

bool Ring_Buffer_Read(ringBuffer_t *ringBuffer, uint8_t *byte) {
  uint32_t localReadIndex = ringBuffer->readIndex;
  uint32_t localWriteIndex = ringBuffer->writeIndex;

  if (localWriteIndex == localReadIndex) {
    return false;
  }

  *byte = ringBuffer->buffer[localReadIndex];
  localReadIndex = (localReadIndex + 1) & ringBuffer->mask;
  ringBuffer->readIndex = localReadIndex;

  return true;
}

uint8_t dataBuffer[RING_BUFFER_SIZE] = {0U};
ringBuffer_t ringBuffer = {0U};

int main(void) {
  Ring_Buffer_Setup(&ringBuffer, dataBuffer, RING_BUFFER_SIZE);
  int a[] = {23, 14, 12, 45, 49, 78, 54, 61, 34, 98};
  int length = 1;

  for (int i = 0; i < 8; i++) {
    if (Ring_Buffer_Write(&ringBuffer, (uint8_t)a[i])) {
      /*handle failure? TBD*/
    }
  }
  int j = 0;
  uint8_t data;
  // while (j < 8) {
  for (uint32_t numberByteRead = 0; numberByteRead < length; numberByteRead++) {
    if (!Ring_Buffer_Read(&ringBuffer, &data)) {
      printf("Length is: %d\t: %d\n", numberByteRead, data);
    } else {
      printf("Length is: %d\t: %d\n", length, data);
    }
  }
  //   j++;
  // }

  return 0;
}