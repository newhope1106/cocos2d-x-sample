#ifndef __SAMPLE_SCENE_H__
#define __SAMPLE_SCENE_H__

#include "cocos2d.h"

class SampleScene : public cocos2d::Layer
{
public:
	cocos2d::Sprite* menuSprite;

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void initMenuSprite();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void gotoMainScene(cocos2d::Ref *pSender);

    void viewVideo(cocos2d::Ref *pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(SampleScene);
};

#endif // __SAMPLE_SCENE_H__
