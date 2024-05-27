#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "tank.h"
#include "map.h"
#include "bullet.h"
#include "gamespace.h"
#include "score.h"

using namespace sf;

Tank game_tank;
Map game_map;
Bullet game_bullet;
Gamespace game_space;
GameState state = GameState::Menu;
Score game_score(game_space.font);
list<Bullet*> bullets;
list<Bullet*>::iterator it;

void Gamespace::GameStart(RenderWindow& win, Tank& game_tank, Map& game_map, Bullet& game_bullet, Gamespace& game_space, GameState& state) {

    switch (state)
    {
    case GameState::Menu:
        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            state = GameState::Game;
            win.setTitle("Battle Tank game!");
        }
        win.clear();
        win.draw(game_space.background);
        win.draw(game_space.title);
        win.draw(game_space.prompt);
        win.display();
        break;



    case GameState::Game:
        win.clear();
        game_tank.players_keys(bullets, game_tank.player1, game_tank.player2, game_tank.state1, game_tank.state2, game_tank.bulletCooldown, game_tank.lastBulletTime1, game_tank.lastBulletTime2);
        game_score.update_score(game_score.score1, game_score.score2, game_score.p1score, game_score.p2score);
        win.clear();

        for (it = bullets.begin(); it != bullets.end(); it++)
            (*it)->update(win, game_tank.player1.getPosition().x, game_tank.player1.getPosition().y, game_tank.player2.getPosition().x, game_tank.player2.getPosition().y);

        for (it = bullets.begin(); it != bullets.end();) {
            Bullet* b = *it;
            if (b->p1life == false) {
                game_score.p2score++;
                game_score.update_score(game_score.score1, game_score.score2, game_score.p1score, game_score.p2score);

                if (game_score.p2score > 2) {
                    state = GameState::yellow_wins;
                    win.setTitle("YELLOW WINS");
                }
                delete b;
                it = bullets.erase(it);
                game_tank.state1 = 4;
                game_tank.state2 = 3;
                game_tank.player1.setPosition(1450, 100);
                game_tank.player2.setPosition(150, 800);
            }
            else it++;
        }
        for (it = bullets.begin(); it != bullets.end();) {
            Bullet* b = *it;
            if (b->p2life == false) {
                game_score.p1score++;
                game_score.update_score(game_score.score1, game_score.score2, game_score.p1score, game_score.p2score);

                if (game_score.p1score > 2) {
                    state = GameState::green_wins;
                    win.setTitle("GREEN WINS");
                }
                delete b;
                it = bullets.erase(it);
                game_tank.state1 = 4;
                game_tank.state2 = 3;
                game_tank.player1.setPosition(1450, 100);
                game_tank.player2.setPosition(150, 800);
            }
            else it++;
        }
        for (it = bullets.begin(); it != bullets.end();) {
            Bullet* b = *it;
            if (b->life == false) {
                it = bullets.erase(it);
                delete b;
            }
            else  it++;
        }

        win.clear();

        game_map.load_map(win);

        for (it = bullets.begin(); it != bullets.end(); it++) {
            (*it)->drawb(win);
        }

        win.draw(game_tank.player1);
        win.draw(game_tank.player2);
        win.draw(game_score.score1);
        win.draw(game_score.score2);

        win.display();
        break;

    case GameState::green_wins:
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            state = GameState::Menu;
        }
        win.clear();

        win.draw(game_space.player1_wins);
        win.draw(game_space.play_again);
        win.draw(game_space.green_wins);
        win.display();
        break;

    case GameState::yellow_wins:
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            state = GameState::Menu;
        }
        win.clear();

        win.draw(game_space.player2_wins);
        win.draw(game_space.play_again);
        win.draw(game_space.yellow_wins);
        win.display();
        break;

    default:
        break;
    }
}