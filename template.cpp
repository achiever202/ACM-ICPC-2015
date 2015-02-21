/*
 * Author: Adarsh Pugalia.
 */
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <queue>

#define ll long long int
#define maxn 100000
#define sieve_max 1000000

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
ll fact[maxn+5];
ll ncr_table[maxn];
ll sieve[sieve_max+5];
vector <ll> primes;

/* Function to calculate sieve and the vector of primes upto sieve_max. */
void calc_sieve()
{
    for(ll i=0; i<=sieve_max; i++)
        sieve[i] = 0;

    sieve[0] = sieve[1] = 1;

    for(ll i=2; i<=sieve_max; i++)
    {
        if(sieve[i]==0)
        {
            primes.push_back(i);
            for(ll j=i+i; j<=sieve_max; j=j+i)
                sieve[j]++;
        }
    }
}

/* Function to calculate gcd. */
ll gcd(ll i, ll j)
{
    ll temp;
    if(i<j)
    {
        temp = i;
        i = j;
        j = temp;
    }

    while(i%j!=0)
    {
        temp = i;
        i = j;
        j = temp%j;
    }

    return j;

}

/* Function to calculate LCM */
ll lcm(ll i, ll j)
{
    ll ans = i*j;
    ans /= gcd(i, j);
    return ans;
}

/* This function generates factorail mod n. */
void init_fact()
{
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2; i<=maxn; i++)
        fact[i] = (fact[i-1]*i)%mod;
}

/* This function calculates the pth power of n in logn. */
ll modpow(ll n, ll p)
{
    ll ans = 1;
    while(p>0)
    {
        if(p&1)
            ans = (ans*n)%mod;

        n = (n*n)%mod;
        p = p/2;
    }
    return ans;
}

/* This function calculates ncr mod prime. */
ll ncr(ll n, ll r)
{
    ll ans = fact[n];
    ll denom = (fact[r]*fact[n-r])%mod;
    ans = (ans*modpow(denom, mod-2))%mod;
    return ans;
}

/* Funtion to build ncr table. */
void build_ncr_table(ll n)
{
    ncr_table[0][0] = 1;
    for(ll i=1; i<=n; i++)
    {
        ncr_table[i][0] = ncr_table[i][i] = 1;

        for(ll j=1; j<i; j++)
            ncr_table[i][j] = ncr_table[i-1][j-1] + ncr_table[i-1][j];
    }
}
