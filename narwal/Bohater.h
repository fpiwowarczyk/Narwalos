#ifndef BOHATER_H
#define BOHATER_H
//#include"Textura.h"
#include<SDL.h>
#include<time.h>
class bohater
{
public: 
	bohater();
	~bohater();
	void ladowanie(SDL_Renderer* Render);
	void poruszanie();
	void rysuj(SDL_Renderer* Render, int frame);
	int miara();
	bool kolizja(int x, int y);
	bool kolizjaryba(int x, int y);
	int getz();
	int getP();
private:
	int frame = 0;
	const Uint8 * state = SDL_GetKeyboardState(NULL);
	const int klatki_plywania = 8;
	SDL_Rect gSpriteClips[8];
	textura gSpriteSheetTexture;
	int posX=1000, posY=200;
	int koniec =0;
	int start=0;
	int zycie = 3;
	int punkty = 0;
};

#endif