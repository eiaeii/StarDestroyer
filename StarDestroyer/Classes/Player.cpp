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
	schedule(schedule_selector(Player::secondWeapon), 2.0f);
	schedule(schedule_selector(Player::mainWeapon), 0.25f);

	return true;
}


void Player::secondWeapon(float ft)
{
	auto planePosition = this->getPosition();
	auto planeSize = this->getContentSize();

	//auto visibleSize = Director::getInstance()->getVisibleSize();
	//static float sAngle = 90.0f - CC_RADIANS_TO_DEGREES(atan(visibleSize.height / visibleSize.width));

	auto bullet1 = Bullet::createWithType(Bullet::BulletType::Bullet_Player_second);
	this->getParent()->addChild(bullet1);
	bullet1->setPosition(planePosition.x - 150, planePosition.y);

	auto bullet2 = Bullet::createWithType(Bullet::BulletType::Bullet_Player_second);
	this->getParent()->addChild(bullet2);
	bullet2->setPosition(planePosition.x - 100, planePosition.y + 100);

	auto bullet3 = Bullet::createWithType(Bullet::BulletType::Bullet_Player_second);
	this->getParent()->addChild(bullet3);
	bullet3->setPosition(planePosition.x - 50, planePosition.y);


	auto bullet4 = Bullet::createWithType(Bullet::BulletType::Bullet_Player_second);
	this->getParent()->addChild(bullet4);
	bullet4->setPosition(planePosition.x + 50, planePosition.y);

	auto bullet5 = Bullet::createWithType(Bullet::BulletType::Bullet_Player_second);
	this->getParent()->addChild(bullet5);
	bullet5->setPosition(planePosition.x + 100, planePosition.y + 100);

	auto bullet6 = Bullet::createWithType(Bullet::BulletType::Bullet_Player_second);
	this->getParent()->addChild(bullet6);
	bullet6->setPosition(planePosition.x + 150, planePosition.y);

	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/rocket1.mp3");
}


void Player::mainWeapon(float ft)
{
	auto planePosition = this->getPosition();
	
	auto bullet = Bullet::createWithType(Bullet::BulletType::Bullet_Player_main);
	this->getParent()->addChild(bullet);
	bullet->setPosition(planePosition.x, planePosition.y + bullet->getContentSize().height);

	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/short_lazer.mp3");
}