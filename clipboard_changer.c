#include <stdio.h>
#include <windows.h>

//soon i'll add more funcs
int main()
{
    //char text[] = "text as var"
    /*Asks text from user*/
    char text[100];
    system("mode 60,15 && title r3x08 && color 4f");
    printf("Enter text to change data in clipboard: ");
    scanf("%s", text);
    /* checks length of text and adds '\0'(null terminator) at the end of the string */
    int len = strlen(text) + 1;
    /* HGLOBAL var named "hMem" == used for selecting dynamic memory via GlobalAlloc() and locate results to "hMem" var
    GMEM_MOVEABLE makes clipboard work between processes.
    Var "len" used for determine length of memory blocks to use */
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    /* memcpy" is used to copy the contents of "text" into the locked memory. */
    memcpy(GlobalLock(hMem), text, len);
    /* unlocks the memory previously locked by GlobalLock(hMem)*/
    GlobalUnlock(hMem);
    /* open system clipboard */
    OpenClipboard(0);
    /* Delete data from clipboard */
    EmptyClipboard();
    /* CF_TEXT = set's format of clipboard to plain text */
    SetClipboardData(CF_TEXT, hMem);
    /* close system clipboard */
    CloseClipboard();
    /* batch */
    system("mode 30,5 && title r3x08 && color 4f && echo DONE! Check your clipboard. && pause >nul");
    return 0;
}
