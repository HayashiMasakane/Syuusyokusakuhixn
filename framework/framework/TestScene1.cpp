#include "TestScene1.h"

//	オブジェクト名
#include"TestObject1.h"
#include"CubeObject.h"

namespace Framework
{
	namespace Scene
	{
		namespace Scenes
		{
			TestScene1::~TestScene1()
			{
			}

			void TestScene1::OnInit()
			{
				Scene::GetGameObjectManager().AddGameObject<GameObject::GameObjects::Primitive::CubeObject>("cubeObject1");
				

			}
			void TestScene1::OnUninit()
			{


			}
			void TestScene1::OnUpdate()
			{

			}
			void TestScene1::OnDraw()
			{
				GameObject::GameObject* cube = Scene::GetGameObjectManager().GetGameObject("cubeObject1");
				


			}




		}

	}//	Scene
}//	Framework
