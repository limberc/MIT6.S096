#include <stdio.h>
#include <stdlib.h>

typedef struct IntPair_s {
  char c;
  int num;
} IntPair;

int main(void) {
  size_t IntPairSize = sizeof( IntPair );
  printf( "Size of IntPair = %zu\n", IntPairSize);

  return 0;
}
