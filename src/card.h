#ifndef CARD_H_
#define CARD_H_

#define CARD_QUANTITY 40
#define SUIT_QUANTITY 4
#define VALUES_QUANTITY 10
#define SCALE_LENGTH 14

typedef enum
{
    Any = 15, // This is for scale purposes
    Espada = 1,
    Basto = 2,
    Copa = 4,
    Oro = 8,
} card_suit_t;

typedef unsigned int card_value_t;

typedef struct {
    card_value_t value;
    card_suit_t suit;
} card_t;

typedef card_t deck_t[CARD_QUANTITY];

static const card_t CARD_SCALE[SCALE_LENGTH] = {
    {.suit=Espada, .value=1},
    {.suit=Basto, .value=1},
    {.suit=Espada, .value=7},
    {.suit=Oro, .value=7},
    {.suit=Any, .value=3},
    {.suit=Any, .value=2},
    {.suit=Copa | Oro, .value=1},
    {.suit=Any, .value=12},
    {.suit=Any, .value=11},
    {.suit=Any, .value=10},
    {.suit=Basto | Copa, .value=7},
    {.suit=Any, .value=6},
    {.suit=Any, .value=5},
    {.suit=Any, .value=4},
};

static const card_value_t POSSIBLE_VALUES[VALUES_QUANTITY] = {1,2,3,4,5,6,7,10,11,12};
static const card_suit_t POSSIBLE_SUITS[SUIT_QUANTITY] = {Basto, Copa, Espada, Oro};

int initialize_deck(deck_t deck);
char *suit_to_string(card_suit_t suit);
int card_rank(card_t card);
int cardcmp(card_t a, card_t b);


#endif // CARD_H_
