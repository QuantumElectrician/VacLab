//
//  main.c
//  Vaki
//
//  Created by Владислав Агафонов on 07.03.17.
//  Copyright © 2017 Владислав Агафонов. All rights reserved.
//
//
//Замена разделительных точек в числе запятыми
//Замена разделителя чисел с <запятая + табуляция> на <табуляция>

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


#define name "B3.txt" //имя исходного файла
#define name1 "B3new+.txt" //имя модифицированной копии файла


int main()
{
    FILE* fileOpen;
    FILE* fileCreate;
    fileOpen = fopen(name, "rt");
    fileCreate = fopen(name1, "w");
    int byte = fgetc(fileOpen);
    int byteComa;
    while (byte != EOF)
    {
       
        if (byte == ',')
        {
            byteComa = fgetc(fileOpen);
            if (byteComa == '\t')
            {
                fputc('\t', fileCreate);
            }
            else
            {
            fputc(',', fileCreate);
            fputc(byteComa, fileCreate);
            }
        }
        else if (byte == '.')
        {
            fputc(',', fileCreate);
        } else
        {
            fputc(byte, fileCreate);
        }
        byte = fgetc(fileOpen);
    }
    fclose(fileCreate);
    fclose(fileOpen);
    return 0;
}
