#pragma once
#include<Windows.h>
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
			T* AddComponent();

			


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

		/// <summary>
		/// コンポーネントの追加
		/// ゲームオブジェクトないでする
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template<typename T>
		inline T* ComponentManager::AddComponent()
		{
			static_assert(std::is_base_of<Component, T>::value,
				"T must be derived from Component");


			// 配列を取得
			std::type_index typeId(typeid(T));
			auto& components = m_componentMap[typeId];

			// コンポーネント生成
			auto component = std::make_unique<T>();
			T* pComponent = component.get();

			// 配列末尾に追加
			components.push_back(std::move(component));

			return pComponent;
		}

		/// <summary>
		/// コンポーネント配列を取得
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template<typename T>
		inline std::vector<T*> ComponentManager::GetComponents()
		{
			std::type_index typeId(typeid(T));


			return m_componentMap[typeId];
		}

	}//	Component
}//	Framework