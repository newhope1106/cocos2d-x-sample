#ifndef __VIDEO_SCENE_H__
#define __VIDEO_SCENE_H__

#include "cocos2d.h"

class VideoScene : public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(VideoScene);//生成create方法
	virtual bool init();
	void playVideo();
	void stopVideo();
	void backToMainScene();

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode,cocos2d::Event * pEvent);
};

#endif
