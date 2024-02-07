BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam) {
    char className[256];
	const char target_wnd[] = "ScreenProfile";
    GetClassName(hwnd, className, sizeof(className) / sizeof(char));
    
    if (strcmp(className,target_wnd) == 0) {
        *(HWND*)lParam = hwnd;
        return FALSE; //Stop enumeration
    } 

    return TRUE; // Continue enumeration
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char className[256];
	const char myClassName[] = "";
    GetClassName(hwnd, className, sizeof(className) / sizeof(char));
    
    if (strcmp(className,myClassName) == 0) {
        std::cout << "something" << std::endl;
        // Found the window by class name
        *(HWND*)lParam = hwnd;
        return FALSE; // Stop enumeration
    } else {
        std::cout << "classname: " << className << std::endl;
    }

    return TRUE; // Continue enumeration
}


void writer(const char *symbol, HWND hwnd){
    int numbers[] = {ID_ZERO, ID_ONE, ID_TWO, ID_THREE, ID_FOUR, ID_FIVE, 
	    ID_SIX, ID_SEVEN, ID_EIGTH, ID_NINE};
    char writing[256] = "";

    HWND pizarra = GetDlgItem(hwnd, ID_EDIT_CONTROL);
    int len = GetWindowTextLength(pizarra);

    char* buffer = new char[len + 1]; 
    GetDlgItemText(hwnd, ID_EDIT_CONTROL, buffer, len + 1);

    strcat(writing, buffer);
    strcat(writing, symbol);

    SetWindowText(pizarra, writing);
}


void CreateBox(HDC hdc,int x0,int y0,int width,int height,int red,int green,int blue){
	HBRUSH brush = CreateSolidBrush(RGB(red, green, blue));
	int xf = x0 + width;
	int yf = y0 + height;

	RECT rect = {x0,y0,xf,yf};
	FillRect(hdc,&rect,brush);
	
	DeleteObject(brush);
}


void CleanScreen(HDC hdc, RECT rect){
	HBRUSH screen_brush = CreateSolidBrush(RGB(0,0,0));	
	FillRect(hdc, &rect, screen_brush);
}

void PointRegister(HWND hwnd, RECT rect){
	using std::endl;

	HWND hStatic = GetDlgItem(hwnd, ID_STATIC_TEXT);
	
    if(hStatic == NULL){ cout << "static is null" << endl;}

	std::string cursory = std::to_string(rect.left + 4);
	std::string cursorx = std::to_string(rect.top + 4);
	std::string message = "x:"+cursorx + "\ny:" + cursory;	

	SetWindowText(hStatic, message.c_str());
}

void CreateLine(HWND wnd, HDC hdc, RECT rect, float angle){
    using std::cout;
    using std::endl;

    /*
    rect.left = -1;
    rect.right= +1;
    rect.top = -1;
    rect.bottom = +1;

    int xwidth= 1;
    int i = 0;
    for(int i = 0;i<10;i++){
        
    }*/
}

void CreatePoint(HWND hwnd, HDC hdc, RECT rect){
    using std::cout;
    using std::endl;

	try {
        HBRUSH brush = CreateSolidBrush(RGB(0,255,0));
	    FillRect(hdc, &rect, brush);
    }

    catch(const std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}


void ShowPopup(HWND hwnd, int x, int y, int width, int height, int IDD, std::vector<std::string> options){
	using std::cout;
	using std::endl;

	HWND hComboBox = CreateWindow("ComboBox", NULL, 
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
			x, y, width, height, hwnd, (HMENU)IDD, NULL, NULL);

	for(auto& option: options){
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM) option.c_str());
	}
}


void PointEntriesMaker(HWND hwnd, std::string label_name, int posH, int ID_BX, int ID_LBL){

	HWND hedit = CreateWindow("EDIT", "", 
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			585,150 + posH,80,16,hwnd, (HMENU)ID_BX, GetModuleHandle(NULL), NULL);
	HWND label = CreateWindow("STATIC", label_name.c_str(), WS_VISIBLE | WS_CHILD | SS_LEFT,
			565,150 + posH,15,15, hwnd, (HMENU)ID_LBL, GetModuleHandle(NULL), NULL);
	//Add a save point button for the whole set
}

void RectiPoint(int ID_ANGLE,HWND hwnd, int ID_BX, int ID_BY, RECT& rect){
    //this function just modify the rect element
    using std::cout;
    using std::endl;
    
    HWND ANG = GetDlgItem(hwnd, ID_ANGLE);
    int lena = GetWindowTextLength(ANG);

    HWND X = GetDlgItem(hwnd, ID_BX);
	int lenx = GetWindowTextLength(X);

    HWND Y = GetDlgItem(hwnd, ID_BY);
    int leny = GetWindowTextLength(Y);
    
    char* PX = new char[lenx+1];
	GetDlgItemText(hwnd, ID_BX, PX, lenx+1);
    
    char* PY = new char[leny+1];
	GetDlgItemText(hwnd, ID_BY, PY, leny+1);
    
    char* PA = new char[lena+1];
	GetDlgItemText(hwnd, ID_ANGLE, PA, lena+1);
    
    cout << "PA:"<<PA << endl;

    int Pnumx = std::atoi(PX);
    int Pnumy = std::atoi(PY);
    float Pnuma = std::strtof(PA, nullptr);

    rect.left = Pnumx-2; 
    rect.right = Pnumx+2;
    rect.top = Pnumy-2;
    rect.bottom = Pnumy+2;

    HWND targetwnd = NULL;
    EnumChildWindows(hwnd, EnumChildProc, (LPARAM)&targetwnd);
    
    if(targetwnd != NULL){
        InvalidateRect(targetwnd,NULL,TRUE);
        SendMessage(targetwnd, WM_PAINT,0,0);
        cout << "window does exists" << endl;
    } else {
        cout << "window does not exists" << endl;
    }
    cout << Pnuma << endl;
    float Pnuma_rads = M_PI * (1/180.0) * Pnuma;
    cout << Pnuma_rads << endl;
    float ite = std::tan(Pnuma_rads); 
    
    cout << "ite: " << ite << endl;

    float acu = 0.0;
    for(int i=0; i<50;i++){
        rect.left = Pnumx + i -1;
        rect.right = Pnumx + i +1;
        rect.top = Pnumy + acu -1;
        rect.bottom = Pnumy + acu +1;

        InvalidateRect(targetwnd,NULL, TRUE);
        SendMessage(targetwnd, WM_PAINT, 0,0);
        acu = acu + ite;
    }

}

void CleanElement(HWND hwnd, int ID_BX, int ID_LABEL){
	using std::cout;
	using std::endl;

	HWND BOX = GetDlgItem(hwnd , ID_BX);
    HWND LBL = GetDlgItem(hwnd, ID_LABEL);

    if(BOX != NULL){ ShowWindow(BOX, SW_HIDE); }

    if(LBL != NULL){ ShowWindow(LBL, SW_HIDE); }
}



