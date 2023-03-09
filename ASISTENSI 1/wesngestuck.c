#include <stdio.h>
#include <string.h>

int main(){
    int loop;
    int top = -1;

    scanf("%d", &loop);
    int stack[loop];
    int flag[loop];
    int numbers = 0;
    char command [101];
    for (int i = 0; i < loop; i++)
    {
        int nilai, banyak;
        scanf("%s", banyak);
        if(strcmp(command,"add")==0){
            scanf("%d %d", &nilai, &banyak);
            flag[++top] = banyak;
            stack[top] = nilai;
            numbers += banyak;
            printf("%d\n", numbers);
        }
        else if(strcmp(command, "del")==0){
            scanf("%d", &banyak);
            printf("%d\n", stack[top]);
            flag[top] -= banyak;
            numbers -= banyak;
            while (flag[top] <= 0)
            {
                banyak = -1 * flag[top];
                flag[--top] -= banyak;
            }
        }
        else if(strcmp(command,"adx")==0){
            scanf("%d", &nilai);
            for (int i = 0; i <= top; i++)
            {
                stack[i] += nilai;
            }
        }
        else if(strcmp(command,"dex")==0){
            scanf("%d", &nilai);
            for (int i = 0; i <=top; i++)
            {
                stack[i] -= nilai;
            }
            
        }
        
    }

    return 0;
    
}