#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include"BaseCon.h"

#define FILE_MENU_EXIT 1
#define CONVERT_BUTTON 2

HWND hInput,hFBase,hTBase,hFinal;
HMENU hmenu;
HBITMAP hButtonImage;

//prototypes
LRESULT CALLBACK windowprocedure(HWND,UINT,WPARAM,LPARAM);
void AddingMenu(HWND);
void AddingControl(HWND);
void AddingImage();

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) //main function
{
    WNDCLASSW ourwindow = {0};

    ourwindow.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    ourwindow.hCursor = LoadCursor(NULL,IDC_ARROW);
    ourwindow.hInstance = hInst;
    ourwindow.lpszClassName = L"MyWindowClass";
    ourwindow.lpfnWndProc = windowprocedure;

    if (!RegisterClassW(&ourwindow)) return -1;

    CreateWindowW(L"MyWindowClass",L"Base Converter",WS_OVERLAPPEDWINDOW|WS_VISIBLE,100,100,500,500,NULL,NULL,NULL,NULL);

    MSG msg = {0};
    while (GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK windowprocedure(HWND hwnd,UINT msg,WPARAM wpa,LPARAM lpa)
{
    int CloseOrIgnore; //needed for messagebox when we ask "are you sure to leave?"
    int NullAnswer; //needed for when user does not give us input
    int WrongNumber; //needed for when user's input is not in mentioned base 
    switch(msg)
    {
        case WM_COMMAND: //when a control pressed
            switch(wpa)
            {
                case FILE_MENU_EXIT:
                    CloseOrIgnore = MessageBoxW(NULL,L"Are You Sure to Leave?",L"Wait!",MB_YESNO|MB_ICONQUESTION); 
                    if (CloseOrIgnore==IDYES) {DestroyWindow(hwnd);}
                    break;
                case CONVERT_BUTTON:
                    char input[30],FBase[3],TBase[3],Final[30];
                    int IFinal;
                    GetWindowText(hInput,input,30);
                    GetWindowText(hFBase,FBase,3);
                    GetWindowText(hTBase,TBase,3);
                    int IInput = CharToNum(input);
                    int IFBase = CharToNum(FBase);
                    int ITBase = CharToNum(TBase);
                    if ((IInput==NULL)&&(IFBase==NULL)&&(ITBase==NULL))
                    {
                        NullAnswer = MessageBox(hwnd,(LPCSTR)"You didn't enter anything!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(NullAnswer)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if ((IInput==NULL)&&(IFBase!=NULL)&&(ITBase!=NULL))
                    {
                        NullAnswer = MessageBox(hwnd,(LPCSTR)"You didn't enter the number!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(NullAnswer)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if ((IInput!=NULL)&&(IFBase==NULL)&&(ITBase!=NULL))
                    {
                        NullAnswer = MessageBox(hwnd,(LPCSTR)"You didn't enter first base!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(NullAnswer)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if ((IInput!=NULL)&&(IFBase!=NULL)&&(ITBase==NULL))
                    {
                        NullAnswer = MessageBox(hwnd,(LPCSTR)"You didn't enter second base!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(NullAnswer)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if ((IInput==NULL)&&(IFBase==NULL)&&(ITBase!=NULL))
                    {
                        NullAnswer = MessageBox(hwnd,(LPCSTR)"You didn't enter the number & first base!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(NullAnswer)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if ((IInput==NULL)&&(IFBase!=NULL)&&(ITBase==NULL))
                    {
                        NullAnswer = MessageBox(hwnd,(LPCSTR)"You didn't enter the number & second base!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(NullAnswer)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if ((IInput!=NULL)&&(IFBase==NULL)&&(ITBase==NULL))
                    {
                        NullAnswer = MessageBox(hwnd,(LPCSTR)"You didn't enter first & second base!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(NullAnswer)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if (WrongNum(IInput,IFBase))
                    {
                        WrongNumber = MessageBox(hwnd,(LPCSTR)"Your Number is not in the base!",(LPCSTR)"Error",MB_ABORTRETRYIGNORE|MB_ICONERROR);
                        switch(WrongNumber)
                        {
                            case IDABORT:
                                DestroyWindow(hwnd);
                                break;
                            case IDTRYAGAIN:
                                return 0;
                                break;
                            case IDIGNORE:
                                break;
                        }
                    }
                    else if (ITBase==10)
                    {
                        IFinal = NumToTen(IInput,IFBase);
                        itoa(IFinal,Final,10);
                        SetWindowText(hFinal,Final);
                    }
                    else if (IFBase==10)
                    {
                        IFinal = TenToNum(IInput,10);
                        itoa(IFinal,Final,ITBase);
                        SetWindowText(hFinal,Final);
                    }
                    else
                    {
                        int Temporary = NumToTen(IInput,IFBase);
                        IFinal = TenToNum(Temporary,ITBase);
                        itoa(IFinal,Final,10);
                        SetWindowText(hFinal,Final);
                    }
            }
            break;
        case WM_CREATE:
            AddingImage();
            AddingMenu(hwnd);
            AddingControl(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd,msg,wpa,lpa);
    }
}

void AddingMenu(HWND hwnd)
{
    hmenu = CreateMenu();
    //add menu to window
    AppendMenu(hmenu,MF_STRING,FILE_MENU_EXIT,"Exit");
    SetMenu(hwnd,hmenu);
}

void AddingControl(HWND hwnd)
{
    CreateWindowW(L"Static",L"Enter Number:",WS_VISIBLE|WS_CHILD|WS_EX_DLGMODALFRAME,100,50,100,30,hwnd,NULL,NULL,NULL);
    hInput = CreateWindowW(L"Edit",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,200,50,150,30,hwnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"From Base:",WS_VISIBLE|WS_CHILD|WS_EX_DLGMODALFRAME,100,100,100,30,hwnd,NULL,NULL,NULL);
    hFBase = CreateWindowW(L"Edit",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,200,100,150,30,hwnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"To Base:",WS_VISIBLE|WS_CHILD|WS_EX_DLGMODALFRAME,100,150,100,30,hwnd,NULL,NULL,NULL);
    hTBase = CreateWindowW(L"Edit",NULL,WS_VISIBLE|WS_BORDER|WS_CHILD,200,150,150,30,hwnd,NULL,NULL,NULL);
    HWND hButton = CreateWindowW(L"Button",NULL,WS_VISIBLE|WS_CHILD|BS_BITMAP,70,200,80,30,hwnd,(HMENU)CONVERT_BUTTON,NULL,NULL);
    hFinal = CreateWindowW(L"Edit",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER|WS_THICKFRAME|WS_EX_DLGMODALFRAME,70,250,300,60,hwnd,NULL,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hButtonImage);
}

void AddingImage()
{
    hButtonImage = (HBITMAP)LoadImageW(NULL,L"convertbutton.bmp",IMAGE_BITMAP,80,40,LR_LOADFROMFILE);
}