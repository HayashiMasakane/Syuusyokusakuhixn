#include "TestObject1.h"
#include"TestComponent.h"
#include"TestComponent1.h"

namespace Framework
{
	namespace GameObject
	{
		namespace GameObjects
		{
			void GameObjects::TestObject1::OnInit()
			{
				auto* testCom = AddComponent<Component::Components::TestComponent>("tectCom");
				auto* testCom1 = AddComponent<Component::Components::TestComponent1>("tectCom1");
				testCom->GetTestComponent1(testCom1);
			
			testCom.
			}


			void GameObjects::TestObject1::OnUninit()
			{

			}


		}//	GameObjects
	}//	Framework
}//	Framework
