#include "bullet.h"

Bullet::Bullet(Image &image, float X, float Y, int W, int H, std::string Name, int dir)
    :Entity(image, X, Y, W, H, Name){
    x = X;
    y = Y;
    direction = dir;
    speed = 0.8;
    w = h = 16;
    life = true;
    //выше инициализация в конструкторе
}

void Bullet::update(float time)
{
    switch (direction)
    {
    case 0: dx = -speed; dy = 0; break;// state = left
    case 1: dx = speed; dy = 0; break;// state = right
    case 2: dx = 0; dy = -speed; break;// state = up
    case 3: dx = 0; dy = speed; break;// state = down
    }
    if (life){
        x += dx*time;//само движение пули по х
        y += dy*time;//по у
        if (x <= 0){
            life = false;
        }
        if (y <= 0){
            life = false;
        }
        if (x >= 800){
            life = false;
        }
        if (y >= 640){
            life = false;
        }
        sprite.setPosition(x + w / 2, y + h / 2);//задается позицию пули
    }
}
