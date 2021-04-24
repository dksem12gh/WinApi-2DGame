#include "stdafx.h"
#include "mainGame.h"
#include "playScene.h"
#include "titleScene.h"

//=========================
//	## init(void) ## �ʱ�ȭ
//=========================
HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	//�̰����� �ʱ�ȭ

	SCENEMANAGER->addScene("title", new titleScene);
	SCENEMANAGER->addScene("play", new playScene);

	SCENEMANAGER->changeScene("title");
	return S_OK;
}

//=====================
//	## release(void) ##
//=====================
void mainGame::release(void)
{
	gameNode::release();

	//�����Ҵ��� �ߴٸ� ���⿡�� SAFE_DELETE() ���
}

//=============================
//	## update(void) ## ������Ʈ
//=============================
void mainGame::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

	//�̰����� ����, Ű����, ���콺��� ������Ʈ�� �Ѵ�
}

//============================
//	## render(HDC hdc) ## ����
//============================

void mainGame::render(float setfps)
{
	//������ �� ��Ʈ�� (�̰͵� ������ �״�� �Ѱ�)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//=============================================================

	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());

	//=============================================================
	//������� ������ HDC�� �׸���
	this->getBackBuffer()->render(getHDC());
}
