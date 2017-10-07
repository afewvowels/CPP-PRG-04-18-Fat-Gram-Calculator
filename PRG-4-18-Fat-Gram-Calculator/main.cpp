//
//  main.cpp
//  PRG-4-18-Fat-Gram-Calculator
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that asks for the number of calories and fat grams in a food. The
//  program should display the percentage of calories that come from fat. If the calories
//  from fat are less than 30 percent of the total calories of the food, it should also display
//  a message indicating that the food is low in fat.
//
//  One gram of fat has 9 calories, so
//  Calories from fat = fat grams * 9
//  The percentage of calories from fat can be calculated as
//  Calories from fat / total calories
//
//  Input Validation: Make sure the number of calories and fat grams are not less than 0.
//  Also, the number of calories from fat cannot be greater than the total number of calories.
//  If that happens, display an error message indicating that either the calories or fat grams
//  were incorrectly entered.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    float fltCaloriesTotal,
    fltCaloriesFat,
    fltCaloriesPercentage,
    fltFatGrams;
    
    //Declare % character for use in string later.
    //Can't use % with in-line declaration in a string.
    char const CHAR_MODULUS_CHARACTER = '%';
    
    cout << "Please enter a calorie value\n"
         << "of your serving:\n";
    cin >> fltCaloriesTotal;
    while(!cin || fltCaloriesTotal < 0.0f || fltCaloriesTotal > 10000.0f)
    {
        cout << "Please enter a number between 0 and 10,000 calories:\n";
        cin.clear();
        cin.ignore();
        cin >> fltCaloriesTotal;
    }
    
    cout << "Please enter the number of grams of fat\n"
         << "in your serving:\n";
    cin >> fltFatGrams;
    while(!cin || fltFatGrams < 0.0f || fltFatGrams > 10000.0f)
    {
        cout << "Please enter a number between 0 and 10,000 grams of fat:\n";
        cin.clear();
        cin.ignore();
        cin >> fltFatGrams;
    }
    
    fltCaloriesFat = fltFatGrams * 9.0f;
    
    if(fltCaloriesFat >= fltCaloriesTotal)
    {
        cout << "ERROR THERE ARE MORE FAT CALORIES THAN CALORIES TOTAL\n";
        return 0;
    }
    
    fltCaloriesPercentage = fltCaloriesFat / fltCaloriesTotal;
    
    cout << "The percentage of calories that comes from fat is "
         << (fltCaloriesPercentage * 100.0f)
         << CHAR_MODULUS_CHARACTER << ".\n";
    
    if(fltCaloriesPercentage < 0.30f)
    {
        cout << "This food is low-fat.";
    }
    
    return 0;
}


