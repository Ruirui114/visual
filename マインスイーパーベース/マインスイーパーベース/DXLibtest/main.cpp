#include "DxLib.h"
#include <time.h>


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetOutApplicationLogValidFlag(false);//ログ出力オフ
	ChangeWindowMode(TRUE); //ウィンドウモード切り替え
	SetGraphMode(640,562, 32); //ウィンドウサイズ

	if (DxLib_Init() == -1) { //DXライブラリ初期化処理
		return -1;			  //エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に変更
	SetWindowText("MineSweeper"); //ウィンドウの名前
	
	//画像---------------------
	int gh_back;//背景

	//画像読み込み
	gh_back = LoadGraph("image\\back.png");

	struct Cell
	{
		int turf;
		int empty;
		int x;
		int y;
		bool IsClick = false;
		bool IsFlag = false;
	};
	
	//変数
	int r = rand();
	int BOM_MAX = 30;
	int bomX[30];
	int bomY[30];
	int Bom_Count = 0;
	int B_randX = 0;
	int B_randY = 0;
	bool start = false;
	int mouseX, mouseY;//カーソル位置保存用

	int empty = LoadGraph("image\\empty.png");
	int one = LoadGraph("image\\one.png");
	int two = LoadGraph("image\\two.png");
	int three = LoadGraph("image\\three.png");
	int four = LoadGraph("image\\four.png");
	int five = LoadGraph("image\\five.png");
	int six = LoadGraph("image\\six.png");
	int seven = LoadGraph("image\\seven.png");
	int turf = LoadGraph("image\\turf.png");
	int frag = LoadGraph("image\\frag.png");
	int mine = LoadGraph("image\\mine.png");

	int placed = 0;

	while (1)
	{
		//裏画面のデータを全て削除
		ClearDrawScreen();

		//処理----------------------------------------------------------------
		{
			//--------------------------------------------------------------------

			ScreenFlip(); //裏画面データを表画面へ反映

			//毎ループ呼び出す。エラーになった場合breakする
			if (ProcessMessage() == -1)break;
			//エスケープキーを押したり、エラーになった場合、breakする
			if (CheckHitKey(KEY_INPUT_ESCAPE))break;
		}
		//画像データ削除
		DeleteGraph(gh_back);

		WaitKey();	 //キー入力待ち
		DxLib_End(); //DXライブラリ使用の終了処理
		return 0;
	}
}