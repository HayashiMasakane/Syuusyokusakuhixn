#pragma once
#include<unordered_map>
#include<memory>
#include<string>
#include<Windows.h>


namespace Framework
{
	namespace GameObject
	{
		class GameObject;
		/// <summary>
		/// コピー禁止オブジェクトマネージャークラス
		/// 生成削除の責任を持つ
		/// </summary>
		class GameObjectManager
		{
		private:
			/// <summary>
			/// オブジェクトのポインタを管理する
			/// string objectName;
			/// unique_ptr<Object> オブジェクトのポインタ
			/// </summary>
			std::unordered_map<std::string, std::unique_ptr<Framework::GameObject::GameObject>> m_gameObjectMap;

		public:
			GameObjectManager() = default;
			~GameObjectManager();

			void Init();
			void Uninit();

			template <typename T>
			GameObject* AddGameObject(std::string _gameObjectName);
			GameObject* GetGameObject(std::string _gameObjectName);

			void DeteleGameObject();

		};





	}//	Object
}//	Framework


#include"GameObject.h"
namespace Framework
{
	namespace GameObject
	{
		/// <summary>
/// ゲームオブジェクトを追加する
/// シーン内で同じ名前があるなら追加せずにnullptrを返す
/// </summary>
/// <typeparam name="T">派生オブジェクトクラス</typeparam>
/// <param name="_gameObjectName">Tにつけたい名前</param>
/// <returns>Tのポインタ</returns>
		template<typename T>
		inline GameObject* GameObjectManager::AddGameObject(std::string _gameObjectName)
		{
			//	すでに引数内の名前が使われているなら弾く
			if (m_gameObjectMap.contains(_gameObjectName))
			{
				std::string msg =
					"引数名:[" + _gameObjectName + "]のゲームオブジェクトは既に登録されています。";
				MessageBoxA(
					NULL,        // 親ウィンドウ（NULLでOK）
					msg.c_str(),    // 本文（メッセージ）
					"AddGameObject", // タイトル
					MB_OK | MB_ICONWARNING        // アイコンやボタンの種類
				);

				return nullptr;

			}

			//	オブジェクトの生成し返す
			m_gameObjectMap[_gameObjectName] = std::make_unique<T>();

			m_gameObjectMap[_gameObjectName].get()->Init();
			return m_gameObjectMap[_gameObjectName].get();

		}
	}
}
