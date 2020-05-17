#include"fps.h"
#include"kamien.h"
#include<time.h>
#include<SDL.h>
void fps::start()
{
	fps_poczatek = clock();
}

void fps::koniec()
{
	fps_koniec = clock();
	roznica = fps_koniec - fps_poczatek;
	//               \|/ ilosc fpsow
	delay = (1000.0 / 60)-roznica;
	if (delay > 0)
	{
		SDL_Delay(delay);
	}
}