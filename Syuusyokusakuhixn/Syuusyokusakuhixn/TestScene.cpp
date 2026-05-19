#include "TestScene.h"
#include<iostream>


//	オブジェクト
#include"TestObject.h"


//	システム
#include"TestSystem.h"

TestScene::TestScene(std::string _sceneName) :Scene(_sceneName)
{
}



void TestScene::Init()
{
	GameObject* test = AddGameObject<TestObject>("testObject");
	AddGameObject<TestObject>("testObject1");
	AddGameObject<TestObject>("testObject2");
	AddGameObject<TestObject>("testObject3");
	AddGameObject<TestObject>("testObject4");

}

void TestScene::Uninit()
{
}

void TestScene::Update()
{
	TestSystem(GetComponentManager());
}

void TestScene::Draw()
{
}
