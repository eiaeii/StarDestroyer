#include "BackgroundLayer.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;



bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto backgroundA = Sprite::create("map/bg1.jpg");
	backgroundA->setTag(e_BackgroundA);
	backgroundA->setAnchorPoint(Vec2::ZERO);
	backgroundA->setPosition(Vec2::ZERO);
	this->addChild(backgroundA);

	auto backgroundB = Sprite::create("map/bg1.jpg");
	backgroundB->setTag(e_BackgroundB);
	backgroundB->setAnchorPoint(Vec2::ZERO);
	backgroundB->setPosition(Vec2::ZERO);
	this->addChild(backgroundB);

	this->schedule(schedule_selector(BackgroundLayer::backgroundMove));
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/background-music1.mp3", true);
	return true;
}

void BackgroundLayer::backgroundMove(float ft)
{
	Sprite* pBackgroundA = static_cast<Sprite*>(this->getChildByTag(e_BackgroundA));
	Sprite* pBackgroundB = static_cast<Sprite*>(this->getChildByTag(e_BackgroundB));

	pBackgroundA->setPositionY(pBackgroundA->getPositionY() - 2);
	pBackgroundB->setPositionY(pBackgroundA->getPositionY() + pBackgroundA->getContentSize().height);
	if (0 == pBackgroundB->getPositionY())
	{
		pBackgroundA->setPositionY(0);
	}
}

