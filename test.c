#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/* Here we are going to write some functions to support a linked list that stores points (x, y) */
/* Here is the data the user in this case us will be storing into our linked list */
typedef struct point
{
	int x;
	int y;
} point;

point* create_point(int x, int y)
{
	point *p;
	p = malloc(sizeof(point));
	p->x = x;
	p->y = y;
	return p;
}

void print_point(void* data)
{
    if (data != NULL) {
        point *p = (point *)data;
	    printf("(%d, %d)", p->x, p->y);
	}
}

void free_point(void* data)
{
	free_data(data);
}

int compare_point_data(const void* a, const void* b)
{
	point *pa = (point *)a;
	point *pb = (point *)b;
	
	int pasum = pa->x + pa->y;
	int pbsum = pb->x + pb->y;
	
	if (pasum == pbsum)
	    return 1;
	else
	    return 0;
}

/* This main function does a little testing
   Like all good CS Majors you are required to test
   your code here. There is no substitute for testing
   and you should be sure to test for all edge cases
   e.g., calling remove_front on an empty list.
*/
int main(void) 
{
	/* Now to make use of all of this stuff */
	list* llist = create_list();
  
  	/* What does an empty list contain?  Lets use our handy traversal function */
  	printf("TEST CASE 1\nAn Empty list should print nothing here:");
  	traverse(llist, print_point);
	printf("\n");

 	/* Lets add a point and then print */
 	push_front(llist, create_point(3, 5));
 	printf("TEST CASE 2\nA List with (3, 5) should print (3, 5):");
 	traverse(llist, print_point);
 	printf("\n");
 	
 	/* Lets remove a point and then print */
 	pop_front(llist, free_point);
 	printf("TEST CASE 3\nAnother Empty list should print nothing here:");
 	traverse(llist, print_point);
 	printf("\n");

 	/* Lets add two points and then print */
 	push_front(llist, create_point(3, 5));
 	push_front(llist, create_point(9, 16));
 	printf("TEST CASE 4\nA List with two nodes should print those two nodes:");
 	traverse(llist, print_point);
 	printf("\n"); 	
 	
  	/* Lets kill the list */
  	empty_list(llist, free_point);
 	printf("TEST CASE 5\nAfter freeing all nodes the list should be empty:");
 	traverse(llist, print_point);
 	printf("\n"); 	
 	
 	/* Add from back */
 	push_back(llist, create_point(3, 5));
 	push_back(llist, create_point(9, 16));
 	printf("TEST CASE 6\nA List with two nodes should print those two nodes:");
 	traverse(llist, print_point);
 	printf("\n");
 	
 	/* Remove from back */
 	pop_back(llist, free_point);
 	pop_back(llist, free_point);
 	printf("TEST CASE 7\nAfter freeing all nodes the list should be empty:");
 	traverse(llist, print_point);
 	printf("\n");
 	
 	/* Test remove_data */
 	point *p8 = create_point(3, 5);
 	push_front(llist, p8);
 	push_front(llist, create_point(9, 16));
 	remove_data(llist, p8, compare_point_data, free_point);
 	printf("TEST CASE 8\nAfter removal only one should remain:");
 	traverse(llist, print_point);
 	printf("\n");
 	pop_back(llist, free_point);
 	
 	/* List querying */
 	push_front(llist, create_point(3, 5));
 	push_front(llist, create_point(9, 16));
 	printf("TEST CASE 9");
 	printf("\nFront:");
 	print_point(front(llist));
 	printf("\nBack:");
 	print_point(back(llist));
 	printf("\nIs empty: %d", is_empty(llist));
 	printf("\nSize: %d", size(llist));
 	printf("\n");
 	pop_front(llist, free_point);
 	pop_front(llist, free_point);
 	
 	/* Searching */
 	point *p10 = create_point(3, 5);
 	push_front(llist, p10);
 	push_front(llist, create_point(9, 16));
 	int result = find_occurrence(llist, p10, compare_point_data);
 	printf("TEST CASE 10\nShould be true: %d", result);
 	p10 = create_point(4, 5);
 	result = find_occurrence(llist, p10, compare_point_data);
 	printf("\nShould be false: %d", result);
 	printf("\n");
 	free_point(p10);
 	pop_front(llist, free_point);
 	pop_front(llist, free_point);
 	
 	/* Testing over clean up*/
 	free(llist);
 	
  	return 0;
}
