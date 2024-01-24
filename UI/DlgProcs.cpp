#include <string>
char content[1024] = ""; 

void writer(const char *symbol, HWND hwnd){
    int numbers[] = {ID_ZERO, ID_ONE, ID_TWO, ID_THREE, ID_FOUR, ID_FIVE, ID_SIX, ID_SEVEN, ID_EIGTH, ID_NINE};
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

bool point_creation = false;
RECT FollowerRect = {0,0,0,0};

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
			HFONT hfont = CreateFont(14,0,0,0, FW_NORMAL, FALSE, FALSE,
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

BOOL CALLBACK PointsDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
	using std::cout;
	using std::endl;
	
	switch(Message){
		case WM_INITDIALOG:
			{
			const char ChildPointsClassName[] = "ChildPointsClass";

			CreateWindowEx(0,ChildPointsClassName, 
				NULL,WS_CHILD | WS_VISIBLE,
				150,10,400,400,
				hwnd,NULL, GetModuleHandle(NULL),NULL);
			}
			return TRUE;
		case WM_DESTROY:
			PostQuitMessage(0);
		
		case WM_SIZE:
			{
				cout << "sized" << endl;
			}
			break;
		case WM_COMMAND:
			{
			switch(LOWORD(wParam)){
				case IDCANCEL:
				cout << "cancel"<< endl;
				EndDialog(hwnd, IDCANCEL);
				break;
				case IDOK:{
					HWND hStatic = GetDlgItem(hwnd, ID_STATIC_TEXT);
					HWND Xentry = GetDlgItem(hwnd, ID_XENTRY);
					HWND Yentry = GetDlgItem(hwnd, ID_YENTRY);

                        		int lenx = GetWindowTextLength(Xentry);
					int leny = GetWindowTextLength(Yentry);

                        		if(lenx > 0 && leny > 0) {
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

				case ID_ADDPOINT:{
					PointRegister(hwnd, FollowerRect);
				} break;
                        }

			} break;
		default:
			return FALSE;
	}

	return TRUE;
}

