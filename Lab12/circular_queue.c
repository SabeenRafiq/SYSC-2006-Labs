/* SYSC 2006 Lab 12
 *
 * circular_queue.c - circular linked-list implementation of a queue.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "circular_queue.h"

/* Return a pointer to a new, empty queue.
 * Terminate (via assert) if memory for the queue cannot be allocated.
 */

queue_t *alloc_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    assert(queue != NULL);

    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

/* Return true if the specified queue contains no elements;
 * otherwise return false.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
_Bool queue_is_empty(const queue_t *queue)
{
    assert(queue != NULL);
    return queue->size == 0;
}

/* Return the number of elements stored in the specified queue.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
int queue_size(const queue_t *queue)
{
    assert(queue != NULL);
    return queue->size;
}

/* Print the contents of the specified queue to the console,
 * from front to rear: [value0, value1, value3, ...]
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */

void queue_print(const queue_t *queue)
{
    assert(queue != NULL);

    if (queue_is_empty(queue))
    { // Handle an empty queue (no nodes).
        printf("[]");
        return;
    }

    node_t *current;

    printf("[");

    /* Print all the elements in the queue, except for the one at the rear. */
    for (current = queue->rear->next; // queue->rear points to the tail node
                                      // (the node at the rear of the queue).
                                      // The tail node points to the head node
                                      // (the node at the front of the queue).
         current != queue->rear; current = current->next)
    {
        printf("%d, ", current->data);
    }

    /* Now print the element at the rear of the queue. */
    printf("%d]", current->data);
}

/*--------------------------------------------------------
 *
 * Solutions to Lab 12 exercises.
 */

/* Enqueue the specified value to the rear of a queue.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
void enqueue(queue_t *queue, int value)
{
    node_t *newnode = malloc(sizeof(node_t));
    assert(newnode != NULL);
    newnode->data = value;
    newnode->next = NULL;

    if (queue_is_empty(queue) == true)
    {
        queue->rear = newnode;
        queue->rear->next = newnode;
        queue->size = (queue->size) + 1;
    }
    else
    {
        newnode->next = queue->rear->next;
        queue->rear->next = newnode;
        queue->rear = newnode;
        queue->size = (queue->size) + 1;
    }
}

/* Copy the value at the front of a queue to the variable pointed to by
 * parameter element, and return true.
 * Return false if the queue is empty.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
_Bool front(const queue_t *queue, int *element)
{
    assert(queue != NULL);
    if (queue_is_empty(queue) == 1)
    {
        return false;
    }
    *element = queue->rear->next->data;
    return true;
}

/* Copy the value at the front of a queue to the variable pointed to by
 * parameter element, remove that value from the queue, and return true.
 * Return false if the queue is empty.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
_Bool dequeue(queue_t *queue, int *element)
{
    assert(queue != NULL);
    front(queue, element);
    if (queue_is_empty(queue) == 1){
        return false;
    }

    node_t *temp = queue->rear->next;

    if (queue->size == 1)
    {
        free(temp);
        queue->rear = NULL;
        queue->size = 0;
        return true;
    }
    
    queue->rear->next = temp->next;
        
    free(temp);
    queue->size = (queue->size) - 1;
    return true;
}
