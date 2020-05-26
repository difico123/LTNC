#pragma once
#ifndef Base_Object_H_
#define Base_Object_H_
#include"CommonFunc.h"
#include<SDL_ttf.h>

class Common
{
public:
	Common();
	~Common();
	void Show(SDL_Surface* des);
	bool LoadImg(const char* file_name);

	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	int GetRect_x() const { return rect_.x; }
	int GetRect_y() const { return rect_.y; }
	SDL_Rect GetRect() { return rect_; }
protected:
	SDL_Rect rect_;
	SDL_Surface* p_object_;
};
#endif // !Base_Object_H_