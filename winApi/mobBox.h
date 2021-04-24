#pragma once
#include "fieldObject.h"
#include<math.h>

#define PI 3.141159265358979323
#define Speed 2.0f;

struct mobStruct
{
	float angle;	//����
	float radius;	//������
	float _mobx;
	float _moby;
};

class mobBox :
	public fieldObject
{
private:
	mobStruct mobstruct;
	randomFunction* rand;
	//�� ������Ʈ�� ī��Ʈ Ÿ�̸�
	int mobCount;
	float _mobTimer;
	float _mobWorldTimer;

	//�Ѿ� ����
	int count;
	float _boomTimer;
	float _boomWorldTimer;

	//�¿��̵�
	int circleCount;
	float _circleTimer;
	float _circleWorldTimer;
	bool circleBool;

	//���� �̵�
	int updownCount;
	float _updownTimer;
	float _updownWorldTimer;
	bool updownBool;

	int _rand;
public:

	HRESULT init(string objectName, OBJECTDISCERN discernNum, int mapNum, POINT pos);
	void update(POINT playerPosition, vector<bullet*> bulletPos);

	void move();
	void bulletEffect();
	void moving();
	void moving01();
	void moving2();
	void circle();

	mobBox(){}
	~mobBox(){}
};

