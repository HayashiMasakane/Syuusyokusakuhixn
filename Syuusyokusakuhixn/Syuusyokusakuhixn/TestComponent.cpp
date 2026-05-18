#include "TestComponent.h"
#include<iostream>

TestComponent::TestComponent(const GameObjectId _gameObjectId) :Component(_gameObjectId)
{
	Init();
}

TestComponent::~TestComponent()
{
	Uninit();
}

void TestComponent::Init()
{
}

void TestComponent::Uninit()
{

}
