#include <stdio.h>
#include <string.h>

int queue[100001];
int back = -1;
int front = -1;
 
void enqueue (int x)
{
    if (front == -1) {
        front++;
    }
    back++;
    queue[back] = x;
}

void dequeue()
{
    if (front <= back) {
        front++;
    }
}

void reverse()
{
    int temp;
    int last = ((back - front) / 2) + 1;
    for (int i = 0; i < last; i++) {
        temp = queue[back - i];
        queue[back - i] = queue[front + i];
        queue[front + i] = temp;
    }
}


int main (){
    int N, nilai, banyak;
    char ket[20];

    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", ket);

        if (strcmp(ket, "add") == 0) 
        {
            scanf("%d %d", &nilai, &banyak);
            for (int i = 0; i < banyak; i++) 
            {
                tambah (nilai);
            }
            printf("%d\n", back + 1 - front);
        }

        else if (strcmp(ket, "del") == 0) 
        {
            scanf("%d", &banyak);
            printf("%d\n", queue[front]);
            for (int i = 0; i < banyak; i++) 
            {
                buang(nilai);
            }
        }

        else if (strcmp(ket, "rev") == 0) 
        {
            rev(nilai);
        }
    
    }
    

}