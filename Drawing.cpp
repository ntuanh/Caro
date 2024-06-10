#include"includes.h"

Drawing drawing;

// Hàm thiết lập màu sắc văn bản
void Drawing::setColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}
    // Các mã màu cơ bản:
    // 0 = Black       8 = Gray
    // 1 = Blue        9 = Light Blue
    // 2 = Green       10 = Light Green
    // 3 = Aqua        11 = Light Aqua
    // 4 = Red         12 = Light Red
    // 5 = Purple      13 = Light Purple
    // 6 = Yellow      14 = Light Yellow
    // 7 = White       15 = Bright White

    // Đặt màu sắc văn bản là đỏ, nền là đen
    //setColor(4, 0);


// ve hinh vuong
void Drawing::retangle(int left, int top, int size_col, int size_row) {
    setCursor(0, 0);
    for (int i = 0; i <= size_col; i++) {
        for (int j = 0; j <= size_row; j++)cout << " ";
        cout << endl;
    }
    setCursor(left, top);
    cout << char(201);
    for (int i = 0; i < size_row; i++)cout << char(205);
    cout << char(187);
    int cnt = 0;
    while (cnt < size_col) {
        setCursor(left, top + cnt + 1);
        cout << char(186);
        setCursor(left + size_row + 1, top + cnt + 1);
        cout << char(186);
        cnt++;
    }
    setCursor(left, top + size_col + 1);
    cout << char(200);
    for (int i = 0; i < size_row; i++)cout << char(205);
    cout << char(188);

}

// ve logo 
void Drawing::logo(int x , int y) {
    setColor(7, 0);
    setCursor(x, y);
    cout << "     __________" << endl;
    setCursor(x, y + 1);
    cout << "     \\_   ___  \\______ _______  ____ " << endl;
    setCursor(x, y + 2);
    cout << "     /     \\ \\ /\\__   \\\\_  __ \\/  _ \\  " << endl;
    setCursor(x, y + 3);
    cout << "     \\      \\____/ __  \\|  | \\(  <_> )  " << endl;
    setCursor(x, y + 4);
    cout << "      \\_______  (____  /|__|   \\____/  " << endl;
    setCursor(x, y + 5);
    cout << "              \\/     \\/  ";
}

void Drawing::set_player_1(bool boolen, int score_1) {
    setCursor(38*3+3, 5);
    setColor(6, int(boolen)  );
    cout << "Player 1 [x]     ";
    setColor(13, 0);
    cout << "Score : " << score_1 ; 
    //setColor(10, 0);
}

void Drawing::set_player_2(bool boolen, int score_2) {
    setCursor(38*3+3, 25);
    setColor(6, int(boolen) );
    cout << "Player 2 [o]     ";// Score: "<< score;
    setColor(14, 0);
    cout << "Score : " << score_2;
    //setColor(11, 0);
}

void Drawing::col(int x ,int begin, int end , int ascii ) {
    for (int i = begin; i <= end;i++) {
        setCursor(x, i);
        cout << char(ascii);
    }
}

void Drawing::row(int y, int begin, int end , int ascii ) {
    setCursor(begin, y);
    for (int i = begin;  i <= end ; i++)
        cout << char(ascii);
}

void Drawing::winner(int n) {
    setColor(10, 7);
    setCursor(38 * 2 + 4, 17);
    if (n== 1) {
        //setCursor(38 * 3 + 3, 5);
        cout << "PLAYER 1 WINNNN !!!";
    }
    else {
        //setCursor(38 * 3 + 3, 25);
        cout << "PLAYER 2 WINNNN !!!";
    }
}

void Drawing::clear(int x1, int y1, int x2, int y2) {
    setColor(0, 0);
    for (int i = y1; i <= y2; i++) {
        setCursor(x1, i);
        for (int j = x1; j <= x2; j++)cout << " ";
    }
}

void Drawing::brear(int x, int y) {
    /*
    ╭╮╱▔▔▔▔▔╲╭╮
    ╰╱╭▅╮　╭▅╮╲╯ 　　　　
     ▏╰╱▔▇▔╲╯▕ 　
    ╲╲　╲╰┻╯╱　╱╱　
╲　　╲╲　▔▔▔　╱╱　　*/
}

//Drawing drawing;