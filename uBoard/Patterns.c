/*/////////////////////////////////////////////////////////////////////////
//
//  File Name    : Patterns.c
//  Version      : 1.0
//  Description  : Code for the various patterns
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802 on uBRD
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 09-07-2011
//
//  Get latest updates from www.uBoard.eu
//  Copyright (c) Bloxi 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
/////////////////////////////////////////////////////////////////////////*/
#include    "Delay.h"
#include    "Patterns.h"
#include    "Peripherals.h"
#include    "uBRD.h"

unsigned char ledmode;
int speed =16;

/* Led pixels defines */
unsigned char patt[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01
};

unsigned char testpatt[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

unsigned char allleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};

unsigned char redleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,
};

unsigned char greenleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
};

unsigned char blueleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,
};

unsigned char rgleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01,
};

unsigned char rbleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,
};

unsigned char bgleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
};

unsigned char rgbleds[192] = {
    /*0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    /*48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    /*96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    /*144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
      B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R */
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};


void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void) {
    static unsigned int t = 0;
    static unsigned char g = 1;
    static unsigned char w = 0;
    static unsigned char dimval = 0x01;

    /* interrupt service routine for Timer1 */
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
    TMR1 = 0;
    T1CONbits.TON = 1;
    /* reset Timer 1 interrupt flag */

    /* Select the LED Mode here */
    if (ledmode == 1) {
            Shift(redleds);
    }

    if (ledmode == 2) {
            Shift(greenleds);
    }

    if (ledmode == 3) {
            Shift(blueleds);
    }

    if (ledmode == 4) {
            Shift(rbleds);
    }
    if (ledmode == 5) {
            Shift(rgleds);
    }
    if (ledmode == 6) {
            Shift(bgleds);
    }

    if (ledmode == 7) {
            Shift(rgbleds);
            ledmode=0;
    }



    t++;
    w++;
    /* Increase brightness every 3/8= 0.3 sec. */
    if (w >= speed)
    {
        if (g == 1 ) dimval = 1;
        if (g == 2 ) dimval = 2;
        if (g == 3 ) dimval = 3;
        if (g == 4 ) dimval = 4;
        if (g == 5 ) dimval = 5;
        if (g == 6 ) dimval = 6;
        if (g == 7 ) dimval = 7;
        if (g == 8 ) dimval = 8;
        if (g == 9 ) dimval = 9;
        if (g == 10 ) dimval = 10;
        if (g == 11 ) dimval = 11;
        if (g == 12 ) dimval = 12;
        if (g == 13 ) dimval = 13;
        if (g == 14 ) dimval = 14;
        if (g == 15 ) dimval = 15;
        if (g == 16 ) dimval = 16;

        if (g == 17 ) dimval = 17;
        if (g == 18 ) dimval = 18;
        if (g == 19 ) dimval = 19;
        if (g == 20 ) dimval = 20;
        if (g == 21 ) dimval = 21;
        if (g == 22 ) dimval = 22;
        if (g == 23 ) dimval = 23;
        if (g == 24 ) dimval = 24;
        if (g == 25 ) dimval = 25;
        if (g == 26 ) dimval = 26;
        if (g == 27 ) dimval = 27;
        if (g == 28 ) dimval = 28;
        if (g == 29 ) dimval = 29;
        if (g == 30 ) dimval = 30;
        if (g == 31 ) dimval = 31;
        if (g == 32 ) dimval = 32;


        if (g == 33 ) dimval = 32;
        if (g == 34 ) dimval = 31;
        if (g == 35 ) dimval = 30;
        if (g == 36 ) dimval = 29;
        if (g == 37 ) dimval = 28;
        if (g == 38 ) dimval = 27;
        if (g == 39 ) dimval = 26;
        if (g == 40 ) dimval = 25;
        if (g == 41 ) dimval = 24;
        if (g == 42 ) dimval = 23;
        if (g == 43 ) dimval = 22;
        if (g == 44 ) dimval = 21;
        if (g == 45 ) dimval = 20;
        if (g == 46 ) dimval = 19;
        if (g == 47 ) dimval = 18;
        if (g == 48 ) dimval = 17;


        if (g == 49 ) dimval = 16;
        if (g == 50 ) dimval = 15;
        if (g == 51 ) dimval = 14;
        if (g == 52 ) dimval = 13;
        if (g == 53 ) dimval = 12;
        if (g == 54 ) dimval = 11;
        if (g == 55 ) dimval = 10;
        if (g == 56 ) dimval = 9;
        if (g == 57 ) dimval = 8;
        if (g == 58 ) dimval = 7;
        if (g == 59 ) dimval = 6;
        if (g == 60 ) dimval = 5;
        if (g == 61 ) dimval = 4;
        if (g == 62 ) dimval = 3;
        if (g == 63 ) dimval = 2;
        if (g == 64 ) { dimval = 1; g = 0; }

        g++;
        w = 0;

    }
    /* Every ~3 sec. new pixel values */
    if (t >= 256) {
        Update(patt);
        t = 1;
    }

    if (ledmode == 0)
    {
        Shiftleds(0x0000);
    }
}

void Eraseleds(void) {
    unsigned char g = 0;

    for (g = 0; g < 192; g++) {
        SHIFT_DATA = 0;
        SHIFT_CLOCK = 1;
        Delayus(1);
        SHIFT_CLOCK = 0;
        Delayus(1);
    }
    SHIFT_DATA = 0;
    SHIFT_STROBE = 1;
    Delayus(1);
    SHIFT_STROBE = 0;
    Delayms(1);
}

void Shiftpwm(unsigned char* pixel, unsigned char dimval)
{
    /* Total time of this function has to be 0.02 S */
    switch (dimval)
    {
        case 1:
            /* Leds 50% on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                break;

            case 2:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                break;

        case 3:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 4:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 5:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 6:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 7:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 8:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 9:
            /* Leds 50% on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

            case 10:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 11:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 12:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 13:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 14:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 15:
                /* Leds fully on */
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 16:
                /* Leds fully on */
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;
    }
}

void Shift(unsigned char* pixel) {
    unsigned char i = 0;

    for (i = 0; i < 192; i++) {
        if (pixel[i] & 0x01) SHIFT_DATA = 1;
        else SHIFT_DATA = 0;

        SHIFT_CLOCK = 1;
        Delayus(1);
        SHIFT_CLOCK = 0;
    }
    /* Latch after 192 clock pulses */
    SHIFT_STROBE = 1;
    Delayus(1);
    SHIFT_STROBE = 0;
}

void Mirror(unsigned char* pixel) {
    unsigned char p = 144;
    unsigned char tmpval[192];
    for (p = 144; p < 192; p++) {
        /* Temporarily store pixel value */
        tmpval[p] = pixel[p];
    }

    pixel[144] = tmpval[189]; /* B */
    pixel[145] = tmpval[190]; /* G */
    pixel[146] = tmpval[191]; /* R */

    pixel[147] = tmpval[186];
    pixel[148] = tmpval[187];
    pixel[149] = tmpval[188];

    pixel[150] = tmpval[183];
    pixel[151] = tmpval[184];
    pixel[152] = tmpval[185];

    pixel[153] = tmpval[180];
    pixel[154] = tmpval[181];
    pixel[155] = tmpval[182];

    pixel[156] = tmpval[177];
    pixel[157] = tmpval[178];
    pixel[158] = tmpval[179];

    pixel[159] = tmpval[174];
    pixel[160] = tmpval[175];
    pixel[161] = tmpval[176];

    pixel[162] = tmpval[171];
    pixel[163] = tmpval[172];
    pixel[164] = tmpval[173];

    pixel[165] = tmpval[168];
    pixel[166] = tmpval[169];
    pixel[167] = tmpval[170];

    pixel[168] = tmpval[165];
    pixel[169] = tmpval[166];
    pixel[170] = tmpval[167];

    pixel[171] = tmpval[162];
    pixel[172] = tmpval[163];
    pixel[173] = tmpval[164];

    pixel[174] = tmpval[159];
    pixel[175] = tmpval[160];
    pixel[176] = tmpval[161];

    pixel[177] = tmpval[156];
    pixel[178] = tmpval[157];
    pixel[179] = tmpval[158];

    pixel[180] = tmpval[153];
    pixel[181] = tmpval[154];
    pixel[182] = tmpval[155];

    pixel[183] = tmpval[150];
    pixel[184] = tmpval[151];
    pixel[185] = tmpval[152];

    pixel[186] = tmpval[147];
    pixel[187] = tmpval[148];
    pixel[188] = tmpval[149];

    pixel[189] = tmpval[144];
    pixel[190] = tmpval[145];
    pixel[191] = tmpval[146];
}

void Update(unsigned char* pixel) {
    unsigned char j = 1;
    unsigned char pixeltempr = 0;
    unsigned char pixeltempg = 0;
    unsigned char pixeltempb = 0;
    unsigned char temp[192];

    /* Shift the other 47 leds up */
    for (j = 1; j < 48; j++) {
        pixel[j] = pixel[j - 1];
    }
    j++;

    pixel[95] = pixel[48];
    for (j = 49; j < 96; j++) {
        pixel[j] = pixel[j + 1];
    }
    j++;

    /* Fill a temporary array */
    for (j = 96; j < 144; j++) {
        temp[j] = pixel[j];
    }



    pixeltempr = pixel[141];
    pixeltempg = pixel[142];
    pixeltempb = pixel[143];
    for (j = 99; j < 144; j++) {
        pixel[j] = temp[j - 3];
    }
    /* Store saved pixel in last pixel */
    pixel[96] = pixeltempr;
    pixel[97] = pixeltempg;
    pixel[98] = pixeltempb;


    pixeltempr = pixel[144];
    pixeltempg = pixel[145];
    pixeltempb = pixel[146];
    for (j = 144; j < 189; j++) {
        pixel[j] = pixel[j + 3];
    }
    /* Store saved pixel in last pixel */
    pixel[189] = pixeltempr;
    pixel[190] = pixeltempg;
    pixel[191] = pixeltempb;
}
