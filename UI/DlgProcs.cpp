
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

/*

float create_substrings (char* complete_string) {
	using std::cout;
	using std::endl;

	int count_symbol = frequency(complete_string);	
	int count_number = count_symbol + 1;

	std::string operations = "";
	
	float* numbers = new float[count_number];
	int k = 0;

	//numbers dimensions should be reviewed more slowly
	//it works but it returns 1 more in size
	while(*complete_string != '\0'){
		if(k < count_number){
			complete_string = separate_terms(complete_string,&operations,numbers,count_symbol,&k);
		}

		complete_string++;
	}

	cout << "operations: " << endl;
	float result = operate(numbers, operations);

	return result;
}*/



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


BOOL CALLBACK PointsDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
	using std::cout;
	using std::endl;
	
	switch(Message){
		case WM_INITDIALOG:
		return TRUE;
		case WM_SIZE:
			{
				cout << "sized" << endl;
			}
			break;
		default:
			return FALSE;
	}

	return TRUE;
}

