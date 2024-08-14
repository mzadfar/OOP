#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ALIGN_UP(number, align) (((number) + ((align - 1))) & ~((align) - 1))

typedef uint16_t offset_t;
#define PTR_OFFSET_SIZE sizeof(offset_t)

void *aligned_malloc(size_t align, size_t size) {
  void *ptr = NULL;

  if (((align) & (align - 1)) != 0) {
    printf("Error: Align is not power of 2.\n");
    exit(1);
  }

  if (align && size) {
    uint32_t headerSize = PTR_OFFSET_SIZE + (align - 1);
    void *p = malloc(size + headerSize);

    if (p) {
      ptr = (void *)ALIGN_UP(((uintptr_t)p + PTR_OFFSET_SIZE), align);

      *((offset_t *)ptr - 1) = (offset_t)((uintptr_t)ptr - (uintptr_t)p);
    }
  }
  return ptr;
}

void aligned_free(void *ptr) {
  if (ptr == NULL) {
    printf("Error: Input pointer is NULL.\n");
    exit(1);
  }
  offset_t offset = *((offset_t *)ptr - 1);

  void *p = (void *)((uint8_t *)ptr - offset);
  free(p);
}

int main() {
  void *p = malloc(103);
  void *q = malloc(1000);
  void *r = malloc(7);

  void *x = aligned_malloc(8, 100);
  void *y = aligned_malloc(32, 1035);
  void *z = aligned_malloc(4, 8);

  printf("Raw malloc pointers, no alignment enforced: \n");
  printf("\t %p, %p, %p\n", p, q, r);
  printf("\t Note: you may see 4-8 bytes alignment on host PC. \n");
  printf("aligned to 8: %p\n", x);
  printf("aligned to 32: %p\n", y);
  printf("aligned to 4: %p\n", z);

  aligned_free(x), x = NULL;
  aligned_free(y), y = NULL;
  aligned_free(z), z = NULL;

  free(p), p = NULL;
  free(q), q = NULL;
  free(r), r = NULL;
}
