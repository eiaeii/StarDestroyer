#pragma once
#include "cocos2d.h"

class Bullet :
	public cocos2d::Sprite
{
public:

	enum BulletType
	{
		Bullet_Unkown = 0,
		Bullet_Player_main,
		Bullet_Player_second,
		Bullet_Enemy1_main,
	};

	virtual bool init(int iType);
	static Bullet* createWithType(int iType);
};