/*
 * =====================================================================================
 *
 *       Filename:  207.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/20/2014 17:19:24
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
	char name[25];
	int score[4];
	bool professional;
	bool out;

	int first_round_score;
	int total_score;
	int round;

	void calc_score() {
		if (!out) {
			first_round_score = score[0] + score[1];
		} else {
			if (round > 1) {
				first_round_score = score[0] + score[1];
			} else {
				first_round_score = -1;
			}
		}
		total_score = first_round_score + score[2] + score[3];
	}

	Player() { }

	void init() {
		memset(score, 0, sizeof(score));
		professional = true;
		out = false;
		round = -1;	
	}

	void outToString() {
		printf("%s %-10c", name, ' '); 
		for (int i = 0; i < 4; ++i) {
			if (score[i] == 0) {
				printf("     ");
			} else {
				printf("%-5d", score[i]);
			}
		}
		printf("DQ\n");
	}
};

int num_of_players;
double total_bonus;
double bonus[72];
Player players[148];
Player out_players[144];

bool comp1(const Player &p1, const Player &p2) {
	if (p1.first_round_score < 0 && p2.first_round_score < 0) return false;
	if (p1.first_round_score < 0) return false;
	if (p2.first_round_score < 0) return true;
	return p1.first_round_score < p2.first_round_score;	
}

bool comp2(const Player &p1, const Player &p2) {
	if (p1.out && p2.out) {
		if (p1.round != p2.round) return p1.round > p2.round; 
		if (p1.total_score != p2.total_score) return p1.total_score < p2.total_score;
		return strcmp(p1.name, p2.name) < 0;
	}
	if (p1.out) return false;
	if (p2.out) return true;
	if (p1.total_score != p2.total_score)
		return p1.total_score < p2.total_score;	
	return strcmp(p1.name, p2.name) < 0;
}

void print() {
	printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
	printf("-----------------------------------------------------------------------\n");
	int i = 0, j;
	int bonus_index = 0;
	while (i < num_of_players) {
		if (players[i].out) {
			players[i].outToString();
			++i;
			continue;
		}
		j = i;
		int m = 0;
		double tot = 0.0;
		bool have_money = false;
		while (j < num_of_players && players[i].total_score == players[j].total_score) {
			if (players[j].professional) {
				++m;
				if (bonus_index < 70) {
					have_money = true;
					tot += bonus[bonus_index++];
				}
			}
			++j;
		}
		char t[5];
		int place = i + 1;	
		double money = total_bonus * tot / m;
		for (; i < j; ++i) {
			sprintf(t, "%d%c", place, (m > 1) && have_money && players[i].professional ? 'T' : ' ');
			printf("%s %-10s", players[i].name, t); 
			printf("%-5d%-5d%-5d%-5d", players[i].score[0], players[i].score[1], players[i].score[2], players[i].score[3]); 
			if (have_money && players[i].professional) {
				printf("%-10d", players[i].total_score);
				printf("$%9.2lf", money);
			} else {
				printf("%d", players[i].total_score);
			}
			printf("\n");
		}
	}
}

int main() {
#ifdef Debug
	freopen("207.in2", "r", stdin);
#endif
	int cases;
	char input[35];
	fgets(input, 35, stdin);
	sscanf(input, "%d", &cases);
	//cout << "cases:" << cases << endl;
	while (cases--) {
		fgets(input, 35, stdin);

		fgets(input, 35, stdin);
		sscanf(input, "%lf", &total_bonus);
		//cout << "total_bonus:" << total_bonus << endl;
		for (int i = 0; i < 70; ++i) {
			fgets(input, 35, stdin);
			sscanf(input, "%lf", &bonus[i]);
			bonus[i] /= 100;
		}

		fgets(input, 35, stdin);
		sscanf(input, "%d", &num_of_players);
		//cout << "num_of_players:" << num_of_players << endl;
		for (int i = 0; i < num_of_players; ++i) {
			players[i].init();
			fgets(input, 35, stdin);
			int k;
			for (k = 0; k < 20; ++k) {
				players[i].name[k] = input[k];
			}
			players[i].name[20] = '\0';
			//cout << players[i].name << endl;
			if (strchr(players[i].name, '*')) {
				players[i].professional = false;
			}
			char s[5];
			for (int j = 0; j < 4; ++j) {
				for (int l = 0; l < 3; ++l) {
					s[l] = input[k++];
				}
				s[4] = '\0';
				if (!sscanf(s, "%d", &players[i].score[j])) {
					players[i].out = true;
					players[i].round = j;
					break;
				}
			}
			players[i].calc_score();
		}
		sort(players, players+num_of_players, comp1);
		for (int i = 69; i < num_of_players; ++i) {
			if (i == num_of_players - 1 || players[i].first_round_score != players[i+1].first_round_score) {
				num_of_players = i + 1;
				break;
			}
		}
		sort(players, players+num_of_players, comp2);
		print();

		if (cases) printf("\n");
	}
	return 0;
}
