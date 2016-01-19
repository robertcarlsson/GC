/**
 *   \file linked_list.h
 *   \brief Module to create a linked list.
 *
 *  Creates a linked list with an iterator.
 *  To be used as the standard storage type for the garbage collector.
 *
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __linked_list__
#define __linked_list__

typedef struct _list list;
typedef struct _iter iter;


/**
 *  \brief Creates a new linked list.
 *
 *  Allocates on the heap for a new linked list and returns a list pointer to the new list.
 *
 *  \return list* to the new linked list.
 */
list *make_list();

/**
 *  \brief checks if list is empty.
 *
 *  Only checks if the first element in the list is NULL.
 *
 *  \param plist is the list to check.
 *  \return bool if the list is empty or not.
 */
bool list_empty(list * plist);

/**
 *  \brief adds a new node.
 *
 *  Adds a new node containing a pointer to the end of the linked list.
 *
 *  \param plist is the list to add to.
 *  \param pointer is the pointer to store in the new node.
 */
void add_node(list * plist, void *pointer);

/**
 *  \brief checks if given pointer exists in list.
 *
 *  Traverses the linked list and checks if the specified pointer is stored in any of the nodes.
 *  Calls upon is_same_pointer() for comparison.
 *
 *  \param plist is the list to search.
 *  \param pointer is the pointer to search for.
 *  \return bool if the pointer is found.
 */
bool list_has(list * plist, void *pointer);

/**
 *  \brief free function for the linked list.
 *
 *  A free function that traverses the linked list and frees every node.
 *  Terminates with a last free on the list itself.
 *
 *  \param plist the list to free.
 */
void free_list(list * plist);

/**
 *  \brief free function for the linked list.
 *
 *  A free function that traverses the linked list and frees every node.
 *  This free differs from free_list in the aspect it also frees the value.
 *  Terminates with a last free on the list itself.
 *
 *  \param plist the list to free.
 */
void free_list_inc_value(list * plist);

/**
 *  \brief returns the length of the given list
 *
 *  Counts the nodes in the given list and returns a size.
 *
 *  \param plist is the list to count
 *  \return size_t representing the amount of objects
 */
size_t list_length(list *plist);

/**
 *  \Brief creates and iterator for the struct list.
 *
 *  Allocates on the heap for the iterator and links it to first object in the list.
 *
 *  \param plist is the list to create the iterator upon.
 *  \return iter* to the allocated iterator.
 */
iter *iterator(list * plist);

/**
 *  \brief Step the iterator once.
 *
 *  Moves the iterator to the next object in the linked list
 *
 *  \param it is the iterator to step
 */
void iter_next(iter * it);

/**
 *  \brief checks if iteration is done
 *
 *  Checks if the iterator has finished "iterating" by checking if current value is NULL.
 *
 *  \param it the iterator to check.
 *  \return bool if current value is NULL.
 */
bool iter_done(iter * it);

/**
 *  \brief Gets the value the iterator is on
 *
 *  A get function for the value the iterator is currently on.
 *
 *  \param iter an iterator to get the value from
 */
void *iter_get(iter * it);

/**
 *  \brief free function for the iterator
 *
 *  A free function that frees the entire iterator
 *
 *  \param it is the iterator to free
 */
void free_iter(iter * it);

#endif
