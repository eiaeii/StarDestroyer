#include "GameScene.h"
#include "BackgroundLayer.h"
#include "SimpleAudioEngine.h"
#include "Player.h"
#include "Define.h"
#include "Enemy.h"

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
	node->setTag(ObjectType::TYPE_WORLD);
	node->setPosition(Director::getInstance()->getVisibleSize() / 2);
	node->setPhysicsBody(world);
	this->addChild(node);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_2(GameScene::onContactPreSolve, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	schedule(schedule_selector(GameScene::setEnemy), 1.0f);
}


bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
	auto spriteA = contact.getShapeA()->getBody()->getNode();
	auto spriteB = contact.getShapeB()->getBody()->getNode();
	if (spriteA == NULL || spriteB == NULL)
	{
		return false;
	}
	auto tagA = spriteA->getTag();
	auto tagB = spriteB->getTag();

	//子弹和边界碰撞则移除
	if ((tagA | tagB) == (ObjectType::TYPE_PLAYER_BULLET | ObjectType::TYPE_WORLD) || (tagA | tagB) == (ObjectType::TYPE_ENEMY_BULLET | ObjectType::TYPE_WORLD))
	{
		if ((tagA == ObjectType::TYPE_PLAYER_BULLET) || (tagA == ObjectType::TYPE_ENEMY_BULLET))
		{
			spriteA->removeAllChildrenWithCleanup(true);
		}
		else if ((tagB == ObjectType::TYPE_PLAYER_BULLET) || (tagB == ObjectType::TYPE_ENEMY_BULLET))
		{
			spriteB->removeAllChildrenWithCleanup(true);
		}
		return false;
	}

	//玩家飞机和边界不碰撞
	else if ((tagA | tagB) == (ObjectType::TYPE_PLAYER | ObjectType::TYPE_WORLD))
	{
		return false;
	}

	//玩家飞机和敌机
	else if ((tagA | tagB) == (ObjectType::TYPE_PLAYER | ObjectType::TYPE_ENEMY))
	{
		if (tagA == ObjectType::TYPE_ENEMY)
		{
			spriteA->removeFromParentAndCleanup(true);
		}
		else if (tagB == ObjectType::TYPE_ENEMY)
		{
			spriteB->removeFromParentAndCleanup(true);
		}
		return false;
	}

	else if ((tagA | tagB) == (ObjectType::TYPE_PLAYER_BULLET | ObjectType::TYPE_ENEMY))
	{
		if (tagA == ObjectType::TYPE_PLAYER_BULLET)
		{
			spriteA->removeFromParentAndCleanup(true);
			spriteB->removeFromParentAndCleanup(true);
		}
		else if (tagB == ObjectType::TYPE_PLAYER_BULLET)
		{
			spriteA->removeFromParentAndCleanup(true);
			spriteB->removeFromParentAndCleanup(true);
		}
		return false;
	}
	return true;
}


bool GameScene::onContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve& solve)
{
	return true;
}

void GameScene::setEnemy(float ft)
{
	float random = CCRANDOM_0_1();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto enemy = Enemy::create();
	this->addChild(enemy);
	auto pos = Vec2(random * visibleSize.width, visibleSize.height);
	auto size = enemy->getContentSize();
	pos.x = pos.x < size.width ? size.width : pos.x;
	pos.x = pos.x > visibleSize.width - size.width ? visibleSize.width - size.width : pos.x;
	enemy->setPosition(pos);
	enemy->getPhysicsBody()->setVelocity(Vec2(0, -200));
}