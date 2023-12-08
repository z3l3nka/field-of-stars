#include "bullet.h"

Bullet::Bullet(Image &image, float X, float Y, int W, int H, std::string Name)
    :Entity(image, X, Y, W, H, Name){
    x = X;
    y = Y;
    speed = 0.8;
    w = h = 16;
    life = true;
    //выше инициализация в конструкторе
}

void Bullet::update(float time)
{
    dy = -speed;
    if (life){
        y += dy*time;//по у

        if (y <= 0 || y >= SCREEN_H){
            life = false;
        }

        sprite.setPosition(x + w / 2, y + h / 2);//задается позицию пули
    }
}
