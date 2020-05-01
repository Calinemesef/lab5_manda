#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <string>
#include "UI.h"
using namespace std;
int main() {
    /// ShellExecuteW(0, 0, L"https://www.youtube.com", 0, 0 , SW_SHOW ); ->merge direct pe link

    /** Merge pe string cu link
    string myUrl="https://www.youtube.com";
    system(string("start " + myUrl).c_str());
     */
     UI().program();
    return 0;
}
