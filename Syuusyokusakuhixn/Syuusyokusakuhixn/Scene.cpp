#include "Scene.h"
#include<iostream>

Scene::Scene(const std::string& _sceneName) :m_sceneName(_sceneName)
{
}
Scene::~Scene()
{
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "~Scene:" << m_sceneName << std::endl;

	m_componentManager.Uninit();
	m_gameObjectManager.Uninit();
}
