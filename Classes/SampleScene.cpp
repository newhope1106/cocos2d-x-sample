#include "SampleScene.h"
#include "VideoScene.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"

#define MUSIC_FILE "music/Hackers.mp3"

USING_NS_CC;

Scene* SampleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SampleScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SampleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MUSIC_FILE);
	// set default volume
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE, true);

    initMenuSprite();

    return true;
}

void SampleScene::initMenuSprite() {
	menuSprite = Sprite::create("menu/menu_bg.jpg");
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	float spriteWidth = menuSprite->getContentSize().width;
	float spriteHeight = menuSprite->getContentSize().height;
	float visibleWidth = visibleSize.width;
	float visibleHeight = visibleSize.height;

	float scalX = visibleWidth*1.0f/spriteWidth;
	float scalY = visibleHeight*1.0f/spriteHeight;

	menuSprite->setScaleX(scalX);
	menuSprite->setScaleY(scalY);

	menuSprite->setPosition(Vec2(visibleWidth/2 + origin.x, visibleHeight/2 + origin.y));

	auto label = Label::createWithTTF("Main Menu", "fonts/Marker Felt.ttf", 24);

	float topBound = visibleHeight - 20;
	// position the label on the center of the screen
	label->setPosition(Vec2(visibleWidth/2, topBound - label->getContentSize().height));
	menuSprite->addChild(label, 0);

	auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);
	menuSprite->addChild(menu, 1);

	Label *startLabel = Label::createWithTTF("Start Game", "fonts/Marker Felt.ttf", 20);
	MenuItemLabel *itemLabel = MenuItemLabel::create(startLabel, CC_CALLBACK_1(SampleScene::gotoMainScene, this));
	itemLabel->setPosition(Point(visibleWidth/2, 140));
	menu->addChild(itemLabel, 0);

	Label *videoLabel = Label::createWithTTF("View Video", "fonts/Marker Felt.ttf", 20);
	itemLabel = MenuItemLabel::create(videoLabel, CC_CALLBACK_1(SampleScene::viewVideo, this));
	itemLabel->setPosition(Point(visibleWidth/2, 100));
	menu->addChild(itemLabel, 0);

	Label *exitLabel = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 20);
	itemLabel = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(SampleScene::menuCloseCallback, this));
	itemLabel->setPosition(Point(visibleWidth/2, 60));
	menu->addChild(itemLabel, 0);

	this->addChild(menuSprite, 0);
}


void SampleScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void SampleScene::viewVideo(Ref *pSender) {
	auto videoScene = VideoScene::createScene();
	TransitionFlipX * transition =TransitionFlipX::create(1.0, videoScene);
	Director::getInstance()->pushScene(transition);
}

void SampleScene::gotoMainScene(Ref *pSender){
	auto mainScene = MainScene::createScene();
	TransitionFlipX * transition =TransitionFlipX::create(1.0, mainScene);
	Director::getInstance()->pushScene(transition);
}
