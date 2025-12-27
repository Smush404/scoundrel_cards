#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HP 20
#define MAX_NUM_CARDS 54
typedef struct{
char type;
int value;
} Card;

Card *deck[MAX_NUM_CARDS];

void create_deck(){
  int count = 0;
  char type[] = {'D', 'C', 'S', 'H'};
  int number[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  for(int i = 0; i < MAX_NUM_CARDS; i++){
    deck[i] = malloc(sizeof(Card));
  }

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      deck[count]->type = type[i];
      deck[count]->value = number[j];
      printf("i:%d j:%d count:%d %c%d \n", i, j, count, deck[count]->type, deck[count]->value);
      count++;
    }
  }

  deck[count++]->type = 'J';
  deck[count]->type = 'J';

  for (int i = 0; i < MAX_NUM_CARDS; i++)
  {
    printf("%c%d, ", deck[i]->type, deck[i]->value);
  }
  
  
}

int main(){
  create_deck();

  
}
