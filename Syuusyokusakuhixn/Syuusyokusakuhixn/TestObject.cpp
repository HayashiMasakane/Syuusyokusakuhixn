#include "TestObject.h"
#include"ComponentManager.h"
#include"TestComponent.h"


TestObject::TestObject( GameObjectId _gameObjectId, ComponentManager& _componentManager) : GameObject(_gameObjectId, _componentManager)
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
