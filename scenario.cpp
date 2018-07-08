#include"Dxlib.h"
int Green = GetColor(0, 255, 0);

void mywait() {
	int i;
	for (i = 0; i < 300; i++)
		;

}


/*----- シナリオリーダー -----*/

void scenario_reader(int length, char text[]) {
	int x_s = 300, y_s = 120;
	
	for (int i = 0; i < length; i++) {
		DrawFormatString(x_s, y_s, Green, "%s", text[i]);
		x_s += 5;
		mywait();
	}
}

/*----- シナリオリーダー -----*/
char A_1[] = "This is tests.";

void scenario() {
DrawFormatString(100, 100, Green, "hoge");
	scenario_reader(sizeof(A_1), A_1);




}



