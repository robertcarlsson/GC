#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef __BITVECTOR__
#define __BITVECTOR__



/**
 *  \Brief creates a bitvector with size
 *
 *  Shift size by 3 to left, creating a bitvector
 *
 *  \param size is the size of the object 
 *  \return size of object						
 */
uintptr_t create_bitvector_size(size_t size);


/**
 *  \Brief gets the bitvectors size
 *
 *  First recognize if it is a bitvector, and then shift it by 3 to right
 *
 *  \param bitvector is the bitvector to get
 *  \return size of the bitvector 			
 */

size_t get_bitvector_size(uintptr_t bitvector);

#endif //__BITVECTOR__
