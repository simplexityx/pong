#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include "res.h"

SDL_SETUP_T get_Setup(int w, int h){

	SDL_SETUP_T setup;

	setup.win = SDL_CreateWindow("hello, SDL!",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								w,h,0);
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	setup.rend = SDL_CreateRenderer(setup.win, -1, render_flags);
	
	return setup;
}


ball_t create_ball(SDL_Renderer *rend, char *filepath){


	ball_t ball;
	ball.surface = IMG_Load(filepath);


	ball.rect.x = 400;
	ball.rect.y = 200;
	ball.xpos = ball.rect.x;
	ball.ypos = ball.rect.y; 
	ball.tex = SDL_CreateTextureFromSurface(rend, ball.surface);
	
	
	SDL_QueryTexture(ball.tex, NULL, NULL, &ball.rect.w, &ball.rect.h);
	return ball;
}

gameobject_t create_gameObject(SDL_Renderer *rend, char *filepath, int x, int y){

	gameobject_t object;
	object.surface =  IMG_Load(filepath);
	object.rect.w /= 4;
	object.rect.h /= 4;
	object.rect.x = x;
	object.rect.y = y;
	object.xpos = object.rect.x;
	object.ypos = object.rect.y; 
	object.tex = SDL_CreateTextureFromSurface(rend, object.surface);
	
	object.up = 0;
	object.down = 0;
	object.left = 0;
	object.right = 0;

	SDL_QueryTexture(object.tex, NULL, NULL, &object.rect.w, &object.rect.h);
	

	return object;
}
