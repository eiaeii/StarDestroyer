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

private:
	void backgroundMove(float ft);
	void setPhysicsWorld(PhysicsWorld* world){ m_world = world; }
	
private:
	PhysicsWorld* m_world;
	
protected:
	Player *m_player;
};

