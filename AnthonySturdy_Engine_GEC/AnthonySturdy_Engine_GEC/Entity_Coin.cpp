#include "Entity_Coin.h"

Entity_Coin::Entity_Coin(SDL_Renderer* renderer, Vector2D startPosition, std::string texturePath, float _movementSpeed, float _accelerationSpeed, float _decelerationSpeed) : Entity(renderer, startPosition, texturePath, _movementSpeed, _accelerationSpeed, _decelerationSpeed) {
	isMoveable = false;
	
	type = ENTITY_TYPE::ENTITY_COIN;

	currentAnimation = new Animation(renderer, "Images/idle_coin", 1, 1.0f);
	coinSound = new SoundEffect("Audio/Super_Mario_Bros/smb_coin.wav");
}

Entity_Coin::~Entity_Coin() {
	delete coinSound;
}

void Entity_Coin::Update(float deltaTime, SDL_Event e) {
	//If colliding with entity
	if (collidingEntity != nullptr) {
		if (collidingEntity->type == ENTITY_TYPE::ENTITY_MARIO) {
			coinSound->Play();
			Die();
		}
	}

	Entity::Update(deltaTime, e);
}
