#include "TestObject1.h"
#include"TestComponent.h"

namespace Framework
{
	namespace GameObject
	{
		namespace GameObjects
		{
			void GameObjects::TestObject1::OnInit()
			{
				AddComponent<Component::Components::TestComponent>("tectCom");

				Component::Components::TestComponent* testCom =
					GetComponent<Component::Components::TestComponent>("testCom");

				testCom->TestCommentDraw();
			}


			void GameObjects::TestObject1::OnUninit()
			{

			}


		}//	GameObjects
	}//	Framework
}//	Framework
