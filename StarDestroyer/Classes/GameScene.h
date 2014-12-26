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
	void setPhysicsWorld(cocos2d::PhysicsWorld* world);
	void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	bool onContactBegin(cocos2d::PhysicsContact &contact);

	void onEnter() override;

protected:
	cocos2d::PhysicsWorld *m_world;
	Player *m_player;
};

