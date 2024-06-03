#include "includes.h"



void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
/*
int main()
{
    std::cout << "Hello World" << std::endl;
    int n;
    std::cin >> n;
    std::cout << ++n;
    ShowConsoleCursor(false);
    system("pause");
}*/

void setCursor(int x, int y) {
    // Tạo một cấu trúc COORD để lưu trữ tọa độ x, y
    COORD coord;
    coord.X = x;
    coord.Y = y;

    // Lấy handle của console output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Sử dụng hàm SetConsoleCursorPosition để di chuyển con trỏ
    SetConsoleCursorPosition(hConsole, coord);
}

//-3275-3272-3277-3280
//52565450
void control(int* ptr_x, int* ptr_y, int left, int top, int* ptr_cnt) {
    int x = *ptr_x, y = *ptr_y;
    int X = (x - left) / 2 + 1;
    int Y = y - top +1;
    int cnt = *ptr_cnt;
    string s[4] = { "   " , " x " , " o " , "[]" };
    setCursor(1, 1);
    //cout << " " << int(_getch());
    int keys[] = { 13, 'W', 'S', 'E' ,'A' , 72};
    for (int i = 0; i < 6; i++) {
        int v = GetAsyncKeyState(keys[i]);

        if (v & 1) {
            setCursor(x, y);
            cout << s[f[Y][X]];
            switch (keys[i])
            {
                //setColor(10, 0);
                //se
            case 'E':
                if (f[Y][X + 1] != 4) X++;
                //setCursor(1, 1);
                //setColor(9, 2);
                //cout << f[Y][X];
                break;
            case 'W':
                if (f[Y - 1][X] != 4) Y--;
                //cout << "nhan phim W" ; 
                break;
            case 'S':
                if (f[Y + 1][X] != 4) Y++;
                //cout << "nhan phim S";
                break;
            case 'A':
                if (f[Y][X - 1] != 4)X -- ;
                //cout << "nhan phim A";
                break;
            case 13:
                if (f[Y][X] == 0) {
                    if (cnt % 2 == 0)f[Y][X] = 2;else
                        f[Y][X] = 1;
                    cnt++;
                }
                break;
            }
            //setCursor(0, *ptr_cnt);
            //cout << x << " " << y << " " << "nhan phim " << ch <<" f : " <<f[y-top][(x-left)/2+1];
        }
    }
    *ptr_cnt = cnt;
    x = (X - 1) * 2 + left;
    y = Y + top - 1;
    *ptr_x = x;
    //setCursor(20, 20);
    *ptr_y = y;
    //cout << Y << " " << X;
    int green = 10 ;
    int aqua = 11;
    int red = 12;
    setCursor(x, y);
    setColor(green, 0);
    cout << "[ ]";
    setCursor(x + 1, y);
    switch (f[Y][X]) {
    case 0:
        cout << " ";
        break;
    case 1:
        setColor(red, 0);
        cout << "x";
        break;
    case 2:
        setColor(aqua, 0);
        cout << "o";
        break;
    }
}
