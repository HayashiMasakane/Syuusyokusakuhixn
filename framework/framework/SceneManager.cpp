#include "SceneManager.h"
#include"Scene.h"
#include"GameObjectManager.h"


namespace Framework
{
	namespace Scene
	{
		/// <summary>
		/// デストラクタ
		/// 内包しているシーン全てを削除
		/// </summary>
		SceneManager::~SceneManager()
		{
			m_pMainScene = nullptr;

			for (auto& scene : m_sceneMap)
			{
				scene.second->Uninit();
			}

			m_sceneMap.clear();

		}

		/// <summary>
		/// SceneManagerの参照を取得
		/// </summary>
		/// <returns></returns>
		SceneManager& SceneManager::GetInstanse()
		{
			static SceneManager instanse;
			return instanse;
		}

		/// <summary>
		/// 初期化
		/// </summary>
		void SceneManager::Init()
		{
		}

		/// <summary>
		/// 終了処理
		/// </summary>
		void SceneManager::Uninit()
		{
		}


		/// <summary>
		/// 更新処理
		/// もしシーンの切り替え予約しているなら切り替える
		/// </summary>
		void SceneManager::Update()
		{
			//	シーン切り替えの予約があるなら切り替える
			if (!m_nextMainSceneName.empty())
			{
				if (m_pMainScene != nullptr)
				{
					m_pMainScene->Uninit();
				}
				m_pMainScene = m_sceneMap[m_nextMainSceneName].get();
				m_pMainScene->Init();

				m_nextMainSceneName.clear();
			}

			//	更新処理
			if (m_pMainScene != nullptr)
			{
				m_pMainScene->Update();
				m_pMainScene->Draw();
			}

		}

		/// <summary>
		/// 引数のシーンに切り替え予約
		/// 実際の切り替えはUpdate()野中で実行
		/// </summary>
		/// <param name="_sceneName"></param>
		void SceneManager::ChangeScene(std::string _sceneName)
		{
			//	登録されていないシーンならはじく
			if (!m_sceneMap.contains(_sceneName))
			{
				std::string msg =
					"引数名:[" + _sceneName + "]のシーンは登録されていません。";
				MessageBoxA(
					NULL,        // 親ウィンドウ（NULLでOK）
					msg.c_str(),    // 本文（メッセージ）
					"ChangeScene", // タイトル
					MB_OK | MB_ICONWARNING    // アイコンやボタンの種類
				);

				return;
			}

			m_nextMainSceneName = _sceneName;
		}


	}//	Scene
}//	Framework