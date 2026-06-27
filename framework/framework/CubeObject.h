#pragma once
#include"GameObject.h"
#include"Commontypes.h"

namespace Framework
{
	namespace GameObject
	{
		namespace GameObjects
		{
			namespace Primitive
			{
				/// <summary>
				/// 立方体のオブジェクト
				/// </summary>
				class CubeObject :public GameObject
				{
				private:
					float m_scaleX = 1.0f;
					float m_scaleY = 1.0f;
					float m_scaleZ = 1.0f;


					void OnInit();
					void OnUninit();
				public:
					void Draw(Matrix4x4 _mtx, Color _col);



				};


			}//	Primitive
		}//	GameObjects
	}//	Framework
}//	Framework
