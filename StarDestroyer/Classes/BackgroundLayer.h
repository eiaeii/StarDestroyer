#pragma once
#include "cocos2d.h"
class BackgroundLayer :
	public cocos2d::Layer
{
public:

	enum EnBackground
	{
		e_BackgroundA = 1, // ����1 
		e_BackgroundB = 2, // ����2 �뱳��һ����ֻ������ѭ����
	};


	virtual bool init();
	CREATE_FUNC(BackgroundLayer);

private:
	void backgroundMove(float ft);
};

