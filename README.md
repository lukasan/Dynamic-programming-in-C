# Dynamic programming in C
## Compiling and running
To compile, simply call make inside the directory. This will compile all programs.
```
make
```

And then run from console:
```
./recursive-palindrome inputString
```
and
```
./dp-palindrome inputString
```
and
```
./lcs_weighted input1 input2 weight1 weight2
```

## Palindrome
Pages 22 to 26 inclusive: https://web.stanford.edu/class/cs97si/04-dynamic-programming.pdf

Finding the number of least insertions needed to form a palindrome.

Implementing expression:

![Image description](dyn.png)

Some code taken from https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

### Cleaning
Make is configured to remove all compiled programs.
```
make clean
```

## Longest weighted common sequence
Asignment:

Find longest common sequence of S1 and S2 by deleting symbols from either S1 or S2, such as the cost would be the lowest. Removing cost is costS1 and costS2.

E.g.

```
S1 = abcd
S2 = acdb
costS1 = 10
costS2 = 20

need to delete 'b' from both strings, i.e:
1 * costS1 + 1 * costS2 = 30
```

Thank you, GeeksforGeeks.

https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

https://www.geeksforgeeks.org/printing-longest-common-subsequence/

https://www.geeksforgeeks.org/edit-distance-and-lcs-longest-common-subsequence/

