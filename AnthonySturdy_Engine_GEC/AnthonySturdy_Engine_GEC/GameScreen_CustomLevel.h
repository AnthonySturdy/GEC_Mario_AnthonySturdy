#pragma once
#include "GameScreen.h"
#include "Texture2D.h"
#include "Commons.h"
#include "Constants.h"
#include "Entity.h"
#include "Entity_Mario.h"
#include "Entity_Goomba.h"
#include "Entity_Koopa.h"
#include "Entity_LevelEnd.h"
#include "Entity_Coin.h"
#include "Commons.h"
#include "TextElement.h"
#include "SoundEffect.h"
#include "UIElement.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class GameScreen_CustomLevel : public GameScreen {
public:
	GameScreen_CustomLevel(SDL_Renderer* renderer, int _mapSizeX, int _mapSizeY, GameScreenManager* _manager);
	~GameScreen_CustomLevel();

	void Render();
	void Update(float deltaTime, SDL_Event e);

private:
	void SetUpLevel();

	bool debugDraw = false;
	int halfScreen = SCREEN_WIDTH / 2;
	
	bool isPaused = false;
	bool PauseMenu();
	Texture2D* pauseMenuTexture;
	Texture2D* currentPauseMenuSelectionTexture;
	UIElement* uiPauseMenu;
	UIElement* uiCurrentPauseMenuSelection;
	std::vector<Rect2D> uiPauseMenuButtonRects;

	int score = 0;
	TextElement* scoreText;
	Texture2D* fontTexture;

	//Sounds
	SoundEffect* jumpSound;
	SoundEffect* pauseSound;

	//Map
	int mapSizeX, mapSizeY;
	std::vector<unsigned short> map;
	std::vector<unsigned short> entityMap;
	bool ReadMapFromFile(const char* filePath);
	Texture2D* texture_tileset;
	std::vector<Rect2D*> tileset;
	std::vector<LevelTile*> levelTiles;
	bool IsTileCollidable(unsigned short sprite);
	std::vector<LevelTile*> GetSurroundTiles(int x, int y);

	std::vector<Entity*> entities;
	Entity* playerEntity;
	Entity* playerCollidingEntity;
	void CreateEntity(unsigned short sprite, int x, int y);

};