#include"function.h"

void shuffleCards(int deck[][FACES])
{

	int i, j;
	srand((int)time(0));

	for (int theCard = 1; theCard <= 52; theCard++)
	{
		do
		{ 
		i = rand() % 4;
		j = rand() % 13; 
		} while (deck[i][j] != 0); 
		deck[i][j] = theCard;
	}

}


void printCardsShuffling(int deck[][FACES],const char *suits[],const char *faces[])
{
	int theCard = 1;
	
	while (theCard <= 52)
	{
		for(int i = 0; i < SUITS; i++)
			for(int j = 0; j < FACES; j++)
				if (deck[i][j] == theCard)
				{
					cout << theCard << " is: (" << suits[i] << "," << faces[j] << ")" << endl;
					theCard++;
				}
	}
}

int** dealingForHand(int deck[SUITS][FACES])
{
	int** result = new int* [row];
    
	for (int i = 0; i < row; i++)
		result[i] = new int[column];

	int step = 0;
	for (int theCard = 1; theCard <= 5; theCard++)
		for(int i = 0; i < SUITS; i++)
			for(int j = 0; j < RANKS; j++)
				if (deck[i][j] == theCard)
				{
					result[step][0] = i;
					result[step][1] = j;

					step++;
				}

	return result;
}

void printHand(int **hand,const char *suits[],const char *faces[])
{
	for (int i = 0; i < row; i++)
	{
		cout <<i+1<<" (" << suits[hand[i][0]] << "," << faces[hand[i][1]] << ")" << endl;
	}
}

void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void sort(int** hand)
{
	for (int i = 0; i < row; i++)
		for (int j = i + 1; j < row; j++)
		{
			if (hand[i][1] > hand[j][1])
			{
				swap(hand[i][1], hand[j][1]);
				swap(hand[i][0], hand[j][0]);
			}
		}
}

int isStraightFlush(int** hand)
{
	sort(hand);

	for (int i = 0; i < row - 1; i++)
	{
		if ((hand[i][0] != hand[i + 1][0]) || ((hand[i + 1][1] - hand[i][1]) != 1))
		{
			return 0;
		}
	}
	return 1;
}

int isFourOfAKind(int** hand)
{
	sort(hand);

	if (hand[row - 1][1] != hand[row - 2][1])
	{
		for (int i = 1; i < row - 1; i++)
			if (hand[i][1] != hand[i - 1][1])
				return 0;
		return 1;
	}
	else if (hand[0][1] != hand[1][1])
	{
		for (int i = 2; i < row; i++)
			if (hand[i][1] != hand[i - 1][1])
				return 0;
		return 1;
	}
	else return 0;
}

int isFullHouse(int** hand)
{
	sort(hand);
    
	if (hand[0][1] != hand[2][1])
	{
		if (hand[0][1] != hand[1][1]) return 0;
		for (int i = 2; i < row - 1; i++)
			if (hand[i][1] != hand[i + 1][1]) return 0;
    return 1;
	}
	else if (hand[row - 1][1] != hand[row - 3][1])
	{
	if (hand[row - 1][1] != hand[row - 2][1]) return 0;
	for (int i = 0; i < row - 3; i++)
		if (hand[i][1] != hand[i + 1][1]) return 0;
	return 1;
	}

	else return 1;
}

int isFlush(int** hand)
{
	
	for (int i = 0; i < row - 1; i++)
		if (hand[i][0] != hand[i + 1][0])
			return 0;

	return 1;
}

int isStraight(int** hand)
{
	sort(hand);
	for (int i = 0; i < row - 1; i++)
		if ((hand[i + 1][1] - hand[i][1]) != 1) return 0;

	return 1;
}

int isThreeOfAKind(int** hand)
{
	sort(hand);
	if (hand[0][1] != hand[2][1])
	{
		if (hand[0][1] == hand[1][1]) return 0;
		for (int i = 2; i < row - 1; i++)
			if (hand[i][1] != hand[i + 1][1]) return 0;
		return 1;
	}
	else if (hand[row - 1][1] != hand[row - 3][1])
	{
		if (hand[row - 1][1] == hand[row - 2][1]) return 0;
		for (int i = 0; i < row - 3; i++)
			if (hand[i][1] != hand[i + 1][1]) return 0;
		return 1;
	}
	else if (hand[0][1] != hand[row - 1][1])
	{
		if (hand[0][1] == hand[1][1]) return 0;
		for (int i = 2; i < row - 1;)
			if (hand[i][1] != hand[i - 1][1])return 0;
		return 1;
	}
	else return 0;
}

int isTwoPair(int** hand)
{
	sort(hand);

	if (hand[0][1] == hand[1][1] && hand[row - 1] == hand[row - 2] && hand[0][1] != hand[2][1] && hand[0][1] != hand[row - 2][1] && hand[row - 2][1] != hand[2][1])
		return 1;
	else if (hand[1][1] == hand[2][1] && hand[row - 1] == hand[row - 2] && hand[1][1] != hand[0][1] && hand[1][1] != hand[row - 2][1] && hand[row - 2][1] != hand[0][1])
		return 1;
	else if (hand[0][1] == hand[1][1] && hand[2][1] == hand[3][1] && hand[3][1] != hand[row - 1][1] && hand[3][1] != hand[0][1] && hand[0][1] != hand[row - 1][1])
		return 1;

	return 0;
}

int isPair(int** hand)
{
	int count = 1;

	sort(hand);

	for (int i = 0; i < row - 1; i++)
		if (hand[i][1] == hand[i + 1][1]) count++;

	if (count == 2) return 1;
	else return 0;
}

int isHighestCard(int** hand)
{
	for (int i = 0; i < row; i++)
	{
		if (hand[i][1] == 0) return hand[i][1];
		for (int j = i + 1; j < row; j++)
			if (hand[i][1] > hand[j][1])
				swap(hand[i][1], hand[j][1]);
	}

	return hand[row - 1][1];
}

void printAllCard(int deck[SUITS][FACES])
{
	setColor(6);
	cout << endl << endl;
	cout << "\t\t\t" << "  All CARDS:" << endl;
	setColor(15);
	for (int i = 0; i < SUITS; i++)
	{
		cout << "\t" << "    ";
		for (int j = 0; j < FACES; j++)
			cout<<deck[i][j] << " ";
		cout << endl;
	}
	cout << "\t\t\t" << "  ------";
	cout << endl;
}

int** createHandTest(int deck[SUITS][FACES], int a[5])
{
	setColor(11);
	cout <<"\t   "<<"You can test some case: ";
	for (int card = 0; card < 5; card++)
	{
		cin >> a[card];
    }

	int** hand = new int* [row];

	for (int i = 0; i < row; i++)
	{
		hand[i] = new int[column];
	}

	for (int i = 0; i < 5; i++)
	{ 
		for(int m = 0; m < SUITS; m++)
			for(int n = 0; n < FACES; n++)
				if (a[i] == deck[m][n])
				{
					
					hand[i][0] = m;
					hand[i][1] = n;
				}
	}

	return hand;
}

void printPlayerCard(int** hand, const char* suits[], const char* faces[])
{
	for (int i = 0; i < row; i++)
	{
		cout <<"\t\t"<< i + 1 << " is: (" << suits[hand[i][0]] << "," << faces[hand[i][1]] << ")" << endl;
	}
}


void importPlayers(int& n)
{
	cout << "Import number of player: ";
	cin >> n;
}

int*** dealingForHands(int deck[SUITS][FACES], int n)
{
	int*** hands = new int** [n];

	for (int i = 0; i < n; i++)
	{
		hands[i] = new int* [row];
		for (int j = 0; j < row; j++)
			hands[i][j] = new int[column];
	}

	//Chia bai theo luot.
	int theCard = 1;
	for (int j = 0; j < row; j++)
		for (int i = 0; i < n; i++)
		{
			for(int m = 0; m < SUITS; m++)
				for(int n = 0; n < FACES; n++)
					if (deck[m][n] == theCard)
					{
						hands[i][j][0] = m;
						hands[i][j][1] = n;
					}

			theCard++;
		}
		  
	return hands;
}

void delete3D(int ***a, int n)
{

	for(int i = 0; i < n; i++)
    {
	for(int j = 0; j < row; j++)
	  delete []a[i][j];
	  delete[]a[i];
	  }
	  delete[]a;
}

void delete2D(int** a)
{
	for (int i = 0; i < row; i++)
		delete[]a[i];
	delete[]a;
}

int getStatusOfHand(int** hand)
{
	
	if (isStraightFlush(hand))return 8;
	else if (isFourOfAKind(hand)) return 7;
	else if (isFullHouse(hand)) return 6;
	else if (isFlush(hand)) return 5;
	else if (isStraight(hand)) return 4;
	else if (isThreeOfAKind(hand)) return 3;
	else if (isTwoPair(hand)) return 2;
	else if (isPair(hand)) return 1;
	else return 0;
}


int whoIsTheWinner(int ***hands, int n)
{
	int* a = new int[2 * n];
	int maxIndex = 0;
	
	int i = 0;
	int j = 0;
	while (i < (2 * n))
	{
		a[i] = getStatusOfHand(hands[j]);
		i++;
		a[i] = isHighestCard(hands[j]);
		i++;
		j++;
	}
    
	int maxScore = a[0];
	int maxCard = a[1];

	for (int m = 2; m < (2 * n); m+=2)
	{
		if (a[m] > maxScore)
		{
			maxScore = a[m];
			maxCard = a[m + 1];
			maxIndex = m;
		}
	}

	if (maxCard == 0) { maxCard = 14; }

	int index = maxIndex;

	for (int m = index; m < (2 * n); m+=2)
	{
		if (a[m] == maxScore)
		{
			if (a[m + 1] > maxCard)
			{
				maxIndex = m;
			}
		}
	}

	maxIndex = maxIndex / 2;

	delete[]a;

	return maxIndex;
}

int* rankingHands(int*** hands, int n)
{
	int* arrayRank = new int[n];

	for (int i = 0; i < n; i++)
	{
		arrayRank[i] = getStatusOfHand(hands[i]);
	}
     
	return arrayRank;
}


void numberOfDealingCards(int& s)
{
	cout << "Import number of dealing cards: ";
	cin >> s;
}

int* evalHands(int n, int s, int deck[SUITS][FACES])
{
	int* sumScore = new int[n];
	int* subRow = new int[n];


	for (int i = 0; i < n; i++)
	{
		sumScore[i] = 0;
	}

	for (int i = 1; i <= s; i++)
	{
		int deck[SUITS][FACES] = { 0 };
		shuffleCards(deck);

		int*** threeD;
		threeD = dealingForHands(deck, n);
		for (int j = 0; j < n; j++)
		{
			subRow[j] = getStatusOfHand(threeD[j]);
		}
		for (int k = 0; k < n; k++)
		{
			sumScore[k] += subRow[k];
		}
        
		//xoa mang 3D
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < row; j++)
				delete[]threeD[i][j];
			delete[]threeD[i];
		}
		delete[]threeD;
	}

	delete[]subRow;

	return sumScore;
}

void dealerDrawCardRandom(int ***hands, int deck[SUITS][FACES], int n)
{

	srand((int)time(0));

	int dealer = n - 1;
	int cardReplaces;
	cardReplaces = rand() % 4;
	
	int* index = new int[cardReplaces];

	for (int i = 0; i < cardReplaces; i++)
	{
		index[i] = rand() % 5;
		for (int j = i; j >= 0; j--)
		{
			if (index[i] == index[j])
			{
				index[i] = rand() % 5;
			}
		}
	}

	int theCard;
	theCard = (n * 5) + 1;

	int a = n - 1;

	for (int i = 0; i < cardReplaces; i++)
	{ 
	     for (int m = 0; m < SUITS; m++)
			for (int n = 0; n < FACES; n++)
				if (deck[m][n] == theCard)
					{
						hands[a][index[i]][0] = m;
						hands[a][index[i]][1] = n;
						theCard++;
					}
	}
}

void playerDrawCard(int*** hands, int deck[SUITS][FACES], int n)
{
	int player = 0;

	int numberOfCard;

	cout << "How many card do you want to draw ? : ";
	cin >> numberOfCard;
    
	int* positionReplace = new int[numberOfCard];

	cout << "Position you want to replace(0 to 4): ";

	for (int i = 0; i < numberOfCard; i++)
	{
		cin >> positionReplace[i];
	}

	int theCard;
	theCard = (n * 5) + 1;

	for (int i = 0; i < numberOfCard; i++)
	{
		for(int m = 0; m < SUITS; m++)
			for(int n = 0; n < FACES; n++)
				if (deck[m][n] == theCard)
				{
					hands[0][positionReplace[i]][0] = m;
					hands[0][positionReplace[i]][1] = n;
					theCard++;
				}
	}

}


void printStatusOfHand(int **hand)
{
	int value = getStatusOfHand(hand);
	switch (value)
	{
	case 8:
	{
		cout << "Straight Flush !!!";
		break;
	}
	case 7:
	{
		cout << "Four Of Kind !!";
		break;
	}
	case 6:
	{
		cout << "Full House !";
		break;
	}
	case 5:
	{
		cout << "Flush !";
		break;
	}
	case 4:
	{
		cout << "Straight !";
		break;
	}
	case 3:
	{
		cout << "Three Of Kind !";
		break;
	}
	case 2:
	{
		cout << "Two Pair !";
		break;
	}
	case 1:
	{
		cout << "Pair !";
		break;
	}
	default:
	{
		cout << "No type :v";
	}
	};

}

void printWinner(int*** hands, int n)
{
	int index = whoIsTheWinner(hands, n);
    
	if (index == 0)
	{
		cout << "The winner is: You.";
	}
	else if (index == (n - 1))
	{
	 cout<<"The winner is: Dealer.";
	}
	else
	{
		cout << "The winner is: " << index + 1 << "th member.";
	}
}






