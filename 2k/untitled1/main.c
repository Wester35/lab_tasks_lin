#include <windows.h>

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MODAL_BUTTON 1
#define ID_MODELESS_BUTTON 2
#define ID_MULTI_BUTTON 3

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

BOOL CALLBACK DlgFuncModal(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
    switch(msg) {
        case WM_CREATE:
            return TRUE;
        case WM_COMMAND:
            if (LOWORD(wp) == 2) EndDialog(hw, 0);
    }
}

/* процедура обработки сообщений для главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            /* при создании окна внедряем в него кнопочку */
            CreateWindow("button", "MODAL", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         50, 100, 100, 50, hw, (HMENU) ID_MODAL_BUTTON, NULL, NULL);
            CreateWindow("button", "MODELESS", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         200, 100, 100, 50, hw, (HMENU) ID_MODELESS_BUTTON, NULL, NULL);
            CreateWindow("button", "MULTI", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         350, 100, 100, 50, hw, (HMENU) ID_MULTI_BUTTON, NULL, NULL);
            return 0;
        case WM_COMMAND:
            /* нажата наша кнопочка? */

            if (LOWORD(wp) == 6)  /* команда меню Exit */
                PostQuitMessage(0);
            else { /* все остальные команды */
                if ((HIWORD(wp) == 0) && (LOWORD(wp) == ID_MODAL_BUTTON))
                    MessageBox(hw, "This is a Modal MessageBox", "Modal", MB_CANCELTRYCONTINUE | MB_ICONINFORMATION);
                if ((HIWORD(wp) == 0) && (LOWORD(wp) == ID_MODELESS_BUTTON)){
                    MessageBox(NULL, "This is a Modeless MessageBox", "Modeless", MB_CANCELTRYCONTINUE | MB_ICONINFORMATION);
                }
                if ((HIWORD(wp) == 0) && (LOWORD(wp) == ID_MULTI_BUTTON)) {
                    HWND hwndGoto = NULL;
                    for (int i = 0; i < 4; ++i) {
                        hwndGoto = CreateDialog(h, "GlebDialogBox", hw, DlgProc);
                        ShowWindow(hwndGoto, SW_SHOW);
                    }
                }
                return 0;
            }
        case WM_DESTROY:
            /* пользователь закрыл окно, программа может завершаться */
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hw, msg, wp, lp);
}