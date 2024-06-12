#ifndef BUTTONS_H
#define BUTTONS_H
#include <stdio.h>
enum operators{
    plus = 13,
    minus = 14,
    multiply = 15,
    devide = 16,
    eaqual = 17
};
int buttons(int buttonnum,int storage,int *storagenum,int *key)
{
    switch (buttonnum)
    {
    case 0:
        storage *= 10;
        return storage;
        break;
    case 1:
        storage *= 10;
        storage += 1;
        return storage;
        break;
    case 2:
        storage *= 10;
        storage += 2;
        return storage;
        break;
    case 3:
        storage *= 10;
        storage += 3;
        return storage;
        break;
    case 4:
        storage *= 10;
        storage += 4;
        return storage;
        break;
    case 5:
        storage *= 10;
        storage += 5;
        return storage;
        break;
    case 6:
        storage *= 10;
        storage += 6;
        return storage;
        break;
    case 7:
        storage *= 10;
        storage += 7;
        return storage;
        break;
    case 8:
        storage *= 10;
        storage += 8;
        return storage;
        break;
    case 9:
        storage *= 10;
        storage += 9;
        return storage;
        break;
    case 10:
        
        break;
    case 11:

        break;
    case 12:

        break;
    case 13:
        printf("Button +\n");
        key = plus;
        *storagenum += 1;
        break;
    case 14:
        *key = minus;
        *storagenum += 1;
        break;
    case 15:
        *key = multiply;
        *storagenum += 1;
        break;
    case 16:
        *key = devide;
        *storagenum += 1;
        break;
    default:
        break;
    }
}
#endif