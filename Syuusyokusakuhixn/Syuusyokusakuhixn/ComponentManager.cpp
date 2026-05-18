#include "ComponentManager.h"
#include<iostream>
ComponentManager::~ComponentManager()
{
}

void ComponentManager::Init()
{


}
void ComponentManager::Uninit()
{
	std::cout << "m_componentMap.clear()" << std::endl;
	m_componentMap.clear();

}