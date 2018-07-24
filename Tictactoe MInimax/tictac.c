#include<stdio.h>
#include<stdlib.h> 
int movesleft(char[][3]);
void display(char[][3]);
void bestmove(char[][3]);
int minimax(char[][3],int,int);
int getscore(char[][3]);
int validmove(char[][3],int,int);
char player='X',opponent='O';
int main(){
	int i=0,j=0,score,flag=0;	
	char board [3][3];
	//intialliize board	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board [i][j]=' ';
			}
		}
	display(board);	
	while(movesleft(board)){		
		printf("\nSelect position\n");
		scanf("%d %d",&i,&j);
		if(!validmove(board,i,j))
			continue;	
		board[i][j]=player;
		display(board);	
		printf("\n Player 2 plays");
		bestmove(board);
		printf("\n");
		display(board);
		score=getscore(board);
		if(score==10){
			printf("\nPlayer 1 wins");
			flag=1;			
			break;
			}		
		else if(score==-10){
			printf("\nPlayer 2 wins");
			flag=1;			
			break;
			}		
		}
	if(!flag)
		printf("It is a draw!");
}
int movesleft(char board[][3]){
	int i=0,j=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==' ')
				return 1;
			}
		}
	return 0;
}
void display(char board[][3]){
	 //display board 
	int i,j;
	for(i=0;i<3;i++){
		printf("    |");		
		for(j=0;j<3;j++){
			printf(" %c |",board [i][j]);
			}
		printf("\n");		
		}
}
void bestmove(char board[][3]){
	int bestval=1000,besti=-1,bestj=-1,value,i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(board [i][j]==' '){
				   board[i][j]=opponent;	
			   	value=minimax(board,0,1);
				   board[i][j]=' ';
			   	if(bestval>value){
					bestval=value;
					besti=i;
					bestj=j;
			     		}
				}
			   }
		 }
	board[besti][bestj]=opponent;
}
int minimax(char board[][3],int depth,int ismax){
	int i,j;	
	int score=getscore(board);
	if(score==10)
		return score;
	if(score==-10)
		return score;
	if(!movesleft(board))
		return 0;
	if(ismax){
	  int bestval=-1000;
	   int value;	
	   for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(board [i][j]==' '){
				     board[i][j]=player;
				     value=minimax(board,depth+1,0);
				     if(bestval<value)
					bestval=value;
				     board[i][j]=' '; 	
				     }
				}
			}
	    return bestval;
	  }
       else {
	   int bestval=1000;
	   int value;	
	   for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(board [i][j]==' '){
				     board[i][j]=opponent;
				     value=minimax(board,depth+1,1);
				     if(bestval>value)
					bestval=value;
				      board[i][j]=' ';	
				     }
				}
			}
	    return bestval;
	  }
}		
int getscore(char board[][3]){
	int row=0,col=0;
	for(row=0;row<3;row++){
		if(board[row][0]==board[row][1] && board[row][1]==board[row][2]){
			if(board[row][0]==player)
				return 10;
			else if (board[row][0]==opponent)
				return -10;
			}
		}
	for(col=0;col<3;col++){
		if(board[0][col]==board[1][col] && board[1][col]==board[2][col]){
			if(board[0][col]==player)
				return 10;
			else if (board[0][col]==opponent)
				return -10;
			}
		}
	if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
           if (board[0][0]==player)
            return 10;
          else if (board[0][0]==opponent)
            return -10;
    	 }
 
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
    	{
         if (board[0][2]==player)
            return 10;
        else if (board[0][2]==opponent)
            return -10;
         }
 
    return 0;
		
}
int validmove(char board[][3],int i,int j){
	if(i<3 && j<3){
		  if(board[i][j]==' ')
			return 1;			  	
		    printf("\nPosition Occupied\n");	
		    }	
	else 
		printf("\nInvalid move!!\n");
	return 0;
}
			
