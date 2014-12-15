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
	return scene;
}

void GameScene::preloadResources()
{
	Director::getInstance()->getTextureCache()->addImage("map/bg1.jpg");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero/hero1.plist");

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/background-music1.mp3");
	
}
