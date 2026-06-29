#include "Scene.h"

namespace Framework
{
	namespace Scene
	{
		Scene::~Scene()
		{
		}

		/// <summary>
		/// 初期化
		/// 派生シーンの初期化もする
		/// </summary>
		void Scene::Init()
		{
			OnInit();
		}

		/// <summary>
		/// 終了処理
		/// 派生シーンの終了処理もする
		/// </summary>
		void Scene::Uninit()
		{
			OnUninit();
			m_gameObjectManager.Uninit();
			m_componentManager.Uninit();
		}

		/// <summary>
		/// 更新処理
		/// 派生シーンの更新処理もする
		/// </summary>
		void Scene::Update()
		{
			OnUpdate();
		}

		/// <summary>
		/// 描画処理
		/// 派生シーンの描画処理もする
		/// </summary>
		void Scene::Draw()
		{
			OnDraw();
		}
		/// <summary>
		/// ゲームオブジェクトマネージャの参照を取得
		/// </summary>
		/// <returns></returns>
		GameObject::GameObjectManager& Scene::GetGameObjectManager()
		{
			return m_gameObjectManager;
		}

		Component::ComponentManager& Scene::GetComponentManager()
		{
			return m_componentManager;
		}


	}//	Scene
}//	Framework