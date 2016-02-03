#include "VideoScene.h"

#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

#define VIDEO_FILE "video/watch dogs.mp4"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#define CCLog(...) __android_log_print(ANDROID_LOG_DEBUG,"cocos2d-x", __VA_ARGS__)

#endif

USING_NS_CC;

Scene* VideoScene::createScene(){
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	auto layer = VideoScene::create();

	 // add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool VideoScene::init(){
	if (!Layer::init() ){
		return false;
	}

	playVideo();

	return true;
}

void VideoScene::playVideo(){
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

	Size size = Director::getInstance()->getVisibleSize();
	cocos2d::experimental::ui::VideoPlayer* videoPlayer = cocos2d::experimental::ui::VideoPlayer::create();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	videoPlayer->setPosition(Point(origin.x + size.width / 2,origin.y + size.height / 2));
	videoPlayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	videoPlayer->setContentSize(Size(size.width , size.height));

	this->addChild(videoPlayer);
	videoPlayer->setFileName(VIDEO_FILE);
	videoPlayer->play();

	auto lambastartgame = [=](Ref* pSender,const cocos2d::experimental::ui::VideoPlayer::EventType eventType)
	{

		switch (eventType) {
			case cocos2d::experimental::ui::VideoPlayer::EventType::PLAYING:
				break;
			case cocos2d::experimental::ui::VideoPlayer::EventType::PAUSED:
				break;
			case cocos2d::experimental::ui::VideoPlayer::EventType::STOPPED:
				break;
			case cocos2d::experimental::ui::VideoPlayer::EventType::COMPLETED:
			{
//				auto scene = MainMenuScene::createScene();
//				// run
//				Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
				break;
			}
			default:
				break;
		}
	};
	videoPlayer->addEventListener(lambastartgame);

	//对手机返回键的监听
	auto listener = EventListenerKeyboard::create();
	//和回调函数绑定
	listener->onKeyReleased = CC_CALLBACK_2(VideoScene::onKeyReleased,this);
	//添加到事件分发器中
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);
}

void VideoScene::stopVideo(){

}

void VideoScene::onKeyReleased(EventKeyboard::KeyCode keyCode,Event * pEvent){
	 switch (keyCode){
	 	 case EventKeyboard::KeyCode::KEY_BACK:
	 		backToMainScene();
	 		break;
	 	case EventKeyboard::KeyCode::KEY_MENU:      //菜单监听
	 	    break;
		case::EventKeyboard::KeyCode::KEY_HOME:
			break;
	 }
}

void VideoScene::backToMainScene(){
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	Director::getInstance()->popScene();
}
