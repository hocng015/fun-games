#include<iostream>
#include <cstdlib>
#include<string>
#include <ctime>
//a friend class/function is allow to use private variables or attributes from another class in its own class/function.
using namespace std;
//Class definition for a deck of cards and how its used;
namespace poker_needs{
class Deck{
	private:
		friend int dealer();
		friend class player;
/*		int** deck ;
    	char** suit;
*/
		int deck[4][9];
		char suit[4][9];
//		int cards_taken;//this int keeps track of how many cards have to taken to imply how many cards in the deck are left. (each number represent a index of the deck array)
	public:
    	int deck_digit[4];
	    char suit_suit[4]; 
		Deck();
		void shuffle();
		void deal();
};
class player{
	private:
	friend class Deck;
		int chips;
		int times_played;
		int wins;
		int loss;
	public:
		player(){
			chips = 100;
			times_played = 0;
			wins = 0;
		}
		void setchips(int achips){
			chips = achips;
		}
		int getchips(){
			return chips;
		}
		void settimes_played(int atimes){
			times_played = atimes;
		}
		int gettimes_played(){
			return times_played;
		}
		void setwins(int awins){
			wins = awins;
		}
		int getwins(){
			return wins;
		}
		void setloss(int aloss){
			loss = aloss;
		}
		int getloss(){
			return loss;
		}
};
Deck::Deck(){
	//setting up the deck (was intended for a dynamic array that could allow deallocation but not needed anymore)
/*	deck = new int*[4];
		for(int i = 0; i < 4; i++){
			deck[i] = new int[9];
		}
for(int i = 0; i < 4; i++){
	for(int j = 0; j < 9; j++){
		deck[i][j] = 0;
	}
}
*/
for(int i = 0; i < 4; i++){
	for(int j = 0; j < 9; j++ ){
		deck[i][j] = 0;
	}
}
//dont shuffle the suit cause it will result in another card in the deck to have the same identity (intended for dynamic array)
/*	suit = new char*[4];
		for(int i = 0; i < 4; i++){
			suit[i] = new char[9];
		}
for(int i = 0; i < 9; i++){
	suit[0][i] = 'C';
	suit[1][i] = 'S';
	suit[2][i] = 'H';
	suit[3][i] = 'D';
}
*/
for(int i = 0; i < 9; i++){
	suit[0][i] = 'C';
	suit[1][i] = 'S';
	suit[2][i] = 'H';
	suit[3][i] = 'D';
}
};
void Deck::shuffle(){
//int four1s, four2s, four3s, four4s, four5s, four6s, four7s, four8s, four9s;
//designate the values of each card through shuffling

int row; // represents suit value of card
int column; // represents face value of card

   // a list of for loops to randomly assign the values from 1-9 in the deck array
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 1;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 2;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 3;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 4;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 5;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 6;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 7;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 8;
  	}
   for (int card = 0; card < 4; card++){
    do{// choose a new random location until unoccupied slot is found
         row = rand() % 4; // randomly select i (0 to 3)
         column = rand() % 9; // randomly select j (0 to 8)
      }while(deck[row][column] != 0 ); // end do...while
      deck[row][column] = 9;
  	}
//	bool pass; 
      // checks to see that a number is not repeating with the same suit(row in this case)
/*      for(int i = 0; i < 9; i++){
      do{
      	int num = rand()%9+1;
      		if(deck[row][i] = num){
    		pass = true;
      		}
      	
      		else{
      		pass = false;
      		deck[row][column] = num;
      		}
      }while(pass);
      if(pass == false){
      	continue;
      }
      }
   }
*/
};
int dealer(Deck &obj){
bool gotpair = false, gotthree = false;
//this checks for a Pair - 2 of a kind
for(int i  = 0; i < 4; i++){
	int j = i + 1;
	for(j; j < 4; j++){
		if(obj.deck_digit[i] == obj.deck_digit[j]){
			gotpair = true;		
			continue;
		}
	}
}
//this checks for a 3 of a kind
for(int i = 0; i < 2; i++){
	for(int j = i + 1; j < 4; j++){
		if(obj.deck_digit[i] == obj.deck_digit[j]){
			for(int k = j +1; k < 4; k++){
				if(obj.deck_digit[j] == obj.deck_digit[k]){
					gotthree = true;
				}
			}		
	    }
	}
}
//list of if statements to check for winnings 
//example for an if statement:	return setchips(***);
if(((obj.suit_suit[0] == obj.suit_suit[1]) && (obj.suit_suit[2] == obj.suit_suit[3]) && (obj.suit_suit[1] == obj.suit_suit[2])) && (((obj.deck_digit[1]) == (obj.deck_digit[0] + 1)) && ((obj.deck_digit[2]) == (obj.deck_digit[1] + 1)) && ((obj.deck_digit[3]) == (obj.deck_digit[2] + 1)))){
	cout<<"Congrats you got a Straight Flush! Awarded $300!"<<endl;
	return 300;
}
else if((obj.deck_digit[0] == obj.deck_digit[1]) && (obj.deck_digit[2] == obj.deck_digit[3]) && (obj.deck_digit[1] == obj.deck_digit[2])){
	cout<<"Congrats you got a 4 of a kind! Awarded $400!"<<endl;
	return 400;
}
else if((obj.deck_digit[1] == (obj.deck_digit[0] + 1)) && (obj.deck_digit[2] == (obj.deck_digit[1] + 1)) && (obj.deck_digit[3] == (obj.deck_digit[2] + 1))){
	cout<<"Congrats you got a Straight! Awarded $200!"<<endl;
	return 200;
} 
else if((obj.suit_suit[0] == obj.suit_suit[1]) && (obj.suit_suit[2] == obj.suit_suit[3]) && (obj.suit_suit[1] == obj.suit_suit[2])){
    cout<<"Congrats you got a Flush! Awarded $250!"<<endl;	
    return 250;
}
else if((obj.deck_digit[0] == obj.deck_digit[1]) || (obj.deck_digit[2] == obj.deck_digit[3]) || (obj.deck_digit[1] == obj.deck_digit[2])){
	cout<<"Congrats you got a Two Pair! Awarded $100!"<<endl;
	return 100;
}
else if(gotthree){
	cout<<"Congrats you got a 3 of a kind! Awarded $150!"<<endl;
	return 150;
}
//this condition is too long so i opt out for a for loop to check(obj.suit_suit[0] == obj.suit_suit[1]) || (obj.suit_suit[0] == obj.suit_suit[2]) || (obj.suit_suit[0] == obj.suit_suit[3]) || (obj.suit_suit[1] == obj.suit_suit[2])
else if(gotpair){
	cout<<"Congrats you got a Pair - 2 of a kind! Awarded $1 per bet!"<<endl;
	return 1; 
}
else{
	return 0;
}
};
void Deck::deal(){
	for(int i = 0; i < 4; i++){
    int rand_digit;
	int rand_suit;
//	do{
//to make sure the same card isn't chosen again
	bool another_card;
	do{
    rand_suit = rand()%4;
    rand_digit = rand()%9;	
	for(int i = 0; i < 4; i++){
		if((deck_digit[i] == rand_digit) && (suit_suit[i] == rand_suit)){
			another_card = true;
			continue;
		}
		else{
			another_card = false;
		}
	}
	}while(another_card);
//	}while((deck[rand_suit][rand_digit] == NULL)||(suit[rand_suit][rand_digit] == NULL));
	cout<<deck[rand_suit][rand_digit]<<suit[rand_suit][rand_digit]/*since this suit array is 36 total to replicate the digit array*/<<endl;;
	deck_digit[i] = deck[rand_digit][rand_digit];
	suit_suit[i] = suit[rand_digit][rand_digit];
/*	for(rand_suit;rand_suit < 4; rand_suit++){                      this part of the code was intended for the condition of if the deck was going to not be shuffled everytime meaning that the card needed to be deallocated appropriately 
		for(rand_digit;rand_digit < 9;rand_digit++){
			deck[rand_suit][rand_digit] = deck[rand_suit + 1][rand_digit + 1];
            suit[rand_suit][rand_digit] = suit[rand_suit + 1][rand_digit + 1];
	        ++cards_taken;
            //removing the elements from right to left as those have ben moved to the previous index resulting in multiple copys of similar digits in the same suit
        	deck[rand_suit][8 - cards_taken];
        	suit[rand_suit][8 - cards_taken];
		}
	}
	}*/
}
//need to restart the deck of cards to get a brand new shuffle of 36 cards again since there is no need to deallocate elements of the array representing cards being taken from the deck
for(int i = 0; i < 4; i++){
	for(int j = 0; j < 9; j++ ){
		deck[i][j] = 0;
	}
}
for(int i = 0; i < 9; i++){
	suit[0][i] = 'C';
	suit[1][i] = 'S';
	suit[2][i] = 'H';
	suit[3][i] = 'D';
}
};
};
int main(void){
using namespace poker_needs;
	int times;
	int betlimit[100], n = 1;
	//setting up an array to limit the amount the player can bet (can't exceed 100 chips)
	for(int i = 0; i < 100;i++){
		betlimit[i] = n;
		++n;
	}
	int wincount;
	int losscount;
	srand(time(NULL));
	cout<<"Welcome to single player Poker game!"<<endl;
	//create an object for the deck
	Deck deck;
	system("pause");
	//create an object for the player and sets the intial amount available for player to bet
	player player1;
	cout<<"Your initial bank roll is $100.00 (100 chips)"<<endl;
	system("pause");
	do{
	char answer;
	int bet, betcheck;
	bool play = true;
	//restricts input
	do{
	cout<<"Play a hand [ y / n ]?"<<endl;
	cin>>answer;
	if((answer == 'y') || (answer == 'n')){
		play = false;
	}
	}while(play);
	//if no then the loop exits and game is done
	if(answer == 'n'){
		continue;
	}
	//if yes the game is executed
	//restricts bet input
	else{
	bool passed = true;
	cout<<"Place your bet [1, 100]:"<<endl;
	do{
	cin>>betcheck;
	for(int j = 0; j < 100;j++){
		if(betlimit[j] == betcheck){
			bet = betcheck;
			passed = false;
			continue;
		}
	}
	if(passed){
		cout<<"Sorry the bet amount is invalid. Please type an amount from 1 - 100"<<endl;
	}
	}while(passed);
	player1.setchips(player1.getchips() - bet);//get the number of chips then take away temporarily the amount that was bet and then set it to the player's current chip amount. It'll be a permanent if c = 0
    cout<<"... Shuffling Deck ..."<<endl;
	deck.shuffle();
	cout<<"Let the cards fall where they may ..."<<endl;
	system("pause");
	deck.deal();
	//checks if the dealer gave back any winnings. doing a function call to the friend function of the deck class called dealer who's task is to check for winnings
	if(0 < dealer(deck)){
		if(dealer(deck) == 1){//if the hand was a Pair - 2 of a kind a int of 1 is returned from the function call
	    	++wincount;
	    	player1.setwins(wincount);
			player1.setchips(2 * bet);
		}
		else{
			++wincount;
			player1.setwins(wincount);
			player1.setchips(dealer(deck) + bet);//giving the player their winning from their hand (c value) and back the amount they had bet
		}
	}
	//if no winnings then the amount bet is lost and the player get notified of a bubkiss hand
	else{
		++losscount;
		player1.setloss(losscount);
		cout<<"Sorry: you got Bubkiss and have lost $"<<bet<<endl;
	}
	//increments the number of hands that have been played
	++times;
	player1.settimes_played(times);
	}
	}while(player1.getchips() > 0);
	//game final stats for player
	cout<<"Thanks for playing ... "<<endl;
	cout<<"You played a total of "<<player1.gettimes_played()<<" hands"<<endl;
	cout<<"Of which, you won "<<player1.getwins()<<" times"<<endl;
	cout<<"And you lost "<<player1.getloss()<<" times"<<endl;
	cout<<"But in the end you won $"<<player1.getchips() - 100<<endl;	
return 0;
};

