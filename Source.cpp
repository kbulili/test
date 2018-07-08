#include "DxLib.h"
#define PI 3.141592654
#include"scenario.h"

int Key[256]; // キーが押されているフレーム数を格納する
int i;
int scene = 0;




// キーの入力状態を更新する
int gpUpdateKey() {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}

int image[12];

int hai0, hai1, doa1, menu1, menu2;

int  a = 0, b = 0, x, y;
int Col;
int menu = 0, save = 0;
int P_flag = 0;





/*===== 画像関連関数 =====*/
void gpCalc() {

	if (Key[KEY_INPUT_X] >= 1) {
		menu = 1;
		if (Key[KEY_INPUT_X] == 0) {
			menu = 2;
			if (Key[KEY_INPUT_X] >= 1) {
				menu = 0;
			}
		}
	}

	if (Key[KEY_INPUT_LSHIFT] >= 1 || Key[KEY_INPUT_RSHIFT] >= 1) {
		if (Key[KEY_INPUT_RIGHT] >= 1) {
			if (x > 600) { x = 600; a = 3; }
			else {
				x = x + 6; a = 3; b = 3;
			}
		}
		if (Key[KEY_INPUT_DOWN] >= 1) {
			if (y > 430) { y = 430; a = 1; }
			else {
				y = y + 6; a = 1; b = 1;
			}
		}
		if (Key[KEY_INPUT_LEFT] >= 1) {
			if (x < 0) { x = 0; a = 2; }
			else {
				x = x - 6; a = 2; b = 2;
			}
		}
		if (Key[KEY_INPUT_UP] >= 1) {
			if (y < 100) { y = 100; a = 4; }
			else {
				y = y - 6; a = 4; b = 4;
			}
		}
	}



	else {
		if (Key[KEY_INPUT_RIGHT] >= 1) {
			if (x > 600) { x = 600; a = 3; }
			else {
				x = x + 4; a = 3; b = 3;
			}
		}
		if (Key[KEY_INPUT_DOWN] >= 1) {
			if (y > 430) { y = 430; a = 1; }
			else {
				y = y + 4; a = 1; b = 1;
			}
		}
		if (Key[KEY_INPUT_LEFT] >= 1) {
			if (x < 0) { x = 0; a = 2; }
			else {
				x = x - 4; a = 2; b = 2;
			}
		}
		if (Key[KEY_INPUT_UP] >= 1) {
			if (y < 100) { y = 100; a = 4; }
			else {
				y = y - 4; a = 4; b = 4;
			}
		}
		if (Key[KEY_INPUT_SPACE] >= 1) {
			a = 5;
		}
	}
}

void gpCalc1() {
	if (Key[KEY_INPUT_X] >= 1) {
		menu = 1;
		if (Key[KEY_INPUT_X] == 0) {
			menu = 2;
			if (Key[KEY_INPUT_X] >= 1) {
				menu = 0;
			}
		}
	}

	if (Key[KEY_INPUT_LSHIFT] >= 1 || Key[KEY_INPUT_RSHIFT] >= 1) {
		if (Key[KEY_INPUT_RIGHT] >= 1) {
			if (x > 600) { x = 600; a = 3; }
			else {
				x = x + 6; a = 3; b = 3;
			}
		}
		if (Key[KEY_INPUT_DOWN] >= 1) {
			if (y > 270) { y = 270; a = 1; }
			else {
				y = y + 6; a = 1; b = 1;
			}
		}
		if (Key[KEY_INPUT_LEFT] >= 1) {
			if (x < 0) { x = 0; a = 2; }
			else {
				x = x - 6; a = 2; b = 2;
			}
		}
		if (Key[KEY_INPUT_UP] >= 1) {
			if (y < 180) { y = 180; a = 4; }
			else {
				y = y - 6; a = 4; b = 4;
			}
		}
	}



	else {
		if (Key[KEY_INPUT_RIGHT] >= 1) {
			if (x > 600) { x = 600; a = 3; }
			else {
				x = x + 4; a = 3; b = 3;
			}
		}
		if (Key[KEY_INPUT_DOWN] >= 1) {
			if (y > 270) { y = 270; a = 1; }
			else {
				y = y + 4; a = 1; b = 1;
			}
		}
		if (Key[KEY_INPUT_LEFT] >= 1) {
			if (x < 0) { x = 0; a = 2; }
			else {
				x = x - 4; a = 2; b = 2;
			}
		}
		if (Key[KEY_INPUT_UP] >= 1) {
			if (y < 180) { y = 180; a = 4; }
			else {
				y = y - 4; a = 4; b = 4;
			}
		}
		if (Key[KEY_INPUT_SPACE] >= 1) {
			a = 5;
		}
	}
}

void gpDraw() {
	switch (a)
	{
	case 1:
		if (Key[KEY_INPUT_DOWN] == 0) { DrawGraph(x, y, image[0], TRUE); break; }
		else if (Key[KEY_INPUT_DOWN] % 15 <= 7) { DrawGraph(x, y, image[4], TRUE); }
		else if (Key[KEY_INPUT_DOWN] % 15 >= 7) { DrawGraph(x, y, image[8], TRUE); }
		else  DrawGraph(x, y, image[0], TRUE); break;

	case 2:
		if (Key[KEY_INPUT_LEFT] % 15 <= 7) { DrawGraph(x, y, image[1], TRUE); }
		else if (Key[KEY_INPUT_LEFT] % 15 >= 7) { DrawGraph(x, y, image[5], TRUE); }
		else if (Key[KEY_INPUT_LEFT] == 0) { break; }
		else DrawGraph(x, y, image[9], TRUE); break;

	case 3:
		if (Key[KEY_INPUT_RIGHT] % 15 <= 7) { DrawGraph(x, y, image[2], TRUE); }
		else if (Key[KEY_INPUT_RIGHT] % 15 >= 7) { DrawGraph(x, y, image[6], TRUE); }
		else if (Key[KEY_INPUT_RIGHT] == 0) { break; }
		else DrawGraph(x, y, image[10], TRUE); break;

	case 4:
		if (Key[KEY_INPUT_UP] == 0) { DrawGraph(x, y, image[3], TRUE); break; }
		else if (Key[KEY_INPUT_UP] % 15 <= 7) { DrawGraph(x, y, image[11], TRUE); }
		else if (Key[KEY_INPUT_UP] % 15 >= 7) { DrawGraph(x, y, image[7], TRUE); }
		else DrawGraph(x, y, image[3], TRUE); break;

	case 5:

		if (b == 2) {
			if (Key[KEY_INPUT_SPACE] == 0) { DrawGraph(x, y, image[1], TRUE); break; }
			else if (Key[KEY_INPUT_SPACE] % 13 <= 8) { DrawGraph(x, y - 10, image[1], TRUE); }
			else if (Key[KEY_INPUT_SPACE] % 13 >= 9) { DrawGraph(x, y, image[1], TRUE); }
			else DrawGraph(x, y, image[1], TRUE); break;
		}

		else if (b == 3) {
			if (Key[KEY_INPUT_SPACE] == 0) { DrawGraph(x, y, image[2], TRUE); break; }
			else if (Key[KEY_INPUT_SPACE] % 13 <= 8) { DrawGraph(x, y - 10, image[2], TRUE); }
			else if (Key[KEY_INPUT_SPACE] % 13 >= 9) { DrawGraph(x, y, image[2], TRUE); }
			else DrawGraph(x, y, image[2], TRUE); break;
		}

		else if (b == 4) {
			if (Key[KEY_INPUT_SPACE] == 0) { DrawGraph(x, y, image[3], TRUE); break; }
			else if (Key[KEY_INPUT_SPACE] % 13 <= 8) { DrawGraph(x, y - 10, image[3], TRUE); }
			else if (Key[KEY_INPUT_SPACE] % 13 >= 9) { DrawGraph(x, y, image[3], TRUE); }
			else DrawGraph(x, y, image[3], TRUE); break;
		}

		else {
			if (Key[KEY_INPUT_SPACE] == 0) { DrawGraph(x, y, image[0], TRUE); break; }
			else if (Key[KEY_INPUT_SPACE] % 13 <= 8) { DrawGraph(x, y - 10, image[0], TRUE); }
			else if (Key[KEY_INPUT_SPACE] % 13 >= 9) { DrawGraph(x, y, image[0], TRUE); }
			else DrawGraph(x, y, image[0], TRUE); break;
		}

	default: DrawGraph(x, y, image[0], TRUE); break;
	}
}


/*===== シーン遷移 =====*/
/*----- menu -----*/
void scene0() {

	x = 300; y = 215;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {


		DrawRotaGraph(330, 240, 1.3, 0, hai0, TRUE);
		DrawRotaGraph(-7, 145, 1.0, 0, doa1, TRUE);

		if (menu >= 1) {
			DrawRotaGraph(323, 251, 1.07, 0, menu1, TRUE);

			switch (save)
			{
			case 1: DrawGraph(482, 122, menu2, TRUE); 
				/*scenario();*/break;

			case 2: DrawGraph(482, 170, menu2, TRUE); break;

			case 3: DrawGraph(482, 218, menu2, TRUE); break;

			default: DrawGraph(482, 75, menu2, TRUE); break;
			}

		}

		if (menu == 1) {
			/*----- back -----*/
			if (Key[KEY_INPUT_Z] >= 1) {
				menu = 0;
			}

			/*----- カーソルの移動 -----*/
			if (save == 0) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 3;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 1;
					P_flag = 1;
				}
			}
			else if (save == 1) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 0;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 2;
					P_flag = 1;
				}
			}
			else if (save == 2) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 1;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 3;
					P_flag = 1;
				}
			}
			else if (save == 3) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 2;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 0;
					P_flag = 1;
				}
			}

			if (!Key[KEY_INPUT_UP] && !Key[KEY_INPUT_DOWN] && P_flag) {
				P_flag = 0;
			}

		}


		else if (menu == 0) {
			if (Key[KEY_INPUT_X] >= 70) {
				menu = 1;
			}

			else {

				gpCalc();

				gpDraw();

				if (x <= 5 && y <= 140 && y >= 95 && a == 2) {
					scene = 1;
					WinMain(0, 0, 0, 0);

				}
			}
		}
	}

}

void scene1() {

	x = 600; y = 270;


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

		DrawRotaGraph(330, 240, 1.3, 0, hai1, TRUE);
		if (menu >= 1) {
			DrawRotaGraph(323, 251, 1.07, 0, menu1, TRUE);

			switch (save)
			{
			case 1: DrawGraph(482, 122, menu2, TRUE); break;

			case 2: DrawGraph(482, 170, menu2, TRUE); break;

			case 3: DrawGraph(482, 218, menu2, TRUE); break;

			default: DrawGraph(482, 75, menu2, TRUE); break;
			}

		}

		if (menu == 1) {
			/*----- back -----*/
			if (Key[KEY_INPUT_Z] >= 1) {
				menu = 0;
			}

			/*----- カーソルの移動 -----*/
			if (save == 0) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 3;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 1;
					P_flag = 1;
				}
			}
			else if (save == 1) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 0;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 2;
					P_flag = 1;
				}
			}
			else if (save == 2) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 1;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 3;
					P_flag = 1;
				}
			}
			else if (save == 3) {
				if (Key[KEY_INPUT_UP] && (P_flag == 0)) {
					save = 2;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] && (P_flag == 0)) {
					save = 0;
					P_flag = 1;
				}
			}

			if (!Key[KEY_INPUT_UP] && !Key[KEY_INPUT_DOWN] && P_flag) {
				P_flag = 0;
			}

		}


		else if (menu == 0) {
			if (Key[KEY_INPUT_X] >= 70) {
				menu = 1;
			}

			else {

				gpCalc1();

				gpDraw();

				if (x >= 595 && y <= 280 && y >= 180 && a == 3) {
					scene = 2;
					WinMain(0, 0, 0, 0);
				}
			}
		}
	}

		
}

void scene2() {

	x = 0; y = 115;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		DrawRotaGraph(330, 240, 1.3, 0, hai0, TRUE);
		DrawRotaGraph(-7, 145, 1.0, 0, doa1, TRUE);
		if (menu >= 1) {
			DrawRotaGraph(323, 251, 1.07, 0, menu1, TRUE);

			switch (save)
			{
			case 1: DrawGraph(482, 122, menu2, TRUE); break;

			case 2: DrawGraph(482, 170, menu2, TRUE); break;

			case 3: DrawGraph(482, 218, menu2, TRUE); break;

			default: DrawGraph(482, 75, menu2, TRUE);
				break;
			}

		}

		if (menu == 1) {
			if (Key[KEY_INPUT_Z] >= 1 && (P_flag == 0)) {
				menu = 0;
			}
			if (save == 0) {
				if (Key[KEY_INPUT_UP] >= 1 && (P_flag == 0)) {
					save = 3;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] >= 1 && (P_flag == 0)) {
					save = 1;
					P_flag = 1;
				}
			}
			else if (save == 1) {
				if (Key[KEY_INPUT_UP] >= 1 && (P_flag == 0)) {
					save = 0;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] >= 1 && (P_flag == 0)) {
					save = 2;
					P_flag = 1;
				}
			}
			else if (save == 2) {
				if (Key[KEY_INPUT_UP] >= 1 && (P_flag == 0)) {
					save = 1;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] >= 1 && (P_flag == 0)) {
					save = 3;
					P_flag = 1;
				}
			}
			else if (save == 3) {
				if (Key[KEY_INPUT_UP] >= 1 && (P_flag == 0)) {
					save = 2;
					P_flag = 1;
				}
				else if (Key[KEY_INPUT_DOWN] >= 1 && (P_flag == 0)) {
					save = 0;
					P_flag = 1;
				}
			
			}
			if (!Key[KEY_INPUT_UP] && !Key[KEY_INPUT_DOWN] && P_flag) {
				P_flag = 0;
			}
		}


		else if (menu == 0) {
			if (Key[KEY_INPUT_X] >= 70) {
				menu = 1;
			}

			else {

				gpCalc();

				gpDraw();

				if (x <= 5 && y <= 140 && y >= 95 && a == 2) {
					scene = 1;
					WinMain(0, 0, 0, 0);

				}

			}

		}
	}
}






/*===== メイン文 =====*/
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定


	hai0 = LoadGraph("101.png");
	hai1 = LoadGraph("104.png");
	doa1 = LoadGraph("105.png");
	menu1 = LoadGraph("106.png");
	menu2 = LoadGraph("107.png");
	LoadDivGraph("100.png", 12, 4, 3, 50, 50, image);


	if (scene == 1) {

		scene1();

	}
	else if (scene == 2) {

		scene2();
	}

	else {
		scene0();

	}



	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キーの更新)


	DxLib_End(); // DXライブラリ終了処理
	return 0;
}