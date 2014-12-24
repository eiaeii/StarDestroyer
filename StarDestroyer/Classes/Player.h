#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Player :
	public Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Player);
};

