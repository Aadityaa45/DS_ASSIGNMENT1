#include<iostream>  //including the header 
using namespace std;
// creating a function to findout the maxvalue, this function takes the aaray and its size as a argument
int MAXVALUE(int arr[],int size){
    int biggest = arr[0];  //initialising the very first value of array into the biigest variable
    for(int i=0;i<size;i++){  //iterating till the last index element of a array using for loop 
        if(arr[i]>biggest){  //here checking that if the the value at i index of array is greter then the value in biggest variable 
            biggest=arr[i]; //assigning the value to the biggest variable
        }
    }
    return biggest;  //after the complition of code we are returning the the value of biggest variable which contains the max value of array.
}

// created a function to find the min value from a given array 
int MINVALUE(int arr[],int size){
    int smallest = 999999999;
    /* here we have initialised the smallest value to the largest value that an integer data type can hold because
    if we initialise it with the very first value of array like arr[0] and if the value of arr[0] will be 0 then the below condition can
    not be checked as 0 is not greater then zero and any positive number can not be smaller than zero. and similarly we 
    cant initialise it with -1 also because everytime we compute reminder with -1 ultimately it will give 0
    */
    for(int i=0;i<size;i++){
        if (arr[i] > 0 && arr[i] < smallest) {  // greater than 0 condition is checked because we dont want to compute 0 as a  minimum value
            smallest = arr[i];
        }
    }
    return smallest;  // returning the value of smallest variable
}

// here the function is declared to to check that the all the elements in the array are zero or not and we have given the ereturn type of boolean as we can get the result in true false
bool AllZero(int arr[],int size){  // this will take the array and size of array as a parameter
    for(int i=0;i<size;i++){
        if(arr[i]!=0){
            return false;
        }
    }
    return true;
}

// main function 
int main(){
    int Array_Size;  //declaring a variable to store the size of the array according to user inputs 
    while (true) { // Infinite loop to keep asking until valid input
        cout << "\t\t\t\t\t\t\t\tEnter the size of the array (Only positive value): ";  
        cin >> Array_Size;
        cout<<"\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    // checking the conditions with the try and catch functionality that the size of array can not be negative or zero 
        try {
            if (Array_Size <= 0) {
                throw invalid_argument("The size of the array cannot be negative or 0.");
            }
            break; 
        }
        catch (const invalid_argument& e) {
            cout << "\t\t\t\t\t\tException caught: " << e.what() << endl;
            cout << "\t\t\t\t\t\tPlease try again.\n";
            cout<<"\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        }
    }
    //-------------------------------------------------------------ARRAY ELEMENT INPUTS ------------------------------------------------------------------------
    int NUMARRAY[Array_Size];  // declaring the array according to the size given by user
    for(int i=0;i<Array_Size;i++){  // iterating over a loop to get input for the array elements from the user
        cout<<"Enter the value of position "<<i+1<<":-";
        cin>>NUMARRAY[i];
    }
    //----------------------------------------------------------------------------------------------------------------------------------------

    cout<<"\n---------------------------------------------"<<endl;

    //---------------------------------------------------------------ARRAY ELEMNTS DISPLAY---------------------------------------------------------
    //printing the values of the array to showcase what the user have enterred 
    cout<<"You entered The values in array are:-"<<endl;
    for(int j=0;j<Array_Size;j++){
        cout<<NUMARRAY[j]<<"     ";
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------
    cout<<"\n---------------------------------------------"<<endl;

    int iteration=0;  //declared a varibale to count the iterations and initiales it with 0

    // while loop that executes until the every element doesnt become 0 inside the array
    while(!AllZero(NUMARRAY,Array_Size)){  //passsing the zero checking function with arguments inside the loop condition 
        int Max = MAXVALUE(NUMARRAY,Array_Size);  // storing the value returned by the MAXVALUE() in the Max variable
        int Min = MINVALUE(NUMARRAY,Array_Size);  //stoing the value returned by MINVALUE() in the Min variable
        int reminder = Max%Min;  //storing the value of modulud in reminder variable 
        for(int k=0;k<Array_Size;k++){  //iterating over the array 
            if(NUMARRAY[k]==Max){ //in order to found the maximum value array 
                NUMARRAY[k]=reminder; //once it is found we update the highest value by assigning the reminder value to it 
                break;  // breaking the loop because in the case of duplicate values it only update the value which comes first 
            }
        }
        iteration=iteration+1;  // incrementing the iteration count by one after every iteration
        cout<<"\nIteration count is:"<<iteration<<endl;  // printing the iteartion count at every step 
        cout<<"After "<<iteration <<" iteration the array is:"<<endl;  // displaying the updated array after every iteration
        for(int i=0;i<Array_Size;i++){
            cout<<NUMARRAY[i]<<" ";
        }
        cout<<"\n---------------------------------------------"<<endl;
    }
    cout<<"It takes "<<iteration<< " iterations overall to accomplish the task";

}

