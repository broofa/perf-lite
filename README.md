

Testing the performance of a variety of (mostly interpreted) languages.
With code from http://izumi.plan99.net/blog/index.php/2008/01/17/ruby-vs-php-performance/

My results can be found at: http://goo.gl/YSmUH

## "But Operation X in language Y could be done faster!"
Yes, it could, but that's not relevant.  The code in these tests is intended to determine (roughly) how languages compare when performing the same kinds of primitive operations - array shifting, recursion, enumeration, etc.  Thus, the goal is not to have the fastest algorithm, but to have the *same* algorithm in each language.

## Implementation Notes

C++ compiled with "g++ -O2 test.cpp"
