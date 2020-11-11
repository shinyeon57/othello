#define N 6
int init_othello(){
	
    extern int gameboard[N][N];
	int	i;
	int	k;

	printf("  0 1 2 3 4 5\n -------------\n");			//number of column
	for(i=0;i<N;i++){									//for blank
		//for first state of game_ ston's position
		if(i==2){										
			for(k=0;k<=N;k++){
					if(k==0)
						printf("%i|", i);				//number of column		
					else if(k==3)
						printf("0|");
					else if(k==4)
						printf("x|");
					else
						printf(" |");				
							
	    	}
	}
		else if(i==3){
			for(k=0;k<=N;k++){
					if(k==0)
						printf("%i|", i);				//number of column		
					else if(k==3)
						printf("x|");
					else if(k==4)
						printf("0|");						
					else
						printf(" |");				
							
	    	}	
		}
		else{
			for(k=0;k<=N;k++){
					if(k==0)
						printf("%i|", i);			//number of  column
					else
						printf(" |");				
							
	    	}	
		}
    printf("\n -------------\n");
    }
    	    
}
