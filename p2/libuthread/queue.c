#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

struct queue {
	/* TODO Phase 1 */
	struct node* head;
	struct node* tail;
	int number;
};

queue_t queue_create(void)
{
	/* TODO Phase 1 */
	struct queue* new = malloc(sizeof(struct node));
	new -> number = 0;
	new -> head = NULL;
	new -> tail = new -> head;
	return new;
}

int queue_destroy(queue_t queue)
{
	/* TODO Phase 1 */
	if(queue == NULL || queue -> number !=0)
		return -1;
	else{
		free(queue);
		return 0;
	}
}

int queue_enqueue(queue_t queue, void *data)
{
	/* TODO Phase 1 */
	if(queue == NULL || data == NULL)
		return -1;

    struct Node *newNode = malloc(sizeof(Node)); 
    newNode->value = data;
    newNode->next = NULL;

	if(queue -> number == 0){

		queue -> head = newNode;
	}
	else{
		queue -> tail -> next = newNode;
	}
	queue -> number ++;
	queue -> tail = newNode;
	return 0;
}

int queue_dequeue(queue_t queue, void **data)
{
	/* TODO Phase 1 */
	if(queue == NULL || data == NULL || queue->number == 0)
		return -1;
	struct node* storehead =  queue->head;
	*data = queue -> head -> value;
	queue -> head = queue -> head -> next;
	free (storehead);
	queue -> number --;
	return 1;
}

int queue_delete(queue_t queue, void *data)
{
	/* TODO Phase 1 */
	if(queue == NULL || data == NULL)
		return -1;
	struct node* search = queue -> head;
	if( search -> value == data){
		struct node* store =  queue->head;
		queue -> head = queue -> head -> next;
		free(store);
		return 0;
	}
	while(search ->next != NULL){
		if(search->next ->value == data){
			struct node* store = search -> next;
			search -> next = search -> next -> next;
			free(store);
			search -> number --;
			return 0;			
		}
	}
	return -1;

}

int queue_iterate(queue_t queue, queue_func_t func)
{
	/* TODO Phase 1 */
	if(queue == NULL || func == NULL)
		return -1;
	struct node* step = queue->head;
	for(int i = 0; i < queue -> number; i++){
		if(step != NULL){
			func(queue, step->value);
		}
		step = step -> next;
	}
	return 0;
}

int queue_length(queue_t queue)
{
	/* TODO Phase 1 */
	if(queue ==NULL)
		return -1;
	return queue -> number;
}

