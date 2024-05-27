#include <SFML/Graphics.hpp>
#include "tank.h"
#include "map.h"
#include "bullet.h"
#include "gamespace.h"
#include "score.h"

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(1700, 1000), "Battle Tank game!");
	Image icon;
	icon.loadFromFile("Image/icon.png");
	win.setIcon(32, 32, icon.getPixelsPtr());

	Tank game_tank;
	Map game_map;
	Bullet game_bullet;
	Gamespace game_space;
	GameState state = GameState::Menu;
	Score game_score(game_space.font);
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;

	while (win.isOpen())
	{
		Event event;
		while (win.pollEvent(event))
		{
			if ((event.type == Event::Closed) ||
				Keyboard::isKeyPressed(Keyboard::Escape))
				win.close();
		}
		game_space.GameStart(win, game_tank, game_map, game_bullet, game_space, state);
	}
	return 0;
}
