#include "padding.h"





void print_struct_size()
{
  printf("\n\nSTRUCTS: ");
  printf("\nSize of pisc: %d", (int)sizeof(pisc));
  printf("\nSize of disc: %d", (int)sizeof(disc));
  printf("\nSize of isc: %d", (int)sizeof(isc));
  printf("\nSize of sic: %d", (int)sizeof(sic));
  printf("\nSize of cccc: %d", (int)sizeof(cccc));
  printf("\nSize of ccccc: %d", (int)sizeof(ccccc));
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
