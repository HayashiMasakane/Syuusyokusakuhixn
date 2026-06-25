#include "Application.h"
#include"Game.h"
//  ウィンドウ名
constexpr auto CLASS_NAME = TEXT("2026 GM31 ひな形");        //!< ウィンドウクラス名.
constexpr auto WINDOW_NAME = TEXT("2026 GM31 ひな形");        //!< ウィンドウ名.

//	メソッド変数の本体
HINSTANCE  Application::m_hInst;        //!< インスタンスハンドルです.
HWND       Application::m_hWnd;         //!< ウィンドウハンドルです.
uint32_t   Application::m_Width;        //!< ウィンドウの横幅です.
uint32_t   Application::m_Height;       //!< ウィンドウの縦幅です.



/// <summary>
/// コンストラクタ
/// 最初のウィンドウサイズを設定
/// </summary>
/// <param name="_width">横幅</param>
/// <param name="_height">縦幅</param>
Application::Application(uint32_t _width, uint32_t _height)
{
	m_Height = _height;
	m_Width = _width;
}

/// <summary>
/// デストラクタ
/// </summary>
Application::~Application()
{
}

/// <summary>
/// アプリの初期化
/// </summary>
/// <returns>初期化できればtrue</returns>
bool Application::InitApp()
{
	// ウィンドウの初期化.
	if (!InitWnd())
	{
		return false;
	}

	// 正常終了.
	return true;
}

/// <summary>
/// アプリとウィンドウの終了処理
/// ウィンドウを解放することで強制的にアプリも解放
/// </summary>
void Application::UninitApp()
{
	UninitWnd();
}


/// <summary>
///	ウィンドウの初期化をする
/// </summary>
/// <returns></returns>
bool Application::InitWnd()
{
	// インスタンスハンドルを取得.
	auto hInst = GetModuleHandle(nullptr);
	if (hInst == nullptr)
	{
		return false;
	}

	// ウィンドウの設定.
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hIcon = LoadIcon(hInst, IDI_APPLICATION);
	wc.hCursor = LoadCursor(hInst, IDC_ARROW);
	wc.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = CLASS_NAME;
	wc.hIconSm = LoadIcon(hInst, IDI_APPLICATION);

	// ウィンドウの登録.
	if (!RegisterClassEx(&wc))
	{
		return false;
	}

	// インスタンスハンドル設定.
	m_hInst = hInst;

	// ウィンドウのサイズを設定.
	RECT rc = {};
	rc.right = static_cast<LONG>(m_Width);
	rc.bottom = static_cast<LONG>(m_Height);

	// ウィンドウサイズを調整.
	auto style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
	AdjustWindowRect(&rc, style, FALSE);

	// ウィンドウを生成.
	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		WINDOW_NAME,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		nullptr,
		nullptr,
		m_hInst,
		nullptr);

	if (m_hWnd == nullptr)
	{
		return false;
	}

	// ウィンドウを表示.
	ShowWindow(m_hWnd, SW_SHOWNORMAL);

	// ウィンドウを更新.
	UpdateWindow(m_hWnd);

	// ウィンドウにフォーカスを設定.
	SetFocus(m_hWnd);

	// 正常終了.
	return true;
}

/// <summary>
/// ウィンドウの終了処理
/// ウィンドウを解放する
/// </summary>
void Application::UninitWnd()
{
	// ウィンドウの登録を解除.
	if (m_hInst != nullptr)
	{
		UnregisterClass(CLASS_NAME, m_hInst);
	}

	m_hInst = nullptr;
	m_hWnd = nullptr;
}

/// <summary>
/// アプリの更新処理
/// 内部にあるwhileでアプリをループさせる
/// ウィンドウメッセージでループを止める
/// </summary>
void Application::MainLoop()
{
	MSG msg = {};

	Game::Init();

	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) == TRUE)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//	ゲームループ
			Game::GameLoop();

		}
	}

	Game::Uninit();
}

/// <summary>
/// ウィンドウプロシージャ
/// </summary>
/// <param name="hWnd">ウィンドウハンドル</param>
/// <param name="msg">Windowに送るメッセージ</param>
/// <param name="wp">WPARAM パラメータ</param>
/// <param name="lp">LPARAM パラメータ</param>
/// <returns>処理結果を返す</returns>
LRESULT Application::WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	break;

	default:
	{ /* DO_NOTHING */ }
	break;
	}

	return DefWindowProc(hWnd, msg, wp, lp);
}

/// <summary>
/// アプリを動かす処理
/// もし動かないのであれば動かさない
/// </summary>
void Application::Run()
{
	//	完全に初期化出ればLoopを動かす
	if (InitApp())
	{
		MainLoop();
	}

	UninitApp();
}

uint32_t Application::GetWidth()
{
	return m_Width;
}

uint32_t Application::GetHeight()
{
	return m_Height;
}
HWND Application::GetWindow()
{
	return m_hWnd;
}



HINSTANCE Application::GetHInstance()
{
	return m_hInst;
}