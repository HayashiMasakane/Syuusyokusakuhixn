#pragma once
#include<unordered_map>
#include<memory>
#include<string>


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
			std::unordered_map<std::string, std::unique_ptr<GameObject>> m_gameObjectMap;
			bool m_gameObjectDeleteFlag = false;

		public:
			GameObjectManager() = default;
			~GameObjectManager();

			void Init();
			void Uninit();

			template <typename T>
			GameObject* AddGameObject(std::string _gameObjectName);
			GameObject* GetGameObject(std::string _gameObjectName);

			bool SetGameObjectDeleteFlag();
			bool GetGameObjectDeleteFlag();

		};


#include<Windows.h>
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
			// todo:AddGameObjectの中身を記述中
			if(m_ga)
			MessageBoxA(
				HWND hWnd,        // 親ウィンドウ（NULLでOK）
				LPCSTR lpText,    // 本文（メッセージ）
				LPCSTR lpCaption, // タイトル
				UINT uType        // アイコンやボタンの種類
			);


			return nullptr;
		}

	}//	Object
}//	Framework
