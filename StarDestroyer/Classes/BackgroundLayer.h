#pragma once
#include "cocos2d.h"
class BackgroundLayer :
	public cocos2d::Layer
{
public:

	enum EnBackground
	{
		e_BackgroundA = 1, // 背景1 
		e_BackgroundB = 2, // 背景2 与背景一样，只是用来循环用
	};


	virtual bool init();
	CREATE_FUNC(BackgroundLayer);

private:
	void backgroundMove(float ft);
};

