#ifndef _card_h 
#define _card_h 

typedef struct {
    char *suit; 
    int value;
} Card;

typedef struct {
    int (*discard)(Card *card); 
    int (*draw)(Card *card); 
    Card *cards[52];
} Deck;

typedef struct {
    char *name; 
    Card *hand[7]; 
    int points; 
} Player;


typedef struct {
    Deck deck; 
    Player human; 
    Player computer;
    int (*create_player)(void *self); 
    int (*prompt_player)(void *self);
    int (*init_deck)();
} Game; 

#endif
