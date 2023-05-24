#ifndef _FUNCTION_H
#define _FUNCTION_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>

#define SUITS 4
#define RANKS 13
#define FACES 13
#define row 5
#define column 2

void shuffleCards(int deck[][FACES]);

void printCardsShuffling(int deck[][FACES],const char* suits[],const char* faces[]);

int** dealingForHand(int deck[SUITS][FACES]);

void printHand(int** hand, const char* suits[], const char* faces[]);

void sort(int** hand);

void swap(int& a, int& b);

int isStraightFlush(int** hand);

int isFourOfAKind(int** hand);

int isFullHouse(int** hand);

int isFlush(int** hand);

int isStraight(int** hand);

int isThreeOfAKind(int** hand);

int isTwoPair(int** hand);

int isPair(int** hand);

int isHighestCard(int** hand);

void printAllCard(int deck[SUITS][FACES]);

int** createHandTest(int deck[SUITS][FACES], int a[5]);

void printPlayerCard(int** hand, const char* suits[], const char* faces[]);

void importPlayers(int& n);

int*** dealingForHands(int deck[SUITS][FACES], int n);

void delete3D(int*** a, int n);

void delete2D(int** a);

int getStatusOfHand(int** hand);

int whoIsTheWinner(int*** hands, int n);

int* rankingHands(int*** hands, int n);

void numberOfDealingCards(int& s);

int* evalHands(int n, int s, int deck[SUITS][FACES]);

void dealerDrawCardRandom(int ***hands, int deck[SUITS][FACES], int n);

void playerDrawCard(int ***hands, int deck[SUITS][FACES], int n);

void printStatusOfHand(int** hand);

void printWinner(int ***hands, int n);

void menu();

void setColor(int code);

void setWindowSize(SHORT width, SHORT height);

using namespace std;
#endif

