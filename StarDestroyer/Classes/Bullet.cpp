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
	this->setTag(ObjectType::TYPE_PLAYER_BULLET);
	auto body = PhysicsBody::createCircle(5.0f);
	body->setCategoryBitmask(Gategorybitmask::GATEGORYBITMASK_PLAYER);
	body->setContactTestBitmask(0xFFFFFFFF);
	body->setCollisionBitmask(Collisionbitmask::COLLISIONBITMASK_PLAYER_BULLET);
	this->setPhysicsBody(body);
	return true;
}
