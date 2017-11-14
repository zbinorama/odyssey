#ifndef MM_COROUTINE_CACHE_H
#define MM_COROUTINE_CACHE_H

/*
 * machinarium.
 *
 * cooperative multitasking engine.
*/

typedef struct mm_coroutine_cache mm_coroutine_cache_t;

struct mm_coroutine_cache
{
	pthread_spinlock_t lock;
	int                stack_size;
	mm_list_t          list;
	int                count;
	int                limit;
};

void mm_coroutine_cache_init(mm_coroutine_cache_t*, int, int);
void mm_coroutine_cache_free(mm_coroutine_cache_t*);

mm_coroutine_t*
mm_coroutine_cache_pop(mm_coroutine_cache_t*);

void mm_coroutine_cache_push(mm_coroutine_cache_t*, mm_coroutine_t*);

#endif /* MM_COROUTINE_CACHE_H */
