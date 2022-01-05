//                                Navid Mafi
//                          Reversi Game (Othello)
//            Using only iostream and windows.h (just for sleep function)
//   TESTED ONLY ON WINDOWS x86 WITH GNU GCC g++ (Rev6, Built by MSYS2 project) 11.2.0
//


#include <iostream>
#include <windows.h>

using namespace std;

char takhteMatrice[8][8];
int whiteScore, blackScore;
char w = 'w', b = 'b';
char loc[2], x, y;

int convertToX(char posX)
{
    if (posX == 'A' || posX == 'a')
        x = 0;
    else if (posX == 'B' || posX == 'b')
        x = 1;
    else if (posX == 'C' || posX == 'c')
        x = 2;
    else if (posX == 'D' || posX == 'd')
        x = 3;
    else if (posX == 'E' || posX == 'e')
        x = 4;
    else if (posX == 'F' || posX == 'f')
        x = 5;
    else if (posX == 'G' || posX == 'g')
        x = 6;
    else if (posX == 'H' || posX == 'h')
        x = 7;
    else
    {
        // Yaani vorodi Na motabar boode 
        return 1;
    }

    return 0;
}

int convertToY(char posY)
{
    if (loc[1] == '1')
        y = 0;
    else if (loc[1] == '2')
        y = 1;
    else if (loc[1] == '3')
        y = 2;
    else if (loc[1] == '4')
        y = 3;
    else if (loc[1] == '5')
        y = 4;
    else if (loc[1] == '6')
        y = 5;
    else if (loc[1] == '7')
        y = 6;
    else if (loc[1] == '8')
        y = 7;
    else
    {
        // Yaani vorodi Na motabar boode 
        return 1;
    }

    return 0;
}

int posCheck(char y, char x, char player, char opponent)
{
    int i, j, r;
    // Left Check
        for (j = x - 1; j >= 0; j--)
        {
            if (takhteMatrice[y][j] == opponent)
                continue;
            else
                break;
        }
        if (takhteMatrice[y][j] == player && takhteMatrice[y][x - 1] == opponent)
        {
                return 0;
        }

    // Right Check
        for (j = x + 1; j < 8; j++)
        {
            if (takhteMatrice[y][j] == opponent)
                continue;
            else
                break;
        }
        if (takhteMatrice[y][j] == player && takhteMatrice[y][x + 1] == opponent)
        {
            return 0;
        }

    // Up Check
        for (i = y - 1; i >= 0; i--)
        {
            if (takhteMatrice[i][x] == opponent)
                continue;
            else
                break;
        }
        if (takhteMatrice[i][x] == player && takhteMatrice[y - 1][x] == opponent)
        {
            return 0;
        }

    // Down Check
        for (i = y + 1; i < 8; i++)
        {
            if (takhteMatrice[i][x] == opponent)
                continue;
            else
                break;
        }

        if (takhteMatrice[i][x] == player && takhteMatrice[y + 1][x] == opponent)
            return 0;

    // UL Diagonal Check
        i = y - 1;
        j = x - 1;
        while (i >= 0 && j >= 0)
        {
            if (takhteMatrice[i][j] == opponent){
                i--;
                j--;
                continue;
            }
            else
                break;
            i--;
            j--;
        }
        if (takhteMatrice[i][j] == player && takhteMatrice[y - 1][x - 1] == opponent)
        {
            return 0;
        }

    // UR Diagonal Check
        i = y - 1;
        j = x + 1;
        while (i >= 0 && j < 8)
        {
            if (takhteMatrice[i][j] == opponent){
                i--;
                j++;
                continue;
            }
            else
                break;
            i--;
            j++;
        }
        if (takhteMatrice[i][j] == player && takhteMatrice[y - 1][x + 1] == opponent)
        {
            return 0;
        }

    // DL Diagonal Check
        i = y + 2;
        j = x - 2;
        while (i < 8 && j >= 0)
        {
            if (takhteMatrice[i][j] == opponent){
                i++;
                j--;
                continue;
            }
            else
                break;
            i++;
            j--;
        }
        if (takhteMatrice[i][j] == player && takhteMatrice[y + 1][x - 1] == opponent)
        {
            return 0;
        }

    // DR Diagonal Check
        i = y + 1;
        j = x + 1;
        while (i < 8 && j < 8)
        {
            if (takhteMatrice[i][j] == opponent){
                i++;
                j++;
                continue;
            }
            else
                break;
            i++;
            j++;
        }
        if (takhteMatrice[i][j] == player && takhteMatrice[y + 1][x + 1] == opponent)
        {
            return 0;
        }

    return 1;
}

void onMoveEvent(char player, char opponent)
{

    int i, j;
    // Left Check
    for (j = x - 1; j >= 0; j--)
    {
        if (takhteMatrice[y][j] == opponent)
            takhteMatrice[y][j] = player;
        else
            break;
    }
    if (takhteMatrice[y][j] != player)
    {
        for (j = x - 1; j >= 0; j--)
        {
            if (takhteMatrice[y][j] == player)
                takhteMatrice[y][j] = opponent;
            else
                break;
        }
    }
    // Right Check
    for (j = x + 1; j < 8; j++)
    {
        if (takhteMatrice[y][j] == opponent)
            takhteMatrice[y][j] = player;
        else
            break;
    }
    if (takhteMatrice[y][j] != player)
    {
        for (j = x + 1; j < 8; j++)
        {
            if (takhteMatrice[y][j] == player)
                takhteMatrice[y][j] = opponent;
            else
                break;
        }
    }
    // Up Check
    for (i = y - 1; i >= 0; i--)
    {
        if (takhteMatrice[i][x] == opponent)
            takhteMatrice[i][x] = player;
        else
            break;
    }
    if (takhteMatrice[i][x] != player)
    {
        for (i = y - 1; i >= 0; i--)
        {
            if (takhteMatrice[i][x] == player)
                takhteMatrice[i][x] = opponent;
            else
                break;
        }
    }
    // Down Check
    for (i = y + 1; i < 8; i++)
    {
        if (takhteMatrice[i][x] == opponent)
            takhteMatrice[i][x] = player;
        else
            break;
    }
    if (takhteMatrice[i][x] != player)
    {
        for (i = y + 1; i < 8; i++)
        {
            if (takhteMatrice[i][x] == player)
                takhteMatrice[i][x] = opponent;
            else
                break;
        }
    }
    // UL Diagonal Check
    i = y - 1;
    j = x - 1;
    while (i >= 0 && j >= 0)
    {
        if (takhteMatrice[i][j] == opponent)
            takhteMatrice[i][j] = player;
        else
            break;
        i--;
        j--;
    }
    if (takhteMatrice[i][j] != player)
    {
        i = y - 1;
        j = x - 1;
        while (i >= 0 && j >= 0)
        {
            if (takhteMatrice[i][j] == player)
                takhteMatrice[i][j] = opponent;
            else
                break;
            i--;
            j--;
        }
    }
    // UR Diagonal Check
    i = y - 1;
    j = x + 1;
    while (i >= 0 && j < 8)
    {
        if (takhteMatrice[i][j] == opponent)
            takhteMatrice[i][j] = player;
        else
            break;
        i--;
        j++;
    }
    if (takhteMatrice[i][j] != player)
    {
        i = y - 1;
        j = x + 1;
        while (i >= 0 && j < 8)
        {
            if (takhteMatrice[i][j] == player)
                takhteMatrice[i][j] = opponent;
            else
                break;
            i--;
            j++;
        }
    }
    // DL Diagonal Check
    i = y + 1;
    j = x - 1;
    while (i < 8 && j >= 0)
    {
        if (takhteMatrice[i][j] == opponent)
            takhteMatrice[i][j] = player;
        else
            break;
        i++;
        j--;
    }
    if (takhteMatrice[i][j] != player)
    {
        i = y + 1;
        j = x - 1;
        while (i < 8 && j >= 0)
        {
            if (takhteMatrice[i][j] == player)
                takhteMatrice[i][j] = opponent;
            else
                break;
            i++;
            j--;
        }
    }
    // DR Diagonal Check
    i = y + 1;
    j = x + 1;
    while (i < 8 && j < 8)
    {
        if (takhteMatrice[i][j] == opponent)
            takhteMatrice[i][j] = player;
        else
            break;
        i++;
        j++;
    }
    if (takhteMatrice[i][j] != player)
    {
        i = y + 1;
        j = x + 1;
        while (i < 8 && j < 8)
        {
            if (takhteMatrice[i][j] == player)
                takhteMatrice[i][j] = opponent;
            else
                break;
            i++;
            j++;
        }
    }
}

void initBoard()
{
    int i, j;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            takhteMatrice[i][j] = '.';
    }

    takhteMatrice[3][3] = w;
    takhteMatrice[3][4] = b;
    takhteMatrice[4][3] = b;
    takhteMatrice[4][4] = w;
}

void showScoreState()
{
    int i, j;
    whiteScore = 0, blackScore = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (takhteMatrice[i][j] == w)
                whiteScore++;
            if (takhteMatrice[i][j] == b)
                blackScore++;
        }
    }
}

void display(char board[8][8])
{
    // clear screen to avoid confilcts.
    system("cls");
    showScoreState();

    cout << "    A   B   C   D   E   F   G   H " << "       W : " << whiteScore << "   B : " << blackScore << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i + 1 << "   " << board[i][0] << "   " << board[i][1] << "   " << board[i][2] << "   " << board[i][3] << "   " << board[i][4] << "   " << board[i][5] << "   " << board[i][6] << "   " << board[i][7] << " " << endl;
    }
}



int main()
{
intro:
    initBoard();
    cout << "Be baazi khosh amadid! "<<endl;
    cout << "Baraye Shoroo Enter bezanid. ";
    cin.get();


start:
    display(takhteMatrice);

    cout <<"Nobat : Black (B)" <<endl << "Koja mikhahid beravid? format : CHAR,NUM : ";
    cin >> loc;
    cout<<endl;
    
    if (convertToX(loc[0]) == 1 || convertToY(loc[1]) ==1)
    {
        cout << "Makane vared shode na motabar ast." << endl << "Yek bar digar emtehan konid.";
        Sleep(1000);
        goto start;
    }

    if (takhteMatrice[y][x] != '.')
    {
        cout << "Makan entekhabi shoma por ast" << endl << "Yek bar digar emtehan konid.";
        Sleep(1000);
        goto start;
    }

    if (posCheck(y, x, b, w) == 1)
    {
       cout << "Makan entekhabi shoma hich mohre harif ra mohasere nmikonad." << endl << "Yek bar digar emtehan konid.";
        Sleep(1000);
        goto start;
    }

    takhteMatrice[y][x] = b;
    onMoveEvent(b, w);
    Sleep(500);
    bool Done = true;
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (takhteMatrice[i][j] == '.')
            {
                if (posCheck(i, j, w, b) == 0)
                    Done = false;
            }
        }
    }
    if (Done)
        goto end;

opponent:
    display(takhteMatrice);

    cout << "\n"
         << "Nobat : Sefid (w)"<<endl << "Koja mikhahid beravid? format : CHAR,NUM : ";
    cin >> loc;
    cout << "\n";

    
    if (convertToX(loc[0]) == 1 || convertToY(loc[1]) ==1)
    {
        cout << "Makane vared shode na motabar ast." << endl << "Yek bar digar emtehan konid.";
        Sleep(1000);
        goto opponent;
    }
    
    if (takhteMatrice[y][x] != '.')
    {
        cout << "Makan entekhabi shoma por ast" << endl << "Yek bar digar emtehan konid.";
        Sleep(1000);
        goto opponent;
    }
    
    if (posCheck(y, x, w, b) == 1)
    {
        cout << "Makan entekhabi shoma hich mohre harif ra mohasere nmikonad." << endl << "Yek bar digar emtehan konid.";
        Sleep(1000);
        goto opponent;
    }

    takhteMatrice[y][x] = w;
    onMoveEvent(w, b);
    Sleep(500);
    Done = true;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (takhteMatrice[i][j] == '.')
            {
                if (posCheck(i, j, b, w) == 0)
                    Done = false;
            }
        }
    }
    if (Done)
        goto end;

    goto start;

end:
    system("cls");
    if (whiteScore < blackScore)
        cout << "Bazikon Siah barande shod";

    if (whiteScore > blackScore)
        cout << "Bazikon Sefid barande shod";

    if (whiteScore == blackScore)
        cout << "Tasavi";

    // 7th grade old hack that prevent immediate exit after results
    cin.get();
    cin.get();
    return 0;
}

