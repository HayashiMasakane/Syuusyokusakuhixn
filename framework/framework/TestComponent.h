#pragma once
#include "Component.h"


namespace Framework
{
	namespace Component
	{
		namespace Components
		{
			class TestComponent1;

			class TestComponent :public Component
			{
			private:
				TestComponent1* m_testcom1 = nullptr;

				void OnInit()override;
				void OnUninit()override;

				bool HasMethodPointerComponent() override;


			public:
				void SetTestComponent1(TestComponent1* _testcom1);
				void TestCommentDraw();



			};

		}
	}
}

