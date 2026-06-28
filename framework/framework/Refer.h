#pragma once

namespace Framework
{
	namespace Scene
	{
		class SceneManager;
	}

	namespace Component
	{
		class ComponentManager;
	}

	namespace GameObject
	{
		class GameObjectManager;
	}


	/// <summary>
	/// 現在使用されているマネージャーの参照を持つシングルトンクラス
	/// </summary>
	class Refer
	{
	private:
		friend Scene::SceneManager;	//	現在のシーンにつかわれている、マネージャーをセットするため

		Component::ComponentManager* m_componentManager = nullptr;
		GameObject::GameObjectManager* m_gameObjectManager = nullptr;

	private:
		Refer() = default;
		~Refer();
		Refer(const Refer&) = delete;
		Refer operator=(const Refer&) = delete;

		//	sceneマネージャで使用
		void SetComponentManager(Component::ComponentManager& _componentManager);
		void SetGameObjectManager(GameObject::GameObjectManager& _gameObjectManager);


	public:
		static Refer& GetInstanse();

		Component::ComponentManager* GetComponentManager();
		GameObject::GameObjectManager* GetGameObjectManager();


	};


}
