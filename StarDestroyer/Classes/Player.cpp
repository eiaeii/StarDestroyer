#include "Player.h"

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	this->initWithFile("hero/plane1.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->setPosition(visibleSize.width / 2, this->getContentSize().height);
	auto body = PhysicsBody::createCircle(20.0f);
	this->setPhysicsBody(body);
	return true;
}