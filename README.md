# bairesdev
Source code for exercises of BairesDev recruitment process.

Developed using C++ and Qt 5.6 msvc2013 x86. 
IDE used: Visual Studio 2013.
Operating Systems tested: Windows 10 x64, Windows 7 x64, with 32 bit binaries.

Solution description:

Why reinvent the wheel if there are excellent query tools available?

Theoretically, the best solution scheme for this exercise is a ponderation equation. Details can be explained in technical interview.

I used a SQLite in-memory database and just designed a basic query for fetching the info, limiting results to 30.
First I parsed .txt file using Regex, altough I could just use a simple split, I love regex.

Later, I build the database and just start doing queries.

The gui code is just boilerplate.

For the main logic, look at https://github.com/jslopezvi/bairesdev/blob/master/BairesDevPotentialCustomerSearch/BairesDevPotentialCustomerSearch/potentialsearch.cpp





