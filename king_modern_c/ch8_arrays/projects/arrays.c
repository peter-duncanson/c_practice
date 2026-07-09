#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//==============================================================================
// (1) Modify the <repdigit.c> program in Section 8.1 so that it shows which
// digits (if any) were repeated.
void repeated_digit_display(void) {
    // create array to track which digits have been seen
    // in order to track specfic repeats, using:
    // 0 = not seen
    // 1 = seen once
    // 2 = seen more than once
    int i, seen_digits[10] = { 0 };
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        i = n % 10;
        if (seen_digits[i]) {
            seen_digits[i] = 2;
        }
        else {
            seen_digits[i] = 1;
        }
        n /= 10;
    }

    printf("The repeated digits were:");
    for (i = 0; i < 10; i++) {
        if (seen_digits[i] == 2) {
            printf(" %d", i);
        }
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (2) Modify the <repdigit.c> program in Section 8.1 so that it prints a table
// showing how many times each digit appears in the number.
void repeated_digit_table(void) {

    // Table will look something like this
    // Digit    Occurances
    // 0            X
    // 1            X
    // 2            X
    // 3            X
    // 4            X
    // 5            X
    // 6            X
    // 7            X
    // 8            X
    // 9            X
    
    // array will now just store amount of occurances
    int i, digit_counts[10] = { 0 };

    long n; // variable to store input
    
    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        i = n % 10;
        digit_counts[i] += 1;
        n /= 10;
    }
    puts("");

    printf("Digits\tOccurances\n======\t==========\n");
    for (i = 0; i < 10; i++) {
        printf("%3d\t%5d\n", i, digit_counts[i]);
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (3) Modify the <repdigit.c> program of Section 8.1 so that the user can enter
// more than one number to be tested for repeated digits. The program should
// terminate when the user enters a number thats less than or equal to zero.
void repeated_digits_loop(void) {

    // just going to put the previous function in a loop
    // instead of manually clearing the array, ill just 
    // re-instantiate it each time the loop runs
    // I assume that is faster..
    while (1) {

        int i, digit_counts[10] = { 0 };

        long n;

        printf("Enter a number or 0 to end: ");
        scanf("%ld", &n);

        if (n <= 0) {
            puts("Thank you for playing!\n");
            break;
        }

        while (n > 0) {
            i = n % 10;
            digit_counts[i] += 1;
            n /= 10;
        }

        puts("");

        printf("Digits\tOccurances\n======\t==========\n");
        for (i = 0; i < 10; i++) {
            printf("%3d\t%5d\n", i, digit_counts[i]);
        }

        puts("");
    }
}
//==============================================================================

//==============================================================================
// (4) Modify the <reverse.c> program of Section 8.1 and use the expression
// (int) (sizeof(a) / sizeof(a[0])) (or a macro with this value) for the array
// length.
void reverse_improved(void) {
     
    // previously, a macro called N was used to hold an integer constant for
    // the size of the array and was also used in the for loop. I see how this
    // could be useful if there was some way to pass in an arbitrary array as
    // a kind of argument, or parameter as was mentioned. Otherwise, it seems
    // to be excessive when a macro defining an integer constant could also be 
    // used to instantiate an array and reference its size.

    #define SIZE (int) (sizeof(a) / sizeof(a[0]))

    int i, a[10];

    printf("Enter %d numbers: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");
    for (i = SIZE - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (5) Modify the <interest.c> program of Section 8.1 so that it compounds
// interest *monthly* instead of *annually*. The form of the output shouldn't
// change; the balance should still be shown at annual intervals.
void monthly_interest(void) {
    
    // initial investment
    #define INITIAL 100.00

    // number of interest rates to be displayed as columns
    // depends on the size of the value array
    #define N_RATES (int) (sizeof(value) / sizeof(value[0]))

    // number of times compounded per year
    #define N_COMPOUNDED 12 

    // macro stores a factor of the exponential base 
    // let A = P * (1 + ((ALPHA) * R))^NT
    // where:
    // A = amount
    // P = initial amount
    // R = current rate
    // N = number of times compounded per year
    // T = number of years
    // ALPHA = scaled coefficient for rate
    #define ALPHA (float) 1 / (N_COMPOUNDED * 100)

    int i, j, base_rate, n_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &base_rate);
    printf("Enter number of years: ");
    scanf("%d", &n_years);

    printf("\nYears");
    for (i = 0; i < N_RATES; i++) {
        // print out each of the rates {base, base + 1, ... , base + 4}
        printf("%6d%%", base_rate + i);
        // each member of the array starts by storing the initial investment
        value[i] = INITIAL;
    }
    puts("");

    for (year = 1; year <= n_years; year++) {
        printf("%3d    ", year);
        // do the calcs for each rate
        for (i = 0; i < N_RATES; i++) {
            // compound
            for (j = 1; j <= N_COMPOUNDED; j++) {
                value[i] *= (1 + (ALPHA * (base_rate + i)));
            }
            printf("%7.2f", value[i]);
        }
        puts("");
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (6) The prototypical Internet newbie is a fellow named B1FF, who has a unique
// way of writing messages. Heres a typical B1FF communiqué:
// H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
// Write a 'B1FF filter' that reads a message entered by the user and translates
// it into B1FF-speak:
// Enter message: Hey dude, C is rilly cool
// In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
// Your program should convert the message to upper-case letters, substitute
// digits for certain letters, and then append 10 or so exclamation marks.
// Mapping: [A -> 4] [B -> 8] [E -> 3] [I -> 1] [O -> 0] [S -> 5] 
void leet_speek(void) {

    // exactly how many exclamation marks do we want to add?
    #define EXCITEMENT 10

    // create a buffer thats large enough to fit any reasonable short message
    char buffer[128];

    // store the length of the message
    int i, len = 0;

    // get the message and store it char by char
    printf("Enter message: ");
    while ((buffer[len] = getchar()) != '\n') {

        if ('a' <= buffer[len] && 'z' >= buffer[len]) {
            buffer[len] -= 32;
        }

        switch (buffer[len]) {
            case 'A':
                buffer[len] = '4';
                break;
            case 'B':
                buffer[len] = '8';
                break;
            case 'E':
                buffer[len] = '3';
                break;
            case 'I':
                buffer[len] = '1';
                break;
            case 'O':
                buffer[len] = '0';
                break;
            case 'S':
                buffer[len] = '5';
                break;
        };

        len++;
        
        if (len >= 118) {
            puts("Max message length reached.");
            break;
        }
    }

    for (i = 0; i <= EXCITEMENT; i++) {
        buffer[len + i] = '!';
    }

    printf("In B1FF-speak: ");
    for (i = 0; i < (len + EXCITEMENT); i++) {
        printf("%c", buffer[i]);
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (7) Write a program that reads a 5x5 array of integers and then prints the
// row sums and the column sums
void marginals(void) {

    int i = 0;
    int a[5][5] = { { 0 } };
    int sum_rows[5] = { 0 };
    int sum_cols[5] = { 0 };

    // read everything in
    for (i = 0; i < 5; i++) {
        printf("Enter row %d: ", i + 1);
        scanf("%d %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    }

    // sum it all up
    for (i = 0; i < 5; i++) {
        sum_rows[i] += (a[i][0] + a[i][1] + a[i][2] + a[i][3] + a[i][4]);
        sum_cols[i] += (a[0][i] + a[1][i] + a[2][i] + a[3][i] + a[4][i]);
    }

    printf("Row totals: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", sum_rows[i]);
    }

    puts("");

    printf("Column totals: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", sum_cols[i]);
    }

    puts("");

}
//==============================================================================

//==============================================================================
// (8) Modify Programming Project 7 so that it prompts for five quiz grades for
// each of five students, then computes the total score and average score for
// each *student*, and the average score, high score, and low score for each
// *quiz*
void quiz_data(void) {
    
    int i, j, high_score, low_score = 0;
    int student_totals[5] = { 0 };
    float student_means[5] = { 0.0 };

    int quiz_low[5] = { 0 };
    int quiz_high[5] = { 0 };
    float quiz_mean[5] = { 0.0 };

    int a[5][5] = { { 0 } };

    // read everything in
    for (i = 0; i < 5; i++) {
        printf("Enter scores for student %d: ", i + 1);
        scanf("%d %d %d %d %d", 
        &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    }

    // -------- Debugging array ------------
    // int a[5][5] = {
    //     {15, 17, 26, 52, 70},
    //     {95, 92, 90, 99, 93},
    //     {70, 72, 81, 85, 90},
    //     {60, 64, 50, 70, 75},
    //     {87, 91, 89, 88, 95}
    // };
    // -------------------------------------

    // sum it all up
    for (i = 0; i < 5; i++) {

        high_score = low_score = a[0][i];

        int student_total = (a[i][0] + a[i][1] + a[i][2] + a[i][3] + a[i][4]);
        int quiz_total = (a[0][i] + a[1][i] + a[2][i] + a[3][i] + a[4][i]);

        student_totals[i] += student_total;
        student_means[i] += ((float) (student_total / 5.0));
        quiz_mean[i] += (float) (quiz_total / 5.0);

        for (j = 0; j < 5; j++) {

            if (a[j][i] >= high_score) {
                quiz_high[i] = high_score = a[j][i];
            }

            if (a[j][i] <= low_score) {
                quiz_low[i] = low_score = a[j][i];
            }
        }
    }

    printf("Student\t\tMean\t\tTotal\n");
    for (i = 0; i < 5; i++) {
        printf("%2d\t\t%4.1f\t\t%4d\n",
        i + 1, student_means[i], student_totals[i]);
    }

    puts("");

    printf("Quiz\t\tMean\t\tHigh\t\tLow\n");
    for (int i = 0; i < 5; i++) {
        printf("%2d\t\t%4.1f\t\t%3d\t\t%3d\n",
        i + 1, quiz_mean[i], quiz_high[i], quiz_low[i]);
    }
}
//==============================================================================

//==============================================================================
// (9) Write a program that generates a random walk across a 10x10 array. The
// array will contain characters (all '.' initially). The program must randomly
// 'walk' from element to element, always going up, down, left, or right by one
// element. The elements visited by the program will be labeled with the letters
// 'A' through 'Z', in the order visited.
void random_walk(void) {

    char a[10][10] = {
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' }
    };
    
    // 0 -> North
    // 1 -> East
    // 2 -> South
    // 3 -> West

    // random number generator seed
    srand((unsigned) time(NULL));

    // variables to track position
    int i = 0;
    int j = 0;
    int direction = 0;

    // initialize element 0 as A
    a[i][j] = 'A';

    for (char letter = 'B'; letter <= 'Z'; letter++) {

        try:
            if ((a[i + 1][j + 1] != '.') &&
                (a[i - 1][j - 1] != '.') && 
                (a[i + 1][j - 1] != '.') && 
                (a[i - 1][j + 1] != '.')) {
                break;
            }

            direction = rand() % 4;
            switch (direction) {
                case 0: // north
                    if (i > 0 && a[i - 1][j] == '.') {
                        i -= 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 1: // east
                    if (j < 9 && a[i][j + 1] == '.') {
                        j += 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 2: // south
                    if (i < 9 && a[i + 1][j] == '.') {
                        i += 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 3: // west
                    if (j > 0 && a[i][j - 1] == '.') {
                        j -= 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
            };
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf(" %c", a[i][j]);
        }
        puts("");
    }

}
//==============================================================================

//==============================================================================
// (10) Modify Programming Project 8 From Chapter 5 so that the departure times
// in an array and the arrival times are stored in a second array. (The times
// are integers, representing the number of minutes since midnight.) The program
// will use a loop to search the array of departure times for the one closest
// to the time entered by the user.
// From Chapter 5 -> 
// The following table shows the daily flights from one city to another:
//
// Departure Time       Arrival Time
//    08:00am              10:16am
//    09:43am              11:52am
//    11:19am              01:31pm
//    12:47pm              03:00pm
//    02:00pm              04:08pm
//    03:45pm              05:55pm
//    07:00pm              09:20pm
//    09:45pm              11:58pm
//
// Write a program to ask the user to enter a time (expressed in hours and
// minues, using the 24-hour clock). The program then displays the departure
// time and arrival times for the flight whose departure time is closest to that
// entered by the user.
void find_flight(void) {

    #define N_TIMES (sizeof(departures) / sizeof(departures[0]))

    // times stored as minutes since midnight
    int departures[8] = { 480, 583, 679, 767, 840, 945, 1140, 1305 };
    int arrivals[8] = { 616, 712, 811, 900, 968, 1075, 1280, 1438 };
    

    int i, hours, minutes, time_gap, closest;

    printf("Enter a 24 hour time: ");
    scanf("%d:%d", &hours, &minutes);

    minutes += (hours * 60);

    for (i = 0; i < N_TIMES; i++) {
        time_gap = departures[i] - minutes;

        // check if flight was in the past and if so continue
        if (time_gap <= 0) {
            continue;
        }
        // if its not in the past, the first one we enounter should be closest
        else {
            closest = i;
            break;
        }
    }

    hours = departures[closest] / 60;
    minutes = departures[closest] % 60;

    printf("Closest departure time is ");

    switch (departures[closest] >= 720) {
        case 0:
            printf("%.2d:%.2d a.m., ", hours, minutes);
            break;
        case 1:
            printf("%.2d:%.2d p.m., ", hours - 12, minutes);
            break;
    };

    hours = arrivals[closest] / 60;
    minutes = arrivals[closest] % 60;

    printf("Arriving at ");
    switch (arrivals[closest] >= 720) {
        case 0:
            printf("%.2d:%.2d a.m., ", hours, minutes);
            break;
        case 1:
            printf("%.2d:%.2d p.m., ", hours - 12, minutes);
            break;
    };

    puts("");

}
//==============================================================================

//==============================================================================
// (11) Modify Programming Project 4 from Chapter 7 so that the program labels
// its output:
// Enter phone number: 1-800-COL-LECT
// In numeric form: 1-800-265-5328
// The program will need to store the phone number (either in its original form
// or in its numeric form) in an array of characters until it can be printed.
// You may assume that the phone number is no more than 15 characters long.
// From Chapter 7 ->
// Write a program that translates an alphabetic phone number into numeric form:
// Enter phone number: CALLATT
// 2255288
// Mapping:
// 2 = ABC
// 3 = DEF
// 4 = GHI
// 5 = JKL
// 6 = MNO
// 7 = PRS
// 8 = TUV
// 9 = WXY
void convert_phone_number(void) {

    char c, phone_number[16];
    int i;

    printf("Enter phone number: ");

    while((c = getchar()) != '\n') {
        phone_number[i] = c;
        i++;
    }
    phone_number[16] = '\0';

    printf("In numeric form: ");

    for (i = 0; i < 15; i++) {
        c = phone_number[i];
        if (c == '\0') {
            break;
        }
        else {
            if ('A' <= c && 'C' >= c) {
                printf("2");
                continue;
            }
            if ('D' <= c && 'F' >= c) {
                printf("3");
                continue;
            }
            if ('G' <= c && 'I' >= c) {
                printf("4");
                continue;
            }
            if ('J' <= c && 'L' >= c) {
                printf("5");
                continue;
            }
            if ('M' <= c && 'O' >= c) {
                printf("6");
                continue;
            }
            if ('P' <= c && 'S' >= c && c != 'Q') {
                printf("7");
                continue;
            }
            if ('T' <= c && 'V' >= c) {
                printf("8");
                continue;
            }
            if ('W' <= c && 'Y' >= c) {
                printf("9");
                continue;
            }
            printf("%c", c);
        }
    }
    puts("");

}
//==============================================================================

//==============================================================================
// (12) Modify Programming Project 5 from Chapter 7 so that the SCRABBLE values
// of the letters are stored in an array. The array will have 25 elements,
// corresponding to the 25 letters of the alphabet.
// For example, element 0 of the array will store 1 (because the SCRABBLE value
// of the letter A is 1), element 1 of the array will store 3 (because the
// SCRABBLE value of the letter B is 3), and so forth. As each character in the
// input word is read, the program will use the array to determine the SCRABBLE
// value of the character. Use an array initializer to set up the array.
// From Chapter 7 ->
// In the SCRABBLE Crossword Game, players form words using small tiles, each
// containing a letter and a face value. The face value varies from one letter
// to another, based on the letter's rarity.
// ----------------------
//     Face values:     |
// - AEILNORSTU -> 1    |
// - DG         -> 2    |
// - BCMP       -> 3    |
// - FHVWY      -> 4    |
// - K          -> 5    |
// - JX         -> 8    |
// - QZ         -> 10   |
// ----------------------
//
// #include <ctype.h>
// int toupper(int c) -> C if c else C
//
void scrabble_score(void) {
    
    int face_values[26] = { 
                            1, 3, 3, 2, 1, // A B C D E
                            4, 2, 4, 1, 8, // F G H I J
                            5, 1, 3, 1, 1, // K L M N O
                            3, 10,1, 1, 1, // P Q R S T
                            1, 4, 4, 8, 4, // U V W X Y
                            10             // Z
    };

    int c, score;
    
    printf("Enter word: ");
    while ((c = getchar()) != '\n') {

        score += face_values[toupper(c) - 65];
    }

    printf("Score: %d\n", score);

}
//==============================================================================

//==============================================================================
// (13) Modify Programming Project 11 from Chapter 7 so that the program labels
// its output:
// Enter a first and last name: Lloyd Fosdick
// You entered the name: Fosdick, L.
// The program will store the last name (but not the first name) in an array of
// characters until it can be printed. You may assume that the array is no more
// than 20 characters long.
void format_name(void) {

    char c, first_initial, last_name[20];
    int i, end;

    printf("Enter a first and last name: ");

    first_initial = getchar();
    while((c = getchar()) != ' ');
    while((c = getchar()) != '\n') {
        last_name[i] = c;
        i++;
    }
    end = i;

    printf("You entered the name: ");
    for (int i = 0; i <= end; i++) {
        printf("%c", last_name[i]);
    }
    printf(", %c.\n", first_initial);

}
//==============================================================================

//==============================================================================
// (14) Write a program that reverses the words in a sentence:
// Enter a sentence: you can cage a swallow can't you?
// Reversal of sentence: you can't swallow a cage can you?
void reverse_sentence(void) {
    
    char c, punctuation, buffer[80];
    int end, word_end, i, j = 0;

    printf("Enter a sentence: ");
    while ((c = getchar()) != '\n') {
        if (c == '!' || c == '?' || c == '.') {
            punctuation = c;
            continue;
        }
        buffer[i] = c;
        i++;
    }
    end = word_end = i;

    for (i = end; i >= 0; i--) {
        if (buffer[i] == ' ') {
            for (j = i + 1; j < word_end; j++) {
                printf("%c", buffer[j]);
            }
            printf(" ");
            word_end = i;
            continue;
        }
        if (i == 0) {
            for (j = i; j <= word_end - 1; j++) {
                printf("%c", buffer[j]);
            }
        }
    }
    if (punctuation) {
        printf("%c", punctuation);
    }

    puts("");

}
//==============================================================================

//==============================================================================
// (15) One of the oldest known encryption techniques is the Caesar cipher,
// attributed to Julius Caesar. It involves replacing each letter in a message
// with another letter that is a fixed number of positions later in the
// alphabet. (If the replacement would go past the letter Z, the cipher
// wraps around to the beginning of the alphabet.) Write a program that encrypts
// a message using a Caesar cipher. The user will enter the message to be
// encrypted and the shift amount.
// -----------------------------------------------------------------------------
// Enter message to be encrypted: Go ahead, make my day.
// Enter shift amount: 3
// Encrypted message: Jr dkhdg, pdnh pb gdb.
// -----------------------------------------------------------------------------
// Notice that the program can decrypt a message if ther user enters 26 minus
// the original key:
// -----------------------------------------------------------------------------
// Enter message to be encrypted: Jr dkhdg, pdnh pb gdb. 
// Enter shift amount: 23
// Encrypted message: Go ahead, make my day.
// -----------------------------------------------------------------------------
// You may assume that the message does not exceed 80 characters. Characters
// other than letters should be left unchanged. Upper and lower case should
// remain that way when encrypted.
void caesar_cipher(void) {

    char c, message[80];
    int shift_amount, message_length, i = 0;

    printf("Enter message to be encrypted: ");
    while ((c = getchar()) != '\n') {
        message[i] = c;
        i++;
    }
    message_length = i;
    printf("Enter shift amount: ");
    scanf("%d", &shift_amount);
    // Shift amount up to the max value of an int32 still works
    shift_amount = shift_amount % 25;
    
    for (i = 0; i <= message_length; i++) {
         c = message[i];
         if ('a' <= c && 'z' >= c) {
             printf("%c", ((c - 'a') + shift_amount) % 26 + 'a');
             continue;
         }
         if ('A' <= c && 'Z' >= c) {
             printf("%c", ((c - 'A') + shift_amount) % 26 + 'A');
             continue;
         }
         else {
             printf("%c", c);
         }
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (16) Write a program that tests whether two words are anagrams (permutations
// ot the same letters):
// -----------------------------------------------------------------------------
// Enter first word: smartest
// Enter second word: mattress
// The words are anagrams.
// -----------------------------------------------------------------------------
// Enter first word: dumbest
// Enter second word: stumble
// The words are not anagrams.
// -----------------------------------------------------------------------------
void is_anagram(void) {

    int c;
    int first_letters[26] = { 0 };
    int second_letters[26] = { 0 };

    printf("Enter first word: ");
    while ((c = getchar()) != '\n') {
        c = toupper(c);
        first_letters[c - 65] += 1;
    }

    printf("Enter second word: ");
    while ((c = getchar()) != '\n') {
        c = toupper(c);
        second_letters[c - 65] += 1;
    }

    for (c = 0; c < 26; c++) {
        if (first_letters[c] != second_letters[(int) c]) {
            printf("The words are not anagrams.\n");
            return;
        }
    }

    printf("The words are anagrams.\n");

}
//==============================================================================

//==============================================================================
// (17) Write a program that prints an n x n magic square (A square arrangement
// of the numbers 1, 2, ... ,n^2 in which the sums of the rows, columns and
// diagonals are all the same) The user will specify the value of n:
// -----------------------------------------------------------------------------
// This program creates a magic square of a specificed size.
// The size must be an odd number between 1 and 99.
// Enter size of magic square: 5
// 17  24   1   8  15
// 23   5   7  14  16
//  4   6  13  20  22
// 10  12  19  21   3
// 11  18  25   2   9
void magic_square(void) {

    int n, i, j, k;

    printf("This program creates a magic square of a specified size\n");
    printf("The size must be an odd number between 1 and 99\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);
    
    int a[n][n];

    i = 0;
    j = n / 2;

    for (k = 1; k <= (n * n); k++) {

        a[i][j] = k;
        i--;
        j++;

        if (k % n == 0) {
            i += 2;
            j--;
        }
        if (i < 0) {
            i = (n - 1);
        }
        if (j == n) {
            j = 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d ", a[i][j]);
        }
        puts("");
    }
}
//==============================================================================
