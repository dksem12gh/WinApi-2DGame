#include "stdafx.h"
#include "drinkItem.h"

HRESULT drinkItem::init(string objectName, OBJECTDISCERN discernNum, int mapNum, POINT pos)
{
	_appearMapNum = 0;
	_discernNum = drink;
	_x = 500.0f;
	_y = 300.0f;
	_rc = RectMakeCenter(_x, _y, 100, 100);
	count = 0;
	fieldObject::init(objectName, discernNum, mapNum, pos);

	_image = IMAGEMANAGER->findImage("������");

	_objNumberX = 0;
	_objNumberY = 1;

	_boomTimer = TIMEMANAGER->getWorldTime();
	_boomWorldTimer = TIMEMANAGER->getWorldTime();

	return S_OK;
}

void drinkItem::update(POINT playerPosition, vector<bullet*> bulletPos)
{
	move();
	flash();

	for (int i = 0; i < bulletPos.size(); i++)
	{
		if (IntersectRect(&_rcTemp, &bulletPos[i]->getrc(), &_rc))
		{
			wind(playerPosition);
		}
	}
}
void drinkItem::wind(POINT playerPos)
{
	//�÷��̾� ��ǥ�� �¿� ���� üũ
	if (playerPos.x < _x)
	{
		_curRight = false;
	}
	else
	{
		_curRight = true;
	}

	if (_curRight)
	{
		_x -= 1;
	}
	else
	{
		_x += 1;
	}
}
void drinkItem::move()
{
	if (_image == NULL)
	{
		_rc = RectMakeCenter(_x, _y, 100, 100);
	}
	else
	{
		_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	}
}

void drinkItem::flash()
{
	_image = IMAGEMANAGER->findImage("������");
	_objNumberY = 4;
	_boomWorldTimer = TIMEMANAGER->getWorldTime();

	if (_boomWorldTimer - _boomTimer > 0.1f)
	{
		_objNumberX = count;
		count++;
		_boomTimer = TIMEMANAGER->getWorldTime();
		if (count == 6)
		{
			count = 0;
		}
		//if (count == 2)
		//{
		//	count = 0;
		//	_state = 2;
		//}
	}
}
//�÷��̾����� ��ȣ�ۿ� �Լ�
void drinkItem::absorption(POINT playerPos)
{
	//�÷��̾� ��ǥ�� �¿� ���� üũ
	if (playerPos.x < _x)
	{
		_curRight = true;
	}
	else
	{
		_curRight = false;
	}

	//���⿡ ���� ������ġ �޶���
	if (_curRight) // ������
	{
		if (playerPos.y < _y)
		{
			_y -= speed;
			_x -= speed;
		}
		else
		{
			_y += speed;
			_x -= speed;
		}


	}//������ ���� ��

	else // ���� ����
	{
		if (playerPos.y > _y)
		{
			_y += speed;
			_x += speed;
		}
		else
		{
			_y -= speed;
			_x += speed;
		}
	}//���� ���� ��
}
