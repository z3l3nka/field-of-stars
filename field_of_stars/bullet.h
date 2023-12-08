#ifndef BULLET_H
#define BULLET_H

#include "entity.h"

////////////////////////////КЛАСС ПУЛИ////////////////////////
class Bullet :public Entity{//класс пули
public:
    int direction;//направление пули
    //всё так же, только взяли в конце состояние игрока (int dir)
    //для задания направления полёта пули
Bullet(Image &image, float X, float Y, int W, int H, std::string Name, int dir);
void update(float time);
};

#endif // BULLET_H
