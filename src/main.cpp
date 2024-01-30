#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

using namespace geode::prelude;
bool m_showPause = true;

class $modify(MyPauseLayer,PauseLayer)
{

	void onMyButton(CCObject* target) {
		m_showPause = !m_showPause;
		if (m_showPause) 
		{
			this->customSetup();
		}
		else 
		{
			this->removeAllChildren();
			this->setOpacity(0);
			auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_pauseEditorBtn_001.png");
			auto button = CCMenuItemSpriteExtra::create(
				buttonSprite, nullptr, this,
				menu_selector(MyPauseLayer::onMyButton)
			);
			button->setOpacity(50);
			auto menu = CCMenu::create();
			menu->addChild(button);
			menu->setPosition(25, 25);
			this->addChild(menu);
		}
	}

	void customSetup()
	{
		if (m_showPause) 
		{
			this->removeAllChildren();
			PauseLayer::customSetup();
		}
		else
		{
			this->removeAllChildren();
			this->setOpacity(0);
		}
		auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_pauseEditorBtn_001.png");
		auto button = CCMenuItemSpriteExtra::create(
			buttonSprite, nullptr, this,
			menu_selector(MyPauseLayer::onMyButton)
		);
		button->setOpacity(50);
		auto menu = CCMenu::create();
		menu->addChild(button);
		menu->setPosition(25, 25);
		this->addChild(menu);
	}
};