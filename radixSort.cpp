#include "sort.h"

void radixSort(vector <int> &v)
{
    //create buckets to hold numbers for each digit
    vector <int> zero;
    vector <int> one;
    vector <int> two;
    vector <int> three;
    vector <int> four;
    vector <int> five;
    vector <int> six;
    vector <int> seven;
    vector <int> eight;
    vector <int> nine;
    
    //declare vector to hold input
    vector <int> all;
    
    int shift;
    int largestNumber;
    int numDigits;
    int digit;
    
    //set shift to 1
    shift = 1;
    //set largest number to be the first element
    largestNumber = v[0];
    
    for (int i = 0; i < v.size(); ++i) {
        //copy input into all vector
        all.push_back(v[i]);
        //if element is greater than largest number then set it as the largest number
        if (v[i] > largestNumber) {
            largestNumber = v[i];
        }
    }
    
    //set number of digits to 1
    numDigits = 1;
    //divide by 10 and increment the number of digits
    while ( largestNumber /= 10 ) {
        numDigits++;
    }
    
    //loop through from 0 to number of digits
    for (int loop = 0; loop < numDigits; ++loop) {
        //loop through vector
        for (int i = 0; i < all.size(); ++i) {
            //get the digit
            digit = ((all[i]/shift)%10);
            //put element in corresponding vector depending on digit
            if (digit == 0) {
                zero.push_back(all[i]);
            } else if (digit == 1) {
                one.push_back(all[i]);
            } else if (digit == 2) {
                two.push_back(all[i]);
            } else if (digit == 3) {
                three.push_back(all[i]);
            } else if (digit == 4) {
                four.push_back(all[i]);
            } else if (digit == 5) {
                five.push_back(all[i]);
            } else if (digit == 6) {
                six.push_back(all[i]);
            } else if (digit == 7) {
                seven.push_back(all[i]);
            } else if (digit == 8) {
                eight.push_back(all[i]);
            } else if (digit == 9) {
                nine.push_back(all[i]);
            }
        }
        //increase your shift
        shift = shift * 10;
        //clear your vector
        all.clear();
        
        //append all buckets to your vector in order
        all.insert(all.end(), zero.begin(), zero.end());
        all.insert(all.end(), one.begin(), one.end());
        all.insert(all.end(), two.begin(), two.end());
        all.insert(all.end(), three.begin(), three.end());
        all.insert(all.end(), four.begin(), four.end());
        all.insert(all.end(), five.begin(), five.end());
        all.insert(all.end(), six.begin(), six.end());
        all.insert(all.end(), seven.begin(), seven.end());
        all.insert(all.end(), eight.begin(), eight.end());
        all.insert(all.end(), nine.begin(), nine.end());

        //clear buckets
        zero.clear();
        one.clear();
        two.clear();
        three.clear();
        four.clear();
        five.clear();
        six.clear();
        seven.clear();
        eight.clear();
        nine.clear();
    }

    //clear input vector
    v.clear();
    //copy your sorted vector into v
    for (int i = 0; i < all.size(); ++i) {
        v.push_back(all[i]);
    }
}
