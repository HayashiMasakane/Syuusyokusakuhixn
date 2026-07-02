#include "TestScene1.h"
#include"TestSystem.h"
//	オブジェクト名
#include"TestObject1.h"

//	コンポーネント名
#include"TestSystem.h"


using namespace Framework::Component::Components;

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
				Scene::GetGameObjectManager().AddGameObject<GameObject::GameObjects::TestObject1>("testObject");


			}
			void TestScene1::OnUninit()
			{


			}
			void TestScene1::OnUpdate()
			{
			//	std::vector<TestComponent*> testComs = Scene::GetComponentManager().GetComponents<TestComponent>();
			//	TestSystem(testComs);
			}
			void TestScene1::OnDraw()
			{



			}




		}

	}//	Scene
}//	Framework
