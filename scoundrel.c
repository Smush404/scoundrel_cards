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

//creates template deck
void create_deck(){
  int count = 0;
  char type[] = {'D', 'C', 'S', 'H'};
  int number[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  for(int i = 0; i < MAX_NUM_CARDS; i++){
    deck[i] = malloc(sizeof(Card));
  }

  //fill template deck
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      deck[count]->type = type[i];
      deck[count]->value = number[j];
      //printf("i:%d j:%d count:%d %c%d \n", i, j, count, deck[count]->type, deck[count]->value);
      count++;
    }
  }

  //add jokers
  deck[count++]->type = 'J';
  deck[count]->type = 'J';

  //DEBUG
  // for (int i = 0; i < MAX_NUM_CARDS; i++)
  // {
  //   printf("%c%d, ", deck[i]->type, deck[i]->value);
  // }  
}


//mian shuffler of deck
Card * shuffle_main(Card *a, Card *b){

  return NULL;
}

//shuffles cards in the deck
void shuffle(){
  Card *deckL[MAX_NUM_CARDS/2];
  Card *deckR[MAX_NUM_CARDS/2];

  for(int i = 0; i < MAX_NUM_CARDS/2; i++){
    deckL[i] = deck[i];
    deckR[i] = deck[i + MAX_NUM_CARDS/2];
  }

  Card *tmp = shuffle_main(deckL, deckR);
}
int main(){
  create_deck();
  shuffle();
}
