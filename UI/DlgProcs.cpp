
void InitializeComboBox(HWND hComboBox, const char que_combo_box[]) {

    using std::endl;

    // Agregar opciones al ComboBox

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

    

    // Seleccionar la primera opción (opcional)
    //SendMessage(hComboBox, CB_SETCURSEL, 0, 0);

    
}

BOOL CALLBACK ConverterDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    const char WC_COMBOBOX_DT[] = "COMBOBOX_DT"; 
    const char WC_COMBOBOX_NT[] = "COMBOBOX_NT"; 

    const char box_classname_dt[] = "boxclassname_dt";
    const char box_classname_nt[] = "boxclassname_nt";

    const char WC_PRUEBABOX[] = "PRUEBABOX";
    const char box_classname_prueba[] = "boxclassname_preba";


    switch(Message){
        case WM_CREATE:
        {
            HWND hComboBox_DT = CreateWindow(WC_COMBOBOX_DT, box_classname_dt,
                        CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
                        65, 55, 75, 19, hwnd, (HMENU)ID_OPTION_DT, NULL, NULL);
            InitializeComboBox(hComboBox_DT, WC_COMBOBOX_DT);

            break;

        }
        case WM_INITDIALOG:
        {
            cout << "\nIniciado el dialogo converter";
            

            HWND hComboBox_NT = CreateWindow(WC_COMBOBOX_NT, box_classname_nt,
                        CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
                        65, 80, 75, 19, hwnd, (HMENU)ID_OPTION_NT, NULL, NULL);

            InitializeComboBox(hComboBox_NT, WC_COMBOBOX_NT);

            HWND hComboBox = CreateWindow(
                WC_PRUEBABOX,
                NULL,
                CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
                20, 20, 200, 200,
                hwnd,
                (HMENU)1,
                NULL,
                NULL
            );

            InitializeComboBox(hComboBox, WC_PRUEBABOX);

            break;

        }


        case WM_COMMAND:
        {   
            switch(LOWORD(wParam))
            {
                case IDADD:
                {
                    cout << "\nAdding";
                    break;
                }
                case IDOK:
                {
                    cout << "\nOking";
                    break;
                }
                case IDCANCEL:
                {
                    cout << "\nCanceling";
                    break;
                }
            }
            break;
        }
    }

    return TRUE;
}

BOOL CALLBACK CalculatorDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){

    switch(Message)
    {
        case WM_INITDIALOG:
        {
            return TRUE;
        }

        case WM_COMMAND:
        {
            return TRUE;
        }
    }

    return TRUE;
}
BOOL CALLBACK NotasDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    using std::cout;
    using std::endl;

    switch(Message)
    {
        case WM_INITDIALOG:
        {
            cout <<"\nEntering the notas dialog";
            return TRUE;
        }

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_NOTAS_PIZARRA:
                    break;
                case ID_NOTAS_BORRARPIZARRA:
                    cout << "\nBorrando";
                    break;
                case ID_NOTAS_SALIRASISTENTE:
                    cout << "\nsaliendo";
                    break;
                case ID_NOTAS_SAVE:
                    {
                        char buffer[256];
                        HWND hEditControl = GetDlgItem(hwnd, ID_NOTAS_PIZARRA);

                        int len = GetWindowText(hEditControl, buffer, sizeof(buffer));
                        buffer[len] = '\0';

                        cout << "\n\n";
                        cout << buffer << endl;

                        break;

                    }

                    
            }
    }
    return TRUE;
}

BOOL CALLBACK CompoDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                break;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                break;
            }
        break;

        default:
            return FALSE;
    }
    return TRUE;
}

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                break;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                break;
            }
        break;

        default:
            return FALSE;
    }
    return TRUE;
}

BOOL CALLBACK CalculatorDlg(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){

    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;

        case WM_CREATE:
        {
            cout << "CalculatorDlg created";
        }
        
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                break;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                break;
            }
        break;

        default:
            return FALSE;
    }

    return TRUE;
}