#include "MainScene.h"
#include "CustomTableViewCell.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();

    // 'layer' is an autorelease object
    MainScene *layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    initBackground();

    curEquipment = NULL;
	Size winSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	TableView* tableView = TableView::create(this, Size(winSize.width, 200));
	tableView->setDirection(ScrollView::Direction::HORIZONTAL);
	tableView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	tableView->setPosition(Point(winSize.width*0.2 + origin.x, winSize.height/2 + origin.y - 50));
	tableView->setDelegate(this);
	this->addChild(tableView);
	tableView->reloadData();

	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleased,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);

    return true;
}

void MainScene::tableCellTouched(TableView* table, TableViewCell* cell)
{
	CCLOG("cell touched at index: %ld", cell->getIdx());
}

Size MainScene::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
	return Size(100, 200);
}

TableViewCell* MainScene::tableCellAtIndex(TableView *table, ssize_t idx)
{
	TableViewCell *cell = cell = new (std::nothrow) CustomTableViewCell();
	cell->autorelease();
	auto sprite = Sprite::create(menuImages[idx%length]);
	sprite->setAnchorPoint(Vec2::ZERO);
	sprite->setPosition(Vec2(0, 0));
	cell->addChild(sprite);

	cell->setContentSize(Size(100,200));
	sprite->setContentSize(Size(110,200));
	Size cellSize = cell->getContentSize();
	auto label = Label::createWithSystemFont(menuTitile[idx%length], "微软雅黑", 16);
	Size lableSize = label->getContentSize();

	label->setPosition(50, 30);
	label->setTag(123);
	cell->addChild(label);

	return cell;
}

ssize_t MainScene::numberOfCellsInTableView(TableView *table)
{
    return length;
}

void MainScene::equipSelect(Ref* pSender){
    if (curEquipment) {
        curEquipment->setEnabled(true);
    }
    curEquipment = (MenuItemImage*)pSender;
    curEquipment->setEnabled(false);
}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode,Event * pEvent){
	 switch (keyCode){
	 	 case EventKeyboard::KeyCode::KEY_BACK:
	 		backToMainScene();
	 		break;
	 	case EventKeyboard::KeyCode::KEY_MENU:
	 	    break;
		case::EventKeyboard::KeyCode::KEY_HOME:
			break;
	 }
}

void MainScene::backToMainScene(){
	Director::getInstance()->popScene();
}

void MainScene::initBackground(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bgSprite = Sprite::create("images/main_bg.jpg");

	float xScale = visibleSize.width/bgSprite->getContentSize().width;
	float yScale = visibleSize.height/bgSprite->getContentSize().height;

	bgSprite->setScaleX(xScale);
	bgSprite->setScaleY(yScale);
	bgSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(bgSprite, 0);
}
