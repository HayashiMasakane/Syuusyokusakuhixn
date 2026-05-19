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
	std::cout << "DeleteComponent" << std::endl;
	for (auto& pair : m_componentMap)
	{
		const std::type_index& type = pair.first;
		void* ptr = pair.second;

		// Œ^–¼‚ðo—Í
		std::cout << " ComponentType:" << type.name() << std::endl;

		// vector<T> ‚ð delete
		delete static_cast<std::vector<char>*>(ptr);
	}

	std::cout << std::endl;

	std::cout << "m_componentMap.clear()" << std::endl;
	m_componentMap.clear();

}