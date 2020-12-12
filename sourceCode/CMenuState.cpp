#include "CMenuState.h"
#include "CTextureManager.h"
#include "CAudioManage.h"
#include "CFontManager.h"
#include "CInputHandle.h"
#include "enums.h"
#include <iostream>

const string CMenuState::s_StateID = "MENUSTATE";

bool CMenuState::onEnter()
{
	cout << "enter MuneState\n";
	return true;
}

void CMenuState::inputHandle()
{
	CInputHandle::Instance()->update();
	//按钮事件跟新
}

void CMenuState::update()
{
	for (int i = 0; i < m_CSpriteList.size(); i++)
	{
		m_CSpriteList[i]->update();
	}
}

void CMenuState::render()
{
	SDL_RenderClear(CGame::Instance()->getRenderer());
	//这里开始写代码
	SDL_RenderPresent(CGame::Instance()->getRenderer());
}

bool CMenuState::onExit()
{
	cout << "exit MuneState\n";
	for (int i = 0; i < m_CSpriteList.size(); i++)
	{
		delete m_CSpriteList[i];
		m_CSpriteList[i] = NULL;
	}
	return true;
}

string CMenuState::getStateID()
{
	return s_StateID;
}

void CMenuState::addSprite(CObject* sprite)
{
	m_CSpriteList.push_back(sprite);
}

void CMenuState::deleteSprite(CObject* sprite)
{
	m_CSpriteList.erase(std::remove(m_CSpriteList.begin(), m_CSpriteList.end(), sprite), m_CSpriteList.end());
}
