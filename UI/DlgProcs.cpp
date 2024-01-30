#include <string>
//#include "controllers/PointsProfile.cpp"

char content[1024] = ""; 

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

BOOL CALLBACK PositionerDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    using std::endl;
    using std::cout;

    switch(Message){
        case WM_CREATE:
            break;

        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case ID_POSITIONER_STATIC:
                {   
                    break;
                }
                case ID_POSITIONER_DYNAMIC:
                {
                    break;
                }
                case ID_POSITIONER_ABSOLUTE:
                {
                    break;
                }
                case ID_POSITIONER_DIFFERENTIAL:
                {
                    break;
                }

                case ID_POSITIONER_CANCEL:
                {
                    EndDialog(hwnd, ID_POSITIONER_CANCEL);
                    break;
                }

                case ID_POSITIONER_OK:
                {
                    EndDialog(hwnd, ID_POSITIONER_OK);
                    break;
                }
            }
        break;

        default:
            return FALSE;
    }

    return TRUE;
}
BOOL CALLBACK NivelatorDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    
    using std::endl;
    using std::cout;

    switch(Message){
        case WM_INITDIALOG:
        return TRUE;

        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case ID_NIVELAR:
                {
                    cout << "\nnivelando";
                    break;
                }
                case ID_NOTAS_NIVELADOR:
                {
                    cout << "\nnoting";
                    break;
                }
                case ID_NIVELADOR_SALIR:
                {
                    cout << "\nSaliendo..";
                    EndDialog(hwnd, ID_NIVELADOR_SALIR);
                    break;
                }

                case ID_PERFIL_SAVE:
                {
                    cout << "\nSaving perfil";
                    break;
                }
            }
        break;

        default:
            return FALSE;
    }

    return TRUE;
}

void InitializeComboBox(HWND hComboBox, const char que_combo_box[]) {

    using std::endl;
    using std::endl;

    const char opcion[] = "PRUEBABOX";

    if(que_combo_box == opcion){

        cout << "\nEl combobox es: " << que_combo_box << endl;

        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("prueba 1"));
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("prueba 2"));
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("prueba 3"));
    }
    else{

        cout << "\nEl combobox es: " << que_combo_box << endl;

        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Opcion 1"));
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Opcion 2"));
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Opcion 3"));
    }

}

BOOL CALLBACK ConverterDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){

    using std::endl;
    using std::cout;

    switch(Message){
        case WM_INITDIALOG:
        return TRUE;
        
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case ID_CONVERTER_CANCEL:
                    
                    EndDialog(hwnd, ID_CONVERTER_CANCEL);
                    break;

                case ID_CONVERTER_OK:
                    
                    EndDialog(hwnd, ID_CONVERTER_OK);
                    break;

                case ID_CONVERTER_ADD:
                    cout << "\nAdding";
                    break;
            }
        break;

        default:
            return FALSE;
    }

    return TRUE;
}


BOOL CALLBACK CalculatorDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){

    HWND hStatic = GetDlgItem(hwnd, ID_STATIC_TEXT);

    switch(Message){
        case WM_INITDIALOG:
        return TRUE;

        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case ID_CALCULATOR_OK:
                    EndDialog(hwnd, ID_CALCULATOR_OK);
                break;

                case ID_CALCULATOR_CANCEL:
                    EndDialog(hwnd, ID_CALCULATOR_CANCEL);
                break;

                case ID_CLEAN:
                {
                    HWND hEdit = GetDlgItem(hwnd, ID_EDIT_CONTROL); 
                    SetWindowText(hEdit, ""); 
                }
                break;

                case ID_DELETE:
                    SetWindowText(hStatic, "");
                    strcpy(content, "");
                break;

                case ID_EQUAL:
                    {
                        HWND pizarra = GetDlgItem(hwnd, ID_EDIT_CONTROL);
                        int len = GetWindowTextLength(pizarra);

                        if (len > 0) {
                            char* buffer = new char[len + 1];  
                            GetDlgItemText(hwnd, ID_EDIT_CONTROL, buffer, len + 1);

                            strcat(content, buffer);
                            strcat(content, "\n");
				/*
			    float result = create_substrings(content);
			    char BUFFER[20];
	
			    std::sprintf(BUFFER, "%f", result);
			    const char* resulbff= BUFFER;
                            SetWindowText(hStatic, resulbff);
				*/
                            delete[] buffer; 
                        }
                    }
                break;

                case ID_PLUS:
                    writer("+", hwnd);
                break;

                case ID_MINUS:
                    writer("-", hwnd);
                break;

                case ID_OPEN:
                    writer("(", hwnd);
                break;

                case ID_CLOSE:
                    writer(")", hwnd);
                break;

                case ID_ZERO:
                    writer("0", hwnd);
                break;

                case ID_ONE:
                    writer("1", hwnd);
                break;

                case ID_TWO:
                    writer("2", hwnd);
                break;

                case ID_THREE:
                    writer("3", hwnd);
                break;

                case ID_FOUR:
                    writer("4", hwnd);
                break;

                case ID_FIVE:
                    writer("5", hwnd);
                break;

                case ID_SIX:
                    writer("6", hwnd);
                break;

                case ID_SEVEN:
                    writer("7", hwnd);
                break;

                case ID_EIGTH:
                    writer("8", hwnd);
                break;

                case ID_NINE:
                    writer("9", hwnd);
                break;
            }
        break;

        default:
            return FALSE;
    }

    return TRUE;
}
BOOL CALLBACK NotasDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    using std::cout;
    using std::endl;

    switch(Message){
        case WM_INITDIALOG:
        return TRUE;

        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case ID_NOTAS_PIZARRA:
                    break;

                case ID_NOTAS_BORRARPIZARRA:
                    {
                        HWND hEdit = GetDlgItem(hwnd, ID_NOTAS_PIZARRA); // Replace with your edit control's resource ID
                        SetWindowText(hEdit, ""); // Set the text to an empty string  
                        
                        break;
                    }

                case ID_NOTAS_SALIRASISTENTE:
                    cout << "\nsaliendo";
                    EndDialog(hwnd, ID_NOTAS_SALIRASISTENTE);
                    break;

                case ID_NOTAS_SAVE:
                    {
                        
                        HWND hEdit = GetDlgItem(hwnd, ID_NOTAS_PIZARRA);
                        int len = GetWindowTextLength(hEdit);

                        if (len > 0) {
                            char* buffer = new char[len + 1];  // Add 1 for null-termination
                            GetDlgItemText(hwnd, ID_NOTAS_PIZARRA, buffer, len + 1);
                            MessageBox(hwnd, buffer, "Edit Control Text", MB_ICONINFORMATION);
                            delete[] buffer; // Free the allocated memory
                        }
                        else {
                            MessageBox(hwnd, "Edit control is empty.", "Edit Control Text", MB_ICONINFORMATION);
                        }
                    }
            }
        break;

        default:
            return FALSE;
    }
    return TRUE;
}


void CreateBox(HDC hdc,int x0,int y0,int width,int height,int red,int green,int blue){
	HBRUSH brush = CreateSolidBrush(RGB(red, green, blue));
	int xf = x0 + width;
	int yf = y0 + height;

	RECT rect = {x0,y0,xf,yf};
	FillRect(hdc,&rect,brush);
	
	DeleteObject(brush);
}

bool clean_screen = false;
bool point_creation = false;
RECT FollowerRect = {0,0,0,0};

void CleanScreen(HDC hdc, RECT rect){
	HBRUSH screen_brush = CreateSolidBrush(RGB(0,0,0));	
	FillRect(hdc, &rect, screen_brush);
}

void PointRegister(HWND hwnd, RECT rect){
	using std::endl;

	HWND hStatic = GetDlgItem(hwnd, ID_STATIC_TEXT);
	
	std::string cursory = std::to_string(rect.left + 4);
	std::string cursorx = std::to_string(rect.top + 4);
	std::string message = "x:"+cursorx + "\ny:" + cursory;	

	SetWindowText(hStatic, message.c_str());
}

void CreatePoint(HWND hwnd, HDC hdc, RECT rect){
	HBRUSH brush = CreateSolidBrush(RGB(0,255,0));
	FillRect(hdc, &rect, brush);
}

LRESULT CALLBACK ScreenPoints(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
	using std::cout;
	using std::endl;

	switch(Message){
		case WM_CREATE:
			{
			const char font[] = "Arial";
			HFONT hfont = CreateFont(10,0,0,0, FW_NORMAL, FALSE, FALSE,
					FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, 
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
					DEFAULT_PITCH | FF_DONTCARE, font);
			SendMessage(hwnd, WM_SETFONT, (WPARAM)hfont, TRUE);
			//this function sends 'WM_SETFONT' to a window (hwnd)
			//it sets the hfont as the default for a specfied window
			}
			break;
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			RECT rect;
			GetClientRect(hwnd, &rect);
			FrameRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			
			if(point_creation){
				
				CreatePoint(hwnd, hdc, FollowerRect);
				point_creation = false;//this does not change anything
			}
			
			if(clean_screen){
				CleanScreen(hdc, rect);
				clean_screen = false;
			}

			EndPaint(hwnd, &ps);
			break;
		}
		case WM_LBUTTONDOWN:{
			point_creation = true;

			POINT cursor;
			GetCursorPos(&cursor);
			ScreenToClient(hwnd, &cursor);

			FollowerRect.left = cursor.x - 4;
			FollowerRect.right = cursor.x + 4;
			FollowerRect.top = cursor.y - 4;
			FollowerRect.bottom = cursor.y + 4;

			InvalidateRect(hwnd, NULL, TRUE);

		} break;
		case WM_MOUSEMOVE:
		{
			POINT cursor;
			GetCursorPos(&cursor);//saves the position in cursor
			ScreenToClient(hwnd, &cursor);
			//converts coords to be relative to client
			std::string xcor = std::to_string(cursor.x);
			std::string ycor = std::to_string(cursor.y);
			
			std::string phrase = "x: " + xcor + "|y: " + ycor;
			
			HDC hdc = GetDC(hwnd);
			RECT clientrect;
			GetClientRect(hwnd, &clientrect);
			//saves hwnd dimension into clientrect
			DrawText(hdc, phrase.c_str(), -1, &clientrect, DT_TOP | DT_LEFT);
			ReleaseDC(hwnd, hdc);
		} break;

	}
	return DefWindowProc(hwnd, Message, wParam, lParam);
}

void ShowPopup(HWND hwnd){

	HWND hComboBox = CreateWindow("ComboBox", NULL, WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
			550, 10, 100, 100, hwnd, (HMENU)ID_CB2, NULL, NULL);

	SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"Option1");
	SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"Option2");
	SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"Option3");
	
}

void PointEntriesMaker(HWND hwnd, std::string label_name, int posH, int ID_TOCALL){

	HWND hedit = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			585,150 + posH,80,16,hwnd, (HMENU)ID_TOCALL, GetModuleHandle(NULL), NULL);
	HWND label = CreateWindow("STATIC", label_name.c_str(), WS_VISIBLE | WS_CHILD | SS_LEFT,
			565,150 + posH,15,15, hwnd, (HMENU)ID_TOCALL + 20, GetModuleHandle(NULL), NULL);
	//Add a save point button for the whole set
}



BOOL CALLBACK PointsDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
	using std::cout;
	using std::endl;
	
	std::string TYPE_SET = "non-type"; 
	//std::vector<StratPoint> StratCurrentSet;
	//std::vector<AnglePoint> AngleCurrentSet;
	//std::vector<NormalPoint> NormCurrentSet;
	
	switch(Message){
		case WM_INITDIALOG:
			{
			HWND hComboBox = CreateWindow("ComboBox", NULL, 
				WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
				5, 170, 100, 100, hwnd, 
				(HMENU)ID_CB1, NULL, NULL);

			SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"Prove 1");
			SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"Prove 2");
			SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"Prove 3");

			const char ChildPointsClassName[] = "ChildPointsClass";

			CreateWindowEx(0,ChildPointsClassName, 
				NULL,WS_CHILD | WS_VISIBLE,
				150,10,400,400,
				hwnd,NULL, GetModuleHandle(NULL),NULL);
			}
			return TRUE;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_SIZE:
			{
				cout << "sized" << endl;
			}
			break;
		case WM_COMMAND:
			{
			switch(LOWORD(wParam)){
				case IDCANCEL:
					PostQuitMessage(0);
					//EndDialog(hwnd, IDCANCEL);
				break;
				case IDOK:{
					HWND hStatic = GetDlgItem(hwnd, ID_REGISTER);
					HWND Xentry = GetDlgItem(hwnd, ID_XENTRY);
					HWND Yentry = GetDlgItem(hwnd, ID_YENTRY);
					
					if(Xentry == NULL && Yentry == NULL){
						cout << "Entry elements were not found" << endl;
						break;
					}
					
					int lenx = GetWindowTextLength(Xentry);
					int leny = GetWindowTextLength(Yentry);
                        		
                        		if(lenx > 0 && leny > 0) {
						cout << "entering conditional" << endl;
                            			char* buffx = new char[lenx + 1];
						char* buffy = new char[leny +1];

						GetDlgItemText(hwnd, ID_XENTRY, 
								buffx, lenx+1);
						std::string xcoor(buffx);

						GetDlgItemText(hwnd, ID_YENTRY, 
								buffy, leny+1);
						std::string ycoor(buffy);
						std::string msg = "x:"+xcoor+"\ny:"+ycoor;

						SetWindowText(hStatic,msg.c_str());
						
						delete[] buffx;
						delete[] buffy;
					}
                           	} break;
				case ID_ADDSETPOINT:
				{
					HWND CB2_content = GetDlgItem(hwnd,ID_CB2);
					int len = GetWindowTextLength(CB2_content);

					if(CB2_content == NULL){
						cout << "Resource not found" << endl;
					} else {
						char* content = new char[len+1];
						GetDlgItemText(hwnd, ID_CB2, content, len+1);
						std::string strcon(content);
						TYPE_SET = strcon;
						cout << "content: " << TYPE_SET << endl;
					}
					
					if(TYPE_SET == "StratSet"){
						PointEntriesMaker(hwnd, "X",0, ID_STRAT_P1);
						PointEntriesMaker(hwnd, "Y",20, ID_STRAT_P2);
						PointEntriesMaker(hwnd, "a1",40, ID_STRAT_P3);
						PointEntriesMaker(hwnd, "a2",60, ID_STRAT_P4);
						PointEntriesMaker(hwnd, "a3",80, ID_STRAT_P5);
					} 

					if(TYPE_SET == "NormalSet"){
						PointEntriesMaker(hwnd, "X", 0, ID_NORMAL_P1);
						PointEntriesMaker(hwnd, "Y", 20, ID_NORMAL_P2);

					}

					if(TYPE_SET == "AngleSet"){
						PointEntriesMaker(hwnd, "X", 0, ID_ANGLE_P1);
						PointEntriesMaker(hwnd, "Y", 20, ID_ANGLE_P2);
						PointEntriesMaker(hwnd, "a1", 40, ID_ANGLE_P3);
						PointEntriesMaker(hwnd, "a2", 60, ID_ANGLE_P4);
						PointEntriesMaker(hwnd, "a3", 80, ID_ANGLE_P5);
					}					}

					HWND SaveButton = CreateWindow("BUTTON", "Save point", 
							WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
							565, 250, 80, 30, hwnd, 
							(HMENU)ID_SAVE_POINT, 
							GetModuleHandle(NULL), NULL);
					
				} break;
				case ID_ADDSET:
				{
					cout << "ADDSET clicked" << endl;

					HWND hComboBox = CreateWindow("ComboBox", NULL, 
						WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
						555, 10, 100, 100, hwnd, 
						(HMENU)ID_CB2, NULL, NULL);
					
					if(hComboBox == NULL){
						cout << "Combo box null"<< endl;
					}

					SendMessage(hComboBox, CB_ADDSTRING, ID_STRATP, 
							(LPARAM)"StratSet");
					SendMessage(hComboBox, CB_ADDSTRING, ID_NORMALP, 
							(LPARAM)"NormalSet");
					SendMessage(hComboBox, CB_ADDSTRING, ID_ANGLEP, 
							(LPARAM)"AngleSet");
				} break;
				case ID_CLEAN_SCREEN:{
					//clean the screen at the first click on the windows
					//later of being this button
					clean_screen = true;
				} break;
				case ID_ADDPOINT:{
					PointRegister(hwnd, FollowerRect);
				} break;

				case ID_SAVE_POINT:
				{
					if(TYPE_SET == "StratSet"){
						HWND HP1 = GetDlgItem(hwnd ,ID_STRAT_P1);
						HWND HP2 = GetDlgItem(hwnd ,ID_STRAT_P2);
						HWND HP3 = GetDlgItem(hwnd ,ID_STRAT_P3);
						HWND HP4 = GetDlgItem(hwnd ,ID_STRAT_P4);
						HWND HP5 = GetDlgItem(hwnd ,ID_STRAT_P5);

						int lenP1 = GetWindowTextLength(HP1);
						int lenP2 = GetWindowTextLength(HP1);
						int lenP3 = GetWindowTextLength(HP1);
						int lenP4 = GetWindowTextLength(HP1);
						int lenP5 = GetWindowTextLength(HP1);
						
						char* P1con = new char[lenP1+1];
						char* P2con = new char[lenP2+1];
						char* P3con = new char[lenP3+1];
						char* P4con = new char[lenP4+1];
						char* P5con = new char[lenP5+1];

						GetDlgItemText(hwnd, ID_STRAT_P1, P1con, lenP1+1);
						GetDlgItemText(hwnd, ID_STRAT_P2, P2con, lenP2+1);
						GetDlgItemText(hwnd, ID_STRAT_P3, P3con, lenP3+1);
						GetDlgItemText(hwnd, ID_STRAT_P4, P4con, lenP4+1);
						GetDlgItemText(hwnd, ID_STRAT_P5, P5con, lenP5+1);
							
						cout << "P1: " << P1con << endl;
						cout << "P2: " << P2con << endl;
						cout << "P3: " << P3con << endl;
						cout << "P4: " << P4con << endl;
						cout << "P5: " << P5con << endl;
			
						delete[] P1con;
						delete[] P2con;
						delete[] P3con;
						delete[] P4con;
						delete[] P5con;
						
					}
				} break;
			} break;
		default:
			return FALSE;
	}

	return TRUE;
}

