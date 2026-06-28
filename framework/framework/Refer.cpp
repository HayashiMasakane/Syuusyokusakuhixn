#include "Refer.h"
#include"GameObjectManager.h"
#include"ComponentManager.h"

namespace Framework
{
	/// <summary>
	/// ポインタを削除
	/// </summary>
	Refer::~Refer()
	{
		m_componentManager = nullptr;
		m_gameObjectManager = nullptr;
	}

	/// <summary>
	///	インスタンスを返す
	/// </summary>
	/// <returns></returns>
	Refer& Refer::GetInstanse()
	{
		static Refer instanse;

		return instanse;
	}

	/// <summary>
	/// コンポーネンとマネージャを代入する
	/// </summary>
	/// <param name="_componentManager"></param>
	void Refer::SetComponentManager(Component::ComponentManager& _componentManager)
	{
		m_componentManager = &_componentManager;
	}



	/// <summary>
	/// ゲームオブジェクトマネージャーを代入する
	/// </summary>
	/// <param name="_gameObjectManager"></param>
	void Refer::SetGameObjectManager(GameObject::GameObjectManager& _gameObjectManager)
	{
		m_gameObjectManager = &_gameObjectManager;
	}

	/// <summary>
	/// コンポーネントマネージャーを取得
	/// </summary>
	/// <param name="_gameObjectManager"></param>
	Component::ComponentManager* Refer::GetComponentManager()
	{
		return 	m_componentManager;
	}

	/// <summary>
	/// ゲームオブジェクトマネージャーを取得
	/// </summary>
	/// <returns></returns>
	GameObject::GameObjectManager* Refer::GetGameObjectManager()
	{
		return m_gameObjectManager;
	}


}

