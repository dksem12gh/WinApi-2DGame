#include "stdafx.h"
#include "fieldObject.h"

//�ڽ� �̹���
HRESULT fieldObject::init(string imageName,OBJECTDISCERN discernNum, int appearMapNum, POINT pos)
{
	_image = IMAGEMANAGER->findImage(imageName);
	_discernNum = discernNum;
	_appearMapNum = appearMapNum;

	_x = pos.x;
	_y = pos.y;

	_effectBullet = false;

	//�ӽ� �÷��̾� ��ǥ - �÷��̾�� �޾ƿ;��� - �޾ƿ;��� �� - �÷��̾�cpp ������ getPos
	_playerPoint.x = 100;
	_playerPoint.y = 500;
	//�ӽ� �÷��̾� ���� - �÷��̾�� �޾ƿ;��� - �޾ƿ;��� �� - �÷��̾�cpp ������ _curRight
	_curRight = true;
	_numK = 0;
	if (_image == NULL)
	{
		_rc = RectMakeCenter(_x, _y, 100, 100);
	}
	else
	{
		_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	}

	_effectImage = IMAGEMANAGER->findImage("�Ѿ�����");
	_discernNum = discernNum;
	_appearMapNum = appearMapNum;

	_x = pos.x;
	_y = pos.y;

	//�ӽ� �÷��̾� ��ǥ - �÷��̾�� �޾ƿ;��� - �޾ƿ;��� �� - �÷��̾�cpp ������ getPos
	_playerPoint.x = 100;
	_playerPoint.y = 500;
	//�ӽ� �÷��̾� ���� - �÷��̾�� �޾ƿ;��� - �޾ƿ;��� �� - �÷��̾�cpp ������ _curRight
	_curRight = true;

	if (_effectImage == NULL)
	{
		_rc = RectMakeCenter(_x, _y, 100, 100);
	}
	else
	{
		_rc = RectMakeCenter(_x, _y, _effectImage->getFrameWidth(), _effectImage->getFrameHeight());
	}

	return S_OK;
}


void fieldObject::release(void)
{
}

void fieldObject::update(POINT playerPosition, vector<bullet*> bulletPos)
{
}

void fieldObject::boomEffect()
{
}

void fieldObject::absorption(POINT playerPos)
{

}
