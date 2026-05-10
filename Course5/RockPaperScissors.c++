#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;


enum enChoice {Stone = 1, Paper=2, Scissors = 3};
enum enWinner {Player1 = 1, Computer = 2, Draw = 3};

string WinnerName(enWinner Winner)
{
    string WinnerName[3] = {"Player 1", "Computer 2", "No Winner"};
    return WinnerName[Winner - 1];
}

struct strRoundInfo
{
    short roundNumber;
    enChoice Player1Choice;
    enChoice Computer2Choice; 
    int Player1Points;
    int Computer2Points;
    enWinner winner;
    string WinnerName;
};

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 0; i < NumberOfTabs; i++)
    {
        t = t + "\t";
              // How is that?
    }
    return t;
}

struct strGameResults
{
    short GameRounds;
    short Player1WonTimes;
    short Computer2WonTimes;
    short DrawTimes;
    enWinner Winner;
    string WinnerName;
};

ShowOverGame()
{
    cout << Tabs(4) << "________________________________________\n\n";   
    cout << Tabs(4) << "       ++ G A M E  O V E R ++\n";
    cout << Tabs(4) << "________________________________________\n\n" << endl;
}

enWinner WhoWonTheRound(strRoundInfo RoundInfo)
{
    if (RoundInfo.Computer2Choice == RoundInfo.Player1Choice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice) // In case player 1 is the winner // Wrong
                                        // But IS It THE BEST DESIGN??
    {
        case enChoice::Paper:
            if (RoundInfo.Computer2Choice == enChoice::Stone)
            {
                return enWinner::Player1;
            }
            break;
        case enChoice::Stone:
            if (RoundInfo.Computer2Choice == enChoice::Scissors)
            {
                return enWinner::Player1;
            }
            break;
        case enChoice::Scissors:
            if (RoundInfo.Computer2Choice == enChoice::Paper)
            {
                return enWinner::Player1;
            }
            break;
    }
    
    return enWinner::Computer;  // If you reach here, then computer is the winner.
}


// SetWinnerScreenColor() funcrion
SetWinnerScreenColor(enWinner winner)
{
    switch (winner)
    {
    case enWinner::Computer:
        system("color 4f");
        break;
    case enWinner::Player1:
        system("color 2f");
        break;
    default:
        system("color 6f");
        break;
    }
}

ShowFinalGameResults(strGameResults GameResults)
{
    cout << Tabs(4) << "Game Rounds: [" << GameResults.GameRounds << "]\n";
    cout << Tabs(4) << "Player1 Won [" << GameResults.Player1WonTimes << "] Times\n";
    cout << Tabs(4) << "Computer2 Won [" << GameResults.Computer2WonTimes << "] Times\n";
    cout << Tabs(4) << "Draw Times: [" << GameResults.DrawTimes << "]\n";
    cout << Tabs(4) << "The winner: " << WinnerName(GameResults.Winner) << endl;
        
    SetWinnerScreenColor(GameResults.Winner);
}

string ChoiceName(enChoice Choice)
{
    string Choices[3] = {"Stone", "Paper", "Scissors"};  // is it wise to repeat the sequence of the elements?
    return Choices[Choice - 1];
}


PrintRoundResult(strRoundInfo RoundInfo)
{
    cout << "________________________________________" << endl;
    cout << "            ROUND RESULTS\n";
    cout << "________________________________________" << endl;
    cout << Tabs(1) << "Player 1 choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << Tabs(1) << "Computer 2 choice: " << ChoiceName(RoundInfo.Computer2Choice) << endl;
    cout << Tabs(1) << "Round winner: " << WinnerName(RoundInfo.winner) << endl;
    cout << RoundInfo.winner << endl;
    cout << "________________________________________" << endl;
}

int RandomNumber(int From, int To)
{
    int N;
    N = rand() % (To - From + 1) + From;
    return N;
}




enChoice PlayerChoice()
{
    short choice;
    choice = ReadNumberInRange(1, 3, "Your Choice(Rock = 1, Paper = 2, Scissors = 3)\n : ");

    return (enChoice) choice;
}



enChoice GameChoice()
{
    enChoice GameChoice;
    GameChoice = enChoice(RandomNumber(1, 3));
    return GameChoice;
}


short HowManyRounds()
{
    return (short) ReadNumberInRange(1, 10, "How many rounds you want to play? (1 to 10)\n");
}



enWinner WhoWonTheGame(strGameResults Game)
{
    if (Game.Player1WonTimes > Game.Computer2WonTimes)
    {
        return enWinner::Player1;
    }
    else if (Game.Computer2WonTimes > Game.Player1WonTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}


// Fill game results function.
strGameResults FillGameResults(short Player1WonTimes, short ComputerWonTimes, short GameRounds, short DrawTimees)
{
    strGameResults Results;
    Results.Player1WonTimes = Player1WonTimes;
    Results.Computer2WonTimes = ComputerWonTimes;
    Results.GameRounds = GameRounds;
    Results.DrawTimes = DrawTimees;
    Results.Winner = WhoWonTheGame(Results);
    Results.WinnerName = WinnerName(Results.Winner);

    return Results;
}


ResetScreen()
{
    system("color 0f");
    system("cls");
}

strGameResults PlayGame()
{
    strRoundInfo RoundInfo;
    short playerWinTimes = 0;
    short CWins = 0;
    short DrawTimes = 0;

    short Rounds = HowManyRounds();
    for (int i = 0; i < Rounds; i++)
    {
        cout << "_______________ Round [" << i + 1 << "] bagins _______________\n";
        RoundInfo.roundNumber = i + 1;
        RoundInfo.Player1Choice = PlayerChoice();
        RoundInfo.Computer2Choice = GameChoice();
        RoundInfo.winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.winner);
        PrintRoundResult(RoundInfo);
        SetWinnerScreenColor(RoundInfo.winner);

        
        // Increase player or device points
        if (RoundInfo.winner == enWinner::Player1)
            playerWinTimes++;
        else if (RoundInfo.winner == enWinner::Computer)
            CWins++;
        else
            DrawTimes++;
        
    }
    
    return FillGameResults(playerWinTimes, CWins, Rounds, DrawTimes);
}


StartGame()
{
    char PlayAgain = 'Y';
   do
    {

        ResetScreen();
        strGameResults Results = PlayGame();
        ShowOverGame();
        ShowFinalGameResults(Results);

        cout << "Do you want to play again (Y, N)?"; cin >> PlayAgain;
    }
    while (PlayAgain == 'y' || PlayAgain == 'Y');
    

}

int main(void)
{

    srand((unsigned) time(NULL));

    StartGame();

    ResetScreen();
    return 0;    
}