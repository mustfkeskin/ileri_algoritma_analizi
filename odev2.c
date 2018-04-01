/*
 Bir A[N] tamsayı dizisindeki her sayının kaç defa kullanıldıklarının
 hesaplanması için bir hash tablosunda sayılar ve kullanım sıklıkları saklanacaktır.
 Elemanlar hash tablosuna,  hash(x) = x mod m fonksiyonu kullanılarak
 linear probing metodu ile yerleştirilecektir.
 Eğer A dizisindeki sayı hash tablosunda yoksa tabloya yerleştiren,
 varsa sayının kullanım sayısını tabloda 1 arttıran algoritmanın
 akış diagramını çizip C dilinde programını yazınız (25 puan).
*/

#include <stdio.h>

int h(int a, int b);

int main()
{
    int n = 15;
    int m = 21;
    int A[15] = {1, 2,2, 3,3,3, 4,4,4,4, 5,5,5,5,5};
    int hashTable[21][2];
    int search;
    int index;

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < 2; j++){
        hashTable[i][j] = -1;
      }
   }

    int i = 0;
    while (i < n){

        search = A[i];
        index = h(search, 31);

        if(hashTable[index][0] == -1){
            hashTable[index][0] = search;
            hashTable[index][1] = 1;
            printf("bulunamadi yerlestirildi search: %d  index: %d \n", search, index);
        }
        else if(hashTable[index][0] == search){
            hashTable[index][1] += 1;
            printf("bulundu search: %d  index: %d \n", search, index);
        }
        else{
            while(hashTable[index][0] != -1 && hashTable[index][0] != search)
            {
                index++;
            }
            if(hashTable[index][0] != search){
                hashTable[index][0] = search;
                hashTable[index][1] += 1;
            }
            else{
                hashTable[index][0] = search;
                hashTable[index][1] = 1;
            }
        }
        i++;
    }


    for(int i = 0; i < m; i++){
      for(int j = 0; j < 2; j++){
        printf("%d ", hashTable[i][j]);
      }
      printf("\n");
   }
}

int h(int sayi, int m)
{
    int result;
    result = sayi % m;
    return result;
}
