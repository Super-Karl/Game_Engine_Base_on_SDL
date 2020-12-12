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
	cout << "enter CPlayState\n";
	//���￪ʼд����

	return true;
}

void CPlayState::inputHandle()
{
	CInputHandle::Instance()->update();
	//���￪ʼд����

}

void CPlayState::update()
{
}

void CPlayState::render()
{
	SDL_RenderClear(CGame::Instance()->getRenderer());
	//���￪ʼд����

	SDL_RenderPresent(CGame::Instance()->getRenderer());
}

bool CPlayState::onExit()
{
	cout << "exit CPlayState\n";
	//���￪ʼд����

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