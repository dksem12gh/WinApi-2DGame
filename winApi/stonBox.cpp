#include "stdafx.h"
#include "stonBox.h"

HRESULT stonBox::init(string objectName, OBJECTDISCERN discernNum, int mapNum, POINT pos)
{
	_appearMapNum = 0;
	_discernNum = stonbox;
	_x = 200.0f;
	_y = 100.0f;
	_rc = RectMakeCenter(_x, _y, 100, 100);

	fieldObject::init(objectName, discernNum, mapNum, pos);

	_image = IMAGEMANAGER->findImage("�ڽ�������Ʈ");
	_objNumberX = 0;
	_objNumberY = 6;

	//���� ����� Ÿ�̸�
	_absoCount = 0;
	_absoTimer = TIMEMANAGER->getWorldTime();
	_absoWorldTimer = TIMEMANAGER->getWorldTime();

	//���� ��ǥ �ʱ�
	box_x = _x;

	//�¿��Ǵ�
	curRight = true;
	count = 0;
	return S_OK;
}

void stonBox::update(POINT playerPosition, vector<bullet*> bulletPos)
{
	move();

	for (int i = 0; i < bulletPos.size(); i++)
	{
		if (IntersectRect(&_rcTemp, &bulletPos[i]->getrc(), &_rc))
		{
			_effectBullet = true;
			bulletPos[i]->setState(2);
		}
	}
	if (_effectBullet)
	{
		bulletEffect();
	}
}

void stonBox::move()
{
	if (_image == NULL)
	{
		_rc = RectMakeCenter(_x, _y, 100, 100);
	}
	else
	{
		_rc = RectMakeCenter(_x, _y, _image->getFrameWidth()+5, _image->getFrameHeight());
	}
}

//�÷��̾� ����� ������ ������Ʈ �Լ� ���� ����
void stonBox::absorption(POINT playerPoint)
{
	if (playerPoint.x < _x)
	{
		curRight = true;
	}
	else
	{
		curRight = false;
	}

	if (curRight) // - �÷��̾� ������ ����
	{
		_absoWorldTimer = TIMEMANAGER->getWorldTime();
		countR++;
		countL++;
		if (countR % 8 == 0)
		{
			_x -= 5;
		}
		if (countL % 16 == 0)
		{
			_x += 8;
		}
		

		if (_absoWorldTimer - _absoTimer > 0.01f)
		{
			box_x = _x;
			_absoTimer = TIMEMANAGER->getWorldTime();
		}
	else
	{
		_x = box_x - 1;
	}
}//���� ������ Ʈ���϶�

	else//���� ������ �޽��϶� - �÷��̾� ���� ����
	{
			_absoWorldTimer = TIMEMANAGER->getWorldTime();
			countR++;
			countL++;
			if (countR % 8 == 0)
			{
				_x += 5;
			}
			if (countL % 16 == 0)
			{
				_x -= 8;
			}


			if (_absoWorldTimer - _absoTimer > 0.01f)
			{
				box_x = _x;
				_absoTimer = TIMEMANAGER->getWorldTime();
			}
		else
		{
			_x = box_x + 1;
		}
	}
}

void stonBox::bulletEffect()
{

	_bulletRc = RectMakeCenter(_rcTemp.left, _rcTemp.top, 100, 100);

	_effectImage = IMAGEMANAGER->findImage("�Ѿ�����");

	_effectNumberY = 0;

	_boomWorldTimer = TIMEMANAGER->getWorldTime();

	if (_boomWorldTimer - _boomTimer > 0.05f)
	{
		_effectNumberX = count;
		count++;
		_boomTimer = TIMEMANAGER->getWorldTime();
		if (count == 6)
		{
			count = 0;
			_effectBullet = false;
		}
	}
}
