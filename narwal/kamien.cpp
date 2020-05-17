#include"kamien.h"
#include"Textura.h"
#include<SDL.h>
#include<SDL_image.h>
#include<vector>
#include<time.h>
#include<Windows.h>
#include<math.h>
#include<iostream>

float PI = 3.14;
textura tex;

kamien::kamien(int x,int y)
{
	posX = x;
	posY = y;

	
}
/*bool kamien::granica()
{
	bool przekroczona = false;

}*/

kamien::~kamien()
{
	tex.zwolnij();
}

void kamien::ladowanie(SDL_Renderer* Render)
{
	tex.laduj("Obrazki/kamix.png", Render);
	rect.x = 0;
	rect.y = 0;
	rect.w = 64;
	rect.h = 64;
}
void kamien::rysuj(SDL_Renderer* Render)
{

	SDL_Rect* clip =&rect;
	tex.render(posX, posY, clip, Render);
	
}


void kamien::move()
{

	if (posX <= -64)
	{
		posX = rand()%3000+1600;
		posY = rand() % 500 + 150;
	
	
	}

	else
	{
		posX = posX - predkosc;
	}
}

int kamien::getx()
{
	return posX;
}
int kamien::gety()
{
	return posY;
}

void kamien::zmienpredkosc()
{
	predkosc++;
}

void kamien::zmienX()
{
	posX = rand() % 2900 + 1600;
}

void kamien::zmienY()
{
	posY = rand() % 480 + 150;
}
