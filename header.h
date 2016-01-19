/**
 *   \file header.h
 *   \brief Gets the information of what kind of objects memory space contains
 *
 *   Gets the information that describes what kind of objects had been moved so *    it can fully be copied and transported. 
 *
 */


#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "linked_list.h"
#include "bitvector.h"

#ifndef _HEADER_
#define _HEADER_


#define FORMAT 0
#define FORWARD 1
#define UNION 2
#define BITVECTOR 3


/**
 *  \Brief points to the information in header
 *
 * Backtracks to the header information
 *
 *  \param *ptr_object gives the pointers position 
 *  \return header 					
 */

void *get_header(void *ptr_object);



/**
 *  \Brief sets the header format
 *
 * Sets the information from the header depending on its mask 
 *
 *  \param *ptr_object gives the pointers position 
 * \param *ptr_format gives the format 						
 */
void set_header_format(void *ptr_object, void *ptr_format);




/**
 *  \Brief  sets the header to forward
 *
 * Directs the headers information to forward 
 *
 *  \param *ptr_object gives the pointers position 
 *  \param *ptr_forward gives the forward
 */
void set_header_forward(void *ptr_object, void *ptr_forward);



/**
 *  \Brief sets the header to bitvector 
 *
 * Directs the header information to bitvector 
 *
 *  \param *ptr_object gives the pointers position 
 *  \param bitvector gives the bitvector					 */

void set_header_bitvector(void *ptr_object, uintptr_t bitvector);



/**
 *  \Brief gets the value from the header
 *
 * Returns the value of the header so 
 *
 *  \param *ptr_object gives the pointers position 
 *  \return the value from the header						
 */
void *get_header_value(void *ptr_object);



/**
 *  \Brief checks whether there is a forward or not 
 *
 * Returns true if the value from the header is a forward, else fale
 *
 *  \param *ptr_object gives the pointers position 
 *  \return forward if true, else false						
 */
bool has_forward(void *ptr_object);


/**
 *  \Brief gets the forward
 *
 * Gets the forward information from header
 *
 *   
 *  \return return the forward information						
 */
void *get_header_forward(void *ptr_object);



bool have_pointer_ptr(void *ptr_object);

/**
 *  \Brief Checks if its has a pointer
 *
 * Reads the information from the format string to see if its a pointer or not. Return true if it is a pointer
 *
 *  \param *layout the format string to be read 
 *  \return true if there is apointer						
 */

bool have_pointer(char *layout);


/**
 *  \Brief Pointer to objects 
 *
 * Collects a pointers in a linked list
 *
 *  \param *ptr_object gives the pointers position 
 *  \return the pointer to the list 					
 */
list *object_pointers(void *ptr_object);



/**
 *  \Brief reads the characters from the format string 
 *
 * Reads the character from the format string and returns their size. (*, i, c, l, f, d)
 *
 *  \param *letter is the character to be read
 *  \return the sizes of the characters						
 */
size_t char_reader(char *letter);

/**
 *  \Brief Returns a number to recognize the format type
 *
 *  Returns a number from 0-3
 *
 *  00 = 0 FORMAT TYPE
 *  01 = 1 FORWARD TYPE
 *  10 = 2 FUNCTION TYPE
 *  11 = 3 BITVECTOR TYPE
 *  \param *ptr_object gives the pointers position 
 *  \return int number of format type 						
 */
int header_mark(void *ptr_object);

/**
 *  \Brief gets the size of the object
 *
 *  Reads through the format string and returns its size in bytes
 *
 *  \param *format_string the format string that shall be read
 *  \return the size in bytes						
 */
size_t size_object(char *format_string);

/**
 *  \Brief Redirects the the size depending on the format type
 *
 *  Returns the different format types and sizes, and a pointer to the different types
 *
 *  \param *ptr_object gives the pointers position 
 *  \return redirections of the different format types 						
 */
size_t size_object_ptr(void *ptr_object);



#endif //_HEADER_
