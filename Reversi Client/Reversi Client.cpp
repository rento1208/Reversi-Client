#include <DxLib.h>
#include <WinSock2.h>
#include "Reversi.h"

#pragma comment(lib, "ws2_32.lib")

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
 //ウィンドウモードで起動
	ChangeWindowMode(TRUE);
	//Dxライブラリ初期化処理
	DxLib_Init();

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);

}