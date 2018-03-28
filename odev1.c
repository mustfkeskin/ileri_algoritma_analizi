#include <stdio.h>
int main()
{
    int B[8] = {5, 7, 8, 10, 13, 17, 19, 3};
    int bas = 0;
    int bit = 7;
    int orta = (bas + bit) / 2;

    while(bas < bit && bas != orta)
    {
        printf("baslangic %d \n", B[bas]);
        printf("orta %d \n", B[orta]);
        printf("bitis %d  \n", B[bit]);
        printf("bas:%d bit:%d orta:%d \n", bas, bit, orta);
        printf("\n");

        if(B[bas] < B[orta])
        {
            bas = orta;
        }
        else
        {
            bit = orta;
        }
        orta = (bas + bit) / 2;

        printf("baslangic %d \n", B[bas]);
        printf("orta %d \n", B[orta]);
        printf("bitis %d  \n", B[bit]);
        printf("bas:%d bit:%d orta:%d \n", bas, bit, orta);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

    }

    printf("\n");
    printf("min:%d", B[orta + 1]);

   return 0;
}
