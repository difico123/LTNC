#include"Commonfunc.h"
#include"MyCar.h"
#include"Threat.h"
#include"things.h"
#include"text.h"
#include<ctime>
#include<cstdlib>
#undef main

const int NUM_THREAT = 3;
TTF_Font* g_font_text = NULL;
SDL_Surface* background = NULL;

bool init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_DOUBLEBUF);
		if (g_screen == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
	}
	if (TTF_Init() < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	g_font_text = TTF_OpenFont("fac.ttf", 30);

	return success;
}
int main(int agv, char* argv[])
{
	srand(time(NULL));
	int Try = 0;
tryAgain:
	int bg_y		= 0;
	int NUM1		= 0;
	int NUM2		= 0;
	int CNT			= 0;
	int score		= 0;
	Try ++;
	bool Is_quit = false;
	if(	init() == false)
	{
		printf("Failed to initialize!\n");
		return 1;
    }
	
	// Background

	background = LoadImage("menu.jpg");
	if (background == NULL) printf("Failed to load pic!");
	if (Try == 1)
	{
		if (MessageBox(NULL, L"Are you want to play this game?", L"???", MB_YESNO |	MB_ICONQUESTION ) == IDYES)
		{
			ApplySurface(background, g_screen, 43, 100);
			SDL_Flip(g_screen);
			SDL_Delay(2000);
		}
		else return 0;
	}
	else
	{
		ApplySurface(background, g_screen, 43, 100);
		SDL_Flip(g_screen);
		SDL_Delay(2000);
	}
	
	g_background = LoadImage("duongduaf3.png");
	if (g_background == NULL) printf("Failed to load pic!");

	// MYCAR

	MyCar* mycar = new MyCar[2];
	bool checkIMG = mycar[0].LoadImg("main3.png");
	if (!checkIMG)
	{
		printf("Failed to load pic!");
	}
	else mycar[0].SetRect(100, 540);

	checkIMG = mycar[1].LoadImg("main2.png");
	if (!checkIMG)
	{
		printf("Failed to load pic!");
	}

	//Threat1

	Threat* threats = new Threat[NUM_THREAT];
	for (int i = 1; i < NUM_THREAT; i++)
	{
		Threat* threat = &threats[i];
		{
			checkIMG = threat->LoadImg("xe128.png");
			if (!checkIMG)
			{
				printf("Failed to load pic!");
			}
			threat->SetRect(SCREEN_WIDTH - (i + 1) * 300 - WIDTH_THREAT, -(i + 1) * 200);
		}
	}

	//Threat2

	checkIMG = threats[0].LoadImg("xedo.png");
	if (!checkIMG)
	{
		printf("Failed to load pic!");
	}
	threats[0].SetRect(200, -400);

	//thing

	//thing[0] gun
	things *thing = new things[2];
	thing[0].SetRect(300, -200);
	checkIMG = thing[0].LoadImg("sungbe.png");
	if (!checkIMG)
	{
		return 0;
	}
	//thing[1] immortality
	thing[1].SetRect(200, -400);
	checkIMG = thing[1].LoadImg("daulau.png");
	if (!checkIMG)
	{
		return 0;
	}

	//text
	//game_time1 score
	//game_time1 immortal time
	//game_time1 gun time
	Text* game_time = new Text[3];


	while (!Is_quit)
	{
		while (SDL_PollEvent(&g_event))
		{
			if (g_event.type == SDL_QUIT)
			{
				Is_quit = true;
				break;
			}
			mycar[0].Handle_Input(g_event);
			mycar[1].Handle_Input(g_event);
		}

		// bg

		bg_y += 20;
		ApplySurface(g_background, g_screen, 0, bg_y);
		ApplySurface(g_background, g_screen, 0, bg_y - SCREEN_HEIGHT);
		if (bg_y >= SCREEN_HEIGHT)
		{
			bg_y = 0;
		}
		
		//text

		CNT++;
		string str_score = "SCORE: ";
		int score = CNT;
		string str_val = to_string(score);
		str_score += str_val;
		game_time[0].SetText(str_score);
		game_time[0].CreateGameText(g_font_text, g_screen);
		game_time[0].SetRect(SCREEN_WIDTH - 350, 10);
		
		
		

		// MYCAR


		mycar[0].Show(g_screen);
		mycar[0].Handle_move();

		//mycar[0].set_is_fire(false);


		//Things

		for (int i = 0; i < 2; i++)
		{
			thing[i].HandleMove();
			thing[i].Show(g_screen);
			thing[i].set_y_val(2);
		}
	

		//Threat

		for (int i = 0; i < NUM_THREAT; i++)
		{
			Threat* threat = threats + i;
			{
				if (i == 0)
				{
					threat->set_y_val(6);
					threat->HandleMove(-500);
				}
				else
				{
					threat->set_y_val(3);
					threat->HandleMove(-200);
				}
				threat->Show(g_screen);
			}

			//check col bullet of my car and threats

			std::vector<Bullet*> amo_list = mycar[0].GetBullet();
			for (int j = 0; j < amo_list.size(); j++)
			{
				Bullet* bullet = amo_list.at(j);
				if (bullet != NULL)
				{
					bool check_col = CheckCollision(bullet->GetRect(), threat->GetRect());
					if (check_col)
					{
						threat->ReSet(-300);
						mycar[0].RemoveBullet(j);
					}
				}
			}
			// Immortality
			
			bool check_col;
			check_col = CheckCollision(mycar[0].GetRect(), thing[1].GetRect());
			{
				if (check_col)
				{
					thing[1].SetRect(mycar[0].GetRect_x() + WIDTH_MYCAR / 3 - 2, mycar[0].GetRect_y() + 15);
					thing[1].set_y_val(0);
					mycar[1].Show(g_screen);
					mycar[1].SetRect(mycar[0].GetRect_x(), mycar[0].GetRect_y());
					NUM2++;
					int cnt = NUM2 % 3000;
					string str_time = "IMT: ";
					string s_val = to_string((3000 - cnt)/250);
					str_time += s_val;
					game_time[1].SetText(str_time);
					game_time[1].CreateGameText(g_font_text, g_screen);
					game_time[1].SetRect( 110, 10);
					if (cnt == 0)
						thing[1].RemoveThings();
				}
				else
				{
					bool Is_col = CheckCollision(mycar[0].GetRect(), threat->GetRect());
					if (Is_col)
					{
						string myString = "High Core: ";
						myString += to_string(score-1);
						LPWSTR ws = new wchar_t[myString.size() + 1];
						copy(myString.begin(), myString.end(), ws);
						ws[myString.size()] = 0;
						if (MessageBox(NULL, ws,L"YOU DEAD", MB_OK) == IDOK)
						{
							if (MessageBox(NULL, L"Do you want to try this game againt?", L"???", MB_YESNO | MB_ICONQUESTION) == IDYES)
								goto tryAgain;
							else
							{
								delete[] threats;
								delete[] thing;
								delete[] mycar;
								delete[] game_time;
								CleanUp();
								SDL_Quit();
								return 1;
							}
						}
					}
				}
			}
		}
		//gun
		bool check_col = CheckCollision(thing[0].GetRect(), mycar[0].GetRect());
		if (!check_col) mycar[0].set_is_fire(false);
		else
		{
			mycar[0].set_is_fire(true);
			thing[0].SetRect(mycar[0].GetRect_x() + WIDTH_MYCAR / 3 - 2, mycar[0].GetRect_y() + 15);
			thing[0].set_y_val(0);
			NUM1++;
			int cnt = NUM1%1000;
			string str_time = "GUN: ";
			string s_val = to_string((1000-cnt)/ 100);
			str_time += s_val;
			game_time[2].SetText(str_time);
			game_time[2].CreateGameText(g_font_text, g_screen);
			game_time[2].SetRect(110, 40);
			mycar[0].MakeBullet(g_screen);
			if (cnt == 0)
			thing[0].RemoveThings();
		}
		
		if (SDL_Flip(g_screen) < 0)
			return 0;
	}
	delete[] threats;
	delete[] thing;
	delete[] mycar;
	delete[] game_time;

	CleanUp();
	SDL_Quit();
	return 1;
}