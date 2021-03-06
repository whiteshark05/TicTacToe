// TicTacToeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <bits/stdc++.h>
using namespace std;

class Square {
public:
	pair<int, int>p;
	char val;
	Square(pair<int,int>p) {
		this->p = p;
		this->val = ' ';
	}

	Square(pair<int, int>p, char c) {
		this->p = p;
		this->val = c;
	}
};

class Board {
public:
	char currentplayer = 'X';
	vector<Square> v;
	char lines[8];

	Board() {
		for (int i = 1; i < 4; i++)
			for (int j = 1; j < 4; j++)
				v.push_back(Square({ i,j }));
	}

	void updateBoard(int x, int y, char currentplayer) {
		bool found = false;
		auto it = v.begin();
		while (!found && it!=v.end()) {
			if (it->p.first == x && it->p.second==y) {
				it->val = currentplayer;
				if (currentplayer == 'X')
					currentplayer = 'O';
				else
					currentplayer = 'X';
				found = true;
			}
			it++;
		}
		cout << "Invalid Move" << endl;
	}

	void reset() {
		for (auto ref : v) {
			ref.val = ' ';
		}
	}

	void printBoard() {
		for (auto ref : v) { 
			cout << "[" << ref.val<< "]";
			if (ref.p.second == 3)
				cout << endl;
		}

		cout << endl;
	}

	bool isWon() {
		for (auto ref : v) {
			if (v[0].val == v[1].val&&v[1].val == v[2].val && v[0].val!=' ') {
				lines[0] = v[0].val;
				return 1;
			}

			if (v[3].val == v[4].val&&v[4].val == v[5].val && v[3].val != ' ') {
				lines[3] = v[3].val;
				return 1;
			}

			if (v[6].val == v[7].val&&v[7].val == v[8].val && v[6].val != ' ') {
				lines[6] = v[6].val;
				return 1;
			}

			if (v[0].val == v[3].val&&v[3].val == v[6].val && v[0].val != ' ') {
				lines[0] = v[0].val;
				return 1;
			}

			if (v[1].val == v[4].val&&v[4].val == v[7].val && v[1].val != ' ') {
				lines[1] = v[1].val;
				return 1;
			}

			if (v[2].val == v[5].val&&v[5].val == v[8].val && v[2].val != ' ') {
				lines[2] = v[2].val;
				return 1;
			}

			if (v[0].val == v[4].val&&v[4].val == v[8].val && v[0].val != ' ') {
				lines[0] = v[0].val;
				return 1;
			}

			if (v[2].val == v[4].val&&v[4].val == v[6].val && v[2].val != ' ') {
				lines[2] = v[2].val;
				return 1;
			}
		}
	}
	
	bool isDraw() {
		int count=0;
		for (auto ref : v) {
			if (ref.val == ' ')
				count++;
		}

		if (count == 0) 
			return true;
		else
			return false;
	
	}
};

void startGame(Board *b) {
	b->printBoard();
	while (!b->isDraw() && !b->isWon()) {
		cout << "Player " << b->currentplayer << " turn" << endl;
		cout << "Enter the coordinates x y: ";
		int x, y;
		cin >> x >> y;
		b->updateBoard(x, y, b->currentplayer);
		b->printBoard();
	}
	if (b->isWon()) {
		cout << "Player " << b->currentplayer << " won" << endl;
	}
	else cout << "The game is drawn" << endl;
}

int main()
{
	bool playagain = false;
	Board *b = new Board();
	int gamecount = 1;
	do {
		cout << "Game " << gamecount << endl;
		startGame(b);
		cout << "Do you want to play again? y/n: ";
		char c;
		cin >> c;
		if (c == 'y') {
			playagain = true;
			b->reset();
		}
		else playagain = false;
		cout << endl << endl;
		gamecount++;
	} while (playagain);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
