#include <stdio.h> 
#include <stdlib.h>
#include <fnctl.h>
#include <unistd.h> 


/*
장수를 count 하는방법 
절수를 count 하는 방법에대해서 생각해봐야하는데 
인덱스 수와 관리하는 dataStructer에대해서  이차원배열 동적할당해서 
넣어주면 될거같긴한데 

prev_ch를 만들 절수를 더하는건 같은방시으 
매번 realloc을 할필요는 없구나 
단어수를  count하고 그걸기반으로 mallooc을 한담에 
단어수와 일치한다면 그 인덱스를 저장하고 번호를 저장하고 춢력하면되겠네 

숫자가 시작되는부분부터 숫자 or : 이 계속된다면 계속 저장

숫자수를 세게하고 
system call을 맞춰보면 되는거니까 

중복되엇는지를 확인을 할ㄸ ㅐ이차원배열을 쓰고 
1. 단어로 판명을 하고
2. 목록리스트에 이 단어가 있는지를 확인을 하고 
3. 있다면 절도 이 리스트에 넣어줘야한다 .
    이떄 장과 절은 또 다른 배열에 같은 인덱스에다가 넣어주면 되겠지 
    구조체로 만들어서 관리를 한다면 어디에 넣냐
    그 자료구조를 생각해봐야한다 
    이차언 배열 하나 더 만들어서 거기다가 넣어주면 될거같은데 

    서로 개별적인 모듈이 되도록 하는게 중요해보인다 
    
*/

int main(void) {
    FILE *fps;  //파일포인터 -> fscanf에 사용되는 intput용.
 
    int nowParagraphNum = 0;
 
    char cha;
    int wordCount = 0;  //단어 수.
    int charCount = 0;  //문자 수.

    int nowStateInWord = 0;  //단어 안이면 1.
    fps = fopen("testTx.txt", "rt");  //파일오픈.
    if (fps == NULL) {  //예외처리.
        printf("실패 - 종료\n");
        return 1;
    }

 

    printf("일단 파일의 내용을 출력합니다..\n");
    while (feof(fps) == 0) {  //feof == 내용 있다면 0 반환.
        fscanf(fps, "%c", &cha);
        printf("%c", cha);
        
        // index의 수 +하는 방법
        // (cha >= 'A' && ch <= 'z' ) && nowStateInword == 0)
        //    index_count ++; 
        if (cha >= 'A' && cha <= 'z') { //문자가 알파벳이면.
            charCount++;

            if (nowStateInWord == 0) {
                nowStateInWord = 1;
            }
        }
        else {
            if (nowStateInWord == 1) {
                if (cha == '(') {
                    nowStateInWord = 2;
                }
                else if (cha == ' ' || cha == ',' || cha == '.') {
                    nowStateInWord = 0;
                    wordCount++;
                }
            }
            else if (nowStateInWord == 2) {
                if (cha == ')') {
                    wordCount++;
                    nowStateInWord = 0;
                }
            }
        }
        if (cha == '\n') {
            nowParagraphNum++;
        }

        
    }
    fclose(fps);


    nowParagraphNum++;
 
    printf("\n\ncharacter Num : %d,  word Num : %d,  paragraph Num : %d \n\n", charCount, wordCount, nowParagraphNum);

 

    return 0;
}


