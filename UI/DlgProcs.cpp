BOOL CALLBACK PositionerDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){

    using std::endl;
    using std::cout;

    switch(Message){
        case WM_PAINT:
        {   
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Aquí debes realizar el dibujo de los elementos de la ventana
            // Utiliza las funciones de dibujo de WinAPI como TextOut, Rectangle, etc.

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_CREATE:
        {
            cout << "positioner created"<< endl;
            break;
        }

        case WM_COMMAND:
        {   

            switch(LOWORD(wParam))
            {
                case ID_POSITIONER_STATIC:
                {   
                    cout << "static" << endl;
                    break;
                }
                case ID_POSITIONER_DYNAMIC:
                {
                    cout << "dynamic" << endl;
                    break;
                }
                case ID_POSITIONER_ABSOLUTE:
                {
                    cout << "absolute" << endl;
                    break;
                }
                case ID_POSITIONER_DIFFERENTIAL:
                {
                    cout << "differential" << endl;
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
        }
    }

    return TRUE;
}
BOOL CALLBACK NivelatorDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    
    using std::endl;
    using std::cout;

    switch(Message){
        case WM_CREATE:
        {   
            cout << "nivelador dlg created" << endl;
            break;
        }

        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {

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
        }
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

BOOL CALLBACK ConverterDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){

    using std::endl;
    using std::cout;

    switch(Message){
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Aquí debes realizar el dibujo de los elementos de la ventana
            // Utiliza las funciones de dibujo de WinAPI como TextOut, Rectangle, etc.

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_CREATE:
        {
            cout << "converter dlg created" << endl;
            break;

        }
        case WM_INITDIALOG:
        {
            cout << "\nIniciado el dialogo converter" << endl;

            break;

        }


        case WM_COMMAND:
        {   
            switch(LOWORD(wParam))
            {
                case ID_CONVERTER_CANCEL:
                {
                    EndDialog(hwnd, ID_CONVERTER_CANCEL);
                    break;
                }
                case ID_CONVERTER_ADD:
                {
                    cout << "\nAdding";
                    break;
                }
                case ID_CONVERTER_OK:
                {
                    cout << "\nOking";
                    break;
                }
            }
            break;
        }
    }

    return TRUE;
}

void send_value(HWND hwnd, int size, char operation[]){

    using std::cout;
    using std::endl;

    char buffer[size];

    HWND hEditControl = GetDlgItem(hwnd, ID_CALCULATOR_DISPLAY);

    int len = GetWindowText(hEditControl, buffer, sizeof(buffer));
    buffer[len] = '\0';

    cout << "\n\n";
    cout << buffer << endl;

    operate(buffer, operation);
    

}

BOOL CALLBACK CalculatorDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    int bsize = 256;

    switch(Message)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Aquí debes realizar el dibujo de los elementos de la ventana
            // Utiliza las funciones de dibujo de WinAPI como TextOut, Rectangle, etc.

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_INITDIALOG:
        {   
            cout << "\nInitializing calculator";
            break;
        }

        case WM_COMMAND:
        {   
            switch(LOWORD(wParam)){
                case ID_CALCULATOR_CANCEL:
                {
                    EndDialog(hwnd, ID_CALCULATOR_CANCEL);
                }

                case ID_SUM:
                {
                    char operation[] = "+";

                    send_value(hwnd, bsize, operation);
                    break;
                }

                case ID_REST:
                {
                    char operation[] = "-";

                    send_value(hwnd, bsize, operation);
                    break;
                }

                case ID_DIV:
                {
                    char operation[] = ":";
                    break;
                }

                case ID_MULT:
                {
                    char operation[] = "*";
                    break;
                }
                
            }
        }
    }

    return TRUE;
}
BOOL CALLBACK NotasDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    using std::cout;
    using std::endl;

    switch(Message)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_INITDIALOG:
        {
            cout <<"\nEntering the notas dialog";
            break;
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
                    EndDialog(hwnd, ID_NOTAS_SALIRASISTENTE);
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



BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Aquí debes realizar el dibujo de los elementos de la ventana
            // Utiliza las funciones de dibujo de WinAPI como TextOut, Rectangle, etc.

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_INITDIALOG:
        {
            break;  
        }
        
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_ABOUT_OK:
                    EndDialog(hwnd, ID_ABOUT_OK);
                break;
                case ID_ABOUT_CANCEL:
                    EndDialog(hwnd, ID_ABOUT_CANCEL);
                break;
            }
        break;

        default:
            return FALSE;
    }
    return TRUE;
}

