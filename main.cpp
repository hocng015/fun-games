#include<iostream>
#include<SDL.h>
#include"game.h"
#include "../../../../Downloads/original (1)/src/constants.h"

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;
int running = false, last_frame_time = 0;

struct game_obj {
	float x; 
	float y;
	float width;
	float height;
	float vel_x;
	float vel_y;
}ball, paddle, paddle2;

int initialize_window(void) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("First game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, 0);

	return true;
}

void setup() {
	ball.x = 20;
	ball.y = 200;
	ball.height = 15;
	ball.width = 15;
	ball.vel_x = 200;
	ball.vel_y = 200;

	paddle.width = 100;
	paddle.height = 20;
	paddle.x = (WINDOW_WIDTH / 2) - (paddle.width / 2);
	paddle.y = (WINDOW_HEIGHT - 40);
	paddle.vel_x = 0;
	paddle.vel_y = 0;

	paddle2.width = 100;
	paddle2.height = 20;
	paddle2.x = (WINDOW_WIDTH / 2) - (paddle2.width / 2);
	paddle2.y = (WINDOW_HEIGHT - 560);
	paddle2.vel_x = 0;
	paddle2.vel_y = 0;
}

void handle_events() {
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		running = FALSE;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
			running = FALSE;
		if (event.key.keysym.sym == SDLK_LEFT)
			paddle.vel_x = -400;
		if (event.key.keysym.sym == SDLK_RIGHT)
			paddle.vel_x = +400;
		break;
	case SDL_KEYUP:
		if (event.key.keysym.sym == SDLK_LEFT)
			paddle.vel_x = 0;
		if (event.key.keysym.sym == SDLK_RIGHT)
			paddle.vel_x = 0;
		break;
	}
}
void update() {
	//easier method

//	SDL_Delay(FRAME_TARGET_TIME);

	//more manual method. its locks the program inside the while loop until its false to then continue to the rest of the instructions in the update function
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));

	float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

	last_frame_time = SDL_GetTicks();

	if (ball.y + ball.height < 0)
		ball.vel_y = -ball.vel_y;

	if (ball.x + ball.width > WINDOW_WIDTH || ball.x < 0)
		ball.vel_x = -ball.vel_x;

	if (ball.y + ball.height >= paddle.y && ball.x + ball.width > paddle.x && ball.x < paddle.x + paddle.width)
		ball.vel_y = -ball.vel_y;

	if (ball.y + ball.height <= paddle2.y && ball.x + ball.width > paddle2.x && ball.x < paddle2.x + paddle2.width)
		ball.vel_y = -ball.vel_y;

	if (ball.y + ball.height > WINDOW_HEIGHT)
		running = FALSE;

	if (paddle2.vel_x == 0)
		paddle2.vel_x = 600;

	if (((paddle2.x + paddle2.width) >= WINDOW_WIDTH) || ((paddle2.x + paddle2.width) < 0))
	paddle2.vel_x = -paddle2.vel_x;

	ball.x += ball.vel_x * delta_time;
	ball.y += ball.vel_y * delta_time;

	paddle.x += paddle.vel_x * delta_time;
	paddle.y += paddle.vel_y * delta_time;

	paddle2.x += paddle2.vel_x * delta_time;
}

void render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Rect ball_rect = { ball.x, ball.y, ball.width, ball.height};

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderFillRect(renderer, &ball_rect);

	SDL_Rect paddle_rect = { paddle.x, paddle.y, paddle.width, paddle.height };

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderFillRect(renderer, &paddle_rect);

	SDL_Rect paddle_rect2 = { paddle2.x, paddle2.y, paddle2.width, paddle2.height };

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderFillRect(renderer, &paddle_rect2);

	SDL_RenderPresent(renderer);

}

void clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char **argv) {
	running = initialize_window();

	setup();
	
	while (running) {
		handle_events();
		update();
		render();
	}

	clean();
	return 0;
}
