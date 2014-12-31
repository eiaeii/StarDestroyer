#include "Bullet.h"
#include "Define.h"
USING_NS_CC;

bool Bullet::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	this->initWithFile("bullet/assisent1_01.png");
	this->setTag(ObjectType::TYPE_ENEMY_BULLET);
	auto body = PhysicsBody::createCircle(5.0f);
	this->setPhysicsBody(body);
	this->scheduleUpdate();
	return true;
}

void Bullet::update(float delta)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto position = this->getPosition();
	if (position.x < 0 || position.x > visibleSize.width || position.y < 0 || position.y > visibleSize.height)
	{
		this->removeFromParentAndCleanup(true);
	}
}