#include "card.h"

int initialize_deck(deck_t deck)
{

    int deck_i = 0;
    for (int j = 0; j < SUIT_QUANTITY; j++){
        for (int i = 0; i < VALUES_QUANTITY; i++){
            card_t card = {
                .suit = POSSIBLE_SUITS[j],
                .value=POSSIBLE_VALUES[i]
            };
            deck[deck_i] = card;
            deck_i++;
        }
    }
    return 0;
}

char *suit_to_string(card_suit_t suit)
{
    switch (suit) {
        case Basto:
            return "Basto";
        case Copa:
            return "Copa" ;
        case Espada:
            return "Espada";
        case Oro:
            return "Oro" ;
        default:
            return "";
    }
}

int card_rank(card_t card)
{
    for (int i = 0; i < SCALE_LENGTH; ++i) {
        card_t target = CARD_SCALE[i];
        if (card.suit & target.suit && card.value == target.value) {
            return i;
        }
    }

    return -1;
}

int cardcmp(card_t a, card_t b)
{
    // Returns:
    // - > 0 if a wins against b
    // - = 0 if it's a draw
    // - < 0 if a loses against b
    return -(card_rank(a) - card_rank(b));
}
