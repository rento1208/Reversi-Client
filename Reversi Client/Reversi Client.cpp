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
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	connect(sock, (sockaddr*)&addr, sizeof(addr));

	Reversi game;

	while (ProcessMessage() == 0)
	{
		char buf[16];
		recv(sock, buf, sizeof(buf), 0);

		int x, y;
		sscanf(buf, "%d %d", &x, &y);
		game.Put(x, y,1);
		game.Draw();

		if (GetMouseInput() & (MOUSE_INPUT_LEFT))
		{
			int mx, my;
			GetMousePoint(&mx, &my);

			x = (mx - 50) / 60;
			y = (my - 50) / 60;

			if (game.CanPut(x, y))
			{
				game.Put(x, y, 2);

				sprintf_s(buf, "%d %d", x, y);
				send(sock, buf, strlen(buf) + 1, 0);
			}
		}

	}

	DxLib_End();
	return 0;

}