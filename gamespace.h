#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "tank.h"
#include "map.h"
#include "bullet.h"

class Score;

using namespace sf;
using namespace std;

enum class GameState
{
    Menu,
    Game,
    green_wins,
    yellow_wins
};

class Gamespace {
private:
    Texture Menu, goal_1, goal_2;
public:
    RectangleShape background, player1_wins, player2_wins;
    Font font;
    Text title, prompt, yellow_wins, green_wins, play_again;

    Gamespace() {

        // Load Menu texture and set up menu background
        Menu.loadFromFile("Image/menu_background.jpg");
        background.setSize(Vector2f(1700, 1000));
        background.setTexture(&Menu);
        background.setPosition(Vector2f(0, 0));

        // Load the font
        font.loadFromFile("Font/Font.TTF");
        // Setup Title
        title.setFont(font);
        title.setString("Battle City game!");
        title.setCharacterSize(84);
        title.setFillColor(Color::Black);
        title.setStyle(Text::Regular);
        title.setPosition(Vector2f(570, 250));

        // Setup Prompt
        prompt.setFont(font);
        prompt.setString("Press Enter to play!");
        prompt.setCharacterSize(45);
        prompt.setFillColor(Color::Black);
        prompt.setStyle(Text::Regular);
        prompt.setPosition(Vector2f(670, 400));

        // Setup Yellow Wins Text
        yellow_wins.setFont(font);
        yellow_wins.setString("Yellow Wins!");
        yellow_wins.setCharacterSize(84);
        yellow_wins.setFillColor(Color::Yellow);
        yellow_wins.setStyle(Text::Regular);
        yellow_wins.setPosition(Vector2f(610, 250));

        // Setup Green Wins Text
        green_wins.setFont(font);
        green_wins.setString("Green Wins!");
        green_wins.setCharacterSize(84);
        green_wins.setFillColor(Color::Green);
        green_wins.setStyle(Text::Regular);
        green_wins.setPosition(Vector2f(660, 250));

        // Setup Play Again Text
        play_again.setFont(font);
        play_again.setString("Press SPACE to play again!");
        play_again.setCharacterSize(50);
        play_again.setFillColor(Color::Black);
        play_again.setStyle(Text::Regular);
        play_again.setPosition(Vector2f(570, 400));

        // Setup Goals
        goal_1.loadFromFile("Image/green_wins.jpg");
        player1_wins.setSize(Vector2f(1700, 1000));
        player1_wins.setTexture(&goal_1);
        player1_wins.setPosition(0, 0);
        goal_2.loadFromFile("Image/yellow_wins.jpg");
        player2_wins.setSize(Vector2f(1700, 1000));
        player2_wins.setTexture(&goal_2);
        player2_wins.setPosition(Vector2f(0, 0));
    }

    void GameStart(RenderWindow& window, Tank& game_tank, Map& game_map, Bullet& game_bullet, Gamespace& game_space, GameState& state);

};

extern Gamespace game_space;
extern GameState state;