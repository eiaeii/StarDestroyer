#pragma once
#include "cocos2d.h"

class Player :
	public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Player);
protected:
	void shoot(float ft);
};
