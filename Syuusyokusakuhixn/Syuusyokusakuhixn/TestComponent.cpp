#include "TestComponent.h"
#include<iostream>

TestComponent::TestComponent(const GameObjectId _gameObjectId) :Component(_gameObjectId)
{
	std::cout << "ì¬FTectComponent" << std::endl;

}

void TestComponent::Init()
{
	std::cout << "ì¬FTectComponent" << std::endl;
}

void TestComponent::Uninit()
{
}
