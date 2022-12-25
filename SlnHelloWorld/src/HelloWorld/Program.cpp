#include <windows.h>
#include <sstream>


#define WIN32_LEAN_AND_MEAN


using std::stringstream;

// WinMain é o ponto de entrada para todo programa Windows
// APIENTRY diz ao compilador como passar argumentos para WinMain
int APIENTRY WinMain(_In_ HINSTANCE hInstance,
                    _In_opt_ HINSTANCE hPrevInstance,
                    _In_ LPSTR lpCmdLine,
                    _In_ int nCmdShow)
{
    int questionWinow = 0;

    int mainWindow = MessageBox(NULL,
        "Hello World!",
        "",
        MB_OK);

    if (mainWindow == IDOK)
    {
        int questionWindow = MessageBox(NULL,
            "Do you want to know the screen size?",
            "Message",
            MB_YESNO | MB_ICONQUESTION);
    }
    
    if (questionWinow == IDOK)
    {
        int cxScreen = GetSystemMetrics(SM_CXSCREEN);
        int cyScreen = GetSystemMetrics(SM_CYSCREEN);

        stringstream text;
        text << "Resolution: " << cxScreen << " x " << cyScreen;

        MessageBox(NULL,
            text.str().c_str(),
            "Screen size",
            MB_OK | MB_ICONINFORMATION);
    }
    else {

        MessageBox(NULL,
            "Ok, Bye",
            "Message",
            MB_OK);
    }
    
    return 0;
}