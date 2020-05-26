#pragma once
#ifndef Things_h
#define Things_h

#include"CommonClass.h"

const int WIDTH_THING = 25;
const int HEIGHT_THING = 33;
class things : public Common
{
public:
	things();
	~things();
	void HandleMove();
	void RemoveThings();
	void set_y_val(const int& val) { y_val_ = val; }
private:
	int y_val_;
};
#endif // !things_h

