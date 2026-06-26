#pragma once
#include"GameObject.h"

namespace Framework
{
	namespace GameObject
	{
		namespace GameObjects
		{
			namespace Primitive
			{
				/// <summary>
				/// 基本形状のキューブ情報を持つ
				/// </summary>
				class Cube :public GameObject
				{
				private:
					float m_scaleX = 1.0f;;
					float m_scaleY = 1.0f;;
					float m_scaleZ = 1.0f;;

				public:
					Cube() = default;
					Cube(float _x, float _y, float _z);
					~Cube()=default;

					void Draw();

				};
			}


		}
	}
}
