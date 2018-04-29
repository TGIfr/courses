#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define __LEN(X) sizeof(X)/sizeof(X[0])
#define __BOOLSTR(X) ((X) ? "TRUE" : "FALSE")

struct TestCase {
    const char * input;
    int unit_len;
    int pad_len;
    char * output;
};

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

int main(void) {
    char outputBuffer[1000];
    struct TestCase testCaseArray[] = {
        {"H", 2, 0, "11001100110011"},
        {"HEY DUDE", 2, 0, "1100110011001100000011000000111111001100111111001111110000000000000011111100110011000000110011001111110000001111110011001100000011"},
        {"HEY DUDE", 1, 3, "00010101010001000111010111011100000001110101000101011100011101010001000"},
        {"HEY DUDE", 3, 0, "111000111000111000111000000000111000000000111111111000111000111111111000111111111000000000000000000000111111111000111000111000000000111000111000111111111000000000111111111000111000111000000000111"},
        {"HELLO KITTY", 2, 2,"0011001100110011000000110000001100111111001100110000001100111111001100110000001111110011111100111111000000000000001111110011001111110000001100110000001111110000001111110000001111110011001111110011111100"},
        {"ONE TWO THREE", 4, 0, "1111111111110000111111111111000011111111111100000000000011111111111100001111000000000000111100000000000000000000000000001111111111110000000000001111000011111111111100001111111111110000000000001111111111110000111111111111000011111111111100000000000000000000000000001111111111110000000000001111000011110000111100001111000000000000111100001111111111110000111100000000000011110000000000001111"}
    };
    char * testOutput = NULL;
    int testCaseArrayLength = __LEN(testCaseArray);
    int testIndex = 0;
    int testStatus = 0;
    struct TestCase * testCase = NULL;

    puts("ENCODE:\n");
    for (testIndex = 0; testIndex < testCaseArrayLength; testIndex++) {
        testCase = &testCaseArray[testIndex];
        outputBuffer[0] = '\0';
        testOutput = morse_encode(outputBuffer, testCase->input, testCase->unit_len, testCase->pad_len);
        testStatus = (0 == strcmp(testOutput, testCase->output));
        printf("%s // %s\n", testCase->input, __BOOLSTR(testStatus));
    }

    puts("\nDECODE:\n");
    for (testIndex = 0; testIndex < testCaseArrayLength; testIndex++) {
        testCase = &testCaseArray[testIndex];
        outputBuffer[0] = '\0';
        testOutput = morse_decode(outputBuffer, testCase->output);
        testStatus = (0 == strcmp(testOutput, testCase->input));
        printf("%s == %s // %s\n", testCase->input, testOutput, __BOOLSTR(testStatus));
    }

    printf("\nEnd.\n");
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
    const int signalLen = strlen(signal);
    char cleanSignal[10000] = "";
    char normalSignal[5000] = "";
    memset(&message[0], 0, sizeof(message));
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
