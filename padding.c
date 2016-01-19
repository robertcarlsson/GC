#include "padding.h"





void print_struct_size()
{
  printf("\n\nSTRUCTS: ");
  printf("\nSize of pisc: %d", sizeof(pisc));

}


void print_original_size()
{
  printf("\n\nPOINTER:: ");
  printf("\nSize of pointer: %d", sizeof(void*));

  printf("\n\nFLOAT:: ");
  printf("\nSize of double: %d", sizeof(double));
  printf("\nSize of float: %d", sizeof(float));

  printf("\n\nNUMBER:: ");
  printf("\nSize of long: %d", sizeof(long));
  printf("\nSize of int: %d", sizeof(int));
  printf("\nSize of short: %d", sizeof(short));
  printf("\nSize of char: %d", sizeof(char));
}
