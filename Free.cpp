#include"DxLib.h"
#include"Free.h" // ヘッダーファイル

//定数定義 
const int WIDTH = 1536, HEIGHT = 896; // ウィンドウの幅と高さのピクセル数
const int FPS = 60; // フレームレート

// グローバル変数

// グローバル関数
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetWindowText("Free Game"); // ウィンドウのタイトル
	SetGraphMode(WIDTH, HEIGHT, 32); // ウィンドウの大きさとカラービット数の指定
	ChangeWindowMode(true); // ウィンドウモードで起動
	if (DxLib_Init() == -1) return -1; // ライブラリ初期化、エラーが起きたら終了
	SetBackgroundColor(0, 0, 0); // 背景色の指定
	SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏背景にする

	while (1)
	{
		ClearDrawScreen(); // 画面をクリアにする

		// ゲームの骨組み処理


		ScreenFlip(); // 裏画面の内容を表画面に反映させる
		WaitTimer(1000 / FPS); // 一定時間待つ
		if (ProcessMessage() == -1) break; // windowsから情報を受け取りエラーが起きたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了
	}
	DxLib_End(); // DXライブラリの使用終了処理
	return 0; // ソフトの終了
}

// 自作関数記述
// 初期化用の関数