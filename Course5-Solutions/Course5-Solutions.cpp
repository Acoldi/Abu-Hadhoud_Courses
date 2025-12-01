#include <iostream>
#include <iomanip>
#include <string>

#include "IsPrime.h"
#include "IsPerfectNumber.h"
#include "PrintReversedNumber.h"
#include "SumOfDigits.h"
#include "ReverseNumber.h"
#include "FindDigitFrequency.h"
#include "PrintAllFrequenciesOfAllDigits.h"
#include "PrintNumberDigits.h"
#include "IsPalindrome.h"
#include "PrintInvertedPattern.h"
#include "PrintNumberPattern.h"
#include "PrintInvertedLetterPattern.h"
#include "PrintLetterPattern.h"
#include "PrintAAAtoZZZ.h"
#include "FindPassword.h"
#include "EncryptDecrypt.h"
#include "RandomNumber.h"
#include "KeyGenerator.h"
#include "ReadPositiveNum.h"
#include "FindFrequencyInArray.h"
#include "FillArrayWithRandomNumbers.h"
#include "MaxMinInArray.h"
#include "SumAndAvgOfArray.h"
#include "CopyPrimeNumbersOfArray.h"
#include "SumArray.h"
#include "Swap.h"
#include "ShuffleArray.h"
#include "ReverseArray.h"
#include "GenerateKeysInArray.h"
#include "FindNumberInArray.h"
#include "IsNumberInArray.h"
#include "AddArrayElement.h"
#include "AddArrayElements.h"
#include "CheckNumberType.h"
#include "CopyArrayUsingAddArrayElement.h"
#include "CopyOddArraysElementsToAnotherOne.h"
#include "CopyPrimeNumbersArraysToAnotherOne.h"
#include "CopyDistinctArrayNumbers.h"
#include "IsArrayPalindrome.h"
#include "CountOddNumbersInArray.h"
#include "CountEvenNumbersInArray.h"
#include "CountPositiveNumbersInArray.h"
#include "CountNegativeNumbersInArray.h"
#include "MyAbs.h"
#include "GetFractionPart.h"
#include "MyRound.h"
#include "MyFloor.h"
#include "MyCeil.h"


using namespace std;

int main()
{
    // Old calls, keeping them commented as they were
    //PrintMultiplicationTable();
	// 
	//PrintPrimeNumbersTo(20);

	//PrintPerfectNumber();
	
	//FindPassword("BBC");

    // Calls for newly created headers

    // IsPrime.h
    // PrintPrimeNumbersTo(ReadPositiveNum("Enter a number to print primes up to"));

    // IsPerfectNumber.h
    // if (IsPerfectNumber(ReadPositiveNum("Enter a number to check if perfect")))
    //     cout << "PERFECT number\n";
    // else
    //     cout << "IMPERFECT number\n";

    // PrintPerfectNumbers.h
    // PrintPerfectNumbersTo(ReadPositiveNum("Enter a number to print perfect numbers up to"));

    // PrintReversedNumber.h
    // PrintReversedNumber(ReadPositiveNum("Enter a number to print reversed digits"));

    // SumOfDigits.h
    // int num_sum = ReadPositiveNum("Enter a positive number to sum its digits");
    // cout << "The sum of the number " << num_sum << " digits is " << SumOfDigits(num_sum) << endl;

    // ReverseNumber.h
    // cout << ReverseNumber(ReadPositiveNum("Enter a positive number to reverse")) << endl;

    // FindDigitFrequency.h
    // cout << TimesRepeated(ReadPositiveNum("Enter The digit you want to find its frequency in that number"), new int[]{123456789, 111222333, 444555666}, 3) << endl; // Example call, needs actual array

    // PrintAllFrequenciesOfAllDigits.h
    // PrintAllFrequenciesOfAllDigits(ReadPositiveNum("Enter a number to print all digit frequencies"));

    // PrintNumberDigits.h
    // PrintNumberDigits(ReverseNumber(ReadPositiveNum("Enter a number to print its digits")));

    // IsPalindrome.h
    // int palindrome_num = ReadPositiveNum("Enter a number to check if palindrome");
    // if (IsPalindrome(palindrome_num))
    //     cout << "The number " << palindrome_num << " is a palindrome number\n";
    // else
    //     cout << "The number " << palindrome_num << " is not a palindrome number\n";

    // PrintInvertedPattern.h
    // PrintInvertedPattern(ReadPositiveNum("Enter a number for inverted pattern"));

    // PrintNumberPattern.h
    // PrintNumberPattern(ReadPositiveNum("Enter a number for number pattern"));

    // PrintInvertedLetterPattern.h
    // PrintInvertedLetterPattern(ReadPositiveNum("Enter a number for inverted letter pattern (e.g., 5 for EEE, DDD...)"));

    // PrintLetterPattern.h
    // PrintLetterPattern(ReadPositiveNum("Enter a number for letter pattern (e.g., 5 for A, BB, CCC...)"));

    // PrintAAAtoZZZ.h
    // PrintAAAtoZZZ();

    // FindPassword.h
    // FindPassword("ABC");

    // EncryptDecrypt.h
    // const short Key = 2;
    // string name_str = ReadString("Enter your name to decrypt it: ");
    // string encrypted_str = Encrypt(Key, name_str);
    // string decrypted_str = Decrypt(Key, encrypted_str);
    // cout << "your name after encription: " << encrypted_str << endl;
    // cout << "your name after decription: " << decrypted_str << endl;

    // RandomNumber.h (utility, used by others)
    // cout << randomNumber(1, 10) << endl;

    // KeyGenerator.h
    // GenerateKeys(ReadPositiveNum("Enter number of keys to generate"));

    // FindFrequencyInArray.h
    // int arr_freq[100];
    // int arr_len_freq = 0;
    // ReadArrayOfInt(arr_len_freq, arr_freq);
    // cout << "Times repeated: " << TimesRepeated(ReadPositiveNum("Enter element to find frequency:"), arr_freq, arr_len_freq) << endl;

    // FillArrayWithRandomNumbers.h
    // int arr_rand[100];
    // int arr_rand_len = 0;
    // FillArrayWithRandomNumbers(arr_rand_len, arr_rand);
    // cout << "Random array: ";
    // PrintArray(arr_rand_len, arr_rand);
    // cout << endl;

    // MaxMinInArray.h
    // int arr_max_min[100];
    // int arr_max_min_len = 0;
    // FillArrayWithRandomNumbers(arr_max_min_len, arr_max_min);
    // cout << "Array: "; PrintArray(arr_max_min_len, arr_max_min); cout << endl;
    // cout << "Max: " << MaxInArray(arr_max_min, arr_max_min_len) << endl;
    // cout << "Min: " << MinInArray(arr_max_min, arr_max_min_len) << endl;

    // SumAndAvgOfArray.h
    // int arr_sum_avg[100];
    // int arr_sum_avg_len = 0;
    // FillArrayWithRandomNumbers(arr_sum_avg_len, arr_sum_avg);
    // cout << "Array: "; PrintArray(arr_sum_avg_len, arr_sum_avg); cout << endl;
    // cout << "Sum: " << SumArrayValue(arr_sum_avg_len, arr_sum_avg) << endl;
    // cout << "Avg: " << AvgOfArray(arr_sum_avg_len, arr_sum_avg) << endl;

    // CopyPrimeNumbersOfArray.h
    // int arr_prime_src[100], arr_prime_dest[100];
    // int arr_prime_src_len = 0, arr_prime_dest_len = 0;
    // FillArrayWithRandomNumbers(arr_prime_src_len, arr_prime_src);
    // CopyPrimrNumbersOfArray(arr_prime_src_len, arr_prime_dest_len, arr_prime_src, arr_prime_dest);
    // cout << "Original Array: "; PrintArray(arr_prime_src_len, arr_prime_src); cout << endl;
    // cout << "Prime Numbers Array: "; PrintArray(arr_prime_dest_len, arr_prime_dest); cout << endl;

    // SumArray.h
    // int arr_sum1[100], arr_sum2[100], arr_sum_res[100];
    // int arr_sum_len = ReadPositiveNum("Enter length for sum arrays");
    // FillArrayWithRandomNumbers(arr_sum_len, arr_sum1);
    // FillArrayWithRandomNumbers(arr_sum_len, arr_sum2);
    // SumArray(arr_sum1, arr_sum2, arr_sum_res, arr_sum_len);
    // cout << "Array 1: "; PrintArray(arr_sum_len, arr_sum1); cout << endl;
    // cout << "Array 2: "; PrintArray(arr_sum_len, arr_sum2); cout << endl;
    // cout << "Sum Array: "; PrintArray(arr_sum_len, arr_sum_res); cout << endl;

    // ShuffleArray.h
    // int arr_shuffle[100];
    // int arr_shuffle_len = ReadPositiveNum("Enter length for shuffle array");
    // FillArrayWithRandomNumbers(arr_shuffle_len, arr_shuffle);
    // cout << "Original Array: "; PrintArray(arr_shuffle_len, arr_shuffle); cout << endl;
    // ShuffleArrayElements(arr_shuffle_len, arr_shuffle);
    // cout << "Shuffled Array: "; PrintArray(arr_shuffle_len, arr_shuffle); cout << endl;

    // ReverseArray.h
    // int arr_rev_src[100], arr_rev_dest[100];
    // int arr_rev_len = ReadPositiveNum("Enter length for reverse array");
    // FillArrayWithRandomNumbers(arr_rev_len, arr_rev_src);
    // ReverseArray(arr_rev_len, arr_rev_src, arr_rev_dest);
    // cout << "Original Array: "; PrintArray(arr_rev_len, arr_rev_src); cout << endl;
    // cout << "Reversed Array: "; PrintArray(arr_rev_len, arr_rev_dest); cout << endl;

    // GenerateKeysInArray.h
    // string keys_arr[10];
    // int keys_len = 5; // Example length
    // GenerateKeysInArray(keys_len, keys_arr);
    // for(int i=0; i<keys_len; ++i) cout << "Key " << i+1 << ": " << keys_arr[i] << endl;

    // FindNumberInArray.h
    // int arr_find_num[100];
    // int arr_find_num_len = ReadPositiveNum("Enter length for find number array");
    // FillArrayWithRandomNumbers(arr_find_num_len, arr_find_num);
    // int num_to_find = ReadPositiveNum("Enter number to find");
    // int found_index = FindNumberInArray(num_to_find, arr_find_num_len, arr_find_num);
    // if (found_index != -1) cout << "Number found at index: " << found_index << endl;
    // else cout << "Number not found" << endl;

    // IsNumberInArray.h
    // int arr_is_num[100];
    // int arr_is_num_len = ReadPositiveNum("Enter length for is number in array");
    // FillArrayWithRandomNumbers(arr_is_num_len, arr_is_num);
    // int num_to_check = ReadPositiveNum("Enter number to check");
    // if (IsNumberInArray(num_to_check, arr_is_num, arr_is_num_len)) cout << "Number is in array" << endl;
    // else cout << "Number is not in array" << endl;

    // AddArrayElements.h
    // int arr_add_elements[100];
    // int arr_add_elements_len = 0;
    // AddArrayElements(arr_add_elements_len, arr_add_elements);
    // cout << "Array with added elements: "; PrintArray(arr_add_elements_len, arr_add_elements); cout << endl;

    // CopyArrayUsingAddArrayElement.h
    // int arr_copy_src[100], arr_copy_dest[100];
    // int arr_copy_src_len = ReadPositiveNum("Enter length for copy array source");
    // int arr_copy_dest_len = 0;
    // FillArrayWithRandomNumbers(arr_copy_src_len, arr_copy_src);
    // CopyArrayUsingAddArrayElement(arr_copy_src_len, arr_copy_dest_len, arr_copy_src, arr_copy_dest);
    // cout << "Original Array: "; PrintArray(arr_copy_src_len, arr_copy_src); cout << endl;
    // cout << "Copied Array: "; PrintArray(arr_copy_dest_len, arr_copy_dest); cout << endl;

    // CopyOddArraysElementsToAnotherOne.h
    // int arr_odd_src[100], arr_odd_dest[100];
    // int arr_odd_src_len = ReadPositiveNum("Enter length for odd array source");
    // int arr_odd_dest_len = 0;
    // FillArrayWithRandomNumbers(arr_odd_src_len, arr_odd_src);
    // CopyOddArraysElementsToAnotherOne(arr_odd_src_len, arr_odd_dest_len, arr_odd_src, arr_odd_dest);
    // cout << "Original Array: "; PrintArray(arr_odd_src_len, arr_odd_src); cout << endl;
    // cout << "Odd Numbers Array: "; PrintArray(arr_odd_dest_len, arr_odd_dest); cout << endl;

    // CopyPrimeNumbersArraysToAnotherOne.h
    // int arr_prime_copy_src[100], arr_prime_copy_dest[100];
    // int arr_prime_copy_src_len = ReadPositiveNum("Enter length for prime array source");
    // int arr_prime_copy_dest_len = 0;
    // FillArrayWithRandomNumbers(arr_prime_copy_src_len, arr_prime_copy_src);
    // CopyPrimeNumbersArraysToAnotherOne(arr_prime_copy_src_len, arr_prime_copy_dest_len, arr_prime_copy_src, arr_prime_copy_dest);
    // cout << "Original Array: "; PrintArray(arr_prime_copy_src_len, arr_prime_copy_src); cout << endl;
    // cout << "Prime Numbers Array: "; PrintArray(arr_prime_copy_dest_len, arr_prime_copy_dest); cout << endl;

    // CopyDistinctArrayNumbers.h
    // int arr_distinct_src[100], arr_distinct_dest[100];
    // int arr_distinct_src_len = 0, arr_distinct_dest_len = 0;
    // FillArrayWithRandomNumbers(arr_distinct_src_len, arr_distinct_src); // Note: This will generate random numbers which might not show distinctness well without sorting
    // CopyDistinctArrayNumbers(arr_distinct_src_len, arr_distinct_dest_len, arr_distinct_src, arr_distinct_dest);
    // cout << "Original Array: "; PrintArray(arr_distinct_src_len, arr_distinct_src); cout << endl;
    // cout << "Distinct Numbers Array: "; PrintArray(arr_distinct_dest_len, arr_distinct_dest); cout << endl;

    // IsArrayPalindrome.h
    // int arr_pal_src[100];
    // int arr_pal_len = ReadPositiveNum("Enter length for palindrome array");
    // FillArrayWithRandomNumbers(arr_pal_len, arr_pal_src);
    // cout << "Array: "; PrintArray(arr_pal_len, arr_pal_src); cout << endl;
    // if (IsArrayPalindrome(arr_pal_len, arr_pal_src)) cout << "Array is a palindrome" << endl;
    // else cout << "Array is not a palindrome" << endl;

    // CountOddNumbersInArray.h
    // int arr_count_odd[100];
    // int arr_count_len = ReadPositiveNum("Enter length for array to count odds");
    // FillArrayWithRandomNumbers(arr_count_len, arr_count_odd);
    // cout << "Array: "; PrintArray(arr_count_len, arr_count_odd); cout << endl;
    // cout << "Odd numbers count: " << CountOfOddNumbersInArray(arr_count_len, arr_count_odd) << endl;

    // CountEvenNumbersInArray.h
    // int arr_count_even[100];
    // int arr_count_even_len = ReadPositiveNum("Enter length for array to count evens");
    // FillArrayWithRandomNumbers(arr_count_even_len, arr_count_even);
    // cout << "Array: "; PrintArray(arr_count_even_len, arr_count_even); cout << endl;
    // cout << "Even numbers count: " << CountOfEvenNumbersInArray(arr_count_even_len, arr_count_even) << endl;

    // CountPositiveNumbersInArray.h
    // int arr_count_pos[100];
    // int arr_count_pos_len = ReadPositiveNum("Enter length for array to count positives");
    // FillArrayWithRandomNumbers(arr_count_pos_len, arr_count_pos);
    // cout << "Array: "; PrintArray(arr_count_pos_len, arr_count_pos); cout << endl;
    // cout << "Positive numbers count: " << CountOfPositiveNumbersInArray(arr_count_pos_len, arr_count_pos) << endl;

    // CountNegativeNumbersInArray.h
    // int arr_count_neg[100];
    // int arr_count_neg_len = ReadPositiveNum("Enter length for array to count negatives");
    // FillArrayWithRandomNumbers(arr_count_neg_len, arr_count_neg);
    // cout << "Array: "; PrintArray(arr_count_neg_len, arr_count_neg); cout << endl;
    // cout << "Negative numbers count: " << CountOfNegativeNumbersInArray(arr_count_neg_len, arr_count_neg) << endl;

    // MyAbs.h
    // float abs_num = -12.5f;
    // cout << "MyAbs(" << abs_num << "): " << MyAbs(abs_num) << endl;

    // MyRound.h
    // float round_num = 12.5f;
    // cout << "MyRound(" << round_num << "): " << MyRound(round_num) << endl;

    // MyFloor.h
     //float floor_num = 12.7f;
     //cout << "MyFloor(" << floor_num << "): " << MyFloor(floor_num) << endl;

     //MyCeil.h
     /*float ceil_num = 12.1;
     cout << "MyCeil(" << ceil_num << "): " << MyCeil(ceil_num) << endl;
     cout << "MyCeil(-12.9f): " << MyCeil(-12.9f) << endl;
     cout << "MyCeil(12.0f): " << MyCeil(12.0f) << endl;*/
	
	/*float ceil_num_final = ReadPositiveNum("Enter a float number to demonstrate MyCeil: ");
	cout << "MyCeil(" << ceil_num_final << "): " << MyCeil(ceil_num_final) << endl;
	cout << "c++ ceil result: " << ceil(ceil_num_final) << endl;*/
}