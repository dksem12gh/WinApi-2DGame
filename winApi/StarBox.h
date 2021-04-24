#pragma once
#include "fieldObject.h"
class StarBox : public fieldObject
{
private:
	int _mapState;
	bool _Loop;
	//���� ����Ʈ�� ���
	int count;
	float _boomTimer;
	float _boomWorldTimer;


	//�Ҹ� ���� ����Ʈ�� ���
	int bullectCount;
	float _bullectTimer;
	float _bullectWorldTimer;

	//�÷��̾� ����üũ
	bool _curRight;

	RECT rcTemp;

public:
	HRESULT init(string, OBJECTDISCERN, int, POINT);
	void update(POINT playerPosition, vector<bullet*> bulletPos);

	void move();
	void boomEffect();			//��ź ���� �������� ������ ����Ʈ
	void boomEffectBullet();	//Ŀ�� �극�� �������� ������ ����Ʈ
	void bulletEffect();		//Ŀ�� �극�� ������� ����Ʈ

	void absorption(POINT);

	StarBox() {}
	~StarBox() {}
};

