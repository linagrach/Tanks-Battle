#include "tank.h"
#include "map.h"
#include "bullet.h"

bool collXL(int dx, int dy) {
    for (int i = (dy + 1) / 50; i < (dy + 100 - 2) / 50; i++) {
        if ((game_map.TileMap[i][dx / 50] == 'B') || (game_map.TileMap[i][dx / 50] == 'S')) return(1);
        else {
            if ((game_map.TileMap[i + 1][dx / 50] == 'B') || (game_map.TileMap[i + 1][dx / 50] == 'S')) return(1);
            else {
                if ((game_map.TileMap[i + 2][dx / 50] == 'B') || (game_map.TileMap[i + 2][dx / 50] == 'S')) return(1);
                else return(0);
            }
        }
    }
}
bool collXR(int dx, int dy) {
    for (int i = (dy + 1) / 50; i < (dy + 100 - 2) / 50; i++) {
        if ((game_map.TileMap[i][(dx + 100) / 50] == 'B') || (game_map.TileMap[i][(dx + 100) / 50] == 'S')) return(1);
        else {
            if ((game_map.TileMap[i + 1][(dx + 100) / 50] == 'B') || (game_map.TileMap[i + 1][(dx + 100) / 50] == 'S')) return(1);
            else {
                if ((game_map.TileMap[i + 2][(dx + 100) / 50] == 'B') || (game_map.TileMap[i + 2][(dx + 100) / 50] == 'S')) return(1);
                else return(0);
            }
        }

    }
}
bool collYU(int dx, int dy) {
    for (int j = (dx + 1) / 50; j < (dx + 100) / 50; j++) {
        if ((game_map.TileMap[dy / 50][j] == 'B') || (game_map.TileMap[dy / 50][j] == 'S'))  return(1);
        else {
            if ((game_map.TileMap[dy / 50][j + 1] == 'B') || (game_map.TileMap[dy / 50][j + 1] == 'S')) return(1);
            else {
                if ((game_map.TileMap[dy / 50][j + 2] == 'B') || (game_map.TileMap[dy / 50][j + 2] == 'S')) return(1);
                else return(0);
            }
        }

    }
}
bool collYD(int dx, int dy) {
    for (int j = (dx + 1) / 50; j < (dx + 100) / 50; j++) {
        if ((game_map.TileMap[(dy + 100) / 50][j] == 'B') || (game_map.TileMap[(dy + 100) / 50][j] == 'S')) return(1);
        else {
            if ((game_map.TileMap[(dy + 100) / 50][j + 1] == 'B') || (game_map.TileMap[(dy + 100) / 50][j + 1] == 'S')) return(1);
            else {
                if ((game_map.TileMap[(dy + 100) / 50][j + 2] == 'B') || (game_map.TileMap[(dy + 100) / 50][j + 2] == 'S')) return(1);
                else return(0);
            }
        }

    }
}

Tank:: Tank() {
    player1_texture.loadFromFile("Image/player1.png");
    player2_texture.loadFromFile("Image/player2.png");

    player2.setTexture(player1_texture);
    player2.setTextureRect(sf::IntRect(100, 0, 100, 100));
    player2.setPosition(140, 800);

    player1.setTexture(player2_texture);
    player1.setTextureRect(sf::IntRect(0, 0, 100, 100));
    player1.setPosition(1450, 100);

    state1 = 4;
    state2 = 3;
    bulletCooldown = 0.5f;

}

void Tank:: players_keys(list<Bullet*>& bullets, Sprite& player1, Sprite& player2, int& state1, int& state2, float& bulletCooldown, float& lastBulletTime1, float& lastBulletTime2) {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if (collXL(player1.getPosition().x, player1.getPosition().y) == 0) player1.move(-0.3, 0);
        player1.setTextureRect(IntRect(300, 0, 100, 100));
        state1 = 1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (collXR(player1.getPosition().x, player1.getPosition().y) == 0) player1.move(0.3, 0);
        player1.setTextureRect(IntRect(200, 0, 100, 100));
        state1 = 2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (collYU(player1.getPosition().x, player1.getPosition().y) == 0) player1.move(0, -0.3);
        player1.setTextureRect(IntRect(100, 0, 100, 100));
        state1 = 3;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        if (collYD(player1.getPosition().x, player1.getPosition().y) == 0) player1.move(0, 0.3);
        player1.setTextureRect(IntRect(0, 0, 100, 100));
        state1 = 4;
    }

    if (Keyboard::isKeyPressed(Keyboard::A)) {
        if (collXL(player2.getPosition().x, player2.getPosition().y) == 0) player2.move(-0.3, 0);
        player2.setTextureRect(IntRect(300, 0, 100, 100));
        state2 = 1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        if (collXR(player2.getPosition().x, player2.getPosition().y) == 0) player2.move(0.3, 0);
        player2.setTextureRect(IntRect(200, 0, 100, 100));
        state2 = 2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::W)) {
        if (collYU(player2.getPosition().x, player2.getPosition().y) == 0) player2.move(0, -0.3);
        player2.setTextureRect(IntRect(100, 0, 100, 100));
        state2 = 3;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S)) {
        if (collYD(player2.getPosition().x, player2.getPosition().y) == 0) player2.move(0, 0.3);
        player2.setTextureRect(IntRect(0, 0, 100, 100));
        state2 = 4;
    }
    if (Keyboard::isKeyPressed(Keyboard::L)) {
        float currentTime1 = static_cast<float>(clock()) / CLOCKS_PER_SEC;
        if (currentTime1 - lastBulletTime1 > bulletCooldown) {
            bullets.push_back(new Bullet(player1.getPosition().x + 43, player1.getPosition().y + 43, state1, 1));
            lastBulletTime1 = currentTime1;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::V)) {
        float currentTime2 = static_cast<float>(clock()) / CLOCKS_PER_SEC;
        if (currentTime2 - lastBulletTime2 > bulletCooldown) {
            bullets.push_back(new Bullet(player2.getPosition().x + 43, player2.getPosition().y + 43, state2, 2));
            lastBulletTime2 = currentTime2;
        }
    }
}