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


void PointDataBox(HWND hwnd, int ID_BX, int ID_LABEL){
	using std::cout;
	using std::endl;

	HWND HP = GetDlgItem(hwnd , ID_BX);
	int len = GetWindowTextLength(HP);
	
	char* Pcon = new char[len+1];
	GetDlgItemText(hwnd, ID_BX, Pcon, len+1);

	cout << "P: " << Pcon << endl;
	delete[] Pcon;
    
    HWND HE = GetDlgItem(hwnd, ID_LABEL);

    if(HP != NULL){
        ShowWindow(HP, SW_HIDE);
    }

    if(HE != NULL){
        ShowWindow(HE, SW_HIDE);
    }

}

