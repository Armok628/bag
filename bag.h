#ifndef BAG_H
#define BAG_H
#include <stdlib.h>
#ifndef BAG_TYPE
#define BAG_TYPE void *
#endif
typedef struct {
	int size,items;
	BAG_TYPE *cont;
} bag_t;
bag_t *new_bag(int size)
{
	bag_t *b=malloc(sizeof(bag_t));
	b->size=size*sizeof(BAG_TYPE);
	b->items=0;
	b->cont=malloc(b->size);
	return b;
}
BAG_TYPE pick(bag_t *b)
{
	int n=rand()%b->items;
	BAG_TYPE i=b->cont[n];
	b->cont[n]=b->cont[--b->items];
	return i;
}
void put(bag_t *b,BAG_TYPE i)
{
	b->cont[b->items++]=i;
}
#endif
