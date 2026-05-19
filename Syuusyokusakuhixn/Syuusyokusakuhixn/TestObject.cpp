#include "TestObject.h"
#include<iostream>
#include"TestComponent.h"


TestObject::TestObject(GameObjectId _gameObjectId, ComponentManager& _componentManager) : GameObject(_gameObjectId, _componentManager)
{
}


void TestObject::Init()
{
	TestComponent* testCom = AddComponent<TestComponent>();

}

void TestObject::Uninit()
{
	std::cout << "TestObject‚ðíœ" << std::endl;
}

void TestObject::Update()
{
}
