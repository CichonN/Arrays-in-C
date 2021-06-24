// ------------------------------------------------------------------------------------------
// Name: Neina Cichon
// Class: Arrays in C
// Date: 2020-11-12
// ------------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

#pragma warning(disable : 4996)

// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// User Defined Types (UDTs)
// --------------------------------------------------------------------------------



// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void MakeArray(int** ppaintValues, int* pintArraySize);
void InitializeArray(int* paintValues, int intArraySize);
void PopulateArray(int* paintValues, int intArraySize);
void PrintArray(int* paintValues, int intArraySize);
int CalculateTotal(int* paintValues, int intArraySize);
int FindMaximum(int* paintValues, int intArraySize);
int FindMinimum(int* paintValues, int intArraySize);
int ArrayAverage(int* paintValues, int intArraySize);
void StandardDeviation(int* paintValues, int intArraySize);
void AddValueToEnd(int** ppaintValues, int* pintArraySize, int intValue);
void AddValueToBeginning(int** ppaintValues, int* pintArraySize, int intValue);
void AddValueToMiddle(int** ppaintValues, int* pintArraySize, int intValue, int intInsertAtIndex);
void RemoveValue(int** ppaintValues, int* pintArraySize, int intRemoveAtIndex);
void MakeArraySmaller(int** ppaintValues, int* pintArraySize, int intRemoveAtIndex);

void DeleteArray(int* paintValues);

void DeleteArray(int* paintValues);

// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts.
// --------------------------------------------------------------------------------
void main()
{
	int intIndex = 0;
	int intArraySize = 0;
	int* paintValues = {0};
	int intResult = 0;
	int intValue = 10;
	int intInsertAtIndex = 3;
	int intRemoveAtIndex = 1;


	MakeArray( &paintValues, &intArraySize);

	InitializeArray(paintValues, intArraySize);

	PopulateArray(paintValues, intArraySize);

	PrintArray(paintValues, intArraySize);

	intResult = CalculateTotal(paintValues, intArraySize);
	printf("Total = %d\n", intResult);
	
	intResult = FindMaximum(paintValues, intArraySize);
	printf("Maximum = %d\n", intResult);

	intResult = FindMinimum(paintValues, intArraySize);
	printf("Minimum = %d\n", intResult);

	intResult = ArrayAverage(paintValues, intArraySize);
	printf("Average = %d\n", intResult);

	StandardDeviation(paintValues, intArraySize);

	AddValueToEnd(&paintValues, &intArraySize, intValue);

	printf("Add Value to end\n");
	PrintArray(paintValues, intArraySize);

	AddValueToBeginning(&paintValues, &intArraySize, intValue);

	printf("Add Value to Beginning\n");
	PrintArray(paintValues, intArraySize);

	AddValueToMiddle(&paintValues, &intArraySize, intValue, intInsertAtIndex);

	printf("Add Value to Middle\n");
	PrintArray(paintValues, intArraySize);

	RemoveValue(&paintValues, &intArraySize, intRemoveAtIndex);
	MakeArraySmaller(&paintValues, &intArraySize, intRemoveAtIndex);

	printf("Remove Value\n");
	PrintArray(paintValues, intArraySize);

	DeleteArray(paintValues);

	system("pause");
}

// --------------------------------------------------------------------------------
// Name: empty_stdin
// Abstract: emptys buffer
// --------------------------------------------------------------------------------

void empty_stdin(void) {
	int unwantedCharacter = getchar();

	while (unwantedCharacter != '\n' && unwantedCharacter != EOF)
		unwantedCharacter = getchar();
}



// --------------------------------------------------------------------------------
// Name: MakeArray
// Abstract: Make Array and allocate an array of integers
// --------------------------------------------------------------------------------

void MakeArray(int** ppaintValues, int* pintArraySize)
{
	while (*pintArraySize < 1 || *pintArraySize > 100000)
	{
		//Create Array Dynamically
		printf("Please enter array size: ");
		scanf("%d", pintArraySize);
		empty_stdin();
	} 

	*ppaintValues = (int*)malloc(sizeof(int) * *pintArraySize);

}


// --------------------------------------------------------------------------------
// Name: InitializeArray
// Abstract: Initialize array
// --------------------------------------------------------------------------------
void InitializeArray(int* paintValues, int intArraySize)
{
	int intIndex = 0;

	//Initialize Array
	for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
	{
		*(paintValues + intIndex) = 0;
	}
}


// --------------------------------------------------------------------------------
// Name: PopulateArray
// Abstract: Populate the array with user entered values
// --------------------------------------------------------------------------------
void PopulateArray(int* paintValues, int intArraySize)
{
	int intIndex = 0;
	int intValidate = 0;

	//Populate Array
	printf("Populate -------------------------\n");
	for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
	{
		do
		{
			printf("Enter value[%d]: ", intIndex);
			intValidate = scanf("%d", (paintValues + intIndex));
			if (intValidate != 1)
			{
				empty_stdin();
			}
			
		} while (intValidate != 1);
	}
	printf("\n");
}


// --------------------------------------------------------------------------------
// Name: PrintArray
// Abstract: Print the array
// --------------------------------------------------------------------------------
void PrintArray(int* paintValues, int intArraySize)
{
	int intIndex = 0; 

	//Print array
	printf("Print -------------------------\n");
	for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
	{
		printf("Value[%d] = %d\n", intIndex, *(paintValues + intIndex));
	}
	printf("\n");
	
}

// --------------------------------------------------------------------------------
// Name: FindMaximum
// Abstract: Find the Maximum of all array values
// --------------------------------------------------------------------------------
int FindMaximum(int* paintValues, int intArraySize)
{
	int intIndex = 0;
	int intMaximum = *(paintValues + 0);

	//Calculate Total
	for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
	{
		if (intMaximum < *(paintValues + intIndex))
		{
			intMaximum = *(paintValues + intIndex);
		}
	}
	return intMaximum;

	//int intIndex = 0;
	//int intMaximum = paintValues[0];

	////Calculate Total
	//for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
	//{
	//	if (paintValues[intIndex] > intMaximum)
	//	{
	//		intMaximum = paintValues[intIndex];
	//	}
	//}
	//printf("Maximum Value = %d\n", intMaximum);
	//printf("\n");
}

// --------------------------------------------------------------------------------
// Name: FindMinimum
// Abstract: Find the Minimum of all array values
// --------------------------------------------------------------------------------
int FindMinimum(int* paintValues, int intArraySize)
{
	int intIndex = 0;
	int intMinimum = paintValues[0];

	//Calculate Total
	for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
	{
		if (intMinimum > *(paintValues + intIndex))
		{
			intMinimum = *(paintValues + intIndex);
		}
	}
	return intMinimum;
}



// --------------------------------------------------------------------------------
// Name: CalculateTotal
// Abstract: Calculate the sum of all array values
// --------------------------------------------------------------------------------
int CalculateTotal(int* paintValues, int intArraySize)
{
	int intIndex = 0;
	int intTotal = 0;

	//Calculate Total
	for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
	{
		intTotal += *(paintValues + intIndex);
	}
	return intTotal;
}

// --------------------------------------------------------------------------------
// Name: ArrayAverage
// Abstract: Calculate average of values in array
// --------------------------------------------------------------------------------
int ArrayAverage(int* paintValues, int intArraySize)
{

	int intTotal = 0;
	int intAverage = 0;

	intTotal = CalculateTotal(paintValues, intArraySize);

	intAverage = intTotal / intArraySize;
	return intAverage;

}

// --------------------------------------------------------------------------------
// Name: StandardDeviation
// Abstract: Calculate Standard Deviation and Print result 
// Get Mean, For each number: Subtract mean and square the result, get the mean of the squared differences, Get square root.
// 
// --------------------------------------------------------------------------------
void StandardDeviation(int* paintValues, int intArraySize)
{
	long lngTotal = 0;
	float flMean = 0;
	float flStandardDeviation = 0;
	long lngIndex = 0;
	float flStandardDeviationResult = 0;

	// Get Total
	for (lngIndex = 0; lngIndex < intArraySize; lngIndex += 1)
	{
		lngTotal += paintValues[lngIndex];
	}

	// Get Mean
	flMean = lngTotal / intArraySize;

	// For each number: Subtract mean and square the result
	for (lngIndex = 0; lngIndex < intArraySize; lngIndex += 1)
	{
		flStandardDeviation += pow(paintValues[lngIndex] - flMean, 2);
	}

	// Get the mean of the squared differences and square root the result
	flStandardDeviationResult = sqrt(flStandardDeviation / intArraySize);

	printf("Standard Deviation = %f\n", flStandardDeviationResult);
	printf("\n");
}

// --------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: Make array bigger and Add Value To End
// --------------------------------------------------------------------------------
void AddValueToEnd(int** ppaintValues, int* pintArraySize, int intValue)
{

	int intNewSize = 0;
	int* paintNewValues = 0;
	int intIndex = 0;

	//Allocate block of memory + 1
	intNewSize = *pintArraySize + 1;
	paintNewValues = (int*)malloc(sizeof(int) * intNewSize);

	//Copy all values from old array into new array
	for (intIndex = 0; intIndex < *pintArraySize; intIndex += 1)
	{
		*(paintNewValues + intIndex) = *(*ppaintValues + intIndex);
	}

	//Set the last array element Value
	*(paintNewValues + intIndex) = intValue;

	//Delete old array
	free(*ppaintValues);
	*ppaintValues = 0;

	//Assign pointer to new array to variable passed in
	*ppaintValues = paintNewValues;
	*pintArraySize += 1;

	//int pintNewArraySize = *pintArraySize + 1;
	//int *intNewArray = (int*)realloc(*ppaintValues, pintNewArraySize * sizeof(int));
	////int intNewArraySize = *pintArraySize + 1;

	//printf("Add %d to the end of the array\n", intValue);

	//*(intNewArray + pintNewArraySize-1) = intValue;
}


// --------------------------------------------------------------------------------
// Name: AddValueToBeginning
// Abstract:  Make array bigger and Add Value to the end of the Array
// --------------------------------------------------------------------------------
void AddValueToBeginning(int** ppaintValues, int* pintArraySize, int intValue)
{	
	int intNewSize = 0;
	int* paintNewValues = 0;
	int intIndex = 0;

	//Allocate block of memory + 1
	intNewSize = *pintArraySize + 1;
	paintNewValues = (int*)malloc(sizeof(int) * intNewSize);

	//Set the first array element Value
	*(paintNewValues + 0) = intValue;

	//Copy all values from old array into new array
	for (intIndex = 0; intIndex < *pintArraySize; intIndex += 1)
	{
		*(paintNewValues + intIndex + 1) = *(*ppaintValues + intIndex);
	}

	//Delete old array
	free(*ppaintValues);
	*ppaintValues = 0;

	//Assign pointer to new array to variable passed in
	*ppaintValues = paintNewValues;
	*pintArraySize += 1;
}


// --------------------------------------------------------------------------------
// Name: AddValueToMiddle
// Abstract:  Make array bigger and Add Value to the end of the Array
// --------------------------------------------------------------------------------
void AddValueToMiddle(int** ppaintValues, int* pintArraySize, int intValue, int intInsertAtIndex)
{
	int intNewSize = 0;
	int* paintNewValues = 0;
	int intIndex = 0;


	//Boundary Check
	if (intInsertAtIndex < 0) intInsertAtIndex = 0;
	if (intInsertAtIndex > *pintArraySize) intInsertAtIndex = *pintArraySize;

	//Allocate block of memory + 1
	intNewSize = *pintArraySize + 1;
	paintNewValues = (int*)malloc(sizeof(int) * intNewSize);

	//Copy 1st half
	for (intIndex = 0; intIndex < intInsertAtIndex; intIndex += 1)
	{
		*(paintNewValues + intIndex) = *(*ppaintValues + intIndex);
	}

	//Insert value
	*(paintNewValues + intInsertAtIndex) = intValue;

	//Copy 2nd half
	for (intIndex = intInsertAtIndex; intIndex < *pintArraySize; intIndex += 1)
	{
		*(paintNewValues + intIndex + 1) = *(*ppaintValues + intIndex);
	}

	//Delete old array
	free(*ppaintValues);
	*ppaintValues = 0;

	//Assign pointer to new array to variable passed in
	*ppaintValues = paintNewValues;
	*pintArraySize += 1;

}


// --------------------------------------------------------------------------------
// Name: RemoveValue
// Abstract:  Remove Value From Array
// --------------------------------------------------------------------------------
void RemoveValue(int** ppaintValues, int* pintArraySize, int intRemoveAtIndex)
{
	int intNewSize = 0;
	int* paintNewValues = 0;
	int intIndex = 0;

	
	if (*pintArraySize > 0)
	{
		//Boundary Check
		if (intRemoveAtIndex < 0) intRemoveAtIndex = 0;
		if (intRemoveAtIndex > * pintArraySize - 1) intRemoveAtIndex = *pintArraySize - 1;

		//Allocate block of memory - 1
		intNewSize = *pintArraySize - 1;
		paintNewValues = (int*)malloc(sizeof(int) * intNewSize);

		//Copy 1st half
		for (intIndex = 0; intIndex < intRemoveAtIndex; intIndex += 1)
		{
			*(paintNewValues + intIndex) = *(*ppaintValues + intIndex);
		}


		//Copy 2nd half
		for (intIndex = intRemoveAtIndex + 1; intIndex < *pintArraySize; intIndex += 1)
		{
			*(paintNewValues + intIndex - 1) = *(*ppaintValues + intIndex);
		}

		//Delete old array
		free(*ppaintValues);
		*ppaintValues = 0;

		//Assign pointer to new array to variable passed in
		*ppaintValues = paintNewValues;
		*pintArraySize -= 1;
	}

	//int intIndex = 0;
	//int intArraySize = *pintArraySize;

	//printf("Remove number from the array at Index %d\n", intRemoveAtIndex);
	//for (intIndex = intRemoveAtIndex; intIndex < intArraySize; intIndex += 1)
	//{
	//	*(*ppaintValues + intIndex) = *(*ppaintValues + intIndex + 1);
	//}
	//*(*ppaintValues + intArraySize) = 0;
}

// --------------------------------------------------------------------------------
// Name: MakeArraySmaller
// Abstract:  Make Array Smaller
// --------------------------------------------------------------------------------
void MakeArraySmaller(int** ppaintValues, int* pintArraySize, int intRemoveAtIndex)
{
	int* intNewArray = (int*)realloc(*ppaintValues, *pintArraySize * sizeof(int));
	//array_type* tmp = realloc(array, (array_length - 1) * sizeof(array_type));
	if (intNewArray == NULL && pintArraySize > 1) 
	{
		/* No memory available */
		exit(EXIT_FAILURE);
	}
	pintArraySize = pintArraySize - 1;
	*ppaintValues = intNewArray;
}
// --------------------------------------------------------------------------------
// Name: DeleteArray
// Abstract: Calculate the sum of all array values
// --------------------------------------------------------------------------------
void DeleteArray(int* paintValues)
{
	//Delete array
	free(paintValues);
	paintValues = 0;
}