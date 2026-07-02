#include "TestObject1.h"
#include"TestComponent.h"
#include"TestComponent1.h"

namespace Framework
{
	namespace GameObject
	{
		namespace GameObjects
		{
			void TestObject1::OnInit()
			{
				auto* testCom = AddComponent<Component::Components::TestComponent>("tectCom");
				auto* testCom1 = AddComponent<Component::Components::TestComponent1>("tectCom1");
				testCom->SetTestComponent1(testCom1);
			
				testCom->TestCommentDraw();
				
			}


			void TestObject1::OnUninit()
			{

			}


		}//	GameObjects
	}//	Framework
}//	Framework
