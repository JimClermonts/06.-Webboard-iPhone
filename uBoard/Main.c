/*/////////////////////////////////////////////////////////////////////////
//  Product/Project : Web board with simple HTML site                    //
///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Main.c
//  Version      : 1.0
//  Description  : Connect the uBoard to the internet with the "Web board"
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 11-11-2011
//
//  Get latest updates from www.uBoard.eu
//  Copyright (c) Bloxi 2012.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
/////////////////////////////////////////////////////////////////////////*/
#include    "Delay.h"
#include    "Peripherals.h"
#include    "Patterns.h"
#include    "Socket.h"
#include    "stdio.h"
#include    "stdlib.h"
#include    "string.h"
#include    "uBRD.h"
#include    "W5100.h"

/* Configuration-for-programmer-------------------------- */
_FBS(RBS_NO_RAM & BSS_NO_FLASH & BWRP_WRPROTECT_OFF)               /* No boot ram, flash, write protection */
_FSS(RSS_NO_RAM & SWRP_WRPROTECT_OFF)                              /* No protected sections */
_FGS(GSS_OFF & GCP_OFF & GWRP_OFF)                                 /* No code protection */
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF)                                  /* FRC Oscillator with PLL, no two-speed oscillator */
_FOSC(FCKSM_CSDCMD & IOL1WAY_OFF & OSCIOFNC_ON  & POSCMD_NONE)     /* Clock Switching and Fail Safe Clock Monitor is disabled */
                                                                   /* Multiple I/O reconfigurations admitted */
                                                                   /* OSC2 Pin is digital I/O */
                                                                   /* Primaire Oscillator Mode: none */
_FWDT(FWDTEN_OFF & WINDIS_OFF)                                     /* Watchdog Timer off */
_FPOR(ALTI2C_ON & FPWRT_PWR64)                                     /* 64 ms power-up timer */
_FICD(JTAGEN_OFF & ICS_PGD2)                                       /* JTAG program port off */
/* ------------------------------------------------------ */

typedef enum _BOOL { FALSE = 0, TRUE } BOOL;    /* Undefined size */

/* Global W5100 defines */
unsigned char mac_addr[6] = {0x00, 0x16, 0x36, 0xDE, 0x58, 0xF6};
unsigned char ip_addr[4] = {192, 168, 1, 130};
unsigned char sub_mask[4] = {255, 255, 255, 0};
unsigned char gtw_addr[4] = {192, 168, 1, 1};

unsigned char startup[60] = "uBoard                                  "
                            "Web board site";
unsigned char sockreg;
unsigned char buf[MAX_BUF];
int tempvalue;
BOOL LedOnOff = FALSE;
extern unsigned char ledmode;
extern int speed;

int main(void) {
    /* Ledstrips inits */
    /* W5100 defines */
    unsigned char sockstat;
    unsigned int rsize;
    char radiostat0[10], radiostat1[10];
    int postidx, getidx;
    /* Initial variable used */
    sockreg = 0;
    tempvalue = 0;
    ledmode = 0;

    Init_timer1();
    Init_timers();
    /*Init_shift();*/
    OSCTUN = 21;
    PLLFBD = 38; /* M=40 */
    CLKDIVbits.PLLPOST = 0; /* N1=2 */
    CLKDIVbits.PLLPRE = 0; /* N2=2 */
   /* Eraseleds();*/
    /* even ledstrips have to be mirrored */
   /* Mirror(patt); */

    /* LCD inits */
    Init_mcp();
    Init_LCD();
    Write_LCD(startup);

    /* W5100 inits */
    Init_pin_SPI();
    Init_SPI();
    W5100_Init(gtw_addr,mac_addr,sub_mask,ip_addr);
    T_SPI_CS;
    SPI_CS = 1;

    Init_UART();

    for (;;) {

        sockstat = SPI_Read(S0_SR);
        switch (sockstat) {
            case SOCK_CLOSED:
                if (socket(sockreg, MR_TCP, TCP_PORT) > 0) {
                    /* Listen to Socket 0 */
                    if (listen(sockreg) <= 0)
                        Delayms(1);
                }
                break;

            case SOCK_ESTABLISHED:
                /* Get the client request size */
                rsize = recv_size();
                if (rsize > 0) {
                    /* Now read the client Request */
                    if (recv(sockreg, buf, rsize) <= 0)
                        break;

                    Putstr(buf);
/*                    printf("%s",buf);*/
                    /* Check the Request Header */
                    getidx = strindex((char *) buf, "GET /");
                    postidx = strindex((char *) buf, "POST /");

                     if (getidx >= 0 || postidx >= 0) {

                        /* Now check the Radio Button for POST request */
                        if (postidx >= 0) {
                            if (strindex((char *) buf, "uBoard new color") > 0)
                                ledmode++;
                        }


            /* Create the HTTP Response	Header */
	    strncpy((char *)buf,("HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n"
                                "<body style=\"background-color:FFFFFF;\">\r\n"),96);

	    strcat((char *)buf,("[\n"
                                 "   {\n"
                                 "       \"id\": \"1\",\n"
                                 "       \"name\": \"uBoard webboard\",\n"
                                 "       \"ipaddr\": \"192.168.0.102\",\n"
                                 "       \"subnetmask\": \"255.255.255.0\",\n"
                                 "       \"gateway\": \"192.168.0.1\",\n"
                                 "       \"adjustSpeedOfPattern\": \"int\",\n"
                                 "       \"turnLedsOnOff\": \"boolean\"\n"
                                 "   }\n"
                                 "]\n"));




            /* Now Send the HTTP Response */
	    if (send(sockreg,buf,strlen((char *)buf)) <= 0) break;

            /* TODO: add status */
            LCD_Clear();
            LCD_PutByte(ledmode);
	    if (ledmode == 1) {
	      strncpy(radiostat0,"",0);
	      strncpy(radiostat1,("checked"),7);
	    } else {
	      strncpy(radiostat0,("checked"),7);
	      strncpy(radiostat1,"",0);
	    }

            /* Create the HTTP Radio Button Response */
	    strncpy((char *)buf,("<p><input type=\"radio\" name=\"radio\" value=\"0\" "),52);
	    strcat((char *)buf,radiostat0);
	    strcat((char *)buf,(">Turn off\r\n"));
	    strcat((char *)buf,("<br><input type=\"radio\" name=\"radio\" value=\"1\" "));
	    strcat((char *)buf,radiostat1);
	    strcat((char *)buf,(">Lounge mode\r\n"));
 	    strcat((char *)buf,("</strong><p>\r\n"));
	    strcat((char *)buf,("<input type=\"submit\">\r\n"));
	    strcat((char *)buf,("</form></span></body></html>\r\n"));            /* Now Send the HTTP Remaining Response */
	    if (send(sockreg,buf,strlen((char *)buf)) <= 0)
                break;


                    } /* Disconnect the socket */
                    disconnect(sockreg);
                } else
                    Delayms(1); /* Wait for request */
                break;

            case SOCK_FIN_WAIT:
            case SOCK_CLOSING:
            case SOCK_TIME_WAIT:
            case SOCK_CLOSE_WAIT:
            case SOCK_LAST_ACK:
                /* Force to close the socket */
                close(sockreg);

                break;
        }
    }
    return 0;
}
