#include "header.h"


//
//CHANGE ALL INPUT VOID * TO ptr_object so other don 't need to think of HEADER very good
//



void *get_header(void *ptr_object)
{
    return (ptr_object - sizeof(void *));
}

void set_header(void *ptr_object, void *ptr, char mask)
{
    *(void **)get_header(ptr_object) = ptr + mask;
}

void set_header_format(void *ptr_object, void *ptr_format)
{
    set_header(ptr_object, ptr_format, FORMAT);
}

void set_header_forward(void *ptr_object, void *ptr_forward)
{
    set_header(ptr_object, ptr_forward, FORWARD);
}

void set_header_bitvector(void *ptr_object, uintptr_t bitvector)
{
    set_header(ptr_object, (void *)bitvector, BITVECTOR);
}


char get_header_mask(void *ptr_object)
{
  return *(char *)get_header(ptr_object) % 4; 
}

//TODO: Remake so it takes away the mask of the header
void *get_header_value(void *ptr_object)
{
  switch (get_header_mask(ptr_object)) {
  case FORMAT:
    return *(void **)get_header(ptr_object);
  case FORWARD:
    return *(void **)get_header(ptr_object) - FORWARD;
  case UNION:
    return *(void **)get_header(ptr_object) - UNION;
  case BITVECTOR: 
    return *(void **)get_header(ptr_object) - BITVECTOR;
  default:
    //Ska aldrig komma hit
    assert(false);
  }
  return NULL;
}






bool has_forward(void *ptr_object)
{
    if (get_header_mask(ptr_object) == FORWARD) {
        return true;
    }
    return false;
}

void *get_header_forward(void *ptr_object)
{
    //FORWARD IS MASKED WITH __01 SO DECREASE 1 to __00
  return get_header_value(ptr_object);
}




//
//SARA ARBETE NMR 1:
//

int header_mark(void *ptr_object)
{
    //THIS FUNCTION SHOULD RETURN A NUMBER FROM 0 - 3
    // 00 = 0 FORMAT TYPE
    // 01 = 1 FORWARD TYPE
    // 10 = 2 FUNCTION TYPE
    // 11 = 3 BITVECTOR TYPE
    // %modulus give the rest of whole number division
    return (uintptr_t) get_header_value(ptr_object) % 4;
}


//MAKE THESE FUNCTIONS INTO ONE FOR ALL HEADERTYPE:

//FORMAT HEADER POINTS TO A FORMATSTRING
// FORWARD POINTS TO NEXT OBJECT WHICH HAVE ANOTHER HEADER
// FUNCTION - NOT IMPLEMENTED = MAKE ASSERT CASE
// BITVECTOR WHERE __011 = BITVECTOR - NOT IMPLEMENTED = MAKE ASSER CASE
// __111 = BITSIZE
// 10010111 = BITSIZE of size 10010 ___(18 decimalt)
size_t size_object_ptr(void *ptr_object)
{
    switch (header_mark(ptr_object)) {
    case 0:{
            //Formatheader
            return size_object((char *)(get_header_value(ptr_object)));
        }
    case 1:{
            return size_object_ptr(get_header_forward(ptr_object));
        }
    case 2:{
            //Header for union
            assert (false);
            break;
        }
    case 3:{
            //Bitsize
                return (uintptr_t) get_header_value(ptr_object) >> 3;
        }
    default:
        assert(false);
    }
    /*
     * size_t bytes = 0; char *char_now =
     * (char*)get_header_value(ptr_object); while(*char_now != '\0'){ bytes
     * += char_reader(char_now); char_now++; } return bytes;
     */
    assert(false);
    return sizeof(int);
}

size_t size_object(char *format_string)
{
    size_t bytes = 0;
    char *char_now = format_string;
    while (*char_now != '\0') {
        bytes += char_reader(char_now);
        char_now++;
    }
    return bytes;
}


//
//SLUT P Ã …SARA ARBETE NMR1
//



size_t char_reader(char *letter)
{
    switch (*letter) {
    case '*':
        return sizeof(void *);
    case 'i':
        return sizeof(int);
    case 'c':
        return sizeof(int);
        //Here its right padded, sizeof(char);
    case 'l':
        return sizeof(long);
    case 'f':
        return sizeof(float);
    case 'd':
        return sizeof(double);
    default:
        printf("\n\nWrong syntax use *,i,d,f,l,c\n\n");
        break;
    }
    assert(false);
    return sizeof(int);
}

list *object_pointers(void *ptr_object)
{
    list *list_ptr = make_list();
    char *format_string = (char *)get_header_value(ptr_object);
    int shift = 0;
    while (*format_string != '\0') {
        if (*format_string == '*' && *(void **)(ptr_object + shift) != NULL) {
            add_node(list_ptr, ptr_object + shift);
        }
        shift += char_reader(format_string);
        format_string++;
    }
    return list_ptr;
}

bool have_pointer_ptr(void *ptr_object)
{
    if (header_mark(ptr_object) == 0) {
        return have_pointer(get_header_value(ptr_object));
    }
    if (header_mark(ptr_object) == 1) {
      return have_pointer_ptr(get_header_forward(ptr_object));
    }
    return false;
}

bool have_pointer(char *layout)
{
  while (*layout != '\0') {
        if (*layout == '*') {
            return true;
        }
        layout++;
    }
    return false;
}
