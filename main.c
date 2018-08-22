#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <math.h>
#include "res.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define SPEED 200



int main(){

	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

	SDL_SETUP_T setup = get_Setup(WINDOW_WIDTH, WINDOW_HEIGHT);

	int score_player_1 = 0;
	int score_player_2 = 0;
	printf("hello git test");


	gameobject_t player = create_gameObject(setup.rend, "resources/pong1.png", 100, 200);
	gameobject_t player2 = create_gameObject(setup.rend, "resources/pong2.png", 500, 200);

	ball_t ball = create_ball(setup.rend, "resources/ball.png");

	player.xvel = player.yvel = 0;
	player2.xvel = player2.yvel = 0;
	ball.xvel = 200;
	ball.yvel = 200;
	int running = 1;
	int up2 = 0, down2 = 0;
	int up = 0, down= 0, left = 0, right = 0;
	while((running)){
		
		
		SDL_Event event;

		while(SDL_PollEvent(&event)){

			switch(event.type){
				case SDL_QUIT:
					running = 0;
					break;

				case SDL_KEYDOWN:

					switch(event.key.keysym.scancode){

						case SDL_SCANCODE_UP:
						
							up2 = 1;
							break;

						case SDL_SCANCODE_DOWN:
							down2 = 1;
							break;
						

						case SDL_SCANCODE_W:
							up = 1;
							break;

						case SDL_SCANCODE_S:
							down = 1;
							break;
						case SDL_SCANCODE_D:
							right = 1;
							break;
						case SDL_SCANCODE_A:
							left = 1;
							break;
					}
					break;

				case SDL_KEYUP:
					switch(event.key.keysym.scancode){

						case SDL_SCANCODE_UP:
							up2 = 0;
							break;

						case SDL_SCANCODE_DOWN:
							down2 = 0;
							break;
						

						case SDL_SCANCODE_W:
							up = 0;
							break;

						case SDL_SCANCODE_S:
							down = 0;
							break;
						case SDL_SCANCODE_D:
							right = 0;
							break;
						case SDL_SCANCODE_A:
							left = 0;
							break;
					}
					break;		
			}
		}

		player.yvel = player.xvel = 0;

		if(up && !down)
			player.yvel -= SPEED;
		if(!up && down)
			player.yvel += SPEED;
		/*if(left && !right)
			player.xvel -= SPEED;
		if(!left && right)
			player.xvel += SPEED;*/
		player.xpos += player.xvel / 60;
		player.ypos += player.yvel / 60;
		

		
	
		if(player.xpos <= 0)
			player.xpos = 0;
		if(player.xpos > (WINDOW_WIDTH - player.rect.w))
			player.xpos = (WINDOW_WIDTH - player.rect.w);

		if(player.ypos <= 0)
			player.ypos = 0;
		if(player.ypos > (WINDOW_HEIGHT - player.rect.h))
			player.ypos = (WINDOW_HEIGHT - player.rect.h);
		
		
		player.rect.x = (int)player.xpos;
		player.rect.y = (int)player.ypos;
		



		player2.yvel = player2.xvel = 0;

		if(up2 && !down2)
			player2.yvel -= SPEED;
		if(!up2 && down2)
			player2.yvel += SPEED;
		
		player2.xpos += player2.xvel / 60;
		player2.ypos += player2.yvel / 60;
		

		
	
		if(player2.xpos <= 0)
			player2.xpos = 0;
		if(player2.xpos > (WINDOW_WIDTH - player2.rect.w))
			player2.xpos = (WINDOW_WIDTH - player2.rect.w);

		if(player2.ypos <= 0)
			player2.ypos = 0;
		if(player2.ypos > (WINDOW_HEIGHT - player2.rect.h))
			player2.ypos = (WINDOW_HEIGHT - player2.rect.h);
		
		
		player2.rect.x = (int)player2.xpos;
		player2.rect.y = (int)player2.ypos;
		
		

		if((ball.xpos < 0) || (ball.xpos > WINDOW_WIDTH-ball.rect.w))
			ball.xvel*=-1;
		if((ball.ypos < 0) || (ball.ypos > WINDOW_HEIGHT-ball.rect.h))
			ball.yvel *=-1;

		if(SDL_HasIntersection(&player.rect, &ball.rect) == 1){

			ball.xvel *=-1;
		}else if(SDL_HasIntersection(&player2.rect, &ball.rect) == 1){
			ball.xvel *=-1; 
		}

		ball.xpos += ball.xvel / 60;
		ball.ypos += ball.yvel / 60;




		ball.rect.x = ball.xpos;
		ball.rect.y = ball.ypos;

		if(ball.rect.x > 500){
			score_player_1++;
			ball.rect.x = 300;
			ball.rect.y = 200;
			ball.ypos = 200;
			ball.yvel = 200;
			ball.xvel = 200;
			ball.xpos = 300;
		}
		if(ball.rect.x < 100){
			score_player_2++;
			ball.rect.x = 300;
			ball.rect.y = 200;
			ball.ypos = 200;
			ball.yvel = 200;
			ball.xvel = 200;
			ball.xpos = 300;
		}

		printf("\tSCORE\n: PLAYER 1: %d\tPLAYER 2: %d\n ", score_player_1, score_player_2);

		

		SDL_RenderClear(setup.rend);
		SDL_RenderCopy(setup.rend, player2.tex, NULL, &player2.rect);
		SDL_RenderCopy(setup.rend, player.tex, NULL, &player.rect);
		SDL_RenderCopy(setup.rend, ball.tex, NULL, &ball.rect);		
		SDL_RenderPresent(setup.rend);

		SDL_Delay(1000/60);

	}

	SDL_DestroyTexture(player.tex);
	SDL_DestroyTexture(player2.tex);
	SDL_DestroyRenderer(setup.rend);
	SDL_DestroyWindow(setup.win);
	SDL_Quit();
	return 0;
}