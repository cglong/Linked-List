/**
 * CS 2110 - Spring 2011 - Homework #11
 * Edited by: Brandon Whitehead
 *
 * list.h: Fix the datatype definitions!
 */

#ifndef _LIST_H_DEF_
#define _LIST_H_DEF_


/*************************
** Datatype definitions **
**************************/

/* The node struct.  Has a prev pointer, next pointer, and data. */
/* NOTE PLEASE DEFINE THE FIELDS IN THE ORDER GIVEN! */
/* DO NOT DEFINE ANYTHING OTHER THAN WHAT I SAY HERE */
typedef struct lnode
{
  struct node *prev;
  struct node *next;
  void *data;
} node;

/* The linked list struct.  Has a head pointer. */
typedef struct llist
{
 node *head;
 unsigned int size;
} list;

/* FIXME Typedef a new function pointer type that points to a function that
         takes in a void* and returns nothing call it list_op */
/* FIXME Typedef a new function pointer type that points to a function that
         takes in a void* and returns an int call it list_pred */
/* FIXME Typedef a new function pointer type that points to a function that
         takes in 2 const void*'s and returns an int call it compare_op */

/**************************************************
** Prototypes for linked list library functions. **
**                                               **
** For more details on their functionality,      **
** check list.c.                                 **
***************************************************/

/* Creating */
list* create_list(void);

/* Adding */
void push_front(list* llist, void* data);
void push_back(list* llist, void* data);

/* Removing */
int pop_front(list* llist, list_op free_func);
int pop_back(list* llist, list_op free_func);
int remove_data(list* llist, void* data, compare_op compare_func, list_op free_func);
int remove_if(list* llist, list_pred pred_func, list_op free_func);

/* Querying List */
void* front(list* llist);
void* back(list* llist);
int is_empty(list* llist);
int size(list* llist);

/* Searching */
int find_occurrence(list* llist, void* search, compare_op compare_func);

/* Freeing */
void empty_list(list* llist, list_op free_func);

/* Traversal */
void traverse(list* llist, list_op do_func);

/* Default functions provided to the user. */
void print_data(void* data);
void free_data(void* data);
int compare_data(const void* a, const void* b);
int test_data(const void* a);

/* Debugging Support */
#ifdef DEBUG
    /*
       Does the following if compiled in debug mode
       When compiled in release mode does absolutely nothing.
    */
    #define IF_DEBUG(call) (call)
    /* Prints text (in red) if in debug mode */
    #define DEBUG_PRINT(string) fprintf(stderr, "\033[31m%s:%d %s\n\033[0m", __FILE__, __LINE__, (string))
    /* Asserts if the expression given is true (!0) */
    /* If this fails it prints a message and terminates */
    #define DEBUG_ASSERT(expr)   \
    do                           \
    {                            \
        if (!(expr))             \
        {                        \
            fprintf(stderr, "ASSERTION FAILED %s != TRUE (%d) IN %s ON line %d\n", #expr, (expr), __FILE__, __LINE__); \
            exit(0);             \
        }                        \
    } while(0)
#else
    #define IF_DEBUG(call)
    #define DEBUG_PRINT(string)
    #define DEBUG_ASSERT(expr)
#endif

#endif
