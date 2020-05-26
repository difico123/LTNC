#include"Threat.h"
#include"Commonfunc.h"

Threat::Threat()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;
	x_val_ = 0;
	y_val_ = 0;
}
Threat::~Threat()
{
	;
}

void Threat::HandleMove(int depth)
{
	rect_.y += y_val_;
	if (rect_.y > SCREEN_HEIGHT)
		this->ReSet(depth);
}

void Threat::ReSet(int depth)
{
	rect_.y = depth;
	int rand_x = rand() % (SCREEN_WIDTH - 200 - WIDTH_THREAT);
	if (rand_x > 100)
		rect_.x = rand_x ;
}
