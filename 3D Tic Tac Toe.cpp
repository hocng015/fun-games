#include <iostream>
#include <string>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
/*
Name: Hoc Nguyen
Lab #10
Date : 03/27/2020
Description: This program is a TicTacToe game but in a 3 X 3 X 3 dimension similar to a rubix cube shape.
file naming : NguyenHoc_lab10.c++
*/
class TicTacToe{
	private:
		int i,j;
	public:
		char Board[3][3];
        int passed;
		char playershape = 'X';
     	char compshape = 'O';
		int move;
		TicTacToe(){//automatically constructed the attributes once an object is created. No input needed
			move = NULL;
			int a = 0;
  		  for (i = 0 ; i <3;i++){
  		      for(j = 0 ; j< 3; j++){
 		          Board[i][j]= '0'+ a;
  		          a++;
       			}
			}
		}
		void design(){
			cout<<endl;
			cout<<Board[0][0]<<"||"<<Board[0][1]<<"||"<<Board[0][2]<<endl;
			cout<<"========"<<endl;
			cout<<Board[1][0]<<"||"<<Board[1][1]<<"||"<<Board[1][2]<<endl;
			cout<<"========"<<endl;
			cout<<Board[2][0]<<"||"<<Board[2][1]<<"||"<<Board[2][2]<<endl;
			cout<<endl;
		}
		void inputs(int turn){
		//turn 1 is the player meaning X. Turn 2 is the computer meaning O.
			if(turn == 1){
				int passed = 0;
				cout<<"Pick a number on board 1!"<<endl;
				cin>>move;
				do{
				switch (move){
					case 0:{
						if(Board[0][0] =='0'){
						Board[0][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 1:{
						if(Board[0][1] =='1'){
						Board[0][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 2:{
						if(Board[0][2] =='2'){
						Board[0][2] = playershape;
						passed = 1;
						}
						break;
					}
					case 3:{
						if(Board[1][0] =='3'){
						Board[1][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 4:{
						if(Board[1][1] =='4'){
						Board[1][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 5:{
						if(Board[1][2] =='5'){
						Board[1][2] = playershape;
						passed = 1;
						}
						break;
					}
					case 6:{
						if(Board[2][0] =='6'){
						Board[2][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 7:{
						if(Board[2][1] =='7'){
						Board[2][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 8:{
						if(Board[2][2] =='8'){
						Board[2][2] = playershape;
						passed = 1;
						}
						break;
					}
					default:{
						cout<<"Sorry invalid number. Try Again."<<endl;
					}						
				}
				}while(passed == 0);
				}
			else{
				do{
				int randmove = rand()%9;
				cout<<"On board 1, the computer choosed "<<randmove<<endl;
				switch (randmove){
					case 0:{
						if(Board[0][0] =='0'){
						Board[0][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 1:{
						if(Board[0][1] =='1'){
						Board[0][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 2:{
						if(Board[0][2] =='2'){
						Board[0][2] = compshape;
						passed = 1;
						}
						break;
					}
					case 3:{
						if(Board[1][0] =='3'){
						Board[1][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 4:{
						if(Board[1][1] =='4'){
						Board[1][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 5:{
						if(Board[1][2] =='5'){
						Board[1][2] = compshape;
						passed = 1;
						}
						break;
					}
					case 6:{
						if(Board[2][0] =='6'){
						Board[2][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 7:{
						if(Board[2][1] =='7'){
						Board[2][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 8:{
						if(Board[2][2] =='8'){
						Board[2][2] = compshape;
						passed = 1;
						}
						break;
					}
					default:{
			    		randmove = rand()%9;	
					}	
				}					
			}while(passed == 0);		
		}		
}
};
//
//
//
class TicTacToe2: public TicTacToe{
	private:
		int move2;
		int i2,j2;
	public:
		char Board2[3][3];
		TicTacToe2(){//automatically constructed the attributes once an object is created. No input needed
			move2 = NULL;
			int a2 = 0;
  		  for (i2 = 0 ; i2 <3;i2++){
  		      for(j2 = 0 ; j2< 3; j2++){
 		          Board2[i2][j2]= '0'+ a2;
  		          a2++;
       			}
			}
		}
		void design2(){
			cout<<endl;
			cout<<Board2[0][0]<<"||"<<Board2[0][1]<<"||"<<Board2[0][2]<<endl;
			cout<<"========"<<endl;
			cout<<Board2[1][0]<<"||"<<Board2[1][1]<<"||"<<Board2[1][2]<<endl;
			cout<<"========"<<endl;
			cout<<Board2[2][0]<<"||"<<Board2[2][1]<<"||"<<Board2[2][2]<<endl;
			cout<<endl;
		}
		void inputs2(int turn2){
			if(turn2 == 1){
				int passed = 0;
				cout<<"Pick a number on board 2!"<<endl;
				cin>>move2;
				do{
				switch (move2){
					case 0:{
						if(Board2[0][0] =='0'){
						Board2[0][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 1:{
						if(Board2[0][1] =='1'){
						Board2[0][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 2:{
						if(Board2[0][2] =='2'){
						Board2[0][2] = playershape;
						passed = 1;
						}
						break;
					}
					case 3:{
						if(Board2[1][0] =='3'){
						Board2[1][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 4:{
						if(Board2[1][1] =='4'){
						Board2[1][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 5:{
						if(Board2[1][2] =='5'){
						Board2[1][2] = playershape;
						passed = 1;
						}
						break;
					}
					case 6:{
						if(Board2[2][0] =='6'){
						Board2[2][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 7:{
						if(Board2[2][1] =='7'){
						Board2[2][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 8:{
						if(Board2[2][2] =='8'){
						Board2[2][2] = playershape;
						passed = 1;
						}
						break;
					}
					default:{
						cout<<"Sorry invalid number. Try Again."<<endl;
					}	
				}					
				}while(passed == 0);
				}		
			else{
				do{
				int randmove = rand()%9;
				cout<<"On Board 2, the computer choosed "<<randmove<<endl;
				switch (randmove){
					case 0:{
						if(Board2[0][0] =='0'){
						Board2[0][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 1:{
						if(Board2[0][1] =='1'){
						Board2[0][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 2:{
						if(Board2[0][2] =='2'){
						Board2[0][2] = compshape;
						passed = 1;
						}
						break;
					}
					case 3:{
						if(Board2[1][0] =='3'){
						Board2[1][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 4:{
						if(Board2[1][1] =='4'){
						Board2[1][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 5:{
						if(Board2[1][2] =='5'){
						Board2[1][2] = compshape;
						passed = 1;
						}
						break;
					}
					case 6:{
						if(Board2[2][0] =='6'){
						Board2[2][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 7:{
						if(Board2[2][1] =='7'){
						Board2[2][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 8:{
						if(Board2[2][2] =='8'){
						Board2[2][2] = compshape;
						passed = 1;
						}
						break;
					}
					default:{
			    		randmove = rand()%9;	
					}	
				}					
			}while(passed == 0);		
		}		
}
};
//
//
//
class TicTacToe3: public TicTacToe2{
	private:
		int move3;
		int i3,j3;
	public:
		char Board3[3][3];
		TicTacToe3(){//automatically constructed the attributes once an object is created. No input needed
			move3 = NULL;
			int a3 = 0;
  		  for (i3 = 0 ; i3 <3;i3++){
  		      for(j3 = 0 ; j3< 3; j3++){
 		          Board3[i3][j3]= '0'+ a3;
  		          a3++;
       			}
			}
		}
		void design3(){
			design();
			design2();
			cout<<endl;
			cout<<Board3[0][0]<<"||"<<Board3[0][1]<<"||"<<Board3[0][2]<<endl;
			cout<<"========"<<endl;
			cout<<Board3[1][0]<<"||"<<Board3[1][1]<<"||"<<Board3[1][2]<<endl;
			cout<<"========"<<endl;
			cout<<Board3[2][0]<<"||"<<Board3[2][1]<<"||"<<Board3[2][2]<<endl;
			cout<<endl;
		}
		void inputs3(int turn3){
			if(turn3 == 1){
				int passed = 0;
				cout<<"Pick a number on board 3!"<<endl;
				cin>>move3;
				do{
				switch (move3){
					case 0:{
						if(Board3[0][0] =='0'){
						Board3[0][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 1:{
						if(Board3[0][1] =='1'){
						Board3[0][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 2:{
						if(Board3[0][2] =='2'){
						Board3[0][2] = playershape;
						passed = 1;
						}
						break;
					}
					case 3:{
						if(Board3[1][0] =='3'){
						Board3[1][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 4:{
						if(Board3[1][1] =='4'){
						Board3[1][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 5:{
						if(Board3[1][2] =='5'){
						Board3[1][2] = playershape;
						passed = 1;
						}
						break;
					}
					case 6:{
						if(Board3[2][0] =='6'){
						Board3[2][0] = playershape;
						passed = 1;
						}
						break;
					}
					case 7:{
						if(Board3[2][1] =='7'){
						Board3[2][1] = playershape;
						passed = 1;
						}
						break;
					}
					case 8:{
						if(Board3[2][2] =='8'){
						Board3[2][2] = playershape;
						passed = 1;
						}
						break;
					}
					default:{
						cout<<"Sorry invalid number. Try Again."<<endl;
					}	
				}					
				}while(passed == 0);
				}		
			else{
				do{
				int randmove = rand()%9;
				cout<<"On Board 3, the computer choosed "<<randmove<<endl;
				switch (randmove){
					case 0:{
						if(Board3[0][0] =='0'){
						Board3[0][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 1:{
						if(Board3[0][1] =='1'){
						Board3[0][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 2:{
						if(Board3[0][2] =='2'){
						Board3[0][2] = compshape;
						passed = 1;
						}
						break;
					}
					case 3:{
						if(Board3[1][0] =='3'){
						Board3[1][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 4:{
						if(Board3[1][1] =='4'){
						Board3[1][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 5:{
						if(Board3[1][2] =='5'){
						Board3[1][2] = compshape;
						passed = 1;
						}
						break;
					}
					case 6:{
						if(Board3[2][0] =='6'){
						Board3[2][0] = compshape;
						passed = 1;
						}
						break;
					}
					case 7:{
						if(Board3[2][1] =='7'){
						Board3[2][1] = compshape;
						passed = 1;
						}
						break;
					}
					case 8:{
						if(Board3[2][2] =='8'){
						Board3[2][2] = compshape;
						passed = 1;
						}
						break;
					}
					default:{
			    		randmove = rand()%9;	
					}	
				}					
			}while(passed == 0);		
		}		
}
};
int main(void){
	int board, x, y, turn;
	bool finish = false;
	int gamestatus = -1;
	srand(time(NULL));
	TicTacToe3 game;
	if(turn == NULL){
		turn = ((rand()%2))+1;
	}
	cout<<"Here is what the board looks like"<<endl;
	game.design3();
	system("pause");
	cout<<"You are going to be X and the Computer will be O."<<endl;
	system("pause");
	do{
		if(turn == 1){
			cout<<"It's your turn! Choose a board!"<<endl;
			cin>>board;
			switch (board){
				case 1:{
					cout<<"You choosed board 1"<<endl;
					game.inputs(turn);
					turn = 2;
					game.design3();
					break;
				}
				case 2:{
					cout<<"You choosed board 2"<<endl;
					game.inputs2(turn);
					turn = 2;
					game.design3();
					break;
				}
				case 3:{
					cout<<"You choosed board 3"<<endl;
					game.inputs3(turn);
					turn = 2;
					game.design3();
					break;
				}
				default:{
					cout<<"Sorry invalid input"<<endl;
				}	
			}
		}
		else if(turn == 2){
			cout<<"It's the computer's turn!"<<endl;
			int randboard = rand()%3+1;
			switch (randboard){
				case 1:{
					cout<<"It choosed board 1"<<endl;
					game.inputs(turn);
					turn = 1;
					game.design3();
					break;
				}
				case 2:{
					cout<<"It choosed board 2"<<endl;
					game.inputs2(turn);
					turn = 1;
					game.design3();
					break;
				}
				case 3:{
					cout<<"It choosed board 3"<<endl;
					game.inputs3(turn);
					turn = 1;
					game.design3();
					break;
				}	
			}	
		}
    for(x=0;x<3;x++){
        for(y=0;y<3;y++)
            //checking on board 1
        if(game.Board[x][0]==game.Board[x][1]&&game.Board[x][2]==game.Board[x][1]){
                finish=true;
               gamestatus= 1;
        }


        else if(game.Board[0][x]==game.Board[1][x]&&game.Board[1][x]==game.Board[2][x]){
                finish=true;
               gamestatus= 1;
        }
        //==========checking on board 2
         else if(game.Board2[x][0]==game.Board2[x][1]&&game.Board2[x][2]==game.Board2[x][1]){
                finish=true;
               gamestatus= 1;
        }


        else if(game.Board2[0][x]==game.Board2[1][x]&&game.Board2[1][x]==game.Board2[2][x]){
                finish=true;
               gamestatus= 1;
    }
    //=============checking on board 3
        else if(game.Board3[x][0]==game.Board3[x][1]&&game.Board3[x][2]==game.Board3[x][1]){
                finish=true;
               gamestatus= 1;
        }


        else if(game.Board[0][x]==game.Board2[1][x]&&game.Board2[1][x]==game.Board3[2][x]){
                finish=true;
               gamestatus= 1;
        }
       else if(game.Board[0][x]==game.Board2[1][x]&&game.Board2[1][x]==game.Board3[2][x]){
            finish =true;
            gamestatus= 1;
       }
        else if(game.Board[2][x]==game.Board2[1][x]&&game.Board2[1][x]==game.Board3[0][x]){
            finish =true;
            gamestatus = 1;
        }
        else if(game.Board[x][0]==game.Board2[x][1]&&game.Board2[x][1]==game.Board3[x][2]){
            finish = true;
            gamestatus=1;
        }
        else if(game.Board[x][2]==game.Board2[x][1]&&game.Board2[x][1]==game.Board3[x][0]){
            finish =true;
            gamestatus=1;
        }

    }
    //continue checking on board 1
        if(game.Board[0][0]==game.Board[1][1]&&game.Board[1][1]==game.Board[2][2]){
                finish=true;
               gamestatus= 1;
        }
            else if(game.Board[0][2]==game.Board[1][1]&&game.Board[1][1]==game.Board[2][0]){
                finish=true;
               gamestatus= 1;
        }
    //continue checking on board 2
        else if(game.Board2[0][0]==game.Board2[1][1]&&game.Board2[1][1]==game.Board2[2][2]){
                finish=true;
               gamestatus= 1;
        }
            else if(game.Board2[0][2]==game.Board2[1][1]&&game.Board2[1][1]==game.Board2[2][0]){
                finish=true;
               gamestatus= 1;
        }
        //continue checking on board 3
            else if(game.Board3[0][0]==game.Board3[1][1]&&game.Board3[1][1]==game.Board3[2][2]){
                finish=true;
               gamestatus= 1;
        }
            else if(game.Board3[0][2]==game.Board3[1][1]&&game.Board3[1][1]==game.Board3[2][0]){
                finish=true;
               gamestatus= 1;}
         //Checking among 3 dimensions================
        else if(game.Board[0][0]==game.Board2[1][1]&&game.Board2[1][1]==game.Board3[2][2]){
            finish=true;
            gamestatus=1;
        }
        else if(game.Board[0][2]==game.Board2[1][1]&&game.Board2[1][1]==game.Board3[2][0]){
            finish=true;
            gamestatus=1;
        }
         else if(game.Board[2][0]==game.Board2[1][1]&&game.Board2[1][1]==game.Board3[0][2]){
            finish=true;
            gamestatus=1;
        }
        else if(game.Board[2][2]==game.Board2[1][1]&&game.Board2[1][1]==game.Board3[0][0]){
                finish =true;
                gamestatus=1;
                }
          //=============Checking vertically =============
        else if(game.Board[0][0] !='0'&&game.Board2[0][0]==game.Board[0][0]&&game.Board2[0][0]==game.Board3[0][0]){
                finish = true;
                gamestatus=1;
       }
         else if(game.Board[0][1] !='1'&&game.Board2[0][1]==game.Board[0][1]&&game.Board2[0][1]==game.Board3[0][1]){
                finish = true;
                gamestatus=1;
       } else if(game.Board[0][2] !='2'&&game.Board2[0][2]==game.Board[0][2]&&game.Board2[0][2]==game.Board3[0][2]){
                finish = true;
                gamestatus=1;
       }
        else if(game.Board[1][0] !='3'&&game.Board2[1][0]==game.Board[1][0]&&game.Board2[1][0]==game.Board3[1][0]){
                finish = true;
                gamestatus=1;
       } else if(game.Board[1][1] !='4'&&game.Board2[1][1]==game.Board[1][1]&&game.Board2[1][1]==game.Board3[1][1]){
                finish = true;
                gamestatus=1;
       } else if(game.Board[1][2] !='5'&&game.Board2[1][2]==game.Board[1][2]&&game.Board2[1][2]==game.Board3[1][2]){
                finish = true;
                gamestatus=1;
       } else if(game.Board[2][0] !='6'&&game.Board2[2][0]==game.Board[2][0]&&game.Board2[2][0]==game.Board3[2][0]){
                finish = true;
                gamestatus=1;
       } else if(game.Board[2][1] !='7'&&game.Board2[2][1]==game.Board[2][1]&&game.Board2[2][1]==game.Board3[2][1]){
                finish = true;
                gamestatus=1;
       }
        else if(game.Board[2][2] !='8'&&game.Board2[2][2]==game.Board[2][2]&&game.Board2[2][2]==game.Board3[2][2]){
                finish = true;
                gamestatus=1;
        }

       //================================
        else if(game.Board[0][0]!='0'&&game.Board[0][1]!='1'&&game.Board[0][2]!='2'&&game.Board[1][0]!='3'&&game.Board[1][1]!='4'&&game.Board[1][2]!='5'&&game.Board[2][0]!='6'&&game.Board[2][1]!='7'&&game.Board[2][2]!='8'&&game.Board2[0][0]!='0'&&game.Board2[0][1]!='1'&&game.Board2[0][2]!='2'&&game.Board2[1][0]!='3'&&game.Board2[1][1]!='4'&&game.Board2[1][2]!='5'&&game.Board2[2][0]!='6'&&game.Board2[2][1]!='7'&&game.Board2[2][2]!='8'&&game.Board3[0][0]!='0'&&game.Board3[0][1]!='1'&&game.Board3[0][2]!='2'&&game.Board3[1][0]!='3'&&game.Board3[1][1]!='4'&&game.Board3[1][2]!='5'&&game.Board3[2][0]!='6'&&game.Board3[2][1]!='7'&&game.Board3[2][2]!='8')
    {
        finish=true;
        gamestatus=0;
    }
    
}while(finish!=true);
    cout<<"Finished\n";
    if(gamestatus==0){
        cout<<"DRAW!! No one win."<<endl;
    }
    if(gamestatus==1){
        cout<<"Player "<<turn<<" won the game"<<endl;
    }
    system("pause");
return 0;	
};

