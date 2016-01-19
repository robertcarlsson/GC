#include "linked_list.h"

typedef struct _node node;

struct _list {
    node *first;
    node *last;
};

struct _iter {
    node *current;
};

struct _node {
    void *value;
    node *next;
};

size_t list_length(list * plist)
{
    size_t length = 0;
    node *current = plist->first;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

bool is_same_pointer(void *nodeValue, void *newValue)
{
    return (nodeValue == newValue);
}

node *make_node(void *pointer)
{
    node *node = calloc(sizeof(node), 1);
    node->value = pointer;
    node->next = NULL;
    return node;
}

list *make_list()
{
    list *plist = calloc(sizeof(list), 1);
    plist->first = NULL;
    plist->last = plist->first;
    return plist;
}

bool list_empty(list * plist)
{
    if (plist->first == NULL) {
        return true;
    }
    else
        return false;
}

void add_node(list * plist, void *pointer)
{
    if (plist->first == NULL) {
        plist->first = make_node(pointer);
        plist->last = plist->first;
        return;
    }

    node *current = make_node(pointer);

    plist->last->next = current;
    plist->last = plist->last->next;
    plist->last->next = NULL;

}


bool list_has(list * plist, void *pointer)
{

    node *current = plist->first;

    while (current != NULL) {
        if (is_same_pointer(current->value, pointer)) {
            return true;
        }
        current = current->next;
    }
    return false;

}


void free_list(list * plist)
{
    node *current = plist->first;
    while (current != NULL) {
        node *to_delete = current;
        current = current->next;
        //free(to_delete->value);
        free(to_delete);
    }

    free(plist);
};

void free_list_inc_value(list * plist)
{
    node *current = plist->first;
    while (current != NULL) {
        node *to_delete = current;
        current = current->next;
        free(to_delete->value);
        free(to_delete);
    }
    free(plist);
};

iter *iterator(list * plist)
{
    iter *it = calloc(sizeof(iter), 1);
    it->current = plist->first;
    return it;
};

void iter_next(iter * it)
{
    if (it->current != NULL) {
        it->current = it->current->next;
    };
}

bool iter_done(iter * it)
{
    if (it->current == NULL)
        return true;
    return false;
}

void *iter_get(iter * it)
{
    return it->current->value;
}

void free_iter(iter * it)
{
    free(it);
}
