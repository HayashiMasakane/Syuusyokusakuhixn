#include "GameObject.h"
#include<iostream>
#include<string>
#include "GameObjectManager.h"

namespace Framework
{
	namespace GameObject
	{

		/// <summary>
		/// 派生オブジェクトの初期化を動かす
		/// </summary>
		void GameObject::Init()
		{
			OnInit();

			std::cout << "コンポーネントのエラー確認" << std::endl;
			//	取得しているコンポーネントに値がちゃんと入っているかを確認
			for (const auto& component : m_componentMap)
			{
				//	ポインタ変数が初期化されていないならエラー分を出す
				if (!component.second->HasMethodPointerComponent())
				{
					std::cout << "エラー" << std::endl;
				}
			}

		}

		/// <summary>
		/// 派生オブジェクトの初期化を動かす
		/// </summary>
		void GameObject::Uninit()
		{
			//	コンポーネントの終了予約
			for (auto& component : m_componentMap)
			{
				component.second->SetDeleteFlag();
			}

			OnUninit();
		}


		/// <summary>
		/// 自身の削除予約をする
		/// </summary>
		void GameObject::SetDeleteFlag()
		{
			m_deleteFlag = true;
		}

		/// <summary>
		/// 自身が削除予約されているかどうかを取得
		/// </summary>
		/// <returns>予約されているならtrue</returns>
		bool GameObject::GetDeleteFlag()
		{
			return m_deleteFlag;
		}


	}//	GameObject

}//	Framework



