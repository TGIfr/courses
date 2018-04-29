#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <progbase.h>
#include <ctype.h>

static const char  inNormal[50] =
{
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '.',
    ',',
    ':',
    ';',
    '(',
    ')',
    '`',
    '\'',
    '"',
    '-',
    '/',
    '?',
    '!',
    ' ' // space
};

static const char * inMorse[] =
{
    "10111",   //A
    "111010101", //B
    "11101011101", //C
    "1110101",  //D
    "1",    //E
    "101011101", //F
    "111011101",  //G
    "1010101", //H
    "101",   //I
    "1011101110111", //J
    "111010111",  //K
    "101110101", //L
    "1110111",   //M
    "11101",   //N
    "11101110111",  //O
    "10111011101", //P
    "1110111010111", //Q
    "1011101",  //R
    "10101",  //S
    "111",    //T
    "1010111",  //U
    "101010111", //V
    "101110111",  //W
    "11101010111", //X
    "1110101110111", //Y
    "11101110101", //Z
    "1110111011101110111", //0
    "10111011101110111", //1
    "101011101110111", //2
    "1010101110111", //3
    "10101010111", //4
    "101010101", //5
    "11101010101", //6
    "1110111010101", //7
    "111011101110101", //8
    "11101110111011101", //9
    "10101010101", // .
    "10111010111010111", //,
    "11101110111010101", //:
    "11101011101011101", //;
    "1110101110111010111", // ( or )
    "1110101110111010111", // ( or )
    "1011101110111011101", // `
    "1011101110111011101", // `
    "101110101011101", // "
    "111010101010111", // -
    "1110101011101", // /
    "101011101110101", // !
    "1110111010101110111", // ?
    "0000" // space
};
char * morse_encode(char * signal, const char * message, int unit_len, int pad_len);
char * morse_decode(char * message, const char * signal);
int main()
{
    //! Some information about functions
    //! Please, dont enter too long signal and too big unit_len (or you can make arrays bigger)
    //! decode function is not able to fully check the signal. In case of wrong signal it will just pass it
    //! also decode function automatically convert 2 and more spaces(' ') into 1
    //! " ' " is the same as " ` " in encode, but decode returns only " ` "
    //! maximum pad_len is 100, but you change size of the array "pad" at any moment
    //! combinations as "000000000" and "11111111111" are  incorrect
    //! if you are still reading this, I suppose that you are really patient
    //! in morse code " ( " and " ) " are the same combinations
    //! It is impossible( at least for me) to convert it properly, so it always decoded as the same symbol " ( "
    //! encode function is able to work with lowercase letters( decode returns only uppercase letters anyway)


    printf("Enter a message:\n");
    char * message = getString();
    printf("Enter a length of a unit:\n");
    int unit_len = getInt();
    printf("Enter a pad length:\n");
    int pad_len = getInt();
    char signal[5000] = "";
    char * answer = morse_encode(signal, message, unit_len, pad_len);
    printf("Code:\n%s\n", answer);
    char * answer2 = morse_decode( message, answer);
    printf("Normal english:\n%s\n", answer2);
    return 0;
}

char * morse_encode(char * signal, const char * message, int unit_len, int pad_len)
{
    if(unit_len < 1)
    {
        printf("Wrong unit length\n");
        return "\0";
    }
    if(pad_len < 0)
    {
        printf("Wrong pad length\n");
        return "\0";
    }
    memset(&signal[0], 0, sizeof(signal));
    const char * space = "000";
    char smallMorse[5000] = "";
    char pad[100] = "";
    for(int i = 0; i < pad_len; i ++)
    {
        strcat(pad, "0");
    }
    for(int i = 0; i < strlen(message); i ++)
    {
        for(int counter = 0; counter < 50; counter ++)
        {
            if(toupper(message[i]) == inNormal[counter])
            {
                strcat(smallMorse, inMorse[counter]);
                if( i !=  strlen(message) -1 && message[i] != ' ')
                {
                    strcat(smallMorse, space);
                }
                break;
            }
        }
    }
    char  temp[2] = "";
    temp[1] = '\0';
    strcat(signal, pad);
    for(int i = 0; i < strlen(smallMorse); i ++)
    {
        temp[0] = smallMorse[i];
        for(int counter = 0; counter < unit_len; counter ++)
        {
            strcat( signal , temp);
        }
    }
    strcat(signal, pad);
    return &signal[0];
}
char * morse_decode(char * message, const char * signal)
{
    memset(&message[0], 0, sizeof(message));
    const int signalLen = strlen(signal);
    char cleanSignal[10000] = "";
    char normalSignal[5000] = "";
    int testFlag1 = 1;
    int startOfSignal = 0;
    int endOfSignal = signalLen;
    for(int i = 0; i < signalLen; i++)
    {
        if(signal[i] != '0' && signal[i] != '1')
        {
            return "CRITICAL ERROR\nNot correct signal\n";
        }
        if(testFlag1 && signal[i] == '1')
        {
            startOfSignal = i;
            testFlag1 = 0;
        }
    }
    if(testFlag1)
    {
        return "CRITICAL ERROR\nEmpty signal\n";
    }
    for(int i = signalLen - 1; i != 0; i --)
    {
        if(signal[i] == '1')
        {
            endOfSignal = i + 1;
            break;
        }
    }
    int b = 0;
    for ( int i = startOfSignal ; i < endOfSignal; i++, b ++)
    {
        cleanSignal[b] = signal[i];
    }
    cleanSignal[endOfSignal] = '\0';
    int cleanSignalLen = strlen(cleanSignal);
    int minZeroLen = 1000;
    int tempZeroLen = 0;
    for(int i = 0; i < cleanSignalLen; i ++)
    {
        if(cleanSignal[i] == '0')
        {
            tempZeroLen ++;
        }
        else
        {
            if(tempZeroLen < minZeroLen && tempZeroLen != 0)
            {
                minZeroLen = tempZeroLen;
            }
            tempZeroLen = 0;
        }
    }
    if(minZeroLen == 1000)
    {
        return "Your message is E or T. Or just some number of 1. Anyway it is impossible to count length of the minimal symbol,so....\nCRITICAL ERROR\nNO ZEROS FOUND\n";
    }
    int counter = 0;
    for(int i = 0; i < cleanSignalLen; i += minZeroLen, counter ++)
    {
        normalSignal[counter] = cleanSignal[i];
    }
    normalSignal[counter] = '\0';
    const int normalSignalLen = strlen(normalSignal);
    int startPart = 0;
    int endPart = 0;
    char temp[1000] = "";
    char tempSymbol[2] = "";
    tempSymbol[1] = '\0';
    int numberOfSymbols = 0;
    for( int i = 0; i < normalSignalLen; i ++)
    {
        if(normalSignal[i] == '0' ||  i == (normalSignalLen - 1))
        {
            tempZeroLen ++;
            if(tempZeroLen > 2 || i == (normalSignalLen - 1))
            {

                if(i == (normalSignalLen - 1))
                {
                    endPart = normalSignalLen;
                }
                else  if(normalSignal[i + 1] == '0' && normalSignal[i - 3] == '0')
                {
                    endPart = i + 1;
                    for(int b = i; normalSignal[b + 1] != '1'; b ++)
                    {
                        i ++;
                    }
                }
                else
                {
                    endPart = i - 3;
                }
                for(counter = 0; startPart < endPart + 1; startPart ++, counter++)
                {
                    temp[counter] = normalSignal[startPart];
                }
                temp[counter ] = '\0';
                for(counter = 0; counter < 50; counter ++)
                {
                    if(strcmp(inMorse[counter], temp) == 0)
                    {
                        tempSymbol[0] = inNormal[counter];
                        strcat(message, tempSymbol);
                        numberOfSymbols ++;
                        break;
                    }
                }
                tempZeroLen = 0;
                startPart = i + 1;
            }
            else
            {

            }
        }
        else
        {
            tempZeroLen = 0;
        }
    }
    message[numberOfSymbols] = '\0';
    return &message[0];
}
