#include "DxLib.h"
#include <time.h>

<<<<<<< HEAD
=======

// -------- 設定 --------
const int MAP_W = 15;
const int MAP_H = 12;
const int CELL = 40;
const int BOM_MAX = 30;

// -------- フィールド --------
bool bomb[MAP_H][MAP_W];
bool open[MAP_H][MAP_W];
int  countB[MAP_H][MAP_W];

// -------- 画像 --------
int img_empty, img_num[8], img_turf, img_mine;

// -------- 再帰で8方向を開く --------
void OpenCell(int x, int y)
{
	// 範囲外
	if (x < 0 || x >= MAP_W || y < 0 || y >= MAP_H) return;

	// 既に開いている
	if (open[y][x]) return;

	open[y][x] = true;

	// 数字があれば止まる
	if (countB[y][x] > 0) return;

	// 周囲8マス
	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			if (dx == 0 && dy == 0) continue;
			OpenCell(x + dx, y + dy);
		}
	}
}

>>>>>>> 85662a4613217a70b414d8102a5160931afe5d40

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
<<<<<<< HEAD
	
=======


	// -------- 初期化 --------
	for (int y = 0; y < MAP_H; y++)
	{
		for (int x = 0; x < MAP_W; x++)
		{
			bomb[y][x] = false;
			open[y][x] = false;
			countB[y][x] = 0;
		}
	}

>>>>>>> 85662a4613217a70b414d8102a5160931afe5d40
	//画像---------------------
	int gh_back;//背景

	//画像読み込み
	gh_back = LoadGraph("image\\back.png");

<<<<<<< HEAD
	struct Cell
	{
		int turf;
		int empty;
		int x;
		int y;
		bool IsClick = false;
		bool IsFlag = false;
	};
=======
	//struct Cell
	//{
	//	bool open = false;
	//	bool bomb = false;
	//	int count = 0;
	//};
	//Cell field[MAP_H][MAP_W];
>>>>>>> 85662a4613217a70b414d8102a5160931afe5d40
	
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
<<<<<<< HEAD
		{
			//--------------------------------------------------------------------



			ScreenFlip(); //裏画面データを表画面へ反映

			//毎ループ呼び出す。エラーになった場合breakする
			if (ProcessMessage() == -1)break;
			//エスケープキーを押したり、エラーになった場合、breakする
			if (CheckHitKey(KEY_INPUT_ESCAPE))break;
=======
		while (placed < BOM_MAX)
		{
			int x = rand() % MAP_W;
			int y = rand() % MAP_H;
			if (!bomb[y][x])
			{
				bomb[y][x] = true;
				placed++;
			}
>>>>>>> 85662a4613217a70b414d8102a5160931afe5d40
		}
		//画像データ削除
		DeleteGraph(gh_back);

<<<<<<< HEAD
=======
		// -------- 周囲爆弾数計算 --------
		for (int y = 0; y < MAP_H; y++)
		{
			for (int x = 0; x < MAP_W; x++)
			{
				if (bomb[y][x]) continue;

				int c = 0;
				for (int dy = -1; dy <= 1; dy++)
				{
					for (int dx = -1; dx <= 1; dx++)
					{
						int nx = x + dx;
						int ny = y + dy;
						if (nx < 0 || nx >= MAP_W || ny < 0 || ny >= MAP_H) continue;
						if (bomb[ny][nx]) c++;
					}
				}
				countB[y][x] = c;
			}
		}

		while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
		{
			ClearDrawScreen();

			int mx = 0, my = 0;
			//GetMousePoint(&mx, &my);

			if (GetMouseInput() & MOUSE_INPUT_LEFT)
			{
				int cx = mx / CELL;
				int cy = my / CELL;

				if (cx >= 0 && cx < MAP_W && cy >= 0 && cy < MAP_H)
				{
					if (!bomb[cy][cx])
					{
						OpenCell(cx, cy);
					}
					else
					{
						// ゲームオーバー：全部開く
						for (int y = 0; y < MAP_H; y++)
							for (int x = 0; x < MAP_W; x++)
								open[y][x] = true;
					}
					WaitTimer(150);
				}
			}

			// -------- 描画 --------
			for (int y = 0; y < MAP_H; y++)
			{
				for (int x = 0; x < MAP_W; x++)
				{
					int px = x * CELL;
					int py = y * CELL;

					if (!open[y][x])
					{
						DrawGraph(px, py, img_turf, TRUE);
					}
					else
					{
						if (bomb[y][x])
						{
							DrawGraph(px, py, img_mine, TRUE);
						}
						else if (countB[y][x] > 0)
						{
							DrawGraph(px, py, img_num[countB[y][x] - 1], TRUE);
						}
						else
						{
							DrawGraph(px, py, img_empty, TRUE);
						}
					}
				}
			}
			//--------------------------------------------------------------------

			ScreenFlip(); //裏画面データを表画面へ反映

			//毎ループ呼び出す。エラーになった場合breakする
			if (ProcessMessage() == -1)break;
			//エスケープキーを押したり、エラーになった場合、breakする
			if (CheckHitKey(KEY_INPUT_ESCAPE))break;
		}

		//画像データ削除
		DeleteGraph(gh_back);

>>>>>>> 85662a4613217a70b414d8102a5160931afe5d40
		WaitKey();	 //キー入力待ち
		DxLib_End(); //DXライブラリ使用の終了処理
		return 0;
	}
}