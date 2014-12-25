#pragma once
#include "cocos2d.h"

class Player;

class GameScene :
	public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(GameScene);

protected:
	void backgroundMove(float ft);
	void setPhysicsWorld(cocos2d::PhysicsWorld* world);
	void movePlane(cocos2d::Touch*, cocos2d::Event*);

protected:
	cocos2d::PhysicsWorld *m_world;
	Player *m_player;
};

