#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HP 20
#define MAX_NUM_CARDS 54
typedef struct{
char type;
int value;
} Card;


/*
rules
  - red face cards are companions
    - https://www.reddit.com/r/cardgames/comments/1isxsif/scoundrel_additions_2/
  - jokers are NPCS 
    - random each joker you hit
    - some shops
    - some nice npc need help
    - mean npc trying to scam you???
*/

Card *deck[MAX_NUM_CARDS];

int random_number(){
  int max = 53, min = 0;
  return (rand() % (max - min + 1)) + min;
}

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
  printf("OG deck\n");
  for (int i = 0; i < MAX_NUM_CARDS; i++)
  {
    printf("%c%d ", deck[i]->type, deck[i]->value);
  }  
}


//main shuffler of deck
void shuffle_main(Card *a[], Card *b[]){
  int acount = 0, bcount = 0;

  //putting splits together
  for(int i = 0; i < MAX_NUM_CARDS; i++){
    if(i % 2){
      deck[i] = a[acount++];
    }
    else{
      deck[i] = b[bcount++];
    }
  }

  //random swap zone 
  for(int i = 0; i < 14; i++){
    int ranint = random_number(), ranint2 = random_number();
    printf("\n%d %d ", ranint, ranint2); 
    Card *tmp = deck[ranint];
    deck[ranint] = deck[ranint2];
    deck[ranint2] = tmp;
  }

  // //split jokers //BROKEN
  // for(int i = 1; i < MAX_NUM_CARDS; i++){
  //   if(deck[i]->type=='J' && deck[i - 1]->type== 'J'){
  //     int ranint = random_number();
  //     Card *tmp = deck[ranint];
  //     deck[i] = tmp;
  //     break;
  //   }
  // }
}

//shuffles cards in the deck
void shuffle(){
  Card *deckL[MAX_NUM_CARDS/2];
  Card *deckR[MAX_NUM_CARDS/2];

  for(int i = 0; i < MAX_NUM_CARDS/2; i++){
    deckL[i] = deck[i];
    deckR[i] = deck[i + MAX_NUM_CARDS/2];
  }
  
  shuffle_main(deckL, deckR);

  // printf("\nshufffle deck\n");
  // for (int i = 0; i < MAX_NUM_CARDS; i++)
  // {
  //   printf("%c%d ", deck[i]->type, deck[i]->value);
  // }  
}

int main(){
  srand(time(NULL));
  create_deck();

  printf("\nshufffle deck\n");
  for(int i = 0; i <= 1000; i++){
    printf("Round %d\n", i);
    shuffle();
    for (int i = 0; i < MAX_NUM_CARDS; i++)
    {
      printf("%c%d ", deck[i]->type, deck[i]->value);
    }  
    printf("\n");
  }
}
