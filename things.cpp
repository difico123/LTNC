#include"things.h"
#include<cmath>
things::things()
{
	y_val_ = 0;
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT;
	rect_.w = WIDTH_THING;
	rect_.h = HEIGHT_THING;
}
things::~things()
{
	;
}

void things::HandleMove()
{
	rect_.y += y_val_;
	if (rect_.y > SCREEN_HEIGHT)
	{
		rect_.y = -300;
		int rand_x = rand() % (SCREEN_WIDTH - 220 - WIDTH_THING);
		if (rand_x > 100)
			rect_.x = rand_x;
	}
}
void things::RemoveThings()
{
	rect_.y = -2000;
	int rand_x = rand() % (SCREEN_WIDTH - 220 - WIDTH_THING);
	if (rand_x > 100)
		rect_.x = rand_x;
}
