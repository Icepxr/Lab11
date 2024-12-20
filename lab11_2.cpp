#include<iostream>
#include<string>
#include<ctime>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	return  1+rand()%13;
	//Write the function to random the number from 1 to 13 and return that random number.
	//srand() is used in main(). Do not use srand() here.
}

int calScore(int x,int y,int z){
	if(x>10) x=10;
	if(y>10) y=10;
	if(z>10) z=10;
	return (x+y+z)%10;
	//Write the function to calculate the score with is the rightmost digit of summation of the scores from three cards.
	//Return the score. 
}

int findYugiAction(int s){	
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{
		// If current score is 6,7,8, Yugi will draw with probability 69% and will stay with probability 31% 
		// Write conditions here using random number 
		if (rand()%100<69){
			return 1;
		}else{
			return 2;
		}
	}
}

void checkWinner(int p, int y){
	// Write condition for cout in this function
	cout << "\n---------------------------------\n";
	if(p == y) cout <<   "|             Draw!!!           |";
	else if(p > y) cout <<   "|         Player wins!!!        |";
	else if(p < y) cout <<   "|          Yugi wins!!!         |";
	cout << "\n---------------------------------\n";
}


int main(){	
    // srand(________________); //This line of code is not completed. Fill the correct input of srand(); 
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0}; //This line of code is not completed. You need to initialize value of yugiCards[].
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction !=1&&playerAction!=2);  
	if(playerAction == 1){
		//The following lines of code are not completed. Please correct it.
		playerCards[2] = drawCard();
  		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] <<endl;
		cout << "Your new score: " << playerScore <<endl;

		cout << "------------ Turn end -------------------\n\n";
		
		cout << "---------YUGI'S TURN, DRAW!!!------------\n";
		cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] <<endl;
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		yugiAction = findYugiAction(yugiScore);
		cout << "Yugi's score: " << yugiScore << "\n";

	}
	
	if(playerAction ==2 ){
		cout << "------------ Turn end -------------------\n\n";

		cout << "---------YUGI'S TURN, DRAW!!!------------\n";
		cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] <<endl;
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		
		yugiAction = findYugiAction(yugiScore);
		cout << "Yugi's score: " << yugiScore << "\n";
	}
	
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] <<endl;
		cout << "Yugi's new score: " << yugiScore<<endl;
	}
	cout << "------------ Turn end -------------------\n";
	
	

	
	checkWinner(playerScore,yugiScore);
}
