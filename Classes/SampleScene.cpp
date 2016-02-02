#include "SampleScene.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(SampleScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
    
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

	Label *startLabel = Label::createWithTTF("Start Game", "fonts/Marker Felt.ttf", 20);
	MenuItemLabel *itemLabel = MenuItemLabel::create(startLabel, CC_CALLBACK_1(SampleScene::Roate, this));
	itemLabel->setPosition(Point(visibleWidth/2, 100));
	menuSprite->addChild(itemLabel, 0);

	Label *exitLabel = Label::createWithTTF("Exit Game", "fonts/Marker Felt.ttf", 20);
	itemLabel = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(SampleScene::menuCloseCallback, this));
	itemLabel->setPosition(Point(visibleWidth/2, 60));
	menuSprite->addChild(itemLabel, 0);

	this->addChild(menuSprite, 0);
}


void SampleScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void SampleScene::Roate(Ref *pSender){

    Node *node = (Node *)pSender;
    node->runAction(RotateBy::create(0.5, 360));
}
