#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <queue.h>

#define TEST_ASSERT(assert)				\
do {									\
	printf("ASSERT: " #assert " ... ");	\
	if (assert) {						\
		printf("PASS\n");				\
	} else	{							\
		printf("FAIL\n");				\
		exit(1);						\
	}									\
} while(0)

/* Create */
void test_create(void)
{
	fprintf(stderr, "*** TEST create ***\n");

	TEST_ASSERT(queue_create() != NULL);
}

/* Enqueue/Dequeue simple */
void test_queue_simple(void)
{
	int data = 3, *ptr;
	queue_t q;

	fprintf(stderr, "*** TEST queue_simple ***\n");

	q = queue_create();
	queue_enqueue(q, &data);
	queue_dequeue(q, (void**)&ptr);
	TEST_ASSERT(ptr == &data);
}
/* Callback function that increments items */
static void iterator_inc(queue_t q, void *data)
{
    int *a = (int*)data;
        *a += 1;
}

void test_iterator(void)
{
    queue_t q;
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t i;

    /* Initialize the queue and enqueue items */
    q = queue_create();
    for (i = 0; i < sizeof(data); i++)
        queue_enqueue(q, &data[i]);

    /* Increment every item of the queue, delete item '42' */
    queue_iterate(q, iterator_inc);
    for(i = 0; i < sizeof(data); i++){
        TEST_assert(data[i] != i+2)
    }
    TEST_assert(queue_length(q) == 9);
}
void test_deleteanddequeue(void){
	fprintf(stderr, "*** TEST test_deleteanddequeue ***\n");
    queue_t q;
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *deque;
    q = queue_create();
    for(int i=0; i <9 ; i++)
        queue_enqueue(q, &data[i]);
    queue_delete(q,&data[2]);
    queue_dequeue(q,(void**)&deque);
    queue_dequeue(q,(void**)&deque);
    TEST_ASSERT(*deque==4);
}

int main(void)
{
	test_create();
	test_queue_simple();
	test_iterator();
	test_delete();
	return 0;
}