#ifndef __Player_H__
#define __Player_H__

#include "Module.h"
#include "Animation.h"
#include "Point.h"
#include "Random.h"

struct SDL_Texture;

enum State
{
	IDLE,
	JUMPING,
	ATTACKING,
	BEINGATTACKED,
	TAKEDDOWN,
	END
};

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool active = true);
	~ModulePlayer();

	bool Start();
	update_status Update();
	void OnCollision(Collider* c1, Collider* c2);
	bool CleanUp();
	


public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation idleLeft;
	Animation up;
	Animation jump;
	Animation jumpLeft;
	Animation upLeft;
	Animation right;
	Animation left;
	Animation attack1;
	Animation attack1Left;
	Animation attack2;
	Animation attack2Left;
	Animation attackAir;
	Animation attackAirLeft;
	Animation attackAir2;
	Animation attackAir2Left;
	Animation reciveDamage1;
	Animation reciveDamage1Left;
	Animation reciveDamage2;
	Animation reciveDamage2Left;
	Animation reciveDamage3;
	Animation reciveDamage3Left;
	Animation reciveDamage4;
	Animation reciveDamage4Left;
	iPoint position;
	bool eliminated = false;
	Collider* colliderFeet;
	Collider* colliderBody;
	Collider* colliderWeapon;
	Collider* colliderJump;
	bool faceRight = true;
	bool inAir = false;
	bool jumped = false;
	bool goingDown = false;
	bool attacking = false;
	int jumpPos;
	int attackingAirX = 0;
	iPoint jumpInit;
	State currentState = IDLE;
	int hits = 0;
	double randomVar;
	bool sameDirection = false;
	bool end = false;
	Random* random = nullptr;


};

#endif