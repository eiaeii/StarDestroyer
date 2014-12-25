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

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* touch, Event* event){
		return true;
	};
	listener->onTouchMoved = [](Touch* touch, Event* event){
		
	};
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::movePlane, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	

	return true;
}

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vect::ZERO);
	auto background = BackgroundLayer::create();
	scene->addChild(background, -10);
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());


	auto physicsBody = PhysicsBody::createEdgeBox(Director::getInstance()->getVisibleSize());
	scene->setPhysicsBody(physicsBody);
	scene->addChild(layer);
	
	return scene;
}


void GameScene::setPhysicsWorld(PhysicsWorld* world)
{ 
	m_world = world; 
}

void GameScene::movePlane(cocos2d::Touch *touch, cocos2d::Event *event)
{
	auto position = m_player->getPosition();
	auto delta = touch->getDelta();
	m_player->setPosition(position + delta);
}
