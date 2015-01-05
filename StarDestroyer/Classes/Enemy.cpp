#include "Enemy.h"
#include "Define.h"
USING_NS_CC;

bool Enemy::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	this->initWithFile("enemy/enemy1_1.png");
	this->setTag(ObjectType::TYPE_ENEMY);
	auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	body->setCategoryBitmask(Gategorybitmask::GATEGORYBITMASK_ENEMY);
	body->setContactTestBitmask(0xFFFFFFFF);
	body->setCollisionBitmask(Collisionbitmask::COLLISIONBITMASK_ENEMY);
	this->setPhysicsBody(body);
	return true;
}
