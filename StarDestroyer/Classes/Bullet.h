#pragma once
#include "cocos2d.h"

class Bullet :
	public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Bullet);
protected:
	void update(float delta) override;
};