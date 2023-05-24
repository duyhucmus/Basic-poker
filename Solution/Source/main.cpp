#include"function.h"

const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char *ranks[RANKS] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King","Ace" };
const char *faces[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

int main()
{

	menu();
	int choice;
	
	while (true)
	{
		cout << "              --> Your choice: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			int deck[SUITS][FACES] = { 0 };
			shuffleCards(deck);
			int** b;
			int a[5];
			printAllCard(deck);
			b = createHandTest(deck, a);
			setColor(9);
			printPlayerCard(b, suits, faces);
			cout << endl;
			setColor(14);
			cout << "\t\t    "; printStatusOfHand(b);
			cout << endl << endl;
			delete2D(b);
		}
		else if (choice == 2)
		{
			int deck[SUITS][FACES] = { 0 };
			shuffleCards(deck);
			int members;
			int*** array;

			setColor(15);
			cout << endl << endl;
			cout << "\t" << "Player must greater or equal than 2." << endl;
			cout << "\t"; importPlayers(members);
			cout << endl;
			array = dealingForHands(deck, members);
			setColor(10);
			cout << "Player's Cards is: " << endl << endl;
			printPlayerCard(array[0],suits,faces);
			cout << endl;
			setColor(13);
			playerDrawCard(array,deck,members);
			cout << endl;
			setColor(11);
			cout << " -> Player's Cards is become: " << endl << endl;
			printPlayerCard(array[0], suits, faces); cout << endl;
			cout << "\t" << "------------------------------------";
			setColor(14);
			cout<< endl;
			cout << "\t\t"; printWinner(array, members); cout << endl << endl;
			if ((whoIsTheWinner(array,members)) != 0)
			{
				cout << "\t\t"; cout << "Winner's Cards: " << endl;
				printPlayerCard(array[whoIsTheWinner(array, members)], suits, faces); cout << endl;
				cout << "\t\t\t"; printStatusOfHand(array[whoIsTheWinner(array, members)]);
				cout << endl << endl;
				delete3D(array, members);
			}
			else
			{
				cout << "\t\t\t"; printStatusOfHand(array[0]);
				cout << endl << endl;
				delete3D(array, members);
			}
		}
		else if (choice == 3)
		{
			int deck[SUITS][FACES] = { 0 };
			shuffleCards(deck);
			int n;
			int*** c;
			setColor(13);
			cout << endl << endl << endl;
			cout << "\t" << "Player must greater or equal than 2." << endl;
			cout << "\t"; importPlayers(n);
			cout << endl;
			c = dealingForHands(deck, n);
			setColor(14);
			cout << endl;
			cout << "\t\t"; printWinner(c, n); cout << endl << endl;
			cout << "\t\t"; cout << "Winner's Cards: " << endl;
			printPlayerCard(c[whoIsTheWinner(c, n)], suits, faces); cout << endl;
			cout << "\t\t     "; printStatusOfHand(c[whoIsTheWinner(c, n)]);
			cout << endl << endl;
			delete3D(c, n);
		}
		else if (choice == 4)
		{
			int deck[SUITS][FACES] = { 0 };
			shuffleCards(deck);
			int mems;
			int*** arr;
			setColor(12);
			cout << endl << endl;
			cout << "\t" << "Player must greater or equal than 2." << endl;
			cout << "\t"; importPlayers(mems);
			cout << endl;
			arr = dealingForHands(deck, mems);
			setColor(13);
			cout << "Dealer'sCards is: " << endl << endl;
			printPlayerCard(arr[mems-1], suits, faces);
			cout << endl;
			dealerDrawCardRandom(arr, deck, mems);
			cout << endl;
			setColor(11);
			cout << " -> Dealer'sCards is become: " << endl << endl;
			printPlayerCard(arr[mems-1], suits, faces);
			cout << "\t" << "-----------------------------------";
			setColor(14);
			cout << endl;
			cout << "\t\t"; printWinner(arr, mems); cout << endl << endl;
			if ((whoIsTheWinner(arr, mems)) != (mems - 1))
			{
				cout << "\t\t"; cout << "Winner's Cards: " << endl;
				printPlayerCard(arr[whoIsTheWinner(arr, mems)], suits, faces); cout << endl;
				cout << "\t\t\t"; printStatusOfHand(arr[whoIsTheWinner(arr, mems)]);
				cout << endl << endl;
				delete3D(arr, mems);
			}
			else
			{
				cout << "\t\t\t"; printStatusOfHand(arr[mems-1]);
				cout << endl << endl;
				delete3D(arr, mems);
			}
		}
		else if (choice == 0) break;

		char ch;
		setColor(13);
		cout <<"\t   "<<"Do you want to continue ?!" << endl;
		setColor(12);
		cout <<"\t       "<<"Yes: Press y or Y." << endl;
		cout <<"\t       "<<"No:  Press n." << endl;
		cout <<"\t           "; cin >> ch;
		if (ch != 'y' && ch != 'Y')
		{
			system("cls");
			menu();
		}
	}
	setColor(11);
	cout << endl << endl;
	cout << "\t\t\t" << "SEE YOU AGAIN !!!" << endl;
	setColor(2);
	return 0;
}

