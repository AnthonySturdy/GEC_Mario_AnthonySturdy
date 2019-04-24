#pragma once

struct Vector2D {
	float x, y;

	Vector2D() {
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float initX, float initY) {
		x = initX;
		y = initY;
	}
};

struct Rect2D {
	float x, y, w, h;

	Rect2D() {
		x = y = w = h = 0.0f;
	}

	Rect2D(int _x, int _y) {
		//Used for UI elements where w and h are defined after
		x = _x;
		y = _y;
		w = h = 0;
	}

	Rect2D(float _x, float _y, float _w, float _h) {
		x = _x;
		y = _y;
		w = _w;
		h = _h;
	}
};

struct Circle2D {
	float x, y, r;

	Circle2D(float _x, float _y, float _r) {
		x = _x;
		y = _y;
		r = _r;
	}
};

enum SCREENS {
	SCREEN_INTRO = 0,
	SCREEN_MAIN_MENU,
	SCREEN_LEVEL1,
	SCREEN_CUSTOM_LEVEL,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES,
	SCREEN_LEVEL_EDITOR
};

enum FACING {
	FACING_LEFT = 0,
	FACING_RIGHT
};

enum SPRITES {	//Tileset Positions
	SPRITE_CLEAR = 0,
	SPRITE_GROUND = 1,
	SPRITE_BRICK_WHITE_TOP = 2,
	SPRITE_BRICK = 3,
	SPRITE_BEZEL = 34,
	SPRITE_QUESTION_BLOCK = 25,
	SPRITE_QUESTION_BLOCK_USED = 4,
	SPRITE_CASTLE_BRICKS = 14,
	SPRITE_CASTLE_BATTLEMENT_EMPTY = 12,
	SPRITE_CASTLE_BATTLEMENT_FULL = 45,
	SPRITE_CASTLE_WINDOW_RIGHT = 13,
	SPRITE_CASTLE_WINDOW_LEFT = 15,
	SPRITE_CASTLE_DOOR_ARCH = 46,
	SPRITE_CASTLE_DOOR_BLACK = 47,
	SPRITE_PIPE_VERTICAL_OPENING_LEFT = 264,
	SPRITE_PIPE_VERTICAL_OPENING_RIGHT = 265,
	SPRITE_PIPE_VERTICAL_BASE_LEFT = 297,
	SPRITE_PIPE_VERTICAL_BASE_RIGHT = 298,
	SPRITE_PIPE_HORIZONTAL_OPENING_TOP = 266,
	SPRITE_PIPE_HORIZONTAL_OPENING_BOTTOM = 299,
	SPRITE_PIPE_HORIZONTAL_BASE_TOP = 267,
	SPRITE_PIPE_HORIZONTAL_BASE_BOTTOM = 300,
	SPRITE_PIPE_VERTICAL_HORIZONTAL_CONNECT_TOP = 268,
	SPRITE_PIPE_VERTICAL_HORIZONTAL_CONNECT_BOTTOM = 301,
	SPRITE_BUSH_LARGE_LEFT_SLOPE = 272,
	SPRITE_BUSH_LARGE_LEFT_SPOTS = 305,
	SPRITE_BUSH_LARGE_TOP = 273,
	SPRITE_BUSH_LARGE_FULL = 306,
	SPRITE_BUSH_LARGE_RIGHT_SLOPE = 274,
	SPRITE_BUSH_LARGE_RIGHT_SPOTS = 307,
	SPRITE_BUSH_SMALL_LEFT = 308,
	SPRITE_BUSH_SMALL_MIDDLE = 309,
	SPRITE_BUSH_SMALL_RIGHT = 310,
	SPRITE_CLOUD_TOP_LEFT = 660,
	SPRITE_CLOUD_TOP_MIDDLE = 661,
	SPRITE_CLOUD_TOP_RIGHT = 662,
	SPRITE_CLOUD_BOTTOM_LEFT = 693,
	SPRITE_CLOUD_BOTTOM_MIDDLE = 694,
	SPRITE_CLOUD_BOTTOM_RIGHT = 695,
	SPRITE_ENTITY_MARIO_LEVEL_START = 919,
	SPRITE_ENTITY_FLAG_LEVEL_END = 920,
	SPRITE_ENTITY_COIN = 921,
	SPRITE_ENTITY_GOOMBA = 922,
	SPRITE_ENTITY_KOOPA = 923
};

struct LevelTile {
	Rect2D rect;
	unsigned short sprite;
	bool isCollidable;

	LevelTile(Rect2D _rect, unsigned short _sprite, bool collidable) {
		rect = _rect;
		sprite = _sprite;
		isCollidable = collidable;
	}
};

enum ENTITY_TYPE {
	ENTITY_DEFAULT,
	ENTITY_MARIO,
	ENTITY_GOOMBA,
	ENTITY_KOOPA,
	ENTITY_LEVELEND,
	ENTITY_COIN
};