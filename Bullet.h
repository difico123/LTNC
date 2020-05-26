#pragma once
#ifndef bullet_h
#define bullet_h

#include"CommonClass.h"

#define WIDTH_BULLET 15
#define HEIGHT_BULLET 15

class Bullet : public Common
{
public:
	Bullet();
	~Bullet();

	void HandleMove();


	bool get_is_move() const { return is_move_; }
	void set_is_move(bool is_move) { is_move_ = is_move; }
	//void SetWidthHeight(const int& width, const int& height) { rect_.w = width; rect_.h = height; };

	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }

	int get_x_val() const { return x_val_; }
	int get_y_val() const { return y_val_; }

private:
	int x_val_;
	int y_val_;
	bool is_move_;
};
#endif // !bullet_h
