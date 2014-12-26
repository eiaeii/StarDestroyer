#include "Player.h"
#include "Bullet.h"
USING_NS_CC;
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
	schedule(schedule_selector(Player::shoot), 0.2f);

	return true;
}


void Player::shoot(float ft)
{
	auto bullet = Bullet::create();
	auto planePosition = this->getPosition();
	auto planeSize = this->getContentSize();
	this->addChild(bullet);
	//bullet->setPosition(Vec2(planePosition.x + planeSize.width / 2, planePosition.y + planeSize.height / 2));
	auto actionMove = MoveTo::create(2.0f, Vec2(planePosition.x + planeSize.width / 2, Director::getInstance()->getVisibleSize().height));
	auto remove = CallFunc::create([](){
		
	});
	auto sequence = Sequence::create(actionMove, remove, NULL);
	bullet->runAction(sequence);
}