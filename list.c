/**
 * CS 2110 - Spring 2011 - Homework #11
 * Edited by: Brandon Whitehead
 *
 * list.c: Complete the functions!
 **/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// This function is declared as static since you should only be calling this inside this file.
static node* create_node(void* data);

/** create_list
  *
  * Creates a list by allocating memory for it.
  * Be sure to initialize size to zero and head to NULL.
  *
  * @return an empty linked list
  */
list* create_list(void)
{
    /// @todo Implement changing the return value!
    return NULL;
}

/** create_node
  *
  * Helper function that creates a node by allocating memory for it.
  * Be sure to set its pointers to NULL.
  *
  * @param data a void pointer to data the user wants to store in the list
  * @return a node with the data.
  */
static node* create_node(void* data)
{
    /// @todo Implement changing the return value!
    return NULL;
}

/** push_front
  *
  * Adds the data to the front of the linked list
  *
  * @param llist a pointer to the list.
  * @param data pointer to data the user wants to store in the list.
  */
void push_front(list* llist, void* data)
{
    /// @todo Implement
}

/** push_back
  *
  * Adds the data to the back/end of the linked list
  *
  * @param llist a pointer to the list.
  * @param data pointer to data the user wants to store in the list.
  */
void push_back(list* llist, void* data)
{
    /// @todo Implement
}

/** pop_front
  *
  * Removes the node at the front of the linked list
  *
  * @warning Note the data the node is pointing to is also freed. If you have any pointers to this node's data it will be freed!
  *
  * @param llist a pointer to the list.
  * @param free_func pointer to a function that is responsible for freeing the node's data.
  * @return -1 if the pop failed 0 if the pop succeeded.
  */
int pop_front(list* llist, list_op free_func)
{
    /// @todo Implement changing the return value
    /// @note remember to also free the node itself
    return 0;
}

/** pop_back
  *
  * Removes the node at the back of the linked list
  *
  * @warning Note the data the node is pointing to is also freed. If you have any pointers to this node's data it will be freed!
  *
  * @param llist a pointer to the list.
  * @param free_func pointer to a function that is responsible for freeing the node's data.
  * @return -1 if the pop failed 0 if the pop succeeded.
  */
int pop_back(list* llist, list_op free_func)
{
    /// @todo Implement changing the return value
    /// @note remember to also free the node itself
    return 0;
}

/** remove
  *
  * Removes ALL nodes whose data is EQUAL to the data you passed in or rather when the comparison function returns true (!0)
  * @warning Note the data the node is pointing to is also freed. If you have any pointers to this node's data it will be freed!
  *
  * @param llist a pointer to the list
  * @param data data to compare to.
  * @param compare_func a pointer to a function that when it returns 1 it will remove the element from the list 0 otherwise.
  * @return the number of nodes that were removed.
  */
int remove_data(list* llist, void* data, compare_op compare_func, list_op free_func)
{
    /// @todo Implement changing the return value!
    /// @note remember to also free all nodes you remove.
    return 0;
}

/** remove_if
  *
  * Removes all nodes whose data when passed into the predicate function returns true
  *
  * @param llist a pointer to the list
  * @param data data to compare to.
  * @param compare_func a pointer to a function that when it returns 1 it will remove the element from the list 0 otherwise.
  * @return the number of nodes that were removed.
  */
int remove_if(list* llist, list_pred pred_func, list_op free_func)
{
    /// @todo Implement changing the return value!
    /// @note remember to also free all nodes you remove.
    /// @note be sure to call pred_func on the NODES DATA to check if the node needs to be removed.
    return 0;
}

/** front
  *
  * Gets the data at the front of the linked list if there are no nodes return NULL.
  *
  * @param llist a pointer to the list
  * @return The data at the first node in the linked list.
  */
void* front(list* llist)
{
    /// @todo Implement changing the return value!
    /// @note you are returning the HEAD's DATA not the head node. Remember the user should never deal with the linked list nodes.
    return NULL;
}

/** back
  *
  * Gets the data at the end of the linked list if there are no nodes return NULL.
  *
  * @param llist a pointer to the list
  * @return The data at the last node in the linked list.
  */
void* back(list* llist)
{
    /// @todo Implement changing the return value!
    return NULL;
}

/** is_empty
  *
  * Checks to see if the list is empty.
  *
  * @param llist a pointer to the list
  * @return 1 if the list is indeed empty 0 otherwise.
  */
int is_empty(list* llist)
{
    ///@note an empty list by the way we want you to implement it has a size of zero and head points to NULL.
    return 0;
}

/** size
  *
  * Gets the size of the linked list
  *
  * @param llist a pointer to the list
  * @return The size of the linked list
  */
int size(list* llist)
{
    ///@note simply return the size of the linked list.  Its that easy!
    return 0;
}

/** find_occurence
  *
  * Tests if the search data passed in is in the linked list.
  *
  * @param llist a pointer to a linked list.
  * @param search data to search for the occurence.
  * @param compare comparison function used to compare two DATA items.
  * @return 1 if the data is indeed in the linked list 0 otherwise.
  */
int find_occurrence(list* llist, void* search, compare_op compare_func)
{
    /// @todo Implement changing the return value
    return 0;
}

/** empty_list
  *
  * Empties the list after this is called the list should be empty.
  *
  * @param llist a pointer to a linked list.
  * @param free_func function used to free the node's data.
  *
  */
void empty_list(list* llist, list_op free_func)
{
    /// @todo Implement
    /// @note Free all of the nodes not the linked list itself.
}

/** traverse
  *
  * Traverses the linked list calling a function on each node's data.
  *
  * @param llist a pointer to a linked list.
  * @param do_func a function that does something to each node's data.
  */
void traverse(list* llist, list_op do_func)
{
    /// @todo Implement
}

/* Below are the default functions users of the linked list library
   Can use instead of defining their own */

/** print_data
  *
  * Default printing function.  All we do here is just print out the pointer passed in.
  *
  * @param data User data.
  */
void print_data(void* data)
{
    ///@todo just call printf.  Remember that %p means pointer.
}

/** free_data
  *
  * Default freeing function.  All we do here is just free the pointer.
  *
  * @param data User data.
  */
void free_data(void* data)
{
    ///@todo free the data here.
}

/** compare_data
  *
  * Default comparision function.  Justs compares the pointers.
  *
  * @param a User Data.
  * @param b User Data.
  */
int compare_data(const void* a, const void* b)
{
    /** @note this functions should if a was 0x6000000 and b was 0x7000000
      * You will return -1 since 0x60000000 is less than 0x70000000
      * Do not dereference a or b here.
      */
    /// @todo Implement changing the return value
    return 0;
}

/** test_data
  *
  * Default testing function. Returns true if the pointer is not 0.
  *
  * @param a User data.
  */
int test_data(const void* a)
{
    ///@warning to test this do not put any nodes whose data is NULL in your linked list for simplicity sake in addition we will not be calling your functions with NULL.
    ///@note for this one and compare_data you may have to do some CASTING!
    /// @todo Implement changing the return value
    return 0;
}
