#pragma once
#ifndef Mycar
#define Mycar
#include"Commonfunc.h"
#include"CommonClass.h"
#include"Bullet.h"

#define WIDTH_MYCAR 50
#define HEIGHT_MYCAR 104

class MyCar : public Common
{
public:
	MyCar();
	~MyCar();

	void Handle_Input(SDL_Event ev);
	void Handle_move();

	void set_is_fire(bool is_fire) { is_fire_ = is_fire; }
	bool get_is_fire()const { return is_fire_; }

	/*int GetRect_y() const { return rect_.y; }
	int GetRect_x() const { return rect_.x; }*/

	void SetBullet(std::vector<Bullet*> bullet) { bullet_ = bullet; }
	std::vector<Bullet*>GetBullet() const { return bullet_; }

	void MakeBullet(SDL_Surface* scr);
	void RemoveBullet(const int& p); // xoa vien dan thu p dc ban

private:
	int x_;
	int y_;
	bool is_fire_;
	vector<Bullet*> bullet_;
};
#endif // !Mycar
