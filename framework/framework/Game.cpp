#include "Game.h"
#include"Renderer.h"
#include"SceneManager.h"

#include"TestScene1.h"

using namespace Framework::Scene;

/// <summary>
/// ゲーム全体の初期化
/// </summary>
void Game::Init()
{
	Renderer::Init();

	Framework::Scene::SceneManager::GetInstanse().Init();
	Framework::Scene::SceneManager::GetInstanse().AddScene<Framework::Scene::Scenes::TestScene1>("testScene");
	
	Framework::Scene::SceneManager::GetInstanse().ChangeScene("testScene");
}

/// <summary>
/// 終了処理
/// </summary>
void Game::Uninit()
{
	Framework::Scene::SceneManager::GetInstanse().Uninit();

	Renderer::Uninit();

}

/// <summary>
/// 更新処理
/// </summary>
void Game::Update()
{
	Framework::Scene::SceneManager::GetInstanse().Update();


}

/// <summary>
/// 描画処理
/// </summary>
void Game::Draw()
{
	Renderer::Start();

	Framework::Scene::SceneManager::GetInstanse().Draw();

	Renderer::End();

}

/// <summary>
/// ゲームループ
/// この中でゲームを動かす
/// </summary>
void Game::GameLoop()
{
	Update();
	Draw();

}
