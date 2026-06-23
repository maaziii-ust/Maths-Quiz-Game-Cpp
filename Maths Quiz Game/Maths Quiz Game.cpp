#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Question {
    string text;
    int answer;
    int points;
};

Question generateQuestion(int level) {
    Question q;
    int a, b, op;

    switch (level) {

    case 1: // Level 1
        a = rand() % 20 + 1;
        b = rand() % 20 + 1;
        op = rand() % 2; 
        if (op == 0)
		{
            q.text = to_string(a) + " + " + to_string(b);
            q.answer = a + b;
        }
		else
		{
            q.text = to_string(a) + " - " + to_string(b);
            q.answer = a - b;
        }
        q.points = 5;
        break;

    case 2: // Level 2
        a = rand() % 11 + 2; 
        b = rand() % 11 + 2;
        op = rand() % 2;
        if (op == 0)
		{
            q.text = to_string(a) + " * " + to_string(b);
            q.answer = a * b;
        }
		else
		{
			do
			{
    			a = rand() % 11 + 2; 
    			b = rand() % 11 + 2;
			} while (a % b != 0);

			q.text = to_string(a) + " / " + to_string(b);
			q.answer = a / b;
        }
        q.points = 10;
        break;

    case 3: // Level 3
        a = rand() % 90 + 10; 
        b = rand() % 90 + 10;
        op = rand() % 2;
        
        if (op == 0)
		{
            int x = rand() % 11 + 2;
            q.text = "What is " + to_string(x) + "^2 ?";
            q.answer = x * x;
        }
		else
		{
            q.text = to_string(a) + " + " + to_string(b);
            q.answer = a + b;
        }
        q.points = 15;
        break;

    case 4: // Level 4
        a = rand() % 90 + 10;
        b = rand() % 9 + 2;
        
        op = rand() % 2;

        if (op == 0)
		{
            q.text = to_string(a) + " * " + to_string(b);
            q.answer = a * b;
        }
		else
		{
            int c = rand() % 20 + 1;
            q.text = to_string(a) + " + " + to_string(b) + " * " + to_string(c);
            q.answer = a + (b * c);
        }
        q.points = 20;
        break;

    case 5: // Level 5
        a = rand() % 8 + 2;//2-9  
        b = rand() % 3 + 2; //2-4
        op = rand() % 2;

        if (op == 0)
		{
            q.text = "What is " + to_string(a) + "^" + to_string(b) + " ?";
            
            q.answer = pow(a, b);
        }
		else
		{
			int perfect = (rand() % 15 + 2);
			int number = perfect * perfect;
			
			q.text = "What is sqrt(" + to_string(number) + ") ?";
			q.answer = perfect;
        }
        q.points = 30;
        break;
    }

    return q;
}

int main()
{
    srand(time(0));

    int lives = 4;
    int level = 1;
    int maxLevel = 5;
    int score = 0;

    cout << "====== MATHS QUIZ GAME ======\n";
    cout << "You have 3 lives. Answer correctly to level up!\n\n";

    while (lives > 0 && level <= maxLevel)
	{

        cout << "\n--- LEVEL " << level << " ---\n";

        int questionsPerLevel = 5;
        int correctNeeded = 3;
        int correctCount = 0;

        for (int i = 0; i < questionsPerLevel; i++)
		{

            Question q = generateQuestion(level);

            cout << "\nQ" << i + 1 << ": " << q.text << " = ";
            int userAnswer;
            cin >> userAnswer;

            if (userAnswer == q.answer)
			{
                cout << "Correct! +" << q.points << " points.\n";
                score += q.points;
                correctCount++;
            }
			else
			{
                lives--;
                cout << "\aWrong! Correct answer was: " << q.answer <<endl;
                cout << "Lives left: " << lives <<endl;
                if (lives == 0) break;
            }
        }

        if (lives == 0) break;

        
        if (correctCount >= correctNeeded)
		{
            cout << "\nLevel " << level << " passed!\n";
            level++;
        }
		else
		{
            cout << "\nYou failed this level. Losing one extra life.\n";
            lives--;
            if (lives == 0) break;
        }
    }

    
    cout << "\n====== GAME OVER ======\n";
    cout << "Your final score: " << score <<endl;
    cout << "You Reached level: " << level - (lives > 0 ? 0 : 1) <<endl;
    cout << "Thanks for playing!\n";

    return 0;
}
