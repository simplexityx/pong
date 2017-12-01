#include <SDL.h>

#ifndef RES_H
#define RES_H

	typedef struct gameobject gameobject_t;

	typedef int (*input_t)(gameobject_t player, int SPEED, int WINDOW_HEIGHT, int WINDOW_WIDTH);

	typedef struct ball ball_t;
	struct ball{
		SDL_Texture *tex;
		SDL_Rect rect;
		SDL_Surface *surface;

		float ypos;
		float xpos;
		float yvel;
		float xvel;

	};

	struct gameobject{
		SDL_Texture *tex;
		SDL_Rect rect;
		SDL_Surface *surface;
		float ypos;
		float xpos;
		float yvel;
		float xvel;

		short up;
		short down;
		short left;
		short right;
	};
	
	typedef struct SDL_SETUP SDL_SETUP_T;
	struct SDL_SETUP{
		SDL_Window *win;
		SDL_Renderer *rend;
	};

	int movement(gameobject_t player, int SPEED, int WINDOW_HEIGHT, int WINDOW_WIDTH);

	SDL_SETUP_T get_Setup(int w, int h);

	gameobject_t create_gameObject(SDL_Renderer *rend, char *filepath, int x, int y);

	ball_t create_ball(SDL_Renderer *rend, char *filepath);


#endif