#include"main.h"
#include"Application.h"


//	エントリーポイント
int main()
{

	Application app(SCREEN_WIDTH, SCREEN_HEIGHT);
	app.Run();

	//	終了処理
	return 0;
}