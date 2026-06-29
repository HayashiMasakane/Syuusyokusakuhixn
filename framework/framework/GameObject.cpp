#include "GameObject.h"
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
		}

		/// <summary>
		/// 派生オブジェクトの初期化を動かす
		/// </summary>
		void GameObject::Uninit()
		{
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



