#include "Model.hpp"

Model::Model()
{
    SDL_Log("[Model::Model] %p", this); //log - наблюдать, что экземпляр класса создан
}

Model::~Model()
{
    SDL_Log("[Model::~Model] %p", this); //log - наблюдать, что экземпляр класса удалён
}



SDL_AppResult Model::init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Could not init SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("week3_qt",
                                     480, 360,
                                     0,
                                     &this -> window, &this -> renderer))
    {
        SDL_Log("Could not create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult Model::onEvent(SDL_Event &event)
{
    switch (event.type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult Model::iterate()
{
    this->clearWindow();

    SDL_RenderPresent(this->renderer);

    return SDL_APP_CONTINUE;
}

void Model::clearWindow()
{
    SDL_SetRenderDrawColorFloat(this -> renderer,
                           0.5f,
                           0.5f,
                           0.5f,
                           SDL_ALPHA_OPAQUE_FLOAT);
    SDL_RenderClear (this->renderer);
}
