#include"Textura.h"
#include"Bohater.h"
#include"zycia.h"
#include"kamien.h"
#include<time.h>
#include<iostream>
bohater::bohater()
{
	
}

bohater::~bohater()
{
	gSpriteSheetTexture.zwolnij();
}

void bohater::ladowanie(SDL_Renderer* Render)
{
	gSpriteSheetTexture.laduj("Obrazki/animowanyboh.png", Render);
	gSpriteClips[0].x = 0;
	gSpriteClips[0].y = 0;
	gSpriteClips[0].w = 128;
	gSpriteClips[0].h = 64;

	gSpriteClips[1].x = 0;
	gSpriteClips[1].y = 64;
	gSpriteClips[1].w = 128;
	gSpriteClips[1].h = 64;

	gSpriteClips[2].x = 0;
	gSpriteClips[2].y = 128;
	gSpriteClips[2].w = 128;
	gSpriteClips[2].h = 64;

	gSpriteClips[3].x = 0;
	gSpriteClips[3].y = 196;
	gSpriteClips[3].w = 128;
	gSpriteClips[3].h = 64;

	gSpriteClips[4].x = 0;
	gSpriteClips[4].y = 256;
	gSpriteClips[4].w = 128;
	gSpriteClips[4].h = 64;

	gSpriteClips[5].x = 0;
	gSpriteClips[5].y = 320;
	gSpriteClips[5].w = 128;
	gSpriteClips[5].h = 64;

	gSpriteClips[6].x = 0;
	gSpriteClips[6].y = 384;
	gSpriteClips[6].w = 128;
	gSpriteClips[6].h = 64;

	gSpriteClips[7].x = 0;
	gSpriteClips[7].y = 448;
	gSpriteClips[7].w = 128;
	gSpriteClips[7].h = 64;
}

void bohater::poruszanie()
{

	if (posX < 0)
	{
		posX = posX + 1;
	}
	else
	{
		if (posY > 600)
		{
			posY = posY - 5;
		}
		else{
			if (posY < 150)
			{
				posY = posY + 5;
			}
			else
			{
				if (posX > 1500)
				{
					posX = posX - 5;
				}
				else
				{

					if (state[SDL_SCANCODE_S])
					{
						posY = posY + 5;
					}
					if (state[SDL_SCANCODE_W])
					{
						posY = posY - 5;
					}
					if (state[SDL_SCANCODE_A])
					{
						posX = posX - 5;
					}
					if (state[SDL_SCANCODE_D])
					{
						posX = posX + 5;
					}
					if (state[SDL_SCANCODE_E])
					{
						if (start==0)
						{
							posX = posX + 50;
						
						}
						else
						{
							posX = posX;
						}
					
						}
					if (state[SDL_SCANCODE_Q])
					{
						posX = posX - 50;
					}
					if (state[SDL_SCANCODE_P])
					{
						SDL_Delay(10000000000);
					}
					}
				}
			}
		}
	}

bool bohater::kolizja(int x,int y)
{

	if ((posX+64) > x)
	{
		x = sqrt(posX*posX - x*x);
	}
	else
	{
		x = sqrt(x*x - posX*posX);
	}
	if ((posY + 32) > y)
	{
		y = sqrt(posY*posY - y*y);
	}
	else
	{
		y = sqrt(y*y - posY*posY);
	}
	if (x < 100 && y < 100)
	{
		zycie--;
		
	
		return 1;
	}
	else
	{
		return 0;
	}
}


bool bohater::kolizjaryba(int x, int y)
{
	if ((posX + 64) > x)
	{
		x = sqrt(posX*posX - x*x);
	}
	else
	{
		x = sqrt(x*x - posX*posX);
	}
	if ((posY + 32) > y)
	{
		y = sqrt(posY*posY - y*y);
	}
	else
	{
		y = sqrt(y*y - posY*posY);
	}
	if (x < 100 && y<100)
	{
		punkty=punkty+1;
		return 1;

	}
	else
	{
		return 0;
	}
}


int bohater::miara()
{
	return start = clock();
}


void bohater::rysuj(SDL_Renderer* Render, int frame)
{
	SDL_Rect* currentClip = &gSpriteClips[frame / 4];
	gSpriteSheetTexture.render(/*(screenW - currentClip->w) / 2*/posX, /*(screenH - currentClip->h) / 2*/posY, currentClip, Render);
}


int bohater::getz()
{
	return zycie;
}

int bohater::getP()
{
	return punkty;
}