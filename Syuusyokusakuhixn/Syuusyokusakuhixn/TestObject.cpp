#include "TestObject.h"
#include"ComponentManager.h"
#include"TestComponent.h"
TestObject::TestObject(const GameObjectId m_gameObjectId) :GameObject(m_gameObjectId)
{
}



void TestObject::Init()
{
	TestComponent* testCom = AddComponent<TestComponent>();
}

void TestObject::Uninit()
{
}

void TestObject::Update()
{
}
