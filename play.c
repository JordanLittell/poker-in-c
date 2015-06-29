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

Card *PickRandom(Game *g) {
    int index = rand()%52; 
    return g->deck.cards[index];
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



int process_input(Game *g) {
    printf("your hand:\n");
    char buffer[100];
    int discard;
    for(int i = 0; i < 7; i++) {
        printf("card %i: %i of %s\n", i, g->human.hand[i]->value, g->human.hand[i]->suit);
    }
    printf("please choose number of cards to discard..."); 
    scanf("%i", &discard); 
    for(int j = 0; j < discard; j++) {
        int to_discard; 
        printf("please choose index of %i card you would like to discard\n", j); 
        scanf("%i", &to_discard);
        int random = rand()%56;
        g->human.hand[to_discard] = g->deck.cards[random];
    }

    printf("your hand is now:\n");
    for(int i = 0; i < 7; i++) {
        printf("card %i: %i of %s\n", i, g->human.hand[i]->value, g->human.hand[i]->suit);
    }

    return 0;
}

void evaluate_hands(Game *g) {
    //first evaluate hand of player
    int match_count;
    for(int i= 0; i < 7; i++) {
        //count matches, put all matches into array
    }   
    //evaluate hand of computer 
    //repeat proccess for human 
    //juxtapose the matches and find winner based on standard poker rules 
}

int main (int argc, char *argv[])
{
    Game *game = Game_init();
    while(process_input(game));
    evaluate_hands(game);
    return 0;
}
