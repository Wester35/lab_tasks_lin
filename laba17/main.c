#include <windows.h>

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MYBUTTON 1    /* идентификатор для кнопочки внутри главного окна */
#define ID_ROMAN_MYBUTTON 2    /* идентификатор для кнопочки внутри главного окна */

char buf[256]=""; /* строка для текстового поля в диалоге */
HINSTANCE h;      /* дескриптор экземпляра программы */

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int ss) {
    /* создаем и регистрируем класс главного окна */
    WNDCLASS wc;
    wc.style=0;
    wc.lpfnWndProc=MainWinProc;
    wc.cbClsExtra=wc.cbWndExtra=0;
    wc.hInstance=hInst;
    wc.hIcon=NULL;
    wc.hCursor=NULL;
    wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName="Ex4_Menu";
    wc.lpszClassName="Example 4 MainWnd Class";
    if (!RegisterClass(&wc)) return FALSE;

    /* создаем главное окно и отображаем его */
    HWND hMainWnd=CreateWindow("Example 4 MainWnd Class","EXAMPLE 4",WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInst,NULL);
    if (!hMainWnd) return FALSE;
    ShowWindow(hMainWnd,ss);
    UpdateWindow(hMainWnd);

    MSG msg; /* цикл обработки событий */
    while (GetMessage(&msg,NULL,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_INITDIALOG: /* сообщение о создании диалога */
            SetDlgItemText(hw,1,buf);
            return TRUE;
        case WM_COMMAND:    /* сообщение от управляющих элементов */
            if (LOWORD(wp)==2) EndDialog(hw,0);
    }
    return FALSE;
}

/* процедура обработки сообщений для главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            CreateWindow("button", "My button", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         50, 100, 100, 200, hw, (HMENU) ID_MYBUTTON, NULL, NULL);
            CreateWindow("button", "My Roman button", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         160, 100, 150, 200, hw, (HMENU) ID_ROMAN_MYBUTTON, NULL, NULL);
            return 0;
        case WM_COMMAND:
            /* нажата наша кнопочка? */

            if (LOWORD(wp) == 6)  /* команда меню Exit */
                PostQuitMessage(0);
            else { /* все остальные команды */
                if ((HIWORD(wp) == 0) && (LOWORD(wp) == ID_MYBUTTON))
                    //MessageBox(hw, "You pressed my button", "MessageBox", MB_OK | MB_ICONWARNING);
                        DialogBox(h, "GlebDialogBox", hw, DlgProc);
                if ((HIWORD(wp) == 0) && (LOWORD(wp) == ID_ROMAN_MYBUTTON)){
                    MessageBox(hw, "Roma is my button", "Roma Info", MB_OK | MB_ICONWARNING);
                    wsprintf(buf, "Command code: %d", LOWORD(wp));
                    DialogBox(h, "Ex4_Dlg", hw, DlgProc);
                }
                if ((HIWORD(wp) == 0) && (LOWORD(wp) >= 3 && (LOWORD(wp) < 8)))
                    MessageBox(hw, "There is PyCharm", "PyCharm", MB_OK | MB_ICONWARNING);


                return 0;
            }
        case WM_DESTROY:
            /* пользователь закрыл окно, программа может завершаться */
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hw, msg, wp, lp);
}