#include "LogoScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

USING_NS_CC;

bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto sprite = Sprite::create("logo.png");
	sprite->setPosition(Vec2::ZERO);
	sprite->setAnchorPoint(Vec2::ZERO);

	this->addChild(sprite);
	preloadResources();
	scheduleOnce(schedule_selector(LogoScene::nextScene), 1.0f);
	return true;
}

Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}

void LogoScene::nextScene(float ft)
{
	auto scene = GameScene::createScene();
	auto transitions = TransitionFade::create(0.2f, scene);
	Director::getInstance()->replaceScene(transitions);
}

void LogoScene::preloadResources()
{
	Director::getInstance()->getTextureCache()->addImage("map/bg1.jpg");
	Director::getInstance()->getTextureCache()->addImage("hero/plane1.png");
	Director::getInstance()->getTextureCache()->addImage("bullet/assisent1_01.png");
	Director::getInstance()->getTextureCache()->addImage("enemy/enemy1_1.png");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero/hero1.plist");

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/background-music1.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/rocket1.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/short_lazer.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/explosion4.mp3");
}
