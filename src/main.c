#include <stdio.h>
#include "card.h"

int main()
{
    int n = 8;

    card_t test_deck[] = {
        {.suit = Espada , .value=1},
        {.suit = Basto , .value=1},
        {.suit = Oro , .value=1},
        {.suit = Copa , .value=1},
        {.suit = Espada , .value=7},
        {.suit = Oro , .value=7},
        {.suit = Basto , .value=7},
        {.suit = Copa , .value=7},
    };

    for(int i = 0; i < n; i++){
        card_t card = test_deck[i];
        printf("%d de %s \t %d\n", card.value, suit_to_string( card.suit ), card_rank(card));
    }

    return 0;
}
