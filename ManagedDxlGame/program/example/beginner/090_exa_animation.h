#if 0

//---------------------------------------------------------------------------------------------------------------
//
//
// [ 入門 ] アニメーション基本サンプル
//
// ※ スプライトシートを分割ロードしてアニメーションを描画するサンプルです
//
//
//---------------------------------------------------------------------------------------------------------------


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"

// アニメーションの最大フレーム数
const int ANIM_FRAME_MAX = 4;

// ロードした画像を識別するハンドル変数配列
// 1つのファイルに複数の絵が描かれた画像データをスプライトシートといいます
// スプライトシートのそれぞれの絵をロードするには配列を使用します
int graphics_handle[ANIM_FRAME_MAX];

// 現在再生中のフレーム数
int now_anim_frame = 0;

// アニメーションのフレームを更新する規定時間
const float ANIM_FRAME_TIME = 0.25f;

// アニメーションのフレームを更新する為の経過時間を加算する変数
float anim_time_count = 0;



//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	SetFontSize(30);

	// 画像ファイルの分割ロード
	// ! ロードは重い処理でメモリも消費します　必要な時に１度だけ実行しましょう ( 毎フレーム実行されないよう工夫しましょう )
	// 第１引数... スプライトシートのファイルパス
	// 第２引数... 全体のフレーム数
	// 第３引数... 横方向のフレーム数
	// 第４引数... 縦方向のフレーム数
	// 第５引数... １フレームあたりの横幅サイズ
	// 第６引数... １フレームあたりの高さサイズ
	// 第７引数... ロードしたハンドルを格納する配列
	LoadDivGraph("resource/graphics/example/c1_anim_down.png", 4, 4, 1, 32, 48, graphics_handle);

}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {

	// アニメーション再生の時間を加算
	anim_time_count += delta_time;

	// フレームの規定時間を超えたら次のフレームを描画する
	if (anim_time_count > ANIM_FRAME_TIME) {

		// フレームを更新
		now_anim_frame++;

		// 最大フレームを超えないように現在のフレーム数を最大数で割った余りで上書きする
		// こうすることで 0 から ( ANIM_FRAME_MAX - 1 ) までの値がループする
		now_anim_frame %= ANIM_FRAME_MAX;

		// フレームあたりの時間をリセット
		anim_time_count = 0;
	}


	// 描画に指定する画像ハンドルは配列中の [ 現在再生中のフレーム番号 ] を指定する
	// ※ サンプル用に第三引数で２倍に拡大描画しています
	DrawRotaGraph(600, 400, 2.0, 0, graphics_handle[now_anim_frame], true);


	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
}


#endif