#pragma once
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

class Bullet;

class Tank {
public:
    Texture player1_texture, player2_texture;
    Sprite player1, player2;
    int state1, state2;
    float bulletCooldown, lastBulletTime1, lastBulletTime2;

    Tank();

    void players_keys(list<Bullet*>& bullets, Sprite& player1, Sprite& player2, int& state1, int& state2, float& bulletCooldown, float& lastBulletTime1, float& lastBulletTime2);

};

extern Tank game_tank;