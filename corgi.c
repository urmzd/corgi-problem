// Include statements.
#include <stdio.h>

/**
 * Charles and the Corgi Conundrum
 * 
 * Using the concept of an adjacency matrix, this program determines the average number
 * of bonds between a set of nodes.
 * 
 * author: Urmzd Mukhammadnaim
 */

// Prototypes.
float solve();

// Function to output.
int main(){
    
    int s, r;
    scanf("%d", &s);

    for(r = 1; r <= s; r++){
        printf("Pond #%d: %.3f\n", r, solve());
    }

    return 0;
}

// Function to solve problem.
float solve(){

    /**
    * Allocate space to variables.
    * 
    * n: Represents the number of corgis in the pond.
    * m: Represents the number of bonds.
    * u: Represents Corgi a.
    * v: Represents Corgi b.
    * 
    * Note: u, v represents the notation that u is friends with v and vice-versa.
    */

    int n, m, u, v;

    // Read in values and store them in their respective variables. 
    scanf("%d %d", &n, &m);

    /**
    * Allocate space to arrays.
    * 
    * booleanArray: booleanArray is meant to hold the relationships between the corgis, 1 if the relationship exists, 0 otherwise.
    * totalArray: totalArray holds the number of corgi's you can expect to take home if you take corgi n.
    * 
    */

    int booleanArray[n][n]; 
    int totalArray[n]; 

    int i, j, temp1, temp2; // Temporary variables used for loops.

    // Initialize all values in booleanArray as 0.
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            booleanArray[i][j] = 0;
        }
    }

    /* 
    * Loop through the boolean array,
    * Place a true value in location: (u - 1 , v-1) and (v - 1, u - 1) to indicate a relationship exists. 
    */
    for(j = 0; j < m; j++){
        
        scanf("%d %d", &u, &v);

        booleanArray[u - 1][v - 1] = 1;
        booleanArray[v - 1][u - 1] = 1;
    }

    /*
    * Loop through the totalArray,
    * Initialize the array with 1's to indicate that atleast 1 object will always be taken home.
    */
    for(j = 0; j < n; j++){
        totalArray[j] = 1;
    }

    /**
     * Loop through the boolean array,
     * If a true value exists at location (i,j),
     * Loop through row j,
     * For each relationship that exists in row j,
     * Increment index i in totalArray by 1.
     */

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){

            if(booleanArray[i][j] == 1){
                temp1 = j;
                for(temp2 = 0; temp2 < n; temp2++){
                    if(booleanArray[temp1][temp2] == 1){
                        totalArray[i] += 1;
                    }
                }
            }

        }
    }

    // Allocate space to the variable that will hold the average.
    float average;

    average = 0; // Initialize the average variable.

    for(i = 0; i < n; i++){
        average += totalArray[i]; // Get total.
    }

    average /= n; // Get average.

    return average;
}