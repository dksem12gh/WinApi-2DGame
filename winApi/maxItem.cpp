#include "stdafx.h"
#include "maxItem.h"

HRESULT maxItem::init(string objectName, OBJECTDISCERN discernNum, int mapNum, POINT pos)
{
	_appearMapNum = 0;
	_discernNum = maxtem;
	_x = 500.0f;
	_y = 300.0f;
	_rc = RectMakeCenter(_x, _y, 100, 100);
	count = 0;
	fieldObject::init(objectName, discernNum, mapNum, pos);

	_image = IMAGEMANAGER->findImage("������");

	_objNumberX = 0;
	_objNumberY = 0;

	_boomTimer = TIMEMANAGER->getWorldTime();
	_boomWorldTimer = TIMEMANAGER->getWorldTime();
	return S_OK;
}

void maxItem::update(POINT playerPosition, vector<bullet*> bulletPos)
{
	move();
	flash();
}

void maxItem::move()
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

void maxItem::flash()
{
	_image = IMAGEMANAGER->findImage("������");
	_objNumberY = 2;
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

//�÷��̾���� ��ȣ�ۿ� �Լ�
void maxItem::absorption(POINT playerPos)
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

	//���⿡ ���� �����ġ �޶���
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


	}//������ ��� ��

	else // ���� ���
	{
		if (playerPos.y > _y)
		{
			_y += speed;
			_x += speed;
			if (playerPos.x - 60 <= _x)
			{
				_state = 4;
			}
		}
		else
		{
			_y -= speed;
			_x += speed;
			if (playerPos.x - 60 <= _x)
			{
				_state = 4;
			}
		}
	}//���� ��� ��
}