#include "TestScene.h"
#include"TestObject.h"



void TestScene::Init()
{
	GameObject* test = GetGameObjectManager().AddGameObject<TestObject>("testObject");
}

void TestScene::Uninit()
{
}

void TestScene::Update()
{
}

void TestScene::Draw()
{
}
