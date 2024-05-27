#include <SFML/Graphics.hpp>
#include <list>
#include "tank.h"
#include "map.h"
#include "bullet.h"
#include "score.h"

Bullet::Bullet(int X, int Y, int dir, int player) : x(X), y(Y), pl(player), life(true), p1life(true), p2life(true) {
    x = X;
    y = Y;
    pl = player;
    if (dir == 1) dx = -1.0f;
    else if (dir == 2) dx = 1.0f;
    else dx = 0;
    if (dir == 3) dy = -1.0f;
    else if (dir == 4) dy = 1.0f;
    else dy = 0;

    p1life = true;
    p2life = true;
    life = true;
    bl.loadFromFile("Image/bullet.png");
    bul.setTexture(bl);
}

void Bullet::update(RenderWindow& win, int x1, int y1, int x2, int y2) {
    x += dx * 3.0f;
    y += dy * 3.0f;

    for (int i = y / 50; i < (y + 15) / 50; i++) {
        for (int j = x / 50; j < (x + 15) / 50; j++) {
            if (game_map.TileMap[i][j] == 'B') {
                game_map.TileMap[i][j] = ' ';
                life = false;
                game_map.load_map(win);
            }
            else if (game_map.TileMap[i][j] == 'S') {
                life = false;
            }
        }
    }

    if (pl == 2 && x > x1 && y > y1 && x < (x1 + 100) && y < (y1 + 100)) {
        life = false;
        p1life = false;
    }
    else if (pl == 1 && x > x2 && y > y2 && x < (x2 + 100) && y < (y2 + 100)) {
        life = false;
        p2life = false;
    }

    bul.setPosition(x, y);
}
void Bullet::drawb(RenderWindow& window) {
    window.draw(bul);
}