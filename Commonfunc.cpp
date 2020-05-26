#include"Commonfunc.h"

void CleanUp()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_background);
}

void ApplySurface(SDL_Surface* img, SDL_Surface* scr, int xx, int yy)
{
	SDL_Rect coordinates;
	coordinates.x = xx;
	coordinates.y = yy;
	SDL_BlitSurface(img, NULL, scr, &coordinates);
}

SDL_Surface* LoadImage(string path)
{
	SDL_Surface* loadimage = NULL;
	SDL_Surface* optimize_image = NULL;
	loadimage = IMG_Load(path.c_str());
	{
		if (loadimage != NULL)
		{
			optimize_image = SDL_DisplayFormat(loadimage);
			SDL_FreeSurface(loadimage);
			if (optimize_image != NULL)
			{
				UINT32 color_key = SDL_MapRGB(optimize_image->format, 128, 128, 128);
				SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
			}
		}
	}
	return optimize_image;
}
bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x + 3;
    int right_a = object1.x + object1.w - 6;
    int top_a = object1.y + 3;
    int bottom_a = object1.y + object1.h - 6;

    int left_b = object2.x + 3;
    int right_b = object2.x + object2.w - 6;
    int top_b = object2.y + 3;
    int bottom_b = object2.y + object2.h - 6;

    // Case 1: size object 1 < size object 2
    if (left_a >= left_b && left_a <= right_b)
    {
        if (top_a >= top_b && top_a <= bottom_b)
        {
            return true;
        }
    }

    if (left_a >= left_b && left_a <= right_b)
    {
        if (bottom_a >= top_b && bottom_a <= bottom_b)
        {
            return true;
        }
    }

    if (right_a >= left_b && right_a <= right_b)
    {
        if (top_a >= top_b && top_a <= bottom_b)
        {
            return true;
        }
    }

    if (right_a >= left_b && right_a <= right_b)
    {
        if (bottom_a >= top_b && bottom_a <= bottom_b)
        {
            return true;
        }
    }

    // Case 2: size object 1 < size object 2
    if (left_b >= left_a && left_b <= right_a)
    {
        if (top_b >= top_a && top_b <= bottom_a)
        {
            return true;
        }
    }
    if (left_b >= left_a && left_b <= right_a)
    {
        if (bottom_b >= top_a && bottom_b <= bottom_a)
        {
            return true;
        }
    }

    if (right_b >= left_a && right_b <= right_a)
    {
        if (top_b >= top_a && top_b <= bottom_a)
        {
            return true;
        }
    }

    if (right_b >= left_a && right_b <= right_a)
    {
        if (bottom_b >= top_a && bottom_b <= bottom_a)
        {
            return true;
        }
    }
    return false;
}
