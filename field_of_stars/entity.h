#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>
#include "map.h" //подключили код с картой

using namespace sf;
////////////////////////////КЛАСС СУЩНОСТЬ////////////////////////
class Entity {
public:
    enum { left, right, up, down, stay} state;// тип перечисления - состояние объекта
    float dx, dy, x, y, speed, moveTimer;//добавили переменную таймер для будущих целей
    int w, h, health; //переменная “health”, хранящая жизни игрока
    bool life; //переменная “life” жизнь, логическая
    Texture texture;//сфмл текстура
    Sprite sprite;//сфмл спрайт
    float CurrentFrame;//хранит текущий кадр
    std::string name;//враги могут быть разные, врагов можно различать по именам
    //каждому можно дать свое действие в update() в зависимости от имени
    Entity(Image &image, float X, float Y, int W, int H, std::string Name){
        x = X; y = Y; //координата появления спрайта
        w = W; h = H;
        name = Name;
        moveTimer = 0;
        dx = 0; dy = 0;
        speed = 0;
        CurrentFrame = 0;
        health = 100;
        life = true; //инициализировали логическую переменную жизни, герой жив
        texture.loadFromImage(image); //заносим наше изображение в текстуру
        sprite.setTexture(texture); //заливаем спрайт текстурой
    }
    FloatRect getRect(){//метод получения прямоугольника. его коорд, размеры (шир,высот).
        FloatRect FR(x, y, w, h); // переменная FR типа FloatRect
        return FR;
        //Тип данных (класс) "sf::FloatRect" позволяет хранить четыре координаты прямоугольника
        //в нашей игре это координаты текущего расположения тайла на карте
        //далее это позволит спросить, есть ли ещё какой-либо тайл на этом месте
        //эта ф-ция нужна для проверки пересечений
    }
    virtual void update(float time) = 0;
};

#endif // ENTITY

