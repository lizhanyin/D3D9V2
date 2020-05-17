#include "MScene.h"
#include <iostream>
//��ʼ����������
GAME_SCENE MScene::GameProgress = GAME_SCENE::GS_Login;
static bool kBtn1 = true;
static bool kBtn2 = true;
static bool kBtn3 = true;
MScene::MScene()
{

}

bool MScene::Init()
{
	std::cout << "[" << this << "]" << "MScene::Init()\t" << std::endl;

	//��������
	mSLogin = new SceneLogin();


	return true;
}

//��������
bool MScene::Update()
{
	SetKey();

	switch (GameProgress)
	{
		case GAME_SCENE::GS_Login:
			SetScene(mSLogin);
			break;
		case GAME_SCENE::GS_SelectRole:
			SetScene(mSelRole);
			//SetScene(nullptr);
			break;
		case GAME_SCENE::GS_World:
			SetScene(mWorld);
			//SetScene(nullptr);
			break;
		default:
			break;
	}
	return true;
}

void MScene::SetKey() {
	if (GetAsyncKeyState('1'))
	{
		if (kBtn1)
		{
			//��½����
			mSLogin = new SceneLogin();
			GameProgress = GAME_SCENE::GS_Login;
			kBtn1 = false;
		}
	}
	else if (!kBtn1)
	{
		kBtn1 = true;
	}

	if (GetAsyncKeyState('2'))
	{
		if (kBtn2)
		{
			//�л�����ɫ
			mSelRole = new SceneSelRole();
			GameProgress = GAME_SCENE::GS_SelectRole;
			kBtn2 = false;

		}
	}
	else if (!kBtn2)
	{
		kBtn2 = true;
	}

	if (GetAsyncKeyState('3'))
	{
		if (kBtn3)
		{
			//��Ϸ����
			mWorld = new SceneWorld();
			GameProgress = GAME_SCENE::GS_World;
			kBtn3 = false;
		}
	}
	else if (!kBtn3)
	{
		kBtn3 = true;
	}
}

MScene::~MScene()
{
	std::cout << "[X]" << "[" << this << "]" << "MScene::~MScene()\t" << std::endl;
}