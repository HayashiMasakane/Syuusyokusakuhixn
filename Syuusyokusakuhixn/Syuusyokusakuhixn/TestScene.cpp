#include "TestScene.h"
#include<iostream>
#include"TestObject.h"

TestScene::TestScene(std::string _sceneName) :Scene(_sceneName)
{
}



void TestScene::Init()
{
	GameObject* test = AddGameObject<TestObject>("testObject");
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
