#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "private.h"
#include "uthread.h"
#include "queue.h"


struct uthread_tcb *process;
queue_t ready_list;
queue_t waiting_list;

struct uthread_tcb {
	/* TODO Phase 2 */
    ucontext_t context;
    void *stack; 
    int state; 
    int tid;
};

struct uthread_tcb *uthread_current(void)
{
	/* TODO Phase 2/3 */
	getcontext(process->context);
	return process;
}

void uthread_yield(void)
{
	preempt_disable();
    struct uthread_tcb *prev_thread = process;
    queue_enqueue(&ready_list, prev_thread);
    struct uthread_tcb *next_thread = queue_dequeue(&ready_list);
    process = next_thread;
    uthread_ctx_switch(prev_thread->context, next_thread->context);
    preempt_enable();

	/* TODO Phase 2 */
}

void uthread_exit(void)
{
	/* TODO Phase 2 */
}

int uthread_create(uthread_func_t func, void *arg)
{
	/* TODO Phase 2 */
}

int uthread_run(bool preempt, uthread_func_t func, void *arg)
{
	/* TODO Phase 2 */
}

void uthread_block(void)
{
	/* TODO Phase 3 */
}

void uthread_unblock(struct uthread_tcb *uthread)
{
	/* TODO Phase 3 */
}

