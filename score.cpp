#include "score.h"

void Score::update_score(Text& score1, Text& score2, int& p1score, int& p2score)
{
	score1.setString(to_string(p1score));
	score2.setString(to_string(p2score));
}
