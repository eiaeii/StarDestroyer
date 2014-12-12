#include "GameScene.h"

USING_NS_CC;

bool GameScene::init()
{
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	return true;
}