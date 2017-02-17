#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define BUFFER_SIZE 10
typedef struct {
   char type; // 0=fried chicken, 1=French fries
   int amount; // pieces or weight
   char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
   while ((first + 1) % BUFFER_SIZE == last) {
         // do nothing -- no free buffer item
   }
   memcpy(&buffer[first], i,sizeof(item));
   first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
    item *i = malloc(sizeof(item));
    while (first == last) {
         // do nothing -- nothing to consume
    } 
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    return i;
}
// Produce 3 items
void *Prothread(void *param){
// Declare 3 items
	item i1, i2, i3;
	i1.type = '1';
	i1.amount = 6;
	i1.unit = '1';

	i2.type = '2';
	i2.amount = 7;
	i2.unit = '2';

	i3.type = '3';
	i3.amount = 5;
	i3.unit = '3';
// Print type, amount, unit of each items
	printf("item 1:\n Type: %c\n Amount: %d\n Unit: %c\n", i1.type, i1.amount, i1.unit);
	printf("item 2:\n Type: %c\n Amount: %d\n Unit: %c\n", i2.type, i2.amount, i2.unit);
	printf("item 3:\n Type: %c\n Amount: %d\n Unit: %c\n", i3.type, i3.amount, i3.unit);
// Print first, last values of each items
	produce(&i1);
	printf("Produce item 1: first: %d  last: %d\n", first, last);
	
	produce(&i2);
	printf("Produce item 2: first: %d  last: %d\n", first, last);
	
	produce(&i3);
	printf("Produce item 3: first: %d  last: %d\n", first, last);
	return 0;
}
// Consume 2 items
void *Conthread(void *param){
	consume();
	printf("\nConsume an item: first: %d  last: %d\n", first, last);
	
	consume();
	printf("Consume another item: first: %d  last: %d\n", first, last);
	return 0;
}

int main(){
	pthread_t pt, ct;
// Produce 3 items in thread
	pthread_create(&pt, NULL, Prothread, NULL);
// Consume 2 items in thread	
	pthread_create(&ct, NULL, Conthread, NULL);
	
	pthread_join(pt, NULL);
	pthread_join(ct, NULL);
	return 0;
}
