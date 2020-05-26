#include"MyCar.h"
MyCar::MyCar()
{
	x_ = 0;
	y_ = 0;
	rect_.w = WIDTH_MYCAR;
	rect_.h = HEIGHT_MYCAR;
	rect_.x = 0;
	rect_.y = 0;
	is_fire_ = false;
}
MyCar::~MyCar()
{
	;
}

void MyCar:: Handle_Input(SDL_Event ev)
{
	if (ev.type == SDL_KEYDOWN)
	{
		switch (ev.key.keysym.sym)
		{
		case SDLK_RIGHT:
			x_ += WIDTH_MYCAR / 15;
			break;
		case SDLK_LEFT:
			x_ -= WIDTH_MYCAR / 15;
			break;
		}
	}
	else if (ev.type == SDL_KEYUP)
	{
		switch (ev.key.keysym.sym)
		{
		case SDLK_RIGHT:
			x_ -= WIDTH_MYCAR / 15;
			break;
		case SDLK_LEFT:
			x_ += WIDTH_MYCAR / 15;
			break;
		}
	}
	else if (ev.type == SDL_MOUSEBUTTONDOWN)
	{
		if (get_is_fire())
		{
			Bullet* bullet = new Bullet();									// tao ra 1 vien dan
			if (ev.button.button == SDL_BUTTON_LEFT)
			{
				//p_amo->SetWidthHeight(WIDTH_BULLET, HEIGHT_BULLET);
				bullet->LoadImg("dan.png");
			}
			bullet->SetRect(this->rect_.x + WIDTH_MYCAR / 3 - 2, this->rect_.y + 15);
			bullet->set_is_move(true);			//bam chuot == true <=> ban
			bullet->set_x_val(20);
			bullet_.push_back(bullet);			//them dan
		}
	}
}
void MyCar::Handle_move()
{
	rect_.x += x_;
	if (rect_.x < 100 || rect_.x + WIDTH_MYCAR>SCREEN_WIDTH - 220)
	{
		rect_.x -= x_;
	}
}
void MyCar::RemoveBullet(const int& p)
{
	for (int i = 0; i < bullet_.size(); i++)
	{
		//Bullet* bullet = bullet_.at(p);
		bullet_.erase(bullet_.begin() + p);
		/*if (bullet != NULL)
		{
			delete bullet;
			bullet = NULL;
		}*/
	}
}
void MyCar::MakeBullet(SDL_Surface* scr)
{
	for (int i = 0; i < bullet_.size(); i++)
	{
		Bullet* bullet = bullet_.at(i);
		if (bullet != NULL)
		{
			if (bullet->get_is_move())
			{
				bullet->HandleMove();
				bullet->Show(scr);
			}
			else
			{
				if (bullet != NULL)
				{
					bullet_.erase(bullet_.begin() + i);
					delete bullet;
					bullet = NULL;
				}
			}
		}
	}
}