#Machine Assignment 2
> This program simulates approximating the derivative of sin(x) where x = 1
> In the resources directory the graph of the results can be found. This graph was created from running the program from the calculations.csv file. 


#Questions
##Is there a minimum value for the magnitude of the error? 
On my machine that number was 2^-28-2^-27 where both equal 0.000000000545511,
note this is much smaller than the percision of 8 that is displayed during the program. 

###If such a value exists, how does it compare to √eps?
if the square root of eps is normally around 16 than it was much smaller than 2^-16

##Diagrams
Under the resources directory there is a diagram of the experiment, with x and y axis both set to logarithmic scales of base 2. 


## Setup 
-Untar package.
-make 
### To Run
-./ApproximateDerivative 


#Author 
-Raphael J. Sandor  
