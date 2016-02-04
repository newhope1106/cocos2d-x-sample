#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;

class MainScene : public Layer, public TableViewDelegate, public TableViewDataSource{
	MenuItemImage *curEquipment;
public:
	const std::string menuImages[3] = {"menu/pic_switch_option.jpg", "menu/particle_system_option.jpg", "menu/download.jpg"};
	const std::string menuTitile[3] = {"图片切换效果", "粒子系统", "网络下载"};
	const int length = 3;
	virtual bool init();
	static cocos2d::Scene* createScene();

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {};
	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx);
	virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);

	void equipSelect(Ref* pSender);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode,cocos2d::Event * pEvent);

	void backToMainScene();

	void initBackground();

	CREATE_FUNC(MainScene);
};
#endif
