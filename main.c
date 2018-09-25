#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BAG_TYPE int
#include "bag.h"
int main(int argc,char **argv)
{ // 6 numbers 1-54, no repeats
	srand(time(NULL));
	bag_t *b=new_bag(54);
	for (int i=1;i<=54;i++)
		place(b,i);
	for (int i=0;i<100;i++) {
		int arr[6];
		for (int i=0;i<6;i++)
			arr[i]=pick(b);
		for (int i=0;i<6;i++) {
			printf("%d ",arr[i]);
			place(b,arr[i]);
		}
		putchar('\n');
	}
	free_bag(b);
	return 0;
}
