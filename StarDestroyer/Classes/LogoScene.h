#pragma once
#include "cocos2d.h"

class LogoScene :
	public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(LogoScene);
private:
	void nextScene(float ft);
	void preloadResources();
};

