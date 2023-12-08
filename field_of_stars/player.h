#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"

using namespace sf;
////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player :public Entity {
public:
    int playerScore;//эта переменная может быть только у игрока
    Player(Image &image, int W, int H, std::string Name);
    void control();
    //Метод проверки столкновений с элементами карты
    void update(float time);
};

#endif // PLAYER_H
