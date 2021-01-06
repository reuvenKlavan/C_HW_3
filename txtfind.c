#include<stdio.h>
#include<string.h>
#define BUFFER_SIZE 1024
#define LINE 256
#define WORD 30
#define TRUE 1
#define FALSE 0 

char buff[BUFFER_SIZE];
int inde = 0;

int get_line(char s[]){
	int getchar = 0;
	
	while(buff[getchar]!='\n' && getchar<LINE){		
		s[getchar] = buff[getchar]; 
		getchar = getchar+1;	
	}
	return getchar;
}

int get_word(char w[]){
	int getchar = 0;	

	while(buff[getchar+inde]!='\n' && buff[getchar+inde]!='\t' && buff[getchar+inde]!=' ' && getchar<WORD){
		w[getchar] = buff[getchar+inde]; 
		getchar = getchar+1;	
	}

	if(buff[getchar+inde]=='\n'){
		inde = 0;
	}

	else if(buff[getchar+inde]==' ' || buff[getchar+inde]=='\t'){
		inde = inde+getchar+1;
	}	

	return getchar;
}

int subString(char* str1, char* str2){
	int lengthStr1 = strlen(str1);
	int lengthStr2 = strlen(str2);	
	int substr=FALSE;	
	int startToCheck=FALSE;	


	for(int i=0; i<lengthStr1-lengthStr2+1 && !substr;i++){
		if(str1[i]==str2[0]){
			startToCheck=TRUE;
		}
		
		for(int j=0; j<lengthStr2 && !substr && startToCheck;j++){
			
			if(str1[i+j]!=str2[j]){
				startToCheck=FALSE;
			}

			else if(str1[i+j]==str2[j] && j == lengthStr2-1){//probably I would have error here because the length
				substr = TRUE;
			}
			
		}
	}

	return substr;
}

int similar(char* s, char* t, int n){
	int canConvert = TRUE;
	int lengthStr1 = strlen(s);
	int lengthStr2 = strlen(t);
	
	if(lengthStr1-lengthStr2>n){
		canConvert = FALSE; 
	}

	else if(lengthStr1<lengthStr2){
		canConvert = FALSE; 
	}

	else{
		int diffrences = 0;
		for(int i = 0, j = 0; diffrences <= n && i<lengthStr1 && canConvert; i++){
			if(t[j]==s[i]){
				j++;
			}
			
			else{
				diffrences++;
				if(diffrences>n){
					canConvert=FALSE;
				}
			}
		}
	}

	return canConvert;
}

void print_lines(char* str){
	while(fgets(buff, sizeof(buff), stdin)!=NULL){
		char line[LINE];
		get_line(line);
		int check = subString(line, str);		
		if(check==1){
			printf("%s\n",line);
		}
		memset(line,'\0',256);
	}
}

void print_similar_words(char* str){
	char line[LINE], word[WORD];
	while(fgets(buff, sizeof(buff), stdin)!=NULL){	
		int lengthLine = get_line(line);
		for(int i=0; i<lengthLine;i++){
			
			if(i==0){
				get_word(word);
				int check = similar(word,str,1);
				if(check==1){
					printf("%s\n",word);
				}
			}

			else if(line[i]==' '){
				get_word(word);
				int check = similar(word,str,1);			
				if(check==1){
					printf("%s\n",word);
				}
			}
			memset(word,'\0',30);
		
		}

		memset(line,'\0',256);	
	}
}




int main(){	

	fgets(buff, sizeof(buff), stdin);	
	
	char lookingFor[WORD];
	memset(lookingFor,'\0',30);

	char option[2];

	get_word(lookingFor);
	get_word(option);
	//printf("%s\n",lookingFor);
	//printf("%s\n",option);
	fgets(buff, sizeof(buff), stdin);
	if(option[0]=='a'){
		print_lines(lookingFor);	
	}

	else if(option[0]=='b'){
		print_similar_words(lookingFor);
	}

	return 0;
}
