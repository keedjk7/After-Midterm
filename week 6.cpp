#include<iostream>
#include<list>
#include <stdlib.h>
#include <time.h>

using namespace std;

list<int>hand_player, hand_bot;
int life_player = 20, life_bot = 20;

struct card {

	int ATK[4] = { 0,3,6,7 };
	int DEF[4] = { 6,5,3,2 };

};

void fight(int player_input, int bot_choose, struct card card, bool side) {
	int result;

	cout << "You Choose : ";
	if (player_input == -1) {
		cout << " You Don't Choose A Card To Defense  \n";
	}
	else if (player_input == 0) {
		cout << "  Stone Turtle Golem(ATK 0/DEF 6)  \n";
	}
	else if (player_input == 1) {
		cout << "  Shield Guardian Knight(ATK 3/DEF 5)  \n";
	}
	else if (player_input == 2) {
		cout << "  Basilisk(ATK 6/DEF 3)  \n";
	}
	else {
		cout << "  Dark Templar Berserker(ATK 7/DEF 2)  \n";
	}

	cout << "Bot Choose : ";
	if (bot_choose == 0) {
		cout << "  Stone Turtle Golem(ATK 0/DEF 6)  \n";
	}
	else if (bot_choose == 1) {
		cout << "  Shield Guardian Knight(ATK 3/DEF 5)  \n";
	}
	else if (bot_choose == 2) {
		cout << "  Basilisk(ATK 6/DEF 3)  \n";
	}
	else {
		cout << "  Dark Templar Berserker(ATK 7/DEF 2)  \n";
	}
	if (side == 1) {
		if (player_input > -1) {
			result = card.ATK[player_input] - card.DEF[bot_choose];
		}
		if (result > 0) {
			life_bot -= result;
		}
		else {
			life_player += result;
		}
	}
	else {
		if (player_input == -1) {
			result = card.ATK[bot_choose] - 0;
			life_player -= result;
		}
		else {
			result = card.ATK[bot_choose] - card.DEF[player_input];
			if (result > 0) {
				life_player -= result;
			}
			else {
				life_bot += result;
			}
		}
	}
	cout << "Player Life Point = " << life_player << "    Bot Life Point = " << life_bot << "\n";

}

int RANDOM_BOT() {
	int RE;
	bool pass = false;
	if (hand_bot.size() != 0) {
		while (pass != true) {
			RE = rand() % 4;
			for (std::list<int>::iterator p = hand_bot.begin(); p != hand_bot.end(); p++) {
				if (RE == *p) {
					hand_bot.erase(p);
					pass = true;
					break;
				}
			}
		}
	}
	else {
		RE = -1;
	}

	return RE;
}

void show_hand_player() {
	cout << "\nCard In Your Hand\n";
	for (std::list<int>::iterator p = hand_player.begin(); p != hand_player.end(); p++) {
		if (*p == 0) {
			cout << "  1.Stone Turtle Golem(ATK 0/DEF 6)  \n";
		}
		else if (*p == 1) {
			cout << "  2.Shield Guardian Knight(ATK 3/DEF 5)  \n";
		}
		else if (*p == 2) {
			cout << "  3.Basilisk(ATK 6/DEF 3)  \n";
		}
		else {
			cout << "  4.Dark Templar Berserker(ATK 7/DEF 2)  \n";
		}
	}
	cout << "\n";
}

void DRAW(int stat) {
	bool pass = false;
	while (pass != true) {
		int R = rand() % 4;
		if (stat == 1) {
			hand_player.push_back(R);
			hand_player.sort();
			pass = true;
		}
		else {
			hand_bot.push_back(R);
			hand_bot.sort();
			pass = true;
		}
	}
}

int C_INPUT(int side) {
	bool check_input = false;
	int input;
	while (check_input != true) {

		cout << "Input Number Cards to place in the fight area : ";
		cin >> input;
		for (std::list<int>::iterator x = hand_player.begin(); x != hand_player.end(); x++) {
			if (*x == input - 1) {
				check_input = true;
				break;
			}
		}
		if (side == 0) {
			if (input == 0) {
				check_input = true;
			}
		}
		if (check_input != true) {
			cout << "You Input Number Hasn't On Your Hand\n";
			check_input = false;
		}

	}
	return input;
}

int COIN() {
	int coin = rand() % 2;


	for (int i = 0; i < 2; i++) {
		DRAW(1);//player
		DRAW(0);//bot
	}


	char guess = 'X', play = 'X';
	bool side;


	while (guess != 'T' && guess != 'H') {
		cout << "Guess The Coin Side (T->Tail , H->Head) : ";
		cin >> guess;
		if (guess != 'T' && guess != 'H') {
			cout << "Input Again Coin Only Have Tail & Head\n";
		}
	}

	if ((guess == 'H' && coin == 0) || (guess == 'T' && coin == 1)) {
		cout << "You guess the coin side correctly!\n";
		while (play != 'F' && play != 'S') {
			cout << "Choose To Play First Or Second (F->First , S->Second) : ";
			cin >> play;
			if (play != 'F' && play != 'S') {
				cout << "Input again Choose To Play Only Have First Or Second\n";
			}
		}
		if (play == 'F') {
			side = 1;//player
		}
		else {
			side = 0;//bot
		}
	}
	else {
		cout << "You guess the coin side incorrectly\n";
		int play_bot = rand() % 2;
		if (play_bot == 0) {
			cout << "Bot Choose To Play First\n";
			side = 0;
		}
		else {
			cout << "Bot Choose To Play Second\n";
			side = 1;
		}
	}
	return side;
}

int main() {
	bool END = false;
	struct card card;
	srand(time(NULL));
	int side;
	side = COIN();
	while (END != true) {
		DRAW(1);
		DRAW(0);
		int place_bot = RANDOM_BOT();
		show_hand_player();
		if (side == 1) {
			cout << "Your Attack Turn\n";
		}
		else {
			cout << "Your Defense Turn\n";
		}
		int input;
		input = C_INPUT(side);
		if (input != 0) {
			for (std::list<int>::iterator x = hand_player.begin(); x != hand_player.end(); x++) {
				if (input - 1 == *x) {
					hand_player.erase(x);
					break;
				}
			}
		}
		fight(input - 1, place_bot, card, side);
		//switch side
		if (side == 1) {
			side = 0;
		}
		else {
			side = 1;
		}
		//end?
		if (life_player <= 0 || life_bot <= 0) {
			END = true;
		}
	}
	cout << "\nPlayer Life Point = " << life_player << "\nBot Life Point = " << life_bot << "\n";
	if (life_player > life_bot) {
		cout << "You Win!!";
	}
	else if (life_player < life_bot) {
		cout << "You Lose!!";
	}
	else {
		cout << "You Equal with Bot!!";
	}
	return 0;
}
