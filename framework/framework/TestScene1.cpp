#include "TestScene1.h"

//	オブジェクト名
#include"TestObject1.h"

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
				Scene::GetGameObjectManager().AddGameObject<GameObject::GameObjects::TestObject1>("testObject1");


			}
			void TestScene1::OnUninit()
			{


			}
			void TestScene1::OnUpdate()
			{

			}
			void TestScene1::OnDraw()
			{


			}

		


		}

	}//	Scene
}//	Framework
