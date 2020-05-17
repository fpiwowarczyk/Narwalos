#include<SDL.h>
#include<vector>
#include<SDL_image.h>
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<string>
#include<SDL_ttf.h>
#include<sstream>
#include<SDL_mixer.h>

#include"fps.h"
#include"kamien.h"
#include"Textura.h"
#include"Bohater.h"
#include"Ryba.h"
#include"zycia.h"

//using namespace std;

	SDL_Window* okno = NULL;
	SDL_Renderer* Render = NULL;
	SDL_Surface* ekran = NULL;
	SDL_Surface* obraz_tlo;
	SDL_Surface* obraz_postac;
	SDL_Event zdarzenie;

	
//wielkosc obrazu
	int screenW = 1600;
	int screenH = 690;


	bohater narwal;
	std::vector<zycia> zycie;
	textura tlo;
	textura tlokoniec;
	SDL_Rect gtlo;
	SDL_Rect gtlokoniec;
	SDL_Rect tekst;
	SDL_Rect punktos;
	SDL_Rect lepunkty;
	std::vector<kamien> kamyki;
	std::vector<Ryba> ryby;
	Ryba r(1000, 500);

	// fonty 
	TTF_Font *gFont = NULL;

	
	textura gTextTexture;
	textura punkty;
	textura punkty1;
	textura punkty2;

	//muzyka

	Mix_Music *gMusic=NULL;
	Mix_Chunk *gScratch;



void losowaniek()
	{
		 int zx = 50;
		for (int i = 0; i < 10; i++)
		{
			int x = rand() % 3000 + 1600;
			int y = rand() % 500 + 150;
			kamien k(x, y);
			kamyki.push_back(k);
	
		}
			for (int i = 0; i < 5; i++)
		{
			int x = rand() % 3000 + 1600;
			int y = rand() % 500 + 150;
			Ryba k(x, y);
			ryby.push_back(k);

		}
			int z=narwal.getz();
			for (int i = 0; i < z; i++)
			{
				int y = 30;
				zycia z(zx, y);
				zx = zx + 50;
				zycie.push_back(z);
				
			}
			

	}
void init()
	{
	
	
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		okno = SDL_CreateWindow("Narwale", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_SHOWN);//SDL_WINDOW_FULLSCREEN_DESKTOP
		Render = SDL_CreateRenderer(okno, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawColor(Render, 0xFF, 0xFF, 0xFF, 0xFF);
		int imgFlags = IMG_INIT_PNG;
		TTF_Init();
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	

	}
void ladowanie()
{


	//ladownaie reszty

	losowaniek();
	tlo.laduj("Obrazki/Tlov3.png",Render);
	tlokoniec.laduj("Obrazki/koniec.png", Render);
	for (int i = 0; i < kamyki.size(); i++)
	{
		kamyki[i].ladowanie(Render);
	}
	for (int i = 0; i < ryby.size(); i++)
	{
		ryby[i].ladowanie(Render);
	}
	for (int i = 0; i < zycie.size(); i++)
	{
		zycie[i].ladowanie(Render);
	}
	r.ladowanie(Render);
	narwal.ladowanie(Render);

	
	gtlo.x=0;
	gtlo.y=0;
	gtlo.w=screenW;
	gtlo.h=screenH;

	gtlokoniec.x = 0;
	gtlokoniec.y = 0;
	gtlokoniec.w = screenW;
	gtlokoniec.h = screenH;

	//muzyka

	gMusic = Mix_LoadMUS("Muzyka/Muzyka1.mp3");
	//gMusic = Mix_LoadMUS("Muzyka/Muzyka2.mp3");
	if (!gMusic) {
		printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
		// this might be a critical error...
	}
//	gScratch = Mix_LoadWAV("Muzyka/Skyrim Theme Song - Full (Dovahkiin Song).wav");
}
void ladowaniet(int p)
{
	if (p < 10)
	{
		std::string plus = "00000";
		int i = p;
		std::ostringstream ss;
		ss << i;
		std::string str = ss.str();
		str = plus + str;

		//ladowanie trzcionki
		gFont = TTF_OpenFont("Trzcionka/Bobblebod.ttf", 72);

		SDL_Color textColor = { 1, 0, 0 };
		gTextTexture.loadFromRenderedText("POINTS", textColor, gFont, Render);

		//punkty1.loadFromRenderedText("00000", textColor, gFont, Render);
		punkty.loadFromRenderedText(str, textColor, gFont, Render);
		punkty1.loadFromRenderedText(str, textColor, gFont, Render);

		tekst.x = 0;
		tekst.y = 0;
		tekst.w = 256;
		tekst.h = 52;

		punktos.x = 0;
		punktos.y = 0;
		punktos.w = 300;
		punktos.h = 64;


		lepunkty.x = 0;
		lepunkty.y = 0;
		lepunkty.w = 200;
		lepunkty.h = 64;
	}
	else if (p < 100)
	{
		std::string plus = "0000";
		int i = p;
		std::ostringstream ss;
		ss << i;
		std::string str = ss.str();
		str = plus + str;

		//ladowanie trzcionki
		gFont = TTF_OpenFont("Trzcionka/Bobblebod.ttf", 72);

		SDL_Color textColor = { 0, 0, 0 };
		gTextTexture.loadFromRenderedText("POINTS", textColor, gFont, Render);

		//punkty1.loadFromRenderedText("00000", textColor, gFont, Render);
		punkty.loadFromRenderedText(str, textColor, gFont, Render);
		punkty1.loadFromRenderedText(str, textColor, gFont, Render);

		tekst.x = 0;
		tekst.y = 0;
		tekst.w = 256;
		tekst.h = 52;

		punktos.x = 0;
		punktos.y = 0;
		punktos.w = 300;
		punktos.h = 64;


		lepunkty.x = 0;
		lepunkty.y = 0;
		lepunkty.w = 200;
		lepunkty.h = 64;
	}
	else if (p < 1000)
	{
		std::string plus = "000";
		int i = p;
		std::ostringstream ss;
		ss << i;
		std::string str = ss.str();
		str = plus + str;

		//ladowanie trzcionki
		gFont = TTF_OpenFont("Trzcionka/Bobblebod.ttf", 72);

		SDL_Color textColor = { 0, 0, 0 };
		gTextTexture.loadFromRenderedText("POINTS", textColor, gFont, Render);

		//punkty1.loadFromRenderedText("00000", textColor, gFont, Render);
		punkty.loadFromRenderedText(str, textColor, gFont, Render);
		punkty1.loadFromRenderedText(str, textColor, gFont, Render);

		tekst.x = 0;
		tekst.y = 0;
		tekst.w = 256;
		tekst.h = 52;

		punktos.x = 0;
		punktos.y = 0;
		punktos.w = 300;
		punktos.h = 64;


		lepunkty.x = 0;
		lepunkty.y = 0;
		lepunkty.w = 200;
		lepunkty.h = 64;
	}
}
void close()
{
	//Free loaded images
	//gSpriteSheetTexture.zwolnij();
	Mix_FreeChunk(gScratch);
	Mix_FreeMusic(gMusic);
	gMusic = NULL;
	tlo.zwolnij();
	//Free loaded images
	gTextTexture.zwolnij();

	//Free global font
	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window	
	SDL_DestroyRenderer(Render);
	SDL_DestroyWindow(okno);
	okno = NULL;
	Render = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}
int main(int argc, char* args[])
{
	//std::string cos="123";
	//std::string cos1 = "000";
	//std::cout << cos1+cos;
	bool udalosie = 0;
	bool udalosie1 = 0;
	int prog = 0;
	fps fps;
	init();	

	ladowanie();
	int klatki_plywania = 8;
	bool quit = false;
	int frame = 0;
	int scena = 0;
	while(scena == 0)
	{
		Mix_PlayMusic(gMusic, -1);
		while (!quit)
		{

			while (SDL_PollEvent(&zdarzenie) != 0)
			{
				if (zdarzenie.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			SDL_SetRenderDrawColor(Render, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(Render);

			//SDL_Rect* currentClip = &gSpriteClips[frame / 4];
			SDL_Rect* clip = &gtlo;
			tlo.render(0, 0, clip, Render);

			//gSpriteSheetTexture.render(/*(screenW - currentClip->w) / 2*/posX, /*(screenH - currentClip->h) / 2*/posY, currentClip, Render);
			int p = narwal.getP();
			ladowaniet(p);
			SDL_Rect* clipix = &tekst;
			gTextTexture.render(1300,0,clipix,Render);

			SDL_Rect* clips = &punktos;
			SDL_Rect* leclip = &lepunkty;
			punkty.render(screenW-300, 50, clips, Render);
			//punkty1.render(1300, 50, leclip, Render);
			narwal.rysuj(Render, frame);
			narwal.poruszanie();


			for (int i = 0; i < kamyki.size(); i++)
			{
				kamyki[i].rysuj(Render);
				kamyki[i].move();
				int POZX = kamyki[i].getx();
				int POZY = kamyki[i].gety();
				udalosie1=narwal.kolizja(POZX,POZY);
				if (udalosie1 == 1)
				{
				
					kamyki[i].zmienX();
					kamyki[i].zmienY();
				
				}
			

			}
			int z = narwal.getz();
			for (int i = 0; i < z; i++)
			{
				zycie[i].rysuj(Render);
			}




			for (int i = 0; i < ryby.size(); i++)
			{
				ryby[i].rysuj(Render);
				ryby[i].move();
				int POZX = ryby[i].getx();
				int POZY = ryby[i].gety();
				 udalosie=narwal.kolizjaryba( POZX, POZY);
				if (udalosie ==1)
				{
					ryby[i].zmienX();
					ryby[i].zmienY();
				}
				
			}
			int punkty=narwal.getP();
			if (punkty > prog)
			{
				for (int i = 0; i < kamyki.size(); i++)
				{
					kamyki[i].zmienpredkosc();

				}
				prog = prog + 5;
			}
			if (z < 0)
			{
				ladowaniet(p);
				SDL_Rect* clip = &gtlokoniec;
				tlokoniec.render(0, 0, clip, Render);
				int p = narwal.getP();
				ladowaniet(p);
				SDL_Rect* clipix = &tekst;
				gTextTexture.render(700, 400, clipix, Render);

				SDL_Rect* clips = &punktos;
				punkty1.render(700, 450, clips, Render);
			
			}
			SDL_RenderPresent(Render);

			++frame;
			if (frame/4  >= klatki_plywania)
			{
				frame = 0;
			}
		}



		close();

		return 0;
	}
	while (scena == 1)
	{


	
		while (!quit)
		{

		while (SDL_PollEvent(&zdarzenie) != 0)
		{
			if (zdarzenie.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		Mix_PlayMusic(gMusic, -1);
	
		SDL_SetRenderDrawColor(Render, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(Render);
		int p = narwal.getP();
		ladowaniet(p);
		SDL_Rect* clipix = &tekst;
		gTextTexture.render(1300, 0, clipix, Render);

		SDL_Rect* clips = &punktos;
		SDL_Rect* leclip = &lepunkty;
		punkty.render(screenW - 300, 50, clips, Render);
		SDL_Rect* clip = &gtlokoniec;
		tlokoniec.render(0, 0, clip, Render);
		

		}

		close();

		return 0;
	
	}
}

