#ifndef KAMIEN_H
#define KAMIEN_H
#include<SDL.h>
#include<SDL_image.h>
//#include"Textura.h"
class kamien
{
public:
	kamien(int x,int y);
	~kamien();
	void rysuj(SDL_Renderer* Render);
	void ladowanie(SDL_Renderer* Render);
	void move();
	//void Reset();
	void Aktualizuj(int czas_aktualny);
	int getx();
	int gety();
	bool granica();
	void zmienpredkosc();
	void zmienX();
	void zmienY();
private:
	int czas;
	int posX, posY, W, H;
	int predkosc = 1;
	SDL_Rect rect;
	SDL_Surface* kamix;
	float v;
	float alfa_v;
	float alfa_g;
};
#endif