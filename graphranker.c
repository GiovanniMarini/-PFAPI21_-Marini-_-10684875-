#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITO 20000000
/*GIOVANNI MARINI 10684875 20/08/2021 */

int sommacammini2[20000000],sommacammini[20000000];
char line[20000000];
int main(){
	
	char agrafo[15];
	int numerografi=0,migliorigrafi=0,percorso,nodosuccessivo=0,somma=0,conta=0;
    if (scanf("%d %d",&numerografi, &migliorigrafi)){}
	int i=0,j=0,z=0,a=1,b=1,d,num,s=50,st,posizione,contatoref=1;
	int array[numerografi][numerografi],distanza[numerografi],visitato[numerografi],grafiminori[migliorigrafi];
	char fine;
  	while(1) {
  		
    	if (scanf("%s",agrafo)){}
    	fine=getchar();
    	a=1;
    	b=1;
		if(fine== EOF ){
			break;
		}
    	a=strcmp("AggiungiGrafo",agrafo);
       	b=strcmp("TopK",agrafo);
		if(a==0){
       		for(j=0;j<numerografi;j++){
    			if (fgets(line,sizeof(line),stdin)){}
  			  	z=0;
  			  	num=0;
  			  	d=0;
 				while(line[d] != '\0') {	
			    	if((line[d] >= '0') && (line[d] <= '9') && (line[d] != ',') && (line[d] != '\n')){
    			   		 num = (num*10) + (line[d] - '0');
   
  				  	}  
  					if(line[d] == ',' || line[d] == '\n' ){
  				 	 	if(num==0){
  				 	 		num=INFINITO;
						}
  			  		array[j][z]=num;
					z++;
					num=0;
  			 		}
  			 
    				d++;
  				}
			}
			for(i=1;i<numerografi;i++){
				distanza[i]=array[0][i];
				visitato[i]=0;
			}

			distanza[0]=0;
			visitato[0]=1;	

			
			for(z=1;z<numerografi;z++)
			{
				percorso=INFINITO;
				for(i=0;i<numerografi;i++){
					if(distanza[i]<percorso)
					{
						if(visitato[i]==0){
						percorso=distanza[i];
						nodosuccessivo=i;
						}
					}
				} 
				visitato[nodosuccessivo]=1;
				for(i=0;i<numerografi;i++){
					if(visitato[i]==0){
						if(array[nodosuccessivo][i]+percorso<distanza[i])
						{
							distanza[i]=percorso+array[nodosuccessivo][i];
						}
					}
				}
			}
			for(i=0;i<numerografi;i++){
				if(distanza[i]==INFINITO)
				{
					distanza[i]=0;
				}
				somma=somma+distanza[i];
			}
			if(conta==0){
				s=s*s*s;
			}
			sommacammini[conta]=somma;			
			conta++;
			somma=0;
				
		}
       	if(b==0){
       		 if(conta>migliorigrafi){
       		 	if(migliorigrafi>s){
       		 		contatoref=1;
       		 		z=0;
       		 		while(z<conta-2){
						if(sommacammini[z]<sommacammini[z+1]){
							contatoref=0;
						}
						z++;
					}
					if(contatoref==1){
 	      		 		int s=conta-1;
    	   		 		for(i=0;i<migliorigrafi;i++){
							if(i==0){
								printf("%d",s);	
							}
							else{
								s--;
								printf(" %d",s);
							}
						}
					}
				}
				else{
				
       		 	for(i = 0; i <conta; i++){
       		 		sommacammini2[i]=sommacammini[i];
					}
				for(i = 0; i <migliorigrafi; i++)
				{
					posizione=0;
					st=INFINITO;
					for(j = 0; j <conta; j++)
					{
						if(sommacammini2[j]<st){
							st=sommacammini2[j];
							posizione=j;	
						}
					}
					sommacammini2[posizione]=INFINITO;				
					grafiminori[i]=posizione;
					if(i==0){
						printf("%d",grafiminori[i]);	
					}
					else{
						printf(" %d",grafiminori[i]);
   					}
				}}
			}
			else if(conta<=migliorigrafi){
				for(i=0;i<conta;i++){
					if(i==0){
						printf("%d",i);	
					}
					else{
						printf(" %d",i);
					}
				}
			}	
			printf("\n");
		
			
		}
		
	}

	return(0);
	}



