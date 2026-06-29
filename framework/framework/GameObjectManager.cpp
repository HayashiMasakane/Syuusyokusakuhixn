#include "GameObjectManager.h"

namespace Framework
{
	namespace GameObject
	{
		/// <summary>
		/// デストラクタ
		/// ソリッド変数すべてを削除
		/// </summary>
		GameObjectManager::~GameObjectManager()
		{
			for (auto& object : m_gameObjectMap)
			{
				object.second->Uninit();
			}

			m_gameObjectMap.clear();
		}
		void GameObjectManager::Init()
		{

		}

		/// <summary>
		/// 生成されたオブジェクト全てを削除する
		/// </summary>
		void GameObjectManager::Uninit()
		{
			for (auto& object : m_gameObjectMap)
			{
				object.second->Uninit();
			}

			m_gameObjectMap.clear();

		}

		/// <summary>
		/// 引数名のゲームオブジェクトのポインタを取得
		/// </summary>
		/// <param name="_gameObjectName">AddGameObjectで登録した引数名</param>
		/// <returns></returns>
		GameObject* GameObjectManager::GetGameObject(std::string _gameObjectName)
		{
			//	引数が登録されていないならはじく
			if (!m_gameObjectMap.contains(_gameObjectName))
			{
				std::string msg =
					"引数名:[" + _gameObjectName + "]のゲームオブジェクトはありません。";

				MessageBoxA(
					NULL,        // 親ウィンドウ（NULLでOK）
					msg.c_str(),    // 本文（メッセージ）
					"GetGameObject", // タイトル
					MB_OK | MB_ICONWARNING       // アイコンやボタンの種類
				);
				return nullptr;

			}

			return	m_gameObjectMap[_gameObjectName].get();

		}

		/// <summary>
		/// 削除予約されているオブジェクトを削除していく
		/// </summary>
		void GameObjectManager::DeteleGameObject()
		{

			for (auto& object : m_gameObjectMap)
			{
				//	削除予約されているなら削除する
				if (object.second->GetDeleteFlag())
				{
					object.second->Uninit();
					
				}

			}

		}

	}//	GameObject
}//	Framework
