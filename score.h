#pragma once

#include <SFML/Graphics.hpp>
#include "gamespace.h"

using namespace sf;
using namespace std;

class Score {
public:

	int p1score = 0;
	int p2score = 0;
	Text score1;
	Text score2;

	Score () {}

	Score(Font& font) : p1score(0), p2score(0) {

		//���� ������ 1 (������)
		score1.setFont(font);
		score1.setCharacterSize(55);
		score1.setFillColor(Color::Green);
		score1.setStyle(Text::Regular);
		score1.setPosition(870, -15);

		//���� ������ 2 (�����)
		score2.setFont(font);
		score2.setCharacterSize(55);
		score2.setFillColor(Color::Yellow);
		score2.setStyle(Text::Regular);
		score2.setPosition(775, -15);

	}

	void update_score(Text& score1, Text& score2, int& p1score, int& p2score);
};

extern Score game_score;