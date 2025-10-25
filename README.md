# word-game-(Cpp)-(oop concepts)
MOTIVATION:  This is a minor project built to properly use the basic oops concept and file handling concepts in C++. I was also trying to add another game option of quiz, that i will soon commit to this very repo.

THE GAME:  The game is that, you are provided with a scrambled word and you guess the actual word to earn points. You may also loose points for each wrong guess (points may go negative); you can view your points and highest score; or exit as well. It uses simple and basic concepts of array, conditional statements and file handling. The modularity, logic and naming of functions are also very simple to understand. 

WORKING:  There is a .txt file that has 100 different words in it. In the code, I accesed that text file and kept all those words in an array. Now the index[0-99] of that array is suffled using rand() function; this also makes sure that no words are repeated. I used srand(time(0)); as seed for rand(). The input word is compared with the original ones to check if the answer is right or wrong to add or deduct the points. The points are then sent to another .txt file; I also extracted the highest point from this txt file. 
