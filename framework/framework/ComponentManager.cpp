#include "ComponentManager.h"
#include"Component.h"


namespace Framework
{
	namespace Component
	{
		/// <summary>
		///	全てのコンポーネントを削除する
		/// </summary>
		ComponentManager::~ComponentManager()
		{
			//	各Component配列を取得後、配列をforで回し、
			//	削除処理をする
			for (auto& components : m_componentMap)
			{
				for (auto& component : components.second)
				{
					component->Uninit();
				}
			}

			m_componentMap.clear();

		}

		void ComponentManager::Init()
		{

		}

		/// <summary>
		/// コンポーネントの削除処理もする
		/// </summary>
		void ComponentManager::Uninit()
		{
			if (!m_componentDeleteFlag)
			{
				return;
			}

			//	削除処理をしていく
			for (auto& components : m_componentMap)
			{
				for (int num = 0; num < components.second.size(); num++)
				{
					//	削除予約が入っているなら削除する
					if (components.second[num]->GetDeleteFlag())
					{
						components.second[num]->Uninit();

						//	末尾に移動し削除
						std::swap(components.second[num], components.second.back());
						components.second.pop_back();

						num--;
					}

				}
			}



		}

		/// <summary>
		/// 内部で削除処理を見ていく
		/// </summary>
		void ComponentManager::Update()
		{
			//	削除予約されているなら削除していく
			if (m_componentDeleteFlag)
			{

			}
		}

		void ComponentManager::SetComponentDeleteFlag()
		{
		}

		bool ComponentManager::GetComponentDeleteFlag()
		{

		}

	}//	Component
}//	Framework