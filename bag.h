#ifndef BAG_H
#define BAG_H
#include <stdlib.h>
#ifndef BAG_TYPE
#define BAG_TYPE void *
#endif
typedef struct {
	int max,items;
	BAG_TYPE *cont;
} bag_t;
bag_t *new_bag(int size)
{
	bag_t *b=malloc(sizeof(bag_t));
	b->max=size;
	b->items=0;
	b->cont=size>0?malloc(b->max*sizeof(BAG_TYPE)):NULL;
	return b;
}
void free_bag(bag_t *b)
{
	free(b->cont);
	free(b);
}
BAG_TYPE pick(bag_t *b)
{
	if (!b->items)
		return (BAG_TYPE)0;
	int n=rand()%b->items;
	BAG_TYPE i=b->cont[n];
	b->cont[n]=b->cont[--b->items];
	return i;
}
void place(bag_t *b,BAG_TYPE i)
{
	if (b->items==b->max) {
		b->max*=2;
		b->cont=realloc(b->cont,b->max*sizeof(BAG_TYPE));
	}
	b->cont[b->items++]=i;
}
#endif
