/**
 * Baekjoon 1920. 수 찾기
 * Hashing
 * 202134202 강민제
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 139999 // prime number
#define TRUE 1
#define FALSE 0

typedef struct HashTable
{
    int* data;
    int* valid;
} HashTable;

void insert(HashTable* hashTable, int val);

int check(HashTable* hashTable, int val);

int main()
{
    int* data = (int*)malloc(sizeof(int)*SIZE);
    int* valid = (int*)malloc(sizeof(int)*SIZE);
    for(int i=0; i<SIZE; i++)
    {
        valid[i] = FALSE;
        data[i] = 0;
    }
    HashTable hashTable = {data, valid};
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int val;
        scanf("%d", &val);
        insert(&hashTable, val);
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int num;
        scanf("%d", &num);
        printf("%d\n", check(&hashTable, num));
    }
    return 0;
}

int hash(int val)
{
    return abs(val % SIZE);
}

void insert(HashTable* hashTable, int val)
{
    if(check(hashTable, val))
        return;
    int i = hash(val);
    while(hashTable->valid[i] == TRUE)
        i = (i + 1) % SIZE;
    hashTable->data[i] = val;
    hashTable->valid[i] = TRUE;
}

int check(HashTable* hashTable, int val)
{
    int i = hash(val);
    while(hashTable->valid[i] == TRUE)
    {
        if(hashTable->data[i] == val)
            return TRUE;
        else
            i = (i + 1) % SIZE;
    }
    return FALSE;
}