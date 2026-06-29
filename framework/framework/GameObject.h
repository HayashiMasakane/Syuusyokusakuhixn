#pragma once
#include<string>
#include<unordered_map>



namespace Framework
{
	namespace Component
	{
		class Component;
	}

	namespace GameObject
	{
		/// <summary>
		/// GameObject基底クラス
		/// インスタンスはオブジェクトマネージャーが持つ
		/// </summary>
		class GameObject
		{
		private:
			

			bool m_deleteFlag = false;
			std::unordered_map<std::string, Component::Component*> m_componentMap;

		protected:
			//	派生オブジェクトの処理用
			virtual void OnInit() = 0;
			virtual void OnUninit() = 0;


			template<typename T>
			T* AddComponent(std::string _componentName);
			template<typename T>
			T* GetComponent(std::string _componentName);

		public:
			GameObject() = default;
			~GameObject() = default;

			void Init();
			void Uninit();

			void SetDeleteFlag();
			bool GetDeleteFlag();


	
		};

	}//	GameObject
}//	Framework



#include"Refer.h"
#include"ComponentManager.h"
#include"Component.h"
namespace Framework
{

	namespace GameObject
	{
		
		/// <summary>
		/// コンポーネントの追加
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="_componentName"></param>
		/// <returns></returns>
		template<typename T>
		inline T* GameObject::AddComponent(std::string _componentName)
		{


			T* component = Refer::GetInstanse().GetComponentManager()->AddComponent<T>();

			m_componentMap[_componentName] = component;
			return component;

		}

		/// <summary>
		/// コンポーネントの取得
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="_componentName"></param>
		/// <returns></returns>
		template<typename T>
		inline T* GameObject::GetComponent(std::string _componentName)
		{
			//	コンポーネント名の物がないならはじく
			if (!m_componentMap.contains(_componentName))
			{
				return nullptr;
			}

			auto* component = m_componentMap[_componentName];


			return dynamic_cast<T*>(component);
		}
	}
}

