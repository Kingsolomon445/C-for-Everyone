#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define PIPS 13
#define DECK_SIZE (SUITS * PIPS)
#define DECK_NUMBER 200000
#define HAND_SIZE 7

/********************************************************
   This is a program that calculates the probabilities of
   7 hands in a deck and outputs them
 *******************************************************/

typedef enum suit
{
    hearts,
    diamonds,
    spades,
    clubs
} suit;

typedef struct card
{
    suit suit;
    short pip;
} card;

struct hand
{
    unsigned long total;
    unsigned long no_pair;
    unsigned long one_pair;
    unsigned long three_of_kind;
    unsigned long two_pair;
    unsigned long four_of_kind;
    unsigned long full_house;
};

void shuffle(card *deck, int size) //this swaps card
{
    int val1;
    int val2;
    card placeholder;

    val1 = 0;
    while (++val1 < size)
    {
        val2 = rand() % (val1+1);
        placeholder = deck[val1];
        deck[val1] = deck[val2];
        deck[val2] = placeholder;
    }
}

void process(card* deck_hand, int size, struct hand* hands)
{
    unsigned count[PIPS] = { 0 }; // get card count of each pip value
    unsigned sub_count[SUITS+1] = { 0 }; // get count of singles or pairs
    int pos = -1;
    while (++pos < size)
        ++count[deck_hand[pos].pip];

    pos = -1;
    while (++pos < PIPS)
        ++sub_count[count[pos]];

    if (sub_count[4])
        ++hands->four_of_kind;
    else if (sub_count[3] && sub_count[2] || sub_count[3] >= 2)
        ++hands->full_house;
    else if (sub_count[3])
        ++hands->three_of_kind;
    else if (sub_count[2] >= 2)
        ++hands->two_pair;
    else if (sub_count[2])
        ++hands->one_pair;
    else
        ++hands->no_pair;
    ++hands->total;
}

int main(void) {
    srand(time(0));
    card deck[DECK_SIZE];
    int pos;
    short val1;
    short val2;

    val1 = 0;
    pos = -1;
    while (++val1 <= PIPS) {
        val2 = 0;
        while (++val2 <= SUITS) {
            deck[++pos].suit = val2;
            deck[pos].pip = val1;
        }
    }

    struct hand hands = {0, 0, 0, 0, 0, 0, 0}; //initially populates with 0's
    pos = -1;
    while (++pos < DECK_NUMBER) {
        shuffle(deck, DECK_SIZE);
        val1 = 0;
        while (val1 + HAND_SIZE < DECK_SIZE) {
            process(deck + val1, HAND_SIZE, &hands);
            val1 += HAND_SIZE;
        }
    }
    // the below sequence outputs probability
    long double total = hands.total;
    printf("No pair probablity =  %Lf\n", hands.no_pair / total);
    printf("One pair probability = %Lf\n", hands.one_pair / total);
    printf("Two pair probability = %Lf\n", hands.two_pair / total);
    printf("Three of a kind probablity = %Lf\n", hands.three_of_kind / total);
    printf("Four of a kind probability = %Lf\n", hands.four_of_kind / total);
    printf("Full house probability = %Lf\n", hands.full_house / total);

    return (0);
}