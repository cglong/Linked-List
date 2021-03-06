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
    list *l;
    l = malloc(sizeof(list));
    if (l == NULL)
        return NULL;
    l->size = 0;
    l->head = NULL;
    return l;
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
    node *lnode;
    lnode = malloc(sizeof(node));
    if (lnode == NULL)
        return NULL;
    lnode->data = data;
    lnode->prev = NULL;
    lnode->next = NULL;
    return lnode;
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
    node *newNode = create_node(data);
    node *head = llist->head;
    
    if (head != NULL) {
        node *prev = head->prev;
        newNode->prev = prev;
        newNode->next = head;
        head->prev = newNode;
        prev->next = newNode;
    } else {
        newNode->prev = newNode;
        newNode->next = newNode;
    }
    llist->head = newNode;
    llist->size++;
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
    node *newNode = create_node(data);
    node *head = llist->head;
    
    if (head != NULL) {
        node *prev = head->prev;
        newNode->prev = prev;
        newNode->next = head;
        head->prev = newNode;
        prev->next = newNode;
    } else {
        llist->head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    }
    llist->size++;
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
    node *front = llist->head;
    
    if (front != NULL) {
        node *prev = front->prev;
        node *next = front->next;
        
        prev->next = next;
        next->prev = prev;
        llist->head = next;
        
        free_func(front->data);
        free(front);
        llist->size--;
        
        if (!llist->size)
            llist->head = NULL;
    }
    
    if (front == NULL)
        return 0;
    else
        return -1;
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
    if (llist->head != NULL) {
        node *back = llist->head->prev;
        node *prev = back->prev;
        node *next = back->next;
        
        prev->next = next;
        next->prev = prev;
        
        free_func(back->data);
        free(back);
        llist->size--;
        
        if (!llist->size)
            llist->head = NULL;
        
        if (back == NULL)
            return 0;
        else
            return -1;
    } else
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
    node *head = llist->head;
    node *test = head;
    node *prev, *next;
    
    if (head != NULL) {
        do {
            prev = test->prev;
            next = test->next;
            if (compare_func(test->data, data)) {
                prev->next = next;
                next->prev = prev;
                
                if (test == head)
                    llist->head = next;
                
                free_func(test->data);
                free(test);
                llist->size--;
                
                if (test != NULL)
                    return -1;
            }
            test = next;
        } while (test != head);
    }
    
    if (!llist->size)
        llist->head = NULL;
    
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
    node *head = llist->head;
    node *test = head;
    node *prev, *next;
    
    if (head != NULL) {
        do {
            prev = test->prev;
            next = test->next;
            if (pred_func(test->data)) {
                prev->next = next;
                next->prev = prev;
                
                if (test == head)
                    llist->head = next;
                
                free_func(test->data);
                free(test);
                llist->size--;
                
                if (test != NULL)
                    return -1;
            }
            test = next;
        } while (test != head);
    }
    
    if (!llist->size)
        llist->head = NULL;
    
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
    if (llist->head != NULL)
        return llist->head->data;
    else
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
    if (llist->head != NULL)
        return llist->head->prev->data;
    else
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
    if (!llist->size && llist->head == NULL)
        return 1;
    else
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
    return llist->size;
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
    node *head = llist->head;
    node *test = head;
    
    if (head != NULL) {
        do {
            if (compare_func(test->data, search))
                return 1;
            else
                test = test->next;
        } while (test != head);
    }
    
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
    node *head = llist->head;
    
    if (head != NULL) {
        node *current = head->next;
        node *next;
        
        while (current != head) {
            next = current->next;
            free_func(current->data);
            free(current);
            current = next;
            llist->size--;
        }
        
        free_func(head->data);
        free(head);
        llist->size--;
        llist->head = NULL;
    }
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
    node *head = llist->head;
    node *current = head;
    
    if (current != NULL) {
        do {
            do_func(current->data);
            current = current->next;
        } while (current != head);
    }
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
    printf("%p", data);
}

/** free_data
  *
  * Default freeing function.  All we do here is just free the pointer.
  *
  * @param data User data.
  */
void free_data(void* data)
{
    free(data);
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
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

/** test_data
  *
  * Default testing function. Returns true if the pointer is not 0.
  *
  * @param a User data.
  */
int test_data(const void* a)
{
    return a != 0;
}
