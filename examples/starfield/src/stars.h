#include <SDL2/SDL.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "proteus.h"

uint16_t WIDTH;
uint16_t HEIGHT;
#define DOTS 1500

typedef struct
{
    float x, y, z;
} Dot;

Dot dots[DOTS];
float angle = 0.0f;
float camera = 0.0005f;

void initDots()
{
    for (int i = 0; i < DOTS; i++)
    {
        dots[i].x = (float)(rand() % 1000 - 500);
        dots[i].y = (float)(rand() % 1000 - 500);
        dots[i].z = (float)(rand() % 255);
    }
}

void updateDots()
{
    angle -= 0.004f;
    camera = 80.03;

    for (int i = 0; i < DOTS; i++)
    {
        dots[i].z -= 0.5f;
        if (dots[i].z < 1)
        {
            dots[i].x = (float)(rand() % 1000 - 500);
            dots[i].y = (float)(rand() % 1000 - 500);
            dots[i].z = (float)(rand() % 255);
        }
    }
}

void renderDots(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < DOTS; i++)
    {
        uint8_t r = 255 - dots[i].z;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        float x = dots[i].x * cos(angle) - dots[i].y * sin(angle);
        float y = dots[i].x * sin(angle) + dots[i].y * cos(angle);
        float scale = camera / dots[i].z;
        int screenX = (int)(WIDTH / 2 + x * scale);
        int screenY = (int)(HEIGHT / 2 + y * scale);
        if (screenX > 0 && screenX < WIDTH && screenY > 0 && screenY < HEIGHT)
            SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    updateDots();

    for (int i = 0; i < DOTS; i++)
    {
        uint8_t r = 255 - dots[i].z;
        SDL_SetRenderDrawColor(renderer, r, r, r, 255);
        float x = dots[i].x * cos(angle) - dots[i].y * sin(angle);
        float y = dots[i].x * sin(angle) + dots[i].y * cos(angle);
        float scale = camera / dots[i].z;
        int screenX = (int)(WIDTH / 2 + x * scale);
        int screenY = (int)(HEIGHT / 2 + y * scale);
        if (screenX > 0 && screenX < WIDTH && screenY > 0 && screenY < HEIGHT)
            SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    SDL_RenderPresent(renderer);
}

void stars_main(uint16_t szer, uint16_t wys)
{
    HEIGHT = wys;
    WIDTH = szer;
    initDots();

    while (appRun())
    {
        renderDots(renderer);
        delay(16);
    }
}