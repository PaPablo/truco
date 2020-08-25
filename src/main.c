#include <stdio.h>
#include "card.h"

deck_t deck;

int main()
{

    initialize_deck(deck);
    shuffle_deck(deck);
    int n_hands = 4;
    hand_t *hands = deal_hands(deck, n_hands);

    for (int i = 0; i < n_hands; i++){
        display_hand(hands[i]);
    }

    return 0;
}
