#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main(){
   item i1;
   i1.type = '1';
   i1.amount = 6;
   i1.unit = '1';
    
   item i2;
   i2.type = '2';
   i2.amount = 7;
   i2.unit = '2';

   produce(&i1);
   printf("Item 1:\n Type: %c\n Amount: %d\n Unit: %c\n First: %d\n Last: %d\n", i1.type, i1.amount, i1.unit, first, last);
   
   produce(&i2);
   printf("\nItem 2:\n Type: %c\n Amount: %d\n Unit: %c\n First: %d\n Last: %d\n", i2.type, i2.amount, i2.unit, first, last);
    
   item* t = consume();
   printf("\nItem consumed:\n Type: %c\n Amount: %d\n Unit: %c\n First: %d\n Last: %d\n", t->type, t->amount, t->unit, first, last);
  
   return 0;
}
