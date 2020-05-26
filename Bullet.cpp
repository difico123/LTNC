#include"Bullet.h"
Bullet::Bullet()
{
	rect_.x = 0;
	rect_.y = 0;
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = false;
	rect_.h = HEIGHT_BULLET;
	rect_.w = WIDTH_BULLET;
}
Bullet::~Bullet()
{
	;
}
void Bullet::HandleMove()
{
	rect_.y -= x_val_;
	if (rect_.y < 0)
	{
		is_move_ = false;
	}
}
