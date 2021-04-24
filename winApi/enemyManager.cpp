#include "stdafx.h"
#include "enemyManager.h"

HRESULT enemyManager::init(void)
{
	IMAGEMANAGER->addFrameImage("�͵��", "enemy/waddle.bmp", 266*3, 600*3, 4, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "enemy/frog.bmp", 333*3, 300*3, 5, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����","enemy/bronto.bmp", 200 * 3, 500 * 3, 3, 5, true, RGB(0, 255, 0));
	IMAGEMANAGER->addFrameImage("����ũ", "enemy/spark.bmp", 1000 * 3, 400 * 3, 15, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĥ��", "enemy/chilly.bmp", 533 * 3, 300 * 3, 8, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "enemy/burning.bmp", 933*3, 600*3, 14, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����ص�", "image/treeboss.bmp", 200 * 3, 380 * 3, 5, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����ü�¹�", "enemy/hpbar.bmp", 1650*2, 30*2, 11, 1, true, RGB(255, 0, 255));
	enemy* em;


	/*em = new waddle;
	em->init("�͵��", waddledee, 0, PointMake(200, 0));
	_vEnemy.push_back(em);

	em = new frog;
	em->init("������", Frog, 0, PointMake(2030, 460));
	_vEnemy.push_back(em);

	em = new brontoburt;
	em->init("�����", Bronto, 0, PointMake(898, 400));
	_vEnemy.push_back(em);

	em = new brontoburt;
	em->init("�����", Bronto, 0, PointMake(2435, 200));
	_vEnemy.push_back(em);

	em = new spark;
	em->init("����ũ", Spark, 0, PointMake(2250, 300));
	_vEnemy.push_back(em);

	em = new chilly;
	em->init("ĥ��", Chilly, 0, PointMake(2700, 350));
	_vEnemy.push_back(em);

	em = new burning;
	em->init("����", Burning, 0, PointMake(220, 250));
	_vEnemy.push_back(em);

	em = new woodboss;
	em->init("�����ص�", treeboss, 3, PointMake(700, 600));
	_vEnemy.push_back(em);*/

	//0����
	em = new waddle;
	em->init("�͵��", waddledee, 0, PointMake(200, 0));
	_vEnemy.push_back(em);

	em = new brontoburt;
	em->init("�����", Bronto, 0, PointMake(898, 400));
	_vEnemy.push_back(em);

	em = new spark;
	em->init("����ũ", Spark, 0, PointMake(2250, 300));
	_vEnemy.push_back(em);

	em = new chilly;
	em->init("ĥ��", Chilly, 0, PointMake(2700, 350));
	_vEnemy.push_back(em);
	//1����
	em = new brontoburt;
	em->init("�����", Bronto, 1, PointMake(1000, 150));
	_vEnemy.push_back(em);

	em = new spark;
	em->init("����ũ", Spark, 1, PointMake(2200, 150));
	_vEnemy.push_back(em);

	em = new chilly;
	em->init("ĥ��", Chilly, 1, PointMake(1000, 150));
	_vEnemy.push_back(em);

	em = new burning;
	em->init("����", Burning, 1, PointMake(220, 250));
	_vEnemy.push_back(em);
	//2����
	em = new chilly;
	em->init("ĥ��", Chilly, 2, PointMake(500, 250));
	_vEnemy.push_back(em);

	em = new spark;
	em->init("����ũ", Spark, 2, PointMake(1500, 150));
	_vEnemy.push_back(em);

	em = new chilly;
	em->init("ĥ��", Chilly, 2, PointMake(3000, 0));
	_vEnemy.push_back(em);

	em = new burning;
	em->init("����", Burning, 2, PointMake(2500, 250));
	_vEnemy.push_back(em);
	em = new woodboss;
	em->init("�����ص�", treeboss, 3, PointMake(700, 500));
	_vEnemy.push_back(em);



	return S_OK;
}

void enemyManager::release(void)
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end();)
	{
		(*_viEnemy)->release();
		SAFE_DELETE(*_viEnemy);
		_viEnemy = _vEnemy.erase(_viEnemy);
	}
}

void enemyManager::update(image* pixelimage, POINT playerPoint, vector<fieldObject*> objectVec, vector<bullet*> bulletVec, int curMapNum, bulletManager* BulletManager)
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end();)
	{
		if (curMapNum == (*_viEnemy)->getAppearMapNum())
		{
			(*_viEnemy)->update(pixelimage, playerPoint, objectVec, bulletVec, BulletManager);
			if ((*_viEnemy)->getState() == 2)
			{
				(*_viEnemy)->release();
				_viEnemy = _vEnemy.erase(_viEnemy);
			}
			else
			{
				++_viEnemy;
			}
		}
		else
		{
			++_viEnemy;
		}
	}

	
}


void enemyManager::mapmonster1()
{
	

}

void enemyManager::mapmonster2()
{

}

void enemyManager::mapmonster3()
{
	enemy* em;
	
	
	

}

