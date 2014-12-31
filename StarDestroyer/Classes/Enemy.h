#pragma once
#include "cocos2d.h"
class Enemy :
	public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Enemy);
};

