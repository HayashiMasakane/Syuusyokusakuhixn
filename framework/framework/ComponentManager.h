#pragma once
#include<memory>
#include<vector>
#include<typeindex>
#include<unordered_map>


namespace Framework
{
	namespace GameObject
	{
		class GameObject;
	}

	namespace Component
	{
		class Component;

		/// <summary>
		/// コピー禁止コンポーネントマネージャクラス
		/// フレンド宣言でゲームオブジェクトを持つ
		/// </summary>
		class ComponentManager
		{
		private:
			friend GameObject::GameObject;	//	AddComponentヲ使えるようにする

			using Components = std::vector<std::unique_ptr<Component>>;
			std::unordered_map<std::type_index, Components> m_componentMap;

			bool m_componentDeleteFlag = false;


		private:
			template<typename T>
			Component* AddComponent();

			


		public:
			ComponentManager() = default;
			~ComponentManager();
			ComponentManager(const ComponentManager&) = delete;
			ComponentManager operator=(const ComponentManager&) = delete;

			void Init();
			void Uninit();
			void Update();	//	コンポーネントの削除処理も入っている

			//	コンポーネントを削除削除予約するときに使う‘
			void SetComponentDeleteFlag();
			bool GetComponentDeleteFlag();


			template<typename T>
			std::vector<T*> GetComponents();

			


		};

		template<typename T>
		inline Component* ComponentManager::AddComponent()
		{
			return nullptr;
		}

		template<typename T>
		inline std::vector<T*> ComponentManager::GetComponents()
		{
			return std::vector<T*>();
		}

	}//	Component
}//	Framework