"For two thousand years, codemakers have fought to preserve secrets while codebreakers have tried their best to reveal them." - taken from Code Book, The Evolution of Secrecy from Mary, Queen of Scots to Quantum Cryptography by Simon Singh.

The idea for this machine problem came from this book.You will encrypt and decrypt some messages using a simplified version of a code in the book. The convention in cryptography is to write the plain text in lower case letters and the encrypted text in upper case letters. We will follow this convention for this machine problem. We will only encrypt/decrypt letters. Any other character will be left as is (i.e. 1 2 3 . , etc).

For simplicity we will exclude the letter 'z' from the alphabet (see below). The method of encryption used here is a simple substitution cipher that depends on the sender and receiver of the message agreeing on a keyword, which is usually just one word that will be easy to remember. Thus the key for decrypting the message will not have to be written down and is less likely to fall into enemy hands!

First, the program must read in a keyword, which will be all capital letters. The letters of the keyword must be inserted in the order in which they occur into a 5x5 two dimensional array by rows, but if a letter is repeated in the keyword it is only used once in the two-dimensional array. Then the array is filled up with the remaining letters of the alphabet in order (excluding the 'Z').e.g. if the keyword was PHENOMENON the array would contain the following:

  0 1 2 3 4
0 P H E N O
1 M A B C D
2 F G I J K
3 L Q R S T
4 U V W X Y


Next, the program will read in a series of lines containing either messages to encrypt or decrypt.

A plain text message will be encrypted as follows:

Each letter in the message will be found in the table, and the row and column will be noted: e.g. 'g' (when converted to upper case) occurs at row 2, column 1 in the above array. (Remember that indexes start at 0 in C++).

It will then be encrypted by reversing the row and column values, so that 'g' will become the character at row 1, column 2, i.e. 'B' in the encrypted message.

Thus if the message was "good luck" it will be encrypted as "BUUV NOQW" Spaces between words will be maintained exactly as they appear in the message.

A message that is already encrypted can be decrypted using exactly the same algorithm – the only difference is that the incoming message will be in upper case and the decrypted message will be in lower case.

You should process a file that contains the following:

HAPPINESS
D EVDEUOA XC GCERVLEWQ, FESS BC EUV OCWWAOX XLC HNUVRAV VCWWERS
E hello there
D HAWWC XHARA
E attack at dawn
D IAAX IA NUVAR HEIIARSIMXH GRMVBA
E the meeting is in san francisco
D XHMS MUPCRIEXMCU MS AUORYFXAV NSMUB XHA QAYLCRV HEFFMUASS
D XHA EUSLAR XC XHA PMRSX KNASXMCU CU XHA PMUEW IEY GA XRNA CR MX IEY GA PEWSA
E the answer to the first question on the final may be true or it may be false
D OCUBREXNWEXMCUS YCN IEVA MX XHRCNBH XHMS IEOHMUA FRCGWAI
E advance to boardwalk, pass go and collect two hundred dollars
E make my day
E zorro is back (in town)
E you ain't nothing but a hound dog
E one day a computer will weigh less than a ton --- popular mechanics 1948
E no computer will ever need more than 640k of memory -- bill gates in the mid eighties
D YCN EMUX UCXHMUB GNX E HCNUV VCB
D CUA VEY E OCIFNXAR LMWW LAMBH WASS XHEU E XCU --- FCFNWER IAOHEUMOS 1948
D UC OCIFNXAR LMWW ADAR UAAV ICRA XHEU 640Q CP IAICRY -- GMWW BEXAS MU XHA IMV AMB HXMAS
E the attack will start in $"population" minutes

This file has the keyword on the first line, then a series of lines beginning with 'E' (for encrypt) or 'D' (for decrypt), then exactly one space, and then the message to be either encrypted or decrypted. The program should read these lines until it comes to the end of the file.

The output should echo all the data, print out the two dimensional array as above, and print out the messages and their encoded equivalents (in either upper case (encrypting output) or lower case(decrypting output)).

So the first few lines of output on the above program would be something like:

keyword is PHENOMENON

0 1 2 3 4
0 P H E N O
1 M A B C D
2 F G I J K
3 L Q R S T
4 U V W X Y

****************************************
AVDALQF XU GUAJVKANW, PASS BU ALV QUNNFQX XKU MOLVJFV VUNNAJS
decrypts to:
advance to boardwalk, pass go and collect two hundred dollars
****************************************
hello there, zuzu.
encrypts to
MFNNU XMFJF, ZOZO.
****************************************

Have fun!!

Requirements:
1.) Break up the problem into smaller modules and get each one working before going on to the next. E.g. concentrate first on how to build the two-dimensional array from the keyword.
2.) Make sure you print out your 5x5 table using the key read from the file.

Hint:
C++ provides 2 useful functions called toupper and tolower. Checkout the following code to see how they get used:

char ltr;
ltr = tolower('C');
cout << ltr << endl;
ltr= toupper('d');
cout << ltr << endl;
