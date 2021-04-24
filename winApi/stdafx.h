// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//
#pragma once

#include <SDKDDKver.h>

// ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#define WIN32_LEAN_AND_MEAN

// Windows ��� ����:
#include <Windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

// C++ ��Ÿ�� ��� �����Դϴ�.
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//======================================
//	## ���� ���� ��������� �̰��� �߰� ##
//======================================
#include "commonMacroFiunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "utils.h"
#include "timeManager.h"
#include "sceneManager.h"
#include "soundManager.h"

using namespace MY_UTIL;

//================================
//	## �̱����� �̰��� �߰��Ѵ� ##
//================================
#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()

//================================
//	## ��ũ�� ## (������â �ʱ�ȭ)
//================================
#define WINNAME			(LPTSTR)(TEXT("WindowAPI"))
#define WINSTARTX		400
#define WINSTARTY		100
#define WINSIZEX		800
#define WINSIZEY		500
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

//=================================================
//	## ��ũ�� �Լ� ## (Ŭ�������� �����Ҵ�� �κ� ����)
//=================================================
#define SAFE_DELETE(p)			{if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = NULL;}}

//================
//	## �������� ##
//================
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;

typedef enum OBJECTDISCERN
{
	// ==========   state 1,3,5,6 ��� ����   ===============

	//������Ʈ state = 2 -> ��ź �ڽ��� Ŀ�� �����̵�,������,����������� �浹�Ҷ� �Ҹ��ϴ� ���� 
	//������Ʈ state = 4 -> Ŀ�� ���������� ��Ÿ�ڽ�, ������ ����Ҷ� �Ҹ��ϴ� ����

	//��Ÿ�ڽ� - ��� ������ �Ͼ�� �� �ڽ�
	//�� �ڽ� - ��ź ������Ʈ
	//���� �ڽ� - �÷��̾� ��� �ÿ��� �����̴� �ڽ�
	//�� - ���� ������Ʈ - �ı� ��� �Ұ� / �浹�� �÷��̾�� ������
	//���̾� - ��ź �ı� x �÷��̾� ��� x
	starbox,boombox,stonbox,mob,ironbox,sandbox,

	//�� ������ - ��� 1 ���� ������
	//ĵ�� ������ - ü�� ���� - ������ �����
	//�ƽ� ������ - ü�� Ǯ ȸ��
	//��� ������ - ü�� ȸ�� - ������ �����
	//���� ������ - ü�� ȸ�� - ������ �����
	//ü�� ������ - ü��ȸ�� - ������ �����
	upItem,candyitem,maxtem,meat,drink,cherry,ENDING
};

typedef enum ENEMYDISCERN
{
	enemyBox,
	waddledee,
	Frog,
	Bronto,
	Burning,
	Spark,
	Chilly,
	treeboss
};

typedef enum BULLETDISCERN
{
	Breath,
	Star,
	BossBreath,
	BossApple
};