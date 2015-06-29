#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <errno.h> 
#include "card.h" 


Deck *Deck_init() {
    int suit_length = 13; 
    Deck *deck = malloc(sizeof(Deck)); 
    int counter = 0;
    char *suits[] = {"Spade", "Club", "Diamond" , "Heart"}; 
    printf("we can hold %lu cards\n", sizeof(deck->cards)/sizeof(Card));
    for(int i = 0; i < suit_length; i++) {
        int value = i;
        for(int j = 0; j < 4; j++) {
            Card *new_card = malloc(sizeof(Card));
            new_card->value = value;
            new_card->suit = suits[j]; 
            deck->cards[counter] = new_card;
            counter++;       
        }
    }
    return deck;
}

Player deal_hand(Player *p, Game *g) {
    for(int i = 0; i < 7; i++) {
        int card_index = rand() % 56;
        p->hand[i] = g->deck.cards[card_index];
    }
    return *p;
}

void report_cards(Player *p) {
    int hand_size = 7; 
    for(int i = 0; i< hand_size; i++) {
        printf("player had %i of %s\n", p->hand[i]->value, p->hand[i]->suit);
    }
}

Player *Player_init (Game *g) {
    Player *p = malloc(sizeof(Player)); 
    p->points = 10; 
    srand(time(NULL));
    *p = deal_hand(p, g);
    report_cards(p);
    return p;
}

Game *Game_init () {
    Game *game = malloc(sizeof(Game)); 
    printf("initializing deck\n");
    game->deck = *Deck_init();
    printf("inisializing players\n");
    game->human = *Player_init(game);
    printf("human\n");
    game->computer = *Player_init(game);
    return game;
}

int main (int argc, char *argv[])
{
    Game *game = Game_init();
    return 0;
}
