#pragma once
#include "fieldObject.h"
class stonBox :
	public fieldObject
{
private:
	//��ǥ �ʱⰪ
	int box_x;

	//�¿��Ǵ�
	bool curRight;

	//����Ҷ� ���
	float _absoTimer;
	float _absoWorldTimer;
	int _absoCount;

	//��鸮�� ȿ�� ī��Ʈ
	int countR;
	int countL;

	int count;
	float _boomTimer;
	float _boomWorldTimer;


public:
	HRESULT init(string objectName, OBJECTDISCERN discernNum, int mapNum, POINT pos);
	void update(POINT playerPosition, vector<bullet*> bulletPos);

	void move();
	void absorption(POINT playerPoint); // �÷��̾� ����� ������ ������Ʈ
	void bulletEffect();

	stonBox(){}
	~stonBox(){}
};

