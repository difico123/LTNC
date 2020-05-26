#pragma once
#ifndef text_h_
#define text_h_
#include"CommonClass.h"

class Text : public Common
{
public:
	Text();
	~Text();
	void SetText(string& text) { text_ = text; }
	void CreateGameText(TTF_Font* font, SDL_Surface* scr);
private:
	string text_;
	SDL_Color text_color_;
};
#endif // !text_h_
