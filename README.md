**Project 1**

Problem Statement:

The task was to create two clocks that meets the international standard ISO 8601. One in 12hr format and the other in 24hr format rather than just the standard 12-hour clock. These two clocks are able to be displayed on a website.

-------------------------------------------------------------------------------------------------------------------------------

Functional Requirements:

The 12hr Clock: The time is displayed in 12-hour format where the clock doesn't exceed 12:59:59
The 24hr Clock: The time is displayed in 24-hour format where the clock doesn't exceed 23:59:59
Both of the clocks are displayed on the screen at the same time with the current time in the proper format.

There is a menu option that displayes to allow the user to interact with the program.
1 - Add One Hour
2 - Add One Minute
3 - Add One Second
4 - Exit Program

Once the user enters their choice, the program takes the appropriate action based on that choice.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Project 2**

Summary: 

This project was to create an application that would allow users to see how their investments
will grow over time. It was meant to allow users to visualize their investmants. 

The problem I was solving with this project was allowing people to get a prediction on the growth of their 
investments. It gives them a tool that they can use and can give them the ability to make informed decisions with 
contributing to their investments, 401k, or other retirement fund.

--------------------------------------------------------------------------------------------------------------------------------------------------------------

What I did particularly well:

I would say one of the things I did well is making the Investment class a more organized structure. This helps to make the
code easy to read and understand for others that want to build upon it. I also think the interface is done well as it allows
the user a clear and easy to follow UI making it easy to complete the program successfully. I think the final output is done well
too because it outputs both simulations for recurring monthly deposits and without.

--------------------------------------------------------------------------------------------------------------------------------------------------------------

Where could I enhance the code:

I think there are a a few areas for improvements and enhancements. The first is adding in some form of input validation.
Validating the user input would make it much better and would help to prevent runtime errors. Refactoring the repeated code would 
also be a good enhancement. Adding helper functions would get rid of some redundant code. Also taking into account large numbers and 
altering the code for this would also enhance it as it would help resolve any potential overflows. Also adding more of an industry standard comment format 
I think would enhance the code as well, this way it's a bit easier for others to understand a bit better what the code is doing.

--------------------------------------------------------------------------------------------------------------------------------------------------------------

Which pieces of the code did you find most challenging to write:

There were a couple areas that were a bit difficult. The first was the format of the reports. 
The setw and setprecision parts took some tweaking to get setup how I needed and wanted them to look. 
Also, the loops for the monthly deposits took a bit longer than I anticipated as I kept putting parts in the wrong spot. 
Thankfully, Stack Overflow is a thing and just about every issue I had or question I needed to find an answer to, there was already an answer on there. 
That has been my go to for almost all of my help, other than some YouTube videos and tutorials. Those two are my top tools when I am stuck or need help 
as they usually have the answers I'm looking for.

--------------------------------------------------------------------------------------------------------------------------------------------------------------

What skills from this project will be transferable to other projects or course work:
The first skill would be Object-Oriented Programming. This was something I feel this project helped me get better with. 
With that being such an important part of programming, I think it will be the most useful with future projects and courses. 
User input and handling is another skill that I was able to build upon with this project. This will be especially useful for 
future projects as it will help me have knowledge on user-friendly applications specifically for web or mobile projects.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Project 3**

Problem Statement:
The task was to build an item-tracking program. The program needs to analyze text records a company generates throughout the day. These records list items purchased in chronological order from the time the store opens to the time it closes. The company is interested in rearranging their produce section and need to know how often items are purchased so they can create the most effective layout for their customers.

--------------------------------------------------------------------------------------------------------------------------------

Requirements:
The program needed the following functional requirements:

Menu Option One:
1. Prompt a user to input the item, or word, they wish to look for.
2. Return a numeric value for the frequency of the specific word.

Menu Option Two:
1. Print the list with numbers that represent the frequency of all items purchased.
   EX: Potatoes 4
       Pumpkins 5
       Onions 3

Menu Option Three:
1. Print the same frequency information for all the items in the form of a histogram.
2. Then print the name, followed by asterisks or another special character to represent the numeric amount.
   Ex: Potatoes ****
       Pumpkins *****
       Onions ***

Menu Option Four:
1. Exit the program.

The program needed to create a data file with the naming convention frequency.dat, for backing up the accumulated data. The frequency.dat file needed to include every item paired with the number of times that item appeared in the input file.


It also required documentation to describe the code's design and functionality with included screenshots to support the description.

