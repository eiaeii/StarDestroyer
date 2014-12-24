#include "GameScene.h"
#include "BackgroundLayer.h"
#include "SimpleAudioEngine.h"
#include "Player.h"

USING_NS_CC;

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	m_player = Player::create();
	this->addChild(m_player);
	return true;
}

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	auto background = BackgroundLayer::create();
	scene->addChild(background, -10);
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	
	return scene;
}
