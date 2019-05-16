#pragma once

#ifndef _GameScene_Scene_H_
#define _GameScene_Scene_H_

#include "cocos2d.h"
#include "Actor.h"
USING_NS_CC;

class Hero;

class GameScene :public cocos2d::Scene
{
protected:
	//³¡¾°ÖÐµÄÓ¢ÐÛ
	//Hero* _hero;
	Actor* _actor;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	static void problemLoading(const char* filename);
	CREATE_FUNC(GameScene);
};


#endif // !_SingleScene_Scene_H_
