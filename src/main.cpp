#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

using namespace geode::prelude;
bool m_showPause = true;

class $modify(MyPauseLayer,PauseLayer)
{
	void changeVisibility(bool vis) 
	{
		for (int i = 0; i < this->getChildrenCount(); i++)
		{
			auto node = reinterpret_cast<CCNode*>(this->getChildren()->objectAtIndex(i));
			if (node->getID() != "hidePauseMenuMenu")
				node->setVisible(vis);
		}
		this->setOpacity(vis ? 100 : 0);
	}

	void onMyButton(CCObject* target) {
		m_showPause = !m_showPause;
		MyPauseLayer::changeVisibility(m_showPause);
	}

	void customSetup()
	{
		PauseLayer::customSetup();
		auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_pauseEditorBtn_001.png");
		auto button = CCMenuItemSpriteExtra::create(buttonSprite, nullptr, this, menu_selector(MyPauseLayer::onMyButton));
		button->setOpacity(50);
		auto menu = CCMenu::create();
		menu->setID("hidePauseMenuMenu");
		menu->addChild(button);
		menu->setPosition(25, 25);
		this->addChild(menu);
		MyPauseLayer::changeVisibility(m_showPause);
	}
};