#pragma once
#include<unordered_map>
#include<memory>
#include<string>
#include<Windows.h>

namespace Framework
{
	namespace Scene
	{
		class Scene;

		/// <summary>
		/// シーンを生成管理するシングルトンクラス
		/// </summary>
		class SceneManager
		{
		private:

			//	string シーン名
			//	unique_ptr シーンのポインタ
			std::unordered_map < std::string, std::unique_ptr<Scene>> m_sceneMap;

			Scene* m_mainScene = nullptr;

			SceneManager() = default;
			~SceneManager();
			SceneManager(const SceneManager&) = delete;
			SceneManager& operator=(const SceneManager&) = delete;

		public:
			static SceneManager& GetInstanse()
			{
				static SceneManager instanse;
				return instanse;
			}

			void Init();
			void Uninit();
			void Update();

			template<typename T>
			void AddScene(std::string _sceneName);
			void ChangeScene(std::string _sceneName);

		};

		/// <summary>
		/// シーンを追加
		/// 同じ名前で登録できない
		/// </summary>
		/// <typeparam name="T">追加したい派生シーン</typeparam>
		/// <param name="_sceneName">Tの名前</param>
		template<typename T>
		inline void SceneManager::AddScene(std::string _sceneName)
		{
			//	引数名が既に使われているならはじく
			if (m_sceneMap.contains(_sceneName))
			{
				std::string msg =
					"引数名:[" + _sceneName + "]のシーンは既に登録されています。";
				MessageBoxA(
					NULL,        // 親ウィンドウ（NULLでOK）
					msg.c_str(),    // 本文（メッセージ）
					"AddScene", // タイトル
					MB_OK | MB_ICONWARNING    // アイコンやボタンの種類
				);

				return;

			}

			//	シーンの追加
			m_sceneMap[_sceneName] = std::make_unique<T>();

		}

	}//	Scene
}//	Framework