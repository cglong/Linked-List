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
    point *p = (point *) data;
	printf("(%d, %d)", p->x, p->y);
}

void free_point(void* data)
{
	free_data(data);
}

int compare_point_data(const void* a, const void* b)
{
	/* TODO Implement compare by x then y here or what have you.*/
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
 	
 	/* YOU ARE REQUIRED TO MAKE MORE TEST CASES THAN THE ONES PROVIDED HERE */
 	/* You will get points off if you do not you should at least test each function here */
 	
 	/* Testing over clean up*/
 	free(llist);
 	
  	return 0;
}
