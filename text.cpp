#include"text.h"
Text::Text()
{
	text_ = "";
	text_color_ = { 0,0,0 };
}
Text::~Text()
{
	;
}
void Text::CreateGameText(TTF_Font* font, SDL_Surface* scr)
{
	p_object_ = TTF_RenderText_Solid(font, text_.c_str(), text_color_);
	Show(scr);
}