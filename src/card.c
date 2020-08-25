#include <stdio.h>
#include <stdlib.h>
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

void display_hand(hand_t hand){
    printf("-------\n");
    for(int i = 0; i < HAND_SIZE; i++){
        card_t card = hand[i];
        printf("%d de %s\n",
                card.value,
                suit_to_string(card.suit));
    }

    printf("-------\n");
}

/**
 * Shuffles deck
 */
void shuffle_deck(deck_t deck){
    // TODO: Lookup shuffle algorithm
    printf("shuffled\n");
}

/**
 * Deals hands from deck
 */
hand_t *deal_hands(deck_t deck, int qty){
    hand_t *dealt_hands = malloc(qty * sizeof(hand_t));
    int deck_i = 0;
    for (int i = 0; i < HAND_SIZE; i++){
        for (int hand_i = 0; hand_i < qty; hand_i++){
            dealt_hands[hand_i][i] = deck[deck_i++];
        }
    } 

    return dealt_hands;
}
