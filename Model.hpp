#pragma once

#include <SDL3/SDL.h>

class Model
{
    //private-секция
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

public:
    Model(); //конструктор класса
    ~Model(); //деструктор класса

    //первичные методы
    SDL_AppResult init();
    SDL_AppResult onEvent(SDL_Event &event); //метод-обработчик событий
    SDL_AppResult iterate(); //метод итерации

//"внутренняя кухня", вторичные
protected:
    void clearWindow();
};
