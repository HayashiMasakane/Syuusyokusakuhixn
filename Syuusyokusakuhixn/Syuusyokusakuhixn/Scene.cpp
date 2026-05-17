#include "Scene.h"



GameObjectManager& Scene::GetGameObjectManager()
{
	return m_gameObjectManager;
}

ComponentManager& Scene::GetComponentManager()
{
	return m_componentManager;
}
