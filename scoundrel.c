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

typedef struct{
Card wep, last_killed, healing;
int hp;
} Player;

/*
varents
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
  
  //mallocs for each card
  for(int i = 0; i < MAX_NUM_CARDS; i++){         //OPT: Can optimize this somehow???
    deck[i] = malloc(sizeof(Card));
  }

  //fill deck
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      //deck[count] = malloc(sizeof(Card));
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
  // printf("OG deck\n");
  // for (int i = 0; i < MAX_NUM_CARDS; i++)
  // {
  //   printf("%c%d ", deck[i]->type, deck[i]->value);
  // }  
}

//shuffles cards in the deck like a real life shuffle through splitting and combining the deck
void shuffle(){
  Card *deckL[MAX_NUM_CARDS/2];
  Card *deckR[MAX_NUM_CARDS/2];
  int acount = 0, bcount = 0;

  //splits the deck into two
  for(int i = 0; i < MAX_NUM_CARDS/2; i++){
    deckL[i] = deck[i];
    deckR[i] = deck[i + MAX_NUM_CARDS/2];
  }

  //intertwining splits together like irl
  for(int i = 0; i < MAX_NUM_CARDS; i++){
    if(i % 2){
      deck[i] = deckL[acount++];
    }
    else{
      deck[i] = deckR[bcount++];
    }
  }

  //random swap zone (add rng)
  for(int i = 0; i < 14; i++){
    int ranint = random_number(), ranint2 = random_number();
    //printf("\n%d %d ", ranint, ranint2); 
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

  //DEBUG
  // printf("\nshufffle deck\n");
  // for (int i = 0; i < MAX_NUM_CARDS; i++)
  // {
  //   printf("%c%d ", deck[i]->type, deck[i]->value);
  // }  
}


//gameplay loop
gameloop(){
  Player p;
  p.hp = HP;
  Card c1,c2,c3,c4;
  int i = 0, input;

  printf("=============================");
  printf("%30s","Welcome to Scoundrel");
  printf("=============================");

  c1 = *deck[i++];
  c2 = *deck[i++];
  c3 = *deck[i++];
  c4 = *deck[i++];

  while(i<MAX_NUM_CARDS){
    printf("Card (1): %s%d Card (2): %s%d Card (3): %s%d Card (4): %s%d \n", c1.type, c1.value, c2.type, c2.value, c3.type, c3.value, c4.type, c4.value);
    printf("Pick a Card: ");
    scanf("%d", &input);

    for(int j = 0; j < 4; j++){
    printf("Card (1): %s%d Card (2): %s%d Card (3): %s%d Card (4): %s%d \n", c1.type, c1.value, c2.type, c2.value, c3.type, c3.value, c4.type, c4.value);
    printf("Pick a Card: ");
    scanf("%d", &input);
    }
  }
}

//clean up
void shutdown(){
  for (int i = 0; i < MAX_NUM_CARDS; i++)
  {
    free(deck[i]);
  }
  *deck = NULL;
}

//shuffles the deck a random number of times 
void random_shuffle(){ 
    // printf("\nshufffle deck\n");
  for(int i = 0; i <= rand(); i++){//can be a massive number of shuffles - OPT: maybe just limit to 100 - 1,000
    // printf("Round %d\n", i);
    shuffle();
    // for (int i = 0; i < MAX_NUM_CARDS; i++)
    // {
    //   printf("%c%d ", deck[i]->type, deck[i]->value);
    // }  
    // printf("\n");
  }
}

int main(){
  srand(time(NULL));
  
  create_deck();
  random_shuffle();
  
  gameloop();
  shutdown();
}
