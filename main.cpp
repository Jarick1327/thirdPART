#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = nullptr; //объект
static SDL_Renderer *renderer = nullptr; //Встроенный в SDL рендер

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
////initialize -
//**appstate - ссылка на ссылку, указатель на указатель
//argc - количество аргументов, argv - вектор сишных строк

//обработка ошибок при создании
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Could not initialize SDL: %s", SDL_GetError());
            return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("week3_qt",
                                     480, 360,
                                     0,
                                     &window, &renderer))
    {
        SDL_Log("Could not create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

//?
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event -> type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}
//event - событие

//отрисовка окна
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColorFloat(renderer,
                                0.7f,
                                0.5f,
                                1.0f,
                                SDL_ALPHA_OPAQUE_FLOAT); //цифры - RGB
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

//выход и удаление
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
