#include "DxLib.h"
#include <time.h>
#include "saiki.h"

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
	
	Board board;

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

	while (1) 
	{
		//裏画面のデータを全て削除
		ClearDrawScreen();

		//処理----------------------------------------------------------------
		board.Click();





		for (int i = 0; i < BOM_MAX; i++)
		{
			B_randX = rand() % 15;
			B_randY = rand() % 12;
			for (int y = 0; y < Bom_Count; y++)
			{
				if (bomX[y] == B_randX && bomY[y] == B_randY)
				{
					BOM_MAX++;
					continue;
				}
				else
				{
					bomX[Bom_Count] = B_randX;
					bomY[Bom_Count] = B_randY;
					Bom_Count++;
				}
			}
		
	
		}

	
		//画像の描画(位置X、位置Y、グラフィックハンドル、透明度の有効無効)
		//背景
		DrawGraph(0, 0, gh_back, true);
		board.Draw();
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