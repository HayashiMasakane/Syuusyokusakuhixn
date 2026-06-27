#include "CubeObject.h"
#include"CubeDrawer.h"

namespace Framework
{
	namespace GameObject
	{
		namespace GameObjects
		{
			namespace Primitive
			{
				void CubeObject::OnInit()
				{

				}
				void CubeObject::OnUninit()
				{

				}

				/// <summary>
				/// çsóÒÇégÇ¡ÇƒÇÃï`âÊ
				/// </summary>
				/// <param name="mtx"></param>
				/// <param name="col"></param>
				void CubeObject::Draw(Matrix4x4 _mtx, Color _col)
				{
					Matrix4x4 scale = Matrix4x4::CreateScale(m_scaleX, m_scaleY, m_scaleZ);
					_mtx = scale * _mtx;
					BoxDrawerDraw(_mtx, _col);
				}



			}//	Primitive
		}//	GameObjects
	}//	Framework
}//	Framework
