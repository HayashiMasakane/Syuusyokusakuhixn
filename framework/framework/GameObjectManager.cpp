#include "GameObjectManager.h"
#include"GameObject.h"

namespace Framework
{
	namespace GameObject
	{
		GameObjectManager::~GameObjectManager()
		{
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
			}


			return nullptr;
		}

		/// <summary>
		/// ゲームオブジェクトを削除処理関数を動かす予約をする。
		/// これとは別でオブジェクト自身が
		/// </summary>
		void GameObjectManager::SetGameObjectDeleteFlag()
		{
			m_gameObjectDeleteFlag = true;
		}

		/// <summary>
		/// ゲームオブジェクトの削除予約がされているかどうかを取得
		/// </summary>
		bool GameObjectManager::GetGameObjectDeleteFlag()
		{
			return m_gameObjectDeleteFlag;
		}


	}
}
