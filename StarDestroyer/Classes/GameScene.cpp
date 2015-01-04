#include "GameScene.h"
#include "BackgroundLayer.h"
#include "SimpleAudioEngine.h"
#include "Player.h"
#include "Define.h"

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
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vect::ZERO);
	auto background = BackgroundLayer::create();
	scene->addChild(background, -10);
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);

	
	
	return scene;
}


void GameScene::setPhysicsWorld(PhysicsWorld* world)
{ 
	m_world = world; 
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	auto position = m_player->getPosition() + touch->getDelta();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	position.x = position.x < 0 ? 0 : position.x;
	position.x = position.x > visibleSize.width ? visibleSize.width : position.x;
	position.y = position.y < 0 ? 0 : position.y;
	position.y = position.y > visibleSize.height ? visibleSize.height : position.y;
	m_player->setPosition(position);
}

void GameScene::onEnter()
{
	Layer::onEnter();

	m_player = Player::create();
	this->addChild(m_player);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* touch, Event* event){
		return true;
	};
	listener->onTouchEnded = [](Touch* touch, Event* event){

	};
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto world = PhysicsBody::createEdgeBox(Director::getInstance()->getVisibleSize());
	world->setCategoryBitmask(Gategorybitmask::GATEGORYBITMASK_WORLD);
	world->setContactTestBitmask(0xFFFFFFFF);
	world->setCollisionBitmask(Collisionbitmask::COLLISIONBITMASK_WORLD);
	auto node = Node::create();
	node->setPosition(Director::getInstance()->getVisibleSize() / 2);
	node->setPhysicsBody(world);
	this->addChild(node);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_2(GameScene::onContactPreSolve, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}


bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
	auto spriteA = contact.getShapeA()->getBody()->getNode();
	auto spriteB = contact.getShapeB()->getBody()->getNode();

	return true;
}


bool GameScene::onContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve& solve)
{
	return true;
}