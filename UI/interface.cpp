const char g_szClassName[] = "myWindowClass";

void basic_commands(int res, HWND hwnd){
    using std::cout;
    using std::endl;

    int OKS[3] = {ID_CONVERTER_OK, ID_CALCULATOR_OK, ID_POSITIONER_OK};
    int CANCELS[4] = {ID_CONVERTER_CANCEL, ID_CALCULATOR_CANCEL, ID_POSITIONER_CANCEL, ID_NOTAS_SALIRASISTENTE};
    int opc = -1;

    bool exists_ok = std::find(std::begin(OKS), std::end(OKS), res);
    bool exists_can = std::find(std::begin(CANCELS), std::end(CANCELS), res);

    if(exists_ok){
        MessageBox(hwnd, "OK... getting out", "Notice", MB_OK | MB_ICONINFORMATION);

    }else if(exists_can){
        MessageBox(hwnd, "OK... getting out", "Notice", MB_OK | MB_ICONINFORMATION);
    }
}

LRESULT CALLBACK window_proc(HWND wnd, UINT wMsg, WPARAM wParam, LPARAM lParam){
    switch (wMsg) {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(wnd, wMsg, wParam, lParam);
    }
}

LRESULT CALLBACK WndProc(HWND parent, UINT msg, WPARAM wParam, LPARAM lParam){
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, Windows Desktop!");
    LRESULT result = 0;

    using std::cout;
    using std::endl;

    switch(msg){
        case WM_CREATE:
            {
                cout << "created"<<endl;
                break;  
            }
            
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case IDD_DIALOG_CONVERTER:
                    {
                        int conv = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_DIALOG_CONVERTER), parent, ConverterDlg);
                        basic_commands(conv, parent);
                    }   break;
                    
                case IDD_DIALOG_CALCULATOR:
                    {   
                        int ret = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_DIALOG_CALCULATOR), parent, CalculatorDlg);
                        basic_commands(ret, parent);
                    }   break;

                case IDD_DIALOG_NIVELATOR:
                    {
                        int ret_niv = DialogBox(GetModuleHandle(NULL),
                        MAKEINTRESOURCE(IDD_DIALOG_NIVELATOR), parent, NivelatorDlg);
                        basic_commands(ret_niv, parent);
                    }   break;
                
                case IDD_DIALOG_NOTES:
                    {
                        int ret_note = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_DIALOG_NOTES), parent, NotasDlg);
                        basic_commands(ret_note, parent);
                    }   break; 

                case IDD_DIALOG_POSITIONER:
                    {
                        int ret_posi = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_DIALOG_POSITIONER), parent, PositionerDlg);
                        basic_commands(ret_posi, parent);
                    }   break;
		case IDD_DIALOG_POINTS:
		    {
			int ret  = DialogBox(GetModuleHandle(NULL),
			    MAKEINTRESOURCE(IDD_DIALOG_POINTS), parent, PointsDlg);
			basic_commands(ret, parent);
		    } 	break;
            }
            break;

        case WM_CLOSE:
            DestroyWindow(parent);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(parent, msg, wParam, lParam);
    }
    return result;
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
    wc.hIcon  = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
    wc.hIconSm  = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, 0);

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Window Registration Failed! wc", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        wc.lpszClassName,
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
