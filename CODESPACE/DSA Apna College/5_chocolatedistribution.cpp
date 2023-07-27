#include<iostream>
using namespace std;

long findMinDiff (ArrayList<Long> a, long n, long m)
{
    collection.sort(a);
    long minDiff = Long.MAX_VALUE;
    for (int i=0 ;i+m-1 <n; i++)
    {
        minDiff = Math.min(a.get(i+(int)m-1)-a,get(i),minDiff);
    }
    return minDiff;
}