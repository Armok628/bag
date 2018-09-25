#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define BAG_TYPE int
#include "bag.h"
bool check_dups(int *arr,int size)
{
	for (int i=0;i<size-1;i++)
		for (int j=i+1;j<size;j++)
			if (arr[i]==arr[j])
				return true;
	return false;
}
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
		if (check_dups(arr,6))
			printf("(contains duplicates)");
		putchar('\n');
	}
	for (int i=0;i<54;i++)
		printf("%d ",b->cont[i]);
	putchar('\n');
	free_bag(b);
	return 0;
}
