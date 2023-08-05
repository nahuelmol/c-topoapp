const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, Windows Desktop!");

    using std::cout;

    switch(msg){
        case WM_CREATE:
            cout << "funciona WM_CREATE\n";
        case WM_LBUTTONDOWN:
            cout << "Get out!!\n";
        break;
        case WM_RBUTTONDOWN:
            cout << "Get out!!\n";
        break;
        case WM_KEYDOWN:
            cout << "Get out!!\n";
        break; 
        case WM_KEYUP:
            cout << "Get out!!\n";
        break;

        case WM_COMMAND:

            switch(LOWORD(wParam)){

                case 93:
                {
                    
                }

                case 94:
                {
                    cout << "Here";
                }
                break;

                case IDR_MENU1:
                {   
                    cout << "\ngetting into the menu\n";
                }
                break;

                case IDM_FILE1:
                {
                    cout <<"\nFile";
                }
                break;

                case IDM_PROJECT1:
                {
                    cout <<"\nProject";
                }
                break;

                case ID_CONVERTER:

                {

                    int ret_co = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_DIALOG_CONVERTER), hwnd, CompoDlgProc);
                    if(ret_co == IDOK){
                        MessageBox(hwnd, "OK... getting out", "Notice",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    else if(ret_co == IDCANCEL){
                        MessageBox(hwnd, "Cancelling.", "Notice",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    else if(ret_co == -1){
                        MessageBox(hwnd, "Dialog failed!", "Error",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    else if(ret_co == IDADD){
                        cout << "You have clicked on the Add button";
                        MessageBox(hwnd, "Adding", "Notice", MB_OK | MB_ICONINFORMATION);
                    }
                }

                case ID_CALCULATOR:

                    int ret_ca = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_DIALOG_CALCULATOR), hwnd, AboutDlgProc);
                    if(ret_ca == IDOK){
                        MessageBox(hwnd, "OK... getting out", "Notice",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    else if(ret_ca == IDCANCEL){
                        MessageBox(hwnd, "Cancelling.", "Notice",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    else if(ret_ca == -1){
                        MessageBox(hwnd, "Dialog failed!", "Error",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    
                
            }
        break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
    WNDCLASSEX wc;
    HWND hwnd;
    HACCEL hAccelerators;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;

    wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
    wc.hIcon  = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
    wc.hIconSm  = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Window Registration Failed! wc", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Topography project",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 480, 240,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL){
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}