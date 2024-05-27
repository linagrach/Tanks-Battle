#include <SFML/Graphics.hpp>
#include "map.h"
#include <iostream>

using namespace sf;

void Map::load_map(RenderWindow& win) {

    brick_texture.loadFromFile("Image/brick.jpg");
    ground_texture.loadFromFile("Image/ground.png");
    stone_texture.loadFromFile("Image/stone.jpg");

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 34; j++) {
            if (game_map.TileMap[i][j] == 'B') {
                brick.setTexture(brick_texture);
                brick.setPosition(j * 50, i * 50);
                win.draw(brick);
            }
            else if (game_map.TileMap[i][j] == ' ') {
                ground.setTexture(ground_texture);
                ground.setPosition(j * 50, i * 50);
                win.draw(ground);
            }
            else {
                stone.setTexture(stone_texture);
                stone.setPosition(j * 50, i * 50);
                win.draw(stone);
            }
        }
    }
}