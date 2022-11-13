## 1. Part 1 + Part 2: 40 points
+ correct function signatures (e.g., correct inputs)
```=+10```
+ returns the right arguments (rhs! returns nothing, solve returns at least 2 arguments)
```=+10```
+ proper use of “method.u_tmp” in “solve”
```=+10```
+ they pass in the parameter “C” in “rhs!”
```=+10```

## **Total part 1 & 2**
+ ```=40/40```

## 2.  Part 3 + Writeup: 50 points
+ Simulations are run correctly (e.g., with 100 particles, using the correct dt) (5 points)
```=+5```
+ Includes a movie (e.g., a gif) (10 points)
```=+10```
+ Includes scatter plots (you may see 2 plots) of the particle positions (10 points)
```=+10```
+ Correct log-log “error vs dt” plots + “rhs evaluations vs error plots” (10 points)
```=+10```
+ Code is type stable and allocation-free (10 points)
```=+5/10``` 
*Running the code I found the following message, a 
a type imprecision, 
Locals
  @_6::Union{Nothing, Tuple{Int64, Int64}} 
it can return nothing or tuple.*
+ @code_warntype doesn’t show any variables of type “Any” (you should be able to check this by looking at the variables in the “Arguments” list or seeing if “Body::Any” appears below the variables list).
+ If the students use @btime for part 2, it should show zero allocations (if they use @time, it may show 4-8 allocations depending on the machine)
+ Writeup should have Sections containing outputs of @code_warntype for Parts 1 and 2 and output of @btime for Part 2
+ jlcode (5 points)
  ```=+5```
+ Their writeup uses the jlcode package
+ Their Github includes jlcode.sty

 ## **Total part 3 and writeup**
+ ```=45/50```

## 3.  Miscellaneous points: 10 points
+ Files are in the appropriate “homework-2” directory in their repository (-5)
```=5```

+ Tagged properly with a “homework-2” tag (-5)
```=5```
##  ** Grade Miscellaneous**
```=45/50```

# **Total**
```=95/100```


