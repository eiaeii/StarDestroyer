#include "Player.h"

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	this->initWithFile("hero/plane1.png");
	return true;
}