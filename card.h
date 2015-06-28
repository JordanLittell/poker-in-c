#ifndef _card_h 
#define _card_h 

typedef struct {
    char *suit; 
    int value;
} Card;

typedef struct {
    int (*discard)(Card *card); 
    int (*draw)(Card *card); 
} Deck;

typedef struct {
    char *name; 
    Deck *deck; 
    int points; 
} Player;


typedef struct {
    int (*create_player)(void *self); 
    int (*prompt_player)(void *self);
    int (*init_deck)();
} Game; 
