#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "map.h"

using namespace sf;
using namespace std;

class Bullet {
public:
    float x, y, dx, dy;
    bool life, p1life, p2life;
    int pl;
    Texture bl;
    Sprite bul;

    Bullet() {}

    Bullet(int X, int Y, int dir, int player);
    void update(RenderWindow& win, int x1, int y1, int x2, int y2);
    void drawb(RenderWindow& window);
};

extern Bullet game_bullet;
extern list<Bullet*> bullets;
extern list<Bullet*>::iterator it;