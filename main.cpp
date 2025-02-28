#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL_main.h>

#include "Model.hpp" //подключили файл заголовка

//4 функции обязательно, их реализацию менять
SDL_AppResult SDL_AppInit( void **appstate, int argc, char *argv[] )
{
    //auto -когда мы объявляем переменную, компиллятор сам может выводить её тип
    auto app = new Model; //используя тип результата в правой части

    //разыменование (что лежит по адресу) appstate
    *appstate = static_cast<void*>(app);
    //размер указателя фиксирован и зависит от платформы -
    //в 64-битной 8-битный указатель

    //FAILURE - мы не можем продолжить работу
    return app -> init();
}
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
//указатель на объект события
{
    auto app = static_cast<Model*>(appstate);

    if (app && event)
    {
        return app->onEvent(*event);
    }

    return SDL_APP_FAILURE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    auto app = static_cast<Model*>(appstate);
    if (app)
    {
        return app->iterate();
    }

    return SDL_APP_FAILURE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    auto app = static_cast<Model*>(appstate);
    //если безликий указатель заполнен, то удалить его
    if (app)
    {
        delete app;
    }
}
