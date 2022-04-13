// TripleXGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
 
#include <iostream>
#include <ctime>
void CheckArray();
void PlayGameAtDifficulty(int& difficulty);
int main()//main functions are what the computer looks for when starting
{

	int difficulty = 2;
	int maxDifficulty = 10;
	while (difficulty <= maxDifficulty)
	{
		PlayGameAtDifficulty(difficulty);
		std::cin.clear();
		std::cin.ignore();
		difficulty++;
	}
	std::cout << "Wow You are a great hacker!!\n";

	
	return 0;
}
void PlayGameAtDifficulty(int& difficulty)
{
	int product;
	int addition;
	int PlayerGuess[3];
	bool MoveToNexLevel = false;
	char PlayerFinalX = NULL;
	int a = rand() % difficulty + difficulty;
	int b = rand() % difficulty + difficulty;
	int c = rand() % difficulty + difficulty;
	while (MoveToNexLevel == false)
	{
		CheckArray();
		std::cout << "You are a secret agent breaking into a LEVEL " << difficulty << " server room\n ";
		std::cout << "Your SuperHacker 2000 tells you the following information...\n";
		addition = a + b + c;
		product = a * b * c;
		std::cout << "+There are three numbers in the code\n";
		std::cout << "+The Code Multiplyes to: " << product << "\n";
		std::cout << "+The Code Adds to: " << addition << "\n" << a << b << c;
		std::cout << "Please Enter the Code:\n";
		std::cin >> PlayerGuess[0];
		std::cin >> PlayerGuess[1];
		std::cin >> PlayerGuess[2];
		//std::cin >> PlayerFinalX;
		if (PlayerGuess[0] != a || PlayerGuess[1] != b || PlayerGuess[2] != c)
		{
			std::cout << "you Died Horribly\n";
			MoveToNexLevel = false;
		}
		else
		{

			std::cout << "You broke The code!! On to the next level\n";
			MoveToNexLevel = true;

		}
	}
}
void CheckArray()
{
	int Nums[] = { 5, 5, 5 };
	int Nums2[] = { 5, 5, 5 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (Nums[i] > Nums[j])
			{
				int temp = Nums[j];
				Nums[j] = Nums[i];
				Nums[i] = temp;
			}
			if (Nums2[i] > Nums2[j])
			{
				int temp = Nums2[j];
				Nums2[j] = Nums2[i];
				Nums2[i] = temp;
			}
		}
	}
	bool correctNumbers = true;
	for (int i = 0; i < 3; i++)
	{
		if (Nums[i] != Nums2[i])
		{
			correctNumbers = false;
			break;
		}
	}
	std::cout << std::boolalpha << correctNumbers << std::endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
