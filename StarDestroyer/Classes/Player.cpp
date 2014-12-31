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
	schedule(schedule_selector(Player::shoot), 0.5f);

	return true;
}


void Player::shoot(float ft)
{
	auto planePosition = this->getPosition();
	auto planeSize = this->getContentSize();

	auto bullet1 = Bullet::create(); 
	bullet1->setRotation(-25.0f);
	this->getParent()->addChild(bullet1);
	bullet1->setPosition(planePosition.x, planePosition.y + planeSize.height / 2);
	auto actionMove1 = MoveBy::create(5.0f, Vec2(-500, Director::getInstance()->getVisibleSize().height));
	auto remove1 = CallFunc::create([](){
		
	});
	auto sequence1 = Sequence::create(actionMove1, remove1, NULL);
	bullet1->runAction(sequence1);


	auto bullet2 = Bullet::create();
	this->getParent()->addChild(bullet2);
	bullet2->setPosition(planePosition.x, planePosition.y + planeSize.height / 2);
	auto actionMove2 = MoveBy::create(5.0f, Vec2(0, Director::getInstance()->getVisibleSize().height));
	auto remove2 = CallFunc::create([](){

	});
	auto sequence2 = Sequence::create(actionMove2, remove2, NULL);
	bullet2->runAction(sequence2);


	auto bullet3 = Bullet::create();
	bullet3->setRotation(25.0f);
	this->getParent()->addChild(bullet3);
	bullet3->setPosition(planePosition.x, planePosition.y + planeSize.height / 2);
	auto actionMove3 = MoveBy::create(5.0f, Vec2(500, Director::getInstance()->getVisibleSize().height));
	auto remove3 = CallFunc::create([](){

	});
	auto sequence3 = Sequence::create(actionMove3, remove3, NULL);
	bullet3->runAction(sequence3);
}