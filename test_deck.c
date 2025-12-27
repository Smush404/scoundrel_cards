#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  AI GENEREATED: meant for checking the deck is healthy.
*/

#define MAX_CARDS 54
#define MAX_CARD_LEN 4

// Function to get index of a card in full deck
int get_card_index(char suit, int value) {
    int suit_offset = 0;
    switch (suit) {
        case 'C': suit_offset = 0; break;
        case 'D': suit_offset = 13; break;
        case 'H': suit_offset = 26; break;
        case 'S': suit_offset = 39; break;
        default: return -1;
    }
    return suit_offset + (value - 2);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"deck_string\"\n", argv[0]);
        return 1;
    }

    char *deck_str = argv[1];
    
    // Array to store individual cards
    char cards[MAX_CARDS][MAX_CARD_LEN];
    int card_count = 0;

    // Split the string into cards
    char deck_copy[strlen(deck_str)+1];
    strcpy(deck_copy, deck_str);  // strtok modifies the string
    char *token = strtok(deck_copy, " ");
    while (token != NULL && card_count < MAX_CARDS) {
        strcpy(cards[card_count++], token);
        token = strtok(NULL, " ");
    }

    // Track seen cards
    bool seen[52] = {false};
    int joker_count = 0;
    bool duplicates_found = false;

    for (int i = 0; i < card_count; i++) {
        if (strcmp(cards[i], "J0") == 0) {
            joker_count++;
            if (joker_count > 2) duplicates_found = true;
            continue;
        }

        char suit = cards[i][0];
        int value = atoi(cards[i]+1);
        int index = get_card_index(suit, value);

        if (index < 0 || index >= 52) {
            printf("Invalid card: %s\n", cards[i]);
            continue;
        }

        if (seen[index]) {
            duplicates_found = true;
            printf("Duplicate card found: %s\n", cards[i]);
        }
        seen[index] = true;
    }

    // Check for missing cards
    bool missing_found = false;
    char suits[] = {'C', 'D', 'H', 'S'};
    for (int s = 0; s < 4; s++) {
        for (int v = 2; v <= 14; v++) {
            int idx = get_card_index(suits[s], v);
            if (!seen[idx]) {
                missing_found = true;
                printf("Missing card: %c%d\n", suits[s], v);
            }
        }
    }

    // Check jokers
    if (joker_count < 2) {
        missing_found = true;
        printf("Missing Joker(s)\n");
    }

    // Summary
    printf("\nTotal cards in string: %d\n", card_count);
    printf("Deck complete: %s\n", (!missing_found && !duplicates_found && card_count == 54) ? "Yes" : "No");

    return 0;
}
