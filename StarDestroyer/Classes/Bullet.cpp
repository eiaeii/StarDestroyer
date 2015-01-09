#include "Bullet.h"
#include "Define.h"
USING_NS_CC;

bool Bullet::init(int iType)
{
	if (!Sprite::init())
	{
		return false;
	}
	if (iType == BulletType::Bullet_Player_main)
	{
		this->initWithFile("bullet/pet_bullet.png");
		this->setTag(ObjectType::TYPE_PLAYER_BULLET);
		auto body = PhysicsBody::createCircle(5.0f);
		body->setCategoryBitmask(Gategorybitmask::GATEGORYBITMASK_PLAYER);
		body->setContactTestBitmask(0xFFFFFFFF);
		body->setCollisionBitmask(Collisionbitmask::COLLISIONBITMASK_PLAYER_BULLET);
		this->setPhysicsBody(body);
		body->setVelocity(Vec2(0, 500));
	}
	else if (iType == BulletType::Bullet_Player_second)
	{
		this->initWithFile("bullet/assisent1_01.png");
		this->setTag(ObjectType::TYPE_PLAYER_BULLET);
		auto body = PhysicsBody::createCircle(5.0f);
		body->setCategoryBitmask(Gategorybitmask::GATEGORYBITMASK_PLAYER);
		body->setContactTestBitmask(0xFFFFFFFF);
		body->setCollisionBitmask(Collisionbitmask::COLLISIONBITMASK_PLAYER_BULLET);
		this->setPhysicsBody(body);
		body->setVelocity(Vec2(0, 1000));
	}
	return true;
}

Bullet* Bullet::createWithType(int iType)
{
	Bullet *pBullet = new Bullet();
	if (pBullet && pBullet->init(iType))
	{
		pBullet->autorelease();
		return pBullet;
	}
	else
	{
		delete pBullet;
		pBullet = NULL;
		return NULL;
	}
}