#pragma once
#include "Component.h"


namespace Framework
{
	namespace Component
	{
		namespace Components
		{
			class TestComponent :public Component
			{
			private:
				void OnInit()override;
				void OnUninit()override;

			public:
				void TestCommentDraw();



			};

		}
	}
}

