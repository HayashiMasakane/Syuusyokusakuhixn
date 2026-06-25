#pragma once
#include <Windows.h>
#include <cstdint>

/// <summary>
///	アプリケーションクラス
/// この中でゲームを動かす
/// </summary>
class Application
{
private:

	static	HINSTANCE   m_hInst;    //	インスタンスハンドルです.
	static	HWND        m_hWnd;     //	ウィンドウハンドルです.
	static	uint32_t    m_Width;    //	ウィンドウの横幅です.
	static	uint32_t    m_Height;   //	ウィンドウの縦幅です.

	static	bool InitApp();
	static	void UninitApp();
	static	bool InitWnd();
	static	void UninitWnd();
	static	void MainLoop();

	static	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

public:

	Application() = default;
	Application(uint32_t _width, uint32_t _height);
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;
	~Application();

	static	void Run();

	//	画面サイズ
	static	uint32_t GetWidth();
	static	uint32_t GetHeight();

	//	ウィンドウ
	static	HWND GetWindow();
	static	HINSTANCE GetHInstance();

};
