// (C) Ediz,         ,        -> Group: 23 (2022)
// Work package 1
// Exercise 5
// Submission code: ------

/*------------------------------------------------------------
References:

*------------------------------------------------------------
Exercise 5

The system.........bla bla

//--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
int create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
int count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
int draw_histogram(int *freq);

int create_random(int *tab)
{
    int index = 0;
    srand(time(0));

    while (index < MAX)
    {
        int randomNumber = rand() % MAXNUMBER;
        tab[index] = randomNumber;
        index++;
    }
    return 0;
}


/**
* Function takes the *tab of random numbers
* and stores the number of the appearance of each number in the tab array
* The function takes as an input 2 params
* @param *tab - array of random numbers numbers.
* @param *freq - where we store the counts for each number appearance in the tab array.
*/

int count_frequency(int *tab, int *freq)
{

    // loop over to reset and set the frequency array to 0s to clean up from the RAM garbage values.
    for (int i = 0; i < MAXNUMBER; ++i) {
        // set each index to 0
        freq[i] = 0;
    }

    // use pointer to point at the tab array
    int *tab_ptr;
    // Assign the pointer address to the tab array address in the memory
    tab_ptr = tab;

    // loop over the length of the tab array
    for (int i = 0; i < MAX; i++)
    {

        // as the frequency array is already indexed and sequential >>
        // use the index of the array as a key to store the occurrence of these numbers.
        // Example - value of tab[i] = 5 then go to index 5 in freq[] and add 1 (found one time)
        // with each loop, the index for this number is incremented if it's found again.
        // module operator is used to find the right index as i will grow higher than MAXNUMBER
        freq[*tab_ptr % MAXNUMBER] ++;

        // increment the tab_pointer to go to next int address
        tab_ptr++;
    }
    return  0;
}


/**
* Function takes the *freq  of counts of how many times a number has appeared in an array
* This function will draw a histogram of the statistics the *freq holds.
* The function takes as an input 1 params
* @param *freq - array of counts of the appearance of numbers in an array.
*/

int draw_histogram(int *freq)
{

    // Plotting the histogram
    // the idea is adopted from https://stackoverflow.com/questions/18930908/c-printing-a-histogram
    printf("\n\t >>>>>> A histogram for the frequency of each number in an array <<<<<<<\n\n");

    // initial int i to hold the index value
    int i = 0;
        do
        {
            // prints the index number with tab afterwards
            printf("%d|\t",i);

            // if the value of the freq[index] is 0 --> no occurrence for this number
            // otherwise we draw the starts of how many times is the value
            if (freq[i] != 0) {

            // loop many times as the value of the freq[i].
            for(int j = 0; j < freq[i]; j++)

                // draw a star char
                printf("%c",'*');
                // start a new line
                printf("\n");
            }
            // increment the i to go to the next index of *freq
            i++;
        // repeat the process for the length of the *freq
        } while(i < MAXNUMBER);

        // return 0 if successful
    return 0;
}



// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{

    int table[MAX], n;
    int frequency[MAXNUMBER];

    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);


    return 0;
}


