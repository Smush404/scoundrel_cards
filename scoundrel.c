#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HP 20

typedef struct{
char type[30];
char name[30];
int value;
} Card;

Card deck[52];

create_deck(){
  Card tmp_c;
  
  for(int i = 0; i <= 52; i++){
    *tmp_c.name = "";
  }
}

int main(){
  create_deck();
}
