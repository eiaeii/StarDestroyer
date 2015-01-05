#include "Player.h"
#include "Bullet.h"
#include "Define.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	this->initWithFile("hero/plane1.png");
	this->setTag(ObjectType::TYPE_PLAYER);
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->setPosition(visibleSize.width / 2, this->getContentSize().height);
	auto body = PhysicsBody::createCircle(20.0f);
	body->setCategoryBitmask(Gategorybitmask::GATEGORYBITMASK_PLAYER);
	body->setContactTestBitmask(0xFFFFFFFF);
	body->setCollisionBitmask(Collisionbitmask::COLLISIONBITMASK_PLAYER);
	this->setPhysicsBody(body);
	schedule(schedule_selector(Player::secondWeapon), 1.0f);

	return true;
}


void Player::secondWeapon(float ft)
{
	auto planePosition = this->getPosition();
	auto planeSize = this->getContentSize();

	//auto visibleSize = Director::getInstance()->getVisibleSize();
	//static float sAngle = 90.0f - CC_RADIANS_TO_DEGREES(atan(visibleSize.height / visibleSize.width));

	auto bullet2 = Bullet::create();
	this->getParent()->addChild(bullet2);
	bullet2->setPosition(planePosition.x - 100, planePosition.y);
	bullet2->getPhysicsBody()->setVelocity(Vec2(0, 500));

	auto bullet3 = Bullet::create();
	this->getParent()->addChild(bullet3);
	bullet3->setPosition(planePosition.x + 100, planePosition.y);
	bullet3->getPhysicsBody()->setVelocity(Vec2(0, 500));


	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/rocket1.mp3");
}