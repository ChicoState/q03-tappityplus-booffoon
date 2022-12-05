#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  //set ref to given refernce and inp to empty string
  ref = reference;
  inp = "";
}

//Provide the input to be compared to the reference. Before this
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  //set inp to user entered input
  inp = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  int difference = ref.length() - inp.length();
  difference = abs(difference);
  return difference;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{

  //track how many characters amtch
  double match = 0;
  //iterate through length of longest string to find how many characters match
  std::string longer = "";
  if(ref.length() > inp.length())
  {
    longer = "ref";
    for(int i = 0; i < ref.length(); i ++)
    {
      if(ref[i] == inp[i])
          match++;
    }
  }
  else
  {
    longer = "inp";
    for(int i = 0; i < inp.length(); i ++)
    {
      if(ref[i] == inp[i])
          match++;
    }
  }

  double matchPercent = 0.0;

  if(ref.length() == 0 && inp.length() == 0) //if both strings are empty it is a 100% match
  {
    matchPercent = 100;
  }
  else if(longer == "ref") //if ref is longer find the percentage match out of ref
  {
    matchPercent = match/ref.length();
    matchPercent = matchPercent * 100;
  }
  else if(longer == "inp") //if inp is longer find the percentage match out of inp
  {
    matchPercent = match/inp.length();
    matchPercent = matchPercent * 100;
  }

  //return final percentage
  return matchPercent;
}
