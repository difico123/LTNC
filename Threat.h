#pragma once
#ifndef THREATS_OBJECT_H_
#define THEATS_OBJECT_H_

#include"CommonClass.h"
#include"CommonFunc.h"
#include<vector>

#define WIDTH_THREAT 40
#define HEIGHT_THREAT 80


class Threat : public Common
{
public:
	Threat();
	~Threat();

	void HandleMove(int p);

	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }
	void ReSet(int depth);
private:
	int x_val_;
	int y_val_;
};
#endif // !THREAT
