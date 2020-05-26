#pragma once
#ifndef comonfunc
#define comonfunc
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<Windows.h>
#include<stdio.h>
#include<vector>
using namespace std;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 650;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_background = NULL;
static SDL_Event g_event;

SDL_Surface* LoadImage(string filepath);
void CleanUp();
void ApplySurface(SDL_Surface* img, SDL_Surface* scr, int x, int y);
bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
#endif // !comonfunc
