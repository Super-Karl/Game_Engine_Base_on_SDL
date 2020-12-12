#include "CFileManage.h"
#include "CPlayState.h"
#include "CTextureManager.h"
#include "CAudioManage.h"
#include "CFontManager.h"
#include "CInputHandle.h"
#include <iostream>
#include <time.h>

const string CPlayState::s_StateID = "PLAYSTATE";

bool CPlayState::onEnter()
{
	cout << "enter CPlayState123\n";
	//这里开始写代码

	return true;
}

void CPlayState::inputHandle()
{
	CInputHandle::Instance()->update();
	//这里开始写代码

}

void CPlayState::update()
{
}

void CPlayState::render()
{
	SDL_RenderClear(CGame::Instance()->getRenderer());
	//这里开始写代码

	SDL_RenderPresent(CGame::Instance()->getRenderer());
}

bool CPlayState::onExit()
{
	cout << "exit CPlayState\n";
	//这里开始写代码

	return true;
}

string CPlayState::getStateID()
{
	return s_StateID;
}

void CPlayState::addSprite(CObject* sprite)
{
	m_CSpriteList.push_back(sprite);
}

void CPlayState::deleteSprite(CObject* sprite)
{
	m_CSpriteList.erase(std::remove(m_CSpriteList.begin(), m_CSpriteList.end(), sprite), m_CSpriteList.end());
}