#include "GameScene.h"
#include "Actor.h"
#include "Constant.h"
#include "HealthComponent.h"
#include "HRocker.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	//auto scene = Scene::createWithPhysics();
	return GameScene::create();
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	//this->scheduleOnce(schedule_selector(GameScene::scheca),5.0);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		[&](Object* sender) {
		Director::getInstance()->end();
		#if(CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
		exit(0);
		#endif
	});

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	closeItem->setPosition(Vec2(visibleSize.width-closeItem->getContentSize().width/2, closeItem->getContentSize().height / 2));
	this->addChild(menu, 1);
	
	_actor = Actor::create("10001.png", ECamp::BLUE);
	_actor->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(_actor);
	
	auto testMove = MoveTo::create(1.0f, Vec2(visibleSize.width, visibleSize.height));
	_actor->runAction(testMove);

	auto testHRocker = HRocker::createHRocker("rocker.png", "rockerBG.png", Point(visibleSize / 2));
	testHRocker->startRocker(false);
	this->addChild(testHRocker);

	return true;
}
	//schedule(CC_CALLBACK_1(HealthComponent::fun, this, _currentrr), 5);
