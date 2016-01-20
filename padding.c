#include "padding.h"





void print_struct_size()
{
  printf("\n\nSTRUCTS: ");
  printf("\nSize of pisc: %d", (int)sizeof(pisc));
  printf("\nSize of isc: %d", (int)sizeof(isc));

}


void print_original_size()
{
  printf("\n\nPOINTER:: ");
  printf("\nSize of pointer: %d", (int)sizeof(void*));

  printf("\n\nFLOAT:: ");
  printf("\nSize of double: %d", (int)sizeof(double));
  printf("\nSize of float: %d", (int)sizeof(float));

  printf("\n\nNUMBER:: ");
  printf("\nSize of long: %d", (int)sizeof(long));
  printf("\nSize of int: %d", (int)sizeof(int));
  printf("\nSize of short: %d", (int)sizeof(short));
  printf("\nSize of char: %d", (int)sizeof(char));
}
