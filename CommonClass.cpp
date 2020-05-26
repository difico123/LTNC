#include"CommonClass.h"
#include"Commonfunc.h"

Common::Common()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
	p_object_ = NULL;
}
Common::~Common()
{
	if (p_object_ != NULL)
	{
		SDL_FreeSurface(p_object_);
	}
}
bool Common::LoadImg(const char* file_name)
{
	p_object_ = LoadImage(file_name);
	if (p_object_ == NULL)
		return false;
	return true;
}

void Common::Show(SDL_Surface* des)
{
	if (p_object_ != NULL)
	{
		ApplySurface(p_object_, des, rect_.x, rect_.y);
	}
}