#include "GameScene.h"
#include "BackgroundLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	auto background = BackgroundLayer::create();
	scene->addChild(background, -10);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sprite = Sprite::createWithSpriteFrameName("hero1left_01.png");
	sprite->setPosition(visibleSize.width / 2, sprite->getContentSize().height);
	scene->addChild(sprite);
	return scene;
}
