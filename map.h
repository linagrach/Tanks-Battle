#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Map {
public:

    Texture brick_texture;
    Texture ground_texture;
    Texture stone_texture;

    Sprite brick;
    Sprite ground;
    Sprite stone;


    String TileMap[20] = {
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
        "SS   BB                   S     SS",
        "S    BB                          S",
        "S    BB                          S",
        "S            SSSSSS              S",
        "S              BB      BBBB      S",
        "S                      BBSS      S",
        "S      BB                BB      S",
        "S      BB        SS      BB      S",
        "S      BB        SS      BB      S",
        "S      BB        SS      BB      S",
        "S      BB        SS      BB      S",
        "S      BB        SS      BB      S",
        "S      SSBBB     SS              S",
        "S      BBBBB     BB              S",
        "S                BB              S",
        "S                          BB    S",
        "S                          BB    S",
        "SS     S                   BB   SS",
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    };

    void load_map(RenderWindow& window);
};

extern Map game_map;
